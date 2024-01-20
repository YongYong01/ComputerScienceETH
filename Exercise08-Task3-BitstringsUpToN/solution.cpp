#include "solution.h"


void generate_bitstrings(std::vector<std::string>& bitstrings, std::string current, int n) {
    if (n == 0) {
        bitstrings.push_back(current);
        return;
    }

    generate_bitstrings(bitstrings, current + "0", n - 1);
    generate_bitstrings(bitstrings, current + "1", n - 1);
}

std::vector<std::string> all_bitstrings_up_to_n(unsigned int n) {
    std::vector<std::string> bitstrings;
    for (unsigned int i = 0; i <= n; ++i) {
        generate_bitstrings(bitstrings, "", i);
    }
    return bitstrings;
}