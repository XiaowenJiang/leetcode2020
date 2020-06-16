#include<iostream>
#include<string>

using namespace std;

/*
 *	Given a string s, find the longest palindromic substring in s.
 * You may assume that the maximum length of s is 1000.
 */

class Solution {
public:
    string longestPalindrome(string s) {
        // The index where the longest palindro starts.
        int minStart = 0, maxLen = 1;
        // If the string is empty or it only has 1 char, just return.
        if (s.size () <= 1)
            return s;
        for (int i = 0; i < s.size();) {
            // The residual part of string is smaller than the current
            // largest palindro
            if (s.size() - i  <= maxLen / 2)
                break;
            // The index to be matched
            int before = i, after = i;
            // Skip some duplicate chars
            while (after < s.size() - 1 && s[after] == s[after + 1]) {
                after++;
            }
            // Move the center position to the right
            i = after + 1;
            // Compare and ensure the boundary is not exceeded.
            while (before > 0 && after < s.size() -1 && s[before - 1] == s[after + 1]) {
                before--;
                after++;
            }
            // Calculate the new length of the palindrom and compare with
            // the largest one.
            int newLen = after - before + 1;
            if (newLen > maxLen) {
                minStart = before;
                maxLen = newLen;
            }
        }
        return s.substr(minStart, maxLen);
    }
};
