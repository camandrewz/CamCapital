#include <fix8/connection.hpp>

Poco::Net::StreamSocket testSocket;

FIX8::Connection testConn = FIX8::Connection(testSocket);

