#include "WS/client.h"
#include "Strategies/marketMaking.h"
#include <External/json.hpp>
#include <iostream>
#include <string>

using json = nlohmann::json;

int main()
{

    json emptyJSON = {};

    double bid = 0;
    double ask = 0;
    double aum = 1000;

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

        double fees = .001;
        double size = aum / ask;
        double profit = MM::mmIsProfitable(fees, bid, ask, size);

        count++;

        if (profit > 0)
        {
            aum += profit;

            std::cout << "Market Make Possible! Profit: " << profit << '\n';
            std::cout << "AUM: " << aum << '\n';
        }
        else
        {
            if (count % 10 == 0)
            {
                std::cout << "AUM: " << aum << '\n';
            }
        }
    });

    client.connect();
}