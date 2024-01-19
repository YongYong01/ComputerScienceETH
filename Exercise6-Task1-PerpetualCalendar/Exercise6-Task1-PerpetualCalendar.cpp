#include <cassert>
#include <iostream>

// Functions to be implemented

// PRE:  a year greater or equal than 1900
// POST: returns whether that year was a leap year
bool is_leap_year(unsigned int year);

// PRE:  a year greater or equal than 1900
// POST: returns the number of days in that year
unsigned int count_days_in_year(unsigned int year);

// PRE:  a month between 1 and 12 and a year greater or equal than 1900
// POST: returns the number of days in the month of that year
unsigned int count_days_in_month(unsigned int month, unsigned int year);

// PRE:  n/a
// POST: returns whether the given values represent a valid date
bool is_valid_date(unsigned int day, unsigned int month, unsigned int year);

// PRE:  the given values represent a valid date
// POST: returns the number of days between January 1, 1900 and this date (excluding this date)
unsigned int count_days(unsigned int day, unsigned int month, unsigned int year);

// PRE: the given values represent a (potentially invalid) date
// POST: prints the weekday if the date is valid or "invalid date" otherwise.
//      Everything must be printed in lowercase.
void print_weekday(unsigned int day, unsigned int month, unsigned int year);

// PRE: a year greater or equal than 1900
// POST: returns whether that year was a leap year
bool is_leap_year(unsigned int year) {
  //To be implemented
  assert(year >= 1900);
  if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
    return true;
  }
  else{
    return false;
  }
}

// PRE: a year greater or equal than 1900
// POST: returns the number of days in that year
unsigned int count_days_in_year(unsigned int year) {
  //To be implemented
  assert(year >= 1900);
  if(is_leap_year(year)){
    return 366;
  }
  else{
    return 365;
  }
}

// PRE: a month between 1 and 12 and a year greater or equal than 1900
// POST: returns the number of days in the month of that year
unsigned int count_days_in_month (unsigned int month, unsigned int year) {
  //To be implemented
  assert((month >= 1 && month <= 12) && year >= 1900);
  int count = 0;
  switch (month) {
    case 1:
      count = 31;
      break;
    case 2:
      if (is_leap_year(year)) {
        count = 29;
      } else {
        count = 28;
      }
      break;
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      count = 31;
      break;
    default:
      count = 30;
      break;
  }
  return count;
}

// PRE:  n/a
// POST: returns whether the given values represent a valid date
bool is_valid_date(unsigned int day, unsigned int month, unsigned int year) {
  //To be implemented
  if (year >= 1900 && month >= 1 && month <= 12) {
    switch (month) {
      case 1: // January
      case 3: // March
      case 5: // May
      case 7: // July
      case 8: // August
      case 10: // October
      case 12: // December
        return (day >= 1 && day <= 31);
      case 4: // April
      case 6: // June
      case 9: // September
      case 11: // November
        return (day >= 1 && day <= 30);
      case 2: // February
        if (is_leap_year(year)){
          return (day >= 1 && day <= 29);
        }
        else{
          return (day >= 1 && day <= 28);
        }
      default:
        return false;
    }
  }
  // out of range
  return false;
}

// PRE: the given values represent a valid date
// POST: returns the number of days between January 1, 1900 and this date (excluding this date)
unsigned int count_days(unsigned int day, unsigned int month, unsigned int year) {
  //To be implemented
  assert(is_valid_date(day, month, year));
  int count = 0;
  for(unsigned int i = 1900; i < year; ++i){
    for (unsigned int m = 1; m <= 12; ++m){
      count += count_days_in_month(m, i);
    }
  }
  for (unsigned int m = 1; m < month; ++m) {
        count += count_days_in_month(m, year);
    }
count += day - 1;
return count;
}

