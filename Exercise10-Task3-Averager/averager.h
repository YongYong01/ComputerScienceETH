#pragma once

class Averager {
  double sum = 0;
  unsigned int count = 0;
public:
  // POST: instance is initialized with 0;
  // Note: Constructor not required here since the compiler generates a
  //       default constructor whenever no explicit constructor is defined in
  //       the code. The default constructor initializes `sum` and `count` to
  //       0 and thus does exactly what we want already.
  // Averager();

  // POST: Adds a value to the current average calculation.
  void add_value(double value);

  // POST: Returns the average of all added values, or zero,
  //       if no value has been added.
  double get_average();

  // POST: Removes all values from the current average calculation.
  void reset();
};
