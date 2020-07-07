#include <iostream>
#include <stack>

using namespace std;

/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

 * An input string is valid if:
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Note that an empty string is also considered valid.
 */

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stk;
        for (const char &c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
                continue;
            } else {
                if (stk.empty()) {
                    return false;
                }
                if ((c == ')' && stk.top() == '(') || (c == '}' && stk.top() == '{') || (c == ']' && stk.top() == '[')) {
                   stk.pop(); 
                } else {
                    return false;
                } 
            }
        }
        if (stk.empty()) {
            return true;
        }
        return false;
    }
};
