#include <iostream>
#include <vector>
#include "num_elements.h"

int main() {
    std::vector<int> vec;
    int idx1, idx2;
    unsigned int length;
    std::cin >> length;
    for (unsigned int i = 0; i < length; ++i) {
        vec.push_back(0);
    }
    std::cin >> idx1 >> idx2;
    std::cout << num_elements(vec.data() + idx1, vec.data() + idx2) << "\n";
    return 0;
}