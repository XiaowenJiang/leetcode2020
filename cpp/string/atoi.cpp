#include<iostream>
#include<climits>

using namespace std;

/*
 * Implement atoi which converts a string to an integer.

 * The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
 * 
 * The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
 * 
 * If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
 * 
 * If no valid conversion could be performed, a zero value is returned.

 * Note:
 * 
 * Only the space character ' ' is considered as whitespace character.
 * Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
 */

class Solution {
public:
    int myAtoi(string str) {
        // digit zero's ascii
        int zero = 48;
        // sign + ascii
        int pos = 43;
        // sign - ascii
        int neg = 45;
        // return value
        int result = 0;
        // positive or negative sign
        int sign = 1;
        int i = 0;
        // skip the leading white spaces.
        for (; i < str.size(); i++) {
            if (str[i] != ' ') {
                break;
            }
        }
        // if the string is not a valid integer, just return 0.
        if (str[i] != pos && str[i] != neg && (str[i] < zero || str[i] > zero + 9)) {
            return 0;
        }
        // find out if the optional sign exists.
        if (str[i] == pos || str[i] == neg) {
            if (str[i] == neg) {
                sign = -1;
            }
            i++;
        }
        // loop through the digit.
        while (i < str.size() && str[i] >= zero && str[i] <= zero + 9) {
            // find out if the result is out of 32-bit integer boundary, if so,
            // return directly.
            long newRst = long(result) * 10 + str[i] - zero;
            if (newRst > INT_MAX) {
                if (sign == 1) {
                    return INT_MAX;
                } else {
                    return INT_MIN;
                }
            }
            result = newRst;
            i++;
        }
        result *= sign;
        return result;
    }
};
