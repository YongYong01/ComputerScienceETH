#include "solution.h"

StringSet all_permutations(const std::string& s) {
    StringSet result;

    // Base case: if the string is empty, return a set with an empty string
    if (s.empty()) {
        result.insert(s);
        return result;
    }
    
    // iterates over each letter in the s string. Each Character creates a new string remainingCharacters
    // afterwads it recursively recalls the function with the new string
    for (unsigned int currentIndex = 0; currentIndex < s.size(); currentIndex++) {
        std::string remainingCharacters = s.substr(0, currentIndex) + s.substr(currentIndex + 1);
        StringSet subResult = all_permutations(remainingCharacters);

        for (unsigned int subIndex = 0; subIndex < subResult.size(); subIndex++) {
            std::string subPermutation = subResult.at(subIndex);
            result.insert(s.at(currentIndex) + subPermutation);
        }
    }

    return result;
  
}