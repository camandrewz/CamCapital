
namespace MM {

double mmIsProfitable(double fees, double bid, double ask, double size) {
    return ((size * (ask - .0000001) * (1 - fees)) - (size * (bid + .0000001) * (1 + fees)));
}

/*
    - Determine whether it is profitable to enter a position including fees
    - Place a bid at the top of the order book
    - Wait to be filled
        -- if while waiting we are no longer top of the book, cancel the order
    - When we get filled, place an ask at the top of the book for the price determined to be profitable
        -- if in the process of getting filled the trade is no longer profitable, continue with the sell anyway

    - Repeat
        -- never finish this process while holding the traded security
*/

}