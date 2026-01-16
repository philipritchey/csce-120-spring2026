#include "number_slicing.h"

/*
have a number: 8675309
want to access the number digit-by-digit
would like 8, 6, 7, 5, 3, 0, 9
will settle for any order, e.g. 9, 0, 3, 5, 7, 6, 8

8675309 = 8657300 + 9 = 867530*10 + 9
get the last digit: 867530|9
shift the number to the right by one (chop off last digit): 867530
repeat: 86753|0 -> 86753
...
until the number becomes 0: 0|8 -> 0
*/

int sum_of_digits(int number) {
    int sum = 0;

    // until the number is 0, do
    while (number != 0) {
        // get the last digit
        int digit = number % 10;
        // chop off the last digit of the number
        number = number / 10;
        // do something with the digit
        sum += digit;
    }  // end
    return sum;
}
