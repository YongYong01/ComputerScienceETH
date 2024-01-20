#pragma once

#include <string>

#include "set.h"

using StringSet = Set<std::string>;

StringSet all_permutations(const std::string& s);