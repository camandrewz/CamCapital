
namespace MM {

double mmIsProfitable(double fees, double bid, double ask, double size) {
    return ((size * (ask - .0000001) * (1 - fees)) - (size * (bid + .0000001) * (1 + fees)));
}

}