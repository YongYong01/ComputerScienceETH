#pragma once

// PRE: x is roundable to a number in the value range of type int
// POST: return value is the integer nearest to x, or the one further
//       away from 0 if x lies right in between two integers.
int round_number(double x) {
  // TODO
  int truncated = (int)x;

    // Calculation
    double fraction = x - truncated;

    if (fraction == 0.5) {
        // Check if even
        if (truncated % 2 == 0) {
            return truncated;
        }
        // Check if odd
        else {
            return truncated + 1;
        }
    }
    if (fraction < 0) {
        if (fraction <= -0.5) {
            return truncated - 1;
        } else {
            return truncated;
        }
    } else {
        if (fraction >= 0.5) {
            return truncated + 1;
        } else {
            return truncated;
        }
    }
}
