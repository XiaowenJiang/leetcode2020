#include<iostream>
#include<vector>
#include<string>

using namespace std;

/*
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
 * A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 */

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        vector<string> maps = {"", "abc", "def", "ghi", "jkl", "mno",
                               "pqrs", "tuv", "wxyz"};
        for (const char &c : digits) {
            int num = c - '0';
            if (num <= 0 || num > 9) {
                break;
            }
            if (num == 1) {
                continue;
            }
            if (result.empty()) {
                result.push_back("");
            }
            string candidates = maps[num - 1];
            vector<string> tmp;
            for (char candi : candidates) {
                for (string s : result) {
                    tmp.push_back(s + candi);
                }
            }
            result.swap(tmp);
        }
        return result;
    }
};
