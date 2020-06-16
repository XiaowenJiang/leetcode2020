#include <iostream>
#include <algorithm>

/*
 *Given a string, find the length of the longest substring without repeating characters.
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int start = -1;
		  // use the dict to record the latest index of
		  // a certain character. Initialize each character's
		  // index to -1.
        vector<int> dict(256, -1);
        for (int i = 0; i < s.length(); i++) {
			   // This indicates that a character has already been
			   // set, and this one is a repeated occurance, so
				// the last non-repeat word could be calculate.
            if (dict[s[i]] > start) {
                start = dict[s[i]];
            }
				// Set the index of the character to the last index.
            dict[s[i]] = i;
				// Calculate the last word's length and compare to
				// the longest word's length.
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};
