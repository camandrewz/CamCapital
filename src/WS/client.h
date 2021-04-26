#pragma once

#include "WS.h"
#include <../External/json.hpp>
#include <string>
#include <vector>

using json = nlohmann::json;

namespace ftx {

class WSClient
{
  public:
    WSClient();

    void on_message(util::WS::OnMessageCB cb);
    void connect();
    std::vector<json> on_open();

    void subscribe_orders(std::string market);
    void subscribe_orderbook(std::string market);
    void subscribe_fills(std::string market);
    void subscribe_trades(std::string market);
    void subscribe_ticker(std::string market);

  private:
    std::vector<std::pair<std::string, std::string>> subscriptions;
    util::WS::OnMessageCB message_cb;
    util::WS ws;
    const std::string uri = "wss://ftx.com/ws/";
    const std::string api_key = "iaUEv7GQnjArPlXLp8EVBCjBKS4JuRagozUi9Gze";
    const std::string api_secret = "3Av_lK2ZSIk6mSSWF9HDdbaN-s7XiLX4eyyb3s1u";
    const std::string subaccount_name = "";
};

}