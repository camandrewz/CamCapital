#include "WS/client.hh"
#include "Strategies/marketMaking.hh"
#include <External/json.hpp>
#include <iostream>
#include <string>
#include <thread>

using json = nlohmann::json;

void print_to_console(std::string str)
{
    std::cout << str;
}

int main()
{

    json emptyJSON = {};

    double bid = 0;
    double ask = 0;
    double aum = 1000;
    double fees = .001;
    int count = 0;

    ftx::WSClient client;

    client.subscribe_ticker("BCH/USD");

    client.on_message([&](std::string j) {
        json tick = json::parse(j);
        json data = tick.value("data", emptyJSON);

        if (data != emptyJSON && data != NULL)
        {
            bid = data.at("bid");
            ask = data.at("ask");
        }
    });

    std::thread ws_thread(&ftx::WSClient::connect, &client);

    while (0 < 1)
    {

        double size = aum / ask;
        double profit = MM::mmIsProfitable(fees, bid, ask, size);

        count++;

        if (profit > 0)
        {
            aum += profit;

            std::thread t1(print_to_console, "Market Make Possible! Profit: " + std::to_string(profit) + "\n");
            t1.join();
        }
        else
        {
            if (count % 10 == 0)
            {
                std::thread t2(print_to_console, "AUM: " + std::to_string(aum) + "\n");
                t2.join();
            }
        }
    }

    ws_thread.join();
}