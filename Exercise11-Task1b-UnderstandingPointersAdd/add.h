#pragma once

// PRE:  a, b, and res are valid pointers to integer values.
// POST: integer at location res contains the result of adding the integer at 
//       location a and the integer at location b.
void add(int* res, const int* a, const int* b);
