#include<iostream>

/*
 * Write a function to find the longest common prefix string amongst an array of strings.
 * If there is no common prefix, return an empty string "".
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common = "";
		  // If the vector is empty, return empty string.
        if (strs.size() == 0) {
            return common;
        }
        for (int i = 0; i < strs[0].size(); common += strs[0][i], i++) {
				// Check from the first one in case of a single elem vector.
            // In the case like ["aaa"], we should return "aaa".
            for (int j = 0; j < strs.size(); j++) {
					 // Check if the index i is out of boundary for strs[j]
                if (i >= strs[j].size() || strs[j][i] != strs[0][i])
                    return common;
            }
        }
        return common;
    }
};
