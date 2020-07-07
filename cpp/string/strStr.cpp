#include <iostream>
#include <string>

/*
 * Implement strStr().
 * Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 */

class Solution {
// Brute force method
public:
    int strStr(string haystack, string needle) {
        int haySize = haystack.size();
        int neSize = needle.size();
        if (neSize > haySize) {
            return -1;
        }
        int idx = 0;
        for (; idx <= haySize - neSize; idx++) {
            int j = 0;
            while ((j < neSize) && (haystack[idx + j] == needle[j])) {
                j++;
            }
            if (j == neSize) {
                return idx;
            }
        }
        return -1;
    }
};
