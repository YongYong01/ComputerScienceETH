#include <iostream>

class CustomArray {
private:
    int* data;
    size_t size;

public:
    // Constructor
    CustomArray(size_t size) : size(size) {
        data = new int[size];
        // Initialize data to zero or some default values
        // TODO: Add your initialization code here
    }

    // Copy Constructor
    CustomArray(const CustomArray& other) : size(other.size) {
        data = new int[size];
        // TODO: Copy the data from 'other' to this object
    }

    // Copy Assignment Operator
    CustomArray& operator=(const CustomArray& other) {
        if (this != &other) {
            // TODO: Free the existing resource
            // TODO: Allocate new memory and copy the data from 'other'
            // TODO: Handle self-assignment and deep copy
        }
        return *this;
    }

    // Destructor
    ~CustomArray() {
        // TODO: Free the allocated memory
    }

    // Additional methods for demonstration (optional)
    void setValue(size_t index, int value) {
        if (index < size) {
            data[index] = value;
        }
        // TODO: Handle out-of-range index
    }

    int getValue(size_t index) const {
        if (index < size) {
            return data[index];
        }
        // TODO: Handle out-of-range index and return a sensible value
        return -1;
    }

    size_t getSize() const {
        return size;
    }
};

int main() {
    // Example usage
    CustomArray arr1(10);
    arr1.setValue(0, 100);

    CustomArray arr2 = arr1;  // Copy constructor
    CustomArray arr3(5);
    arr3 = arr1;              // Copy assignment

    // TODO: Add more tests and demonstrations
}
