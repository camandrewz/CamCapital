// We want Boost Date_Time support, so include these before hffix.hpp.
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/date_time/gregorian/gregorian_types.hpp>
#include "Secrets/secrets.hh"
#include <External/hffix.hpp>
#include <External/cpp-cryptlite/include/cryptlite/sha256.h>
#include <External/cpp-cryptlite/include/cryptlite/hmac.h>

#include <iostream>

using namespace boost::posix_time;
using namespace boost::gregorian;
using namespace cryptlite;

int main(int argc, char **argv)
{
    int seq_send(1); // Sending sequence number.
    char buffer[1 << 13];

    time_t now = time(0);
    tm *ltm = localtime(&now);
    ptime tsend(date(1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday), time_duration(5 + ltm->tm_hour, 30 + ltm->tm_min, ltm->tm_sec));

    // calculate hmac-sha256
    boost::uint8_t hmacsha256digest[sha256::HASH_SIZE];
    std::string signature = hmac<sha256>::calc_hex("basestring", Secrets::get_secret());

    // We'll put a FIX Logon message in the buffer.
    hffix::message_writer logon(buffer, buffer + sizeof(buffer));

    // Write BeginString and BodyLength.
    logon.push_back_header("FIX.4.2");
    // Logon MsgType.
    logon.push_back_string(hffix::tag::MsgType, "A");
    logon.push_back_string(hffix::tag::SenderCompID, Secrets::get_public());
    logon.push_back_string(hffix::tag::TargetCompID, "FTXUS");
    // No encryption.
    logon.push_back_int(hffix::tag::EncryptMethod, 0);
    // 30 second heartbeat interval.
    logon.push_back_int(hffix::tag::HeartBtInt, 30);
    logon.push_back_string(hffix::tag::RawData, signature);
    // "Y": all account orders will be cancelled at the end of the session
    logon.push_back_string(8013, "Y");
    logon.push_back_int(hffix::tag::MsgSeqNum, seq_send++);
    logon.push_back_timestamp(hffix::tag::SendingTime, tsend);

    logon.push_back_trailer(); // write CheckSum.

    // Now the Logon message is written to the buffer.

    // Write both messages to stdout.
    std::cout.write(buffer, logon.message_end() - buffer);

    return 0;
}