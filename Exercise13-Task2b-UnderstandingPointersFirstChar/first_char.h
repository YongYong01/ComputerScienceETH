#pragma once

// PRE: str points within an allocated memory block which contains
//      the null character (numerical ASCII value 0) at its last location, 
//      and nowhere else.
// POST: Returns the pointer to first element at str or after 
//       that is equal to ch, otherwise return nullptr.
const char* first_char(const char* str, const char ch);
