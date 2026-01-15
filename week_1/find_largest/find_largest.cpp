// find the largest number in a series of numbers
// assume we are given the number of numbers (how many there are)
//   i.e. input looks like
//   3
//   1 2 3
// assume that all the numbers are non-negative

#include <iostream>

int main() {
    // read in how many numbers there are -> n
    int n = 0;
    std::cin >> n;

    // set current max to 0
    int current_max = 0;

    // do the following n times:
    for (int i = 0; i < n; i++) {
        // read a number
        int number = 0;
        std::cin >> number;

        // set current max to first number if not yet set
        if (i == 0) {
            current_max = number;
        }

        // if the number is bigger than the current max, then
        if (number > current_max) {
            // update the current max to be the number
            current_max = number;
        }  // end
    }
    // print the current max
    std::cout << "max: " << current_max << std::endl;
}
