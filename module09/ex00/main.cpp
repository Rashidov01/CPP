#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " input" << std::endl;
        return 1;
    }

    std::cout << std::fixed << std::setprecision(2);

    BitcoinExchange exchange("data.csv");
    exchange.infileRead(argv[1]);

    return 0;
}