// PRE: the given values represent a (potentially invalid) date
// POST: prints the weekday if the date is valid or "invalid date" otherwise.
//      Everything must be printed in lowercase.
void print_weekday(unsigned int day, unsigned int month, unsigned int year){
  //To be implemented
  
  if (!is_valid_date(day, month, year)) {
      std::cout << "invalid date";
      return;
  }
  /*
  // Zeller Algorithm
  if (month == 1) {
        month = 13;
        year--;
    }
    if (month == 2) {
        month = 14;
        year--;
    }
  
  int k = year % 100;
  int j = year / 100;
  
  int day_of_week = (day + 13 * (month + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
  
  if (day_of_week < 0) {
      day_of_week += 7;
  }
  */
  
   // start date (January 1, 1900)
  //unsigned int start_day = 1;
  //unsigned int start_month = 1;
  unsigned int start_year = 1900;
  unsigned int total_days = 0;

  for (unsigned int y = start_year; y < year; ++y) {
    total_days += count_days_in_year(y);
  }

  for (unsigned int m = 1; m < month; ++m) {
    total_days += count_days_in_month(m, year);
  }

  total_days += day - 1;

  // Calculate the weekday using modulo 7
  unsigned int day_of_week = (total_days + 1) % 7;
  
  switch (day_of_week){
    case 0:
      std::cout << "sunday";
      break;
    case 1:
      std::cout << "monday";
      break;
    case 2:
      std::cout << "tuesday";
      break;
    case 3:
      std::cout << "wednesday";
      break;
    case 4:
      std::cout << "thursday";
      break;
    case 5:
      std::cout << "friday";
      break;
    case 6:
      std::cout << "saturday";
      break;
  }
}

void test_is_leap_year(){
  std::cout << "Year?\n";
  unsigned int year; std::cin >> year;
  
  bool ret = is_leap_year(year);
  if (ret)
    std::cout << "This is a leap year" << std::endl;
  else
    std::cout << "This is not a leap year" << std::endl;
}

void test_count_days_in_year(){
  // input the date
  std::cout << "Year?\n";
  unsigned int year; std::cin >> year;
  std::cout <<  count_days_in_year(year) << std::endl;
}


void test_count_days_in_month(){
  // input the date
  std::cout << "Month?\n";
  unsigned int month; std::cin >> month;

  std::cout << "Year?\n";
  unsigned int year; std::cin >> year;
  std::cout <<  count_days_in_month(month, year) << std::endl;
}

void test_is_valid_date(){
  // input the date
  std::cout << "Day?\n";
  unsigned int day; std::cin >> day;

  std::cout << "Month?\n";
  unsigned int month; std::cin >> month;

  std::cout << "Year?\n";
  unsigned int year; std::cin >> year;
  bool ret = is_valid_date(day, month, year);
  if (ret)
    std::cout <<  "This is a valid date" << std::endl;
  else
    std::cout <<  "This is not a valid date" << std::endl;
}


void test_count_days(){
  // input the date
  // std::cout << "Day?\n";
  unsigned int day; std::cin >> day;
  
  // std::cout << "Month?\n";
  unsigned int month; std::cin >> month;
  
  // std::cout << "Year?\n";
  unsigned int year; std::cin >> year;
  std::cout <<  count_days(day, month, year) << std::endl;
}

void test_print_weekday(){
  // input the date
  std::cout << "Day?\n";
  unsigned int day; std::cin >> day;

  std::cout << "Month?\n";
  unsigned int month; std::cin >> month;

  std::cout << "Year?\n";
  unsigned int year; std::cin >> year;
  print_weekday(day, month, year);
}

// Main function of the C++ program.
int main() {
  
  
  unsigned int choice;
  do{
    std::cout << "Please select the function to test:" << std::endl;
    std::cout << "1: is_leap_year" << std::endl;
    std::cout << "2: count_days_in_year" << std::endl;
    std::cout << "3: count_days_in_month" << std::endl;
    std::cout << "4: is_valid_date" << std::endl;
    std::cout << "5: count_days" << std::endl;
    std::cout << "6: print_weekday" << std::endl;
    std::cin >> choice;
  }while(choice < 1 || choice > 7);
    
  //call the appropriate function
  switch(choice){
    case 1:
      test_is_leap_year();
      break;
    case 2:
      test_count_days_in_year();
      break;
    case 3:
      test_count_days_in_month();
      break;
    case 4:
      test_is_valid_date();
      break;
    case 5:
      test_count_days();
      break;
    case 6:
      test_print_weekday();
      break;
  }

  return 0;
}
