#include <iostream>
#include <vector>

using namespace std;

/*
 * Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].
 * Return the array in the form [x1,y1,x2,y2,...,xn,yn].
 */

// Method 1: Brute force

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> rst;
        rst.reserve(n * 2);
        for (int i = 0; i < n; i++) {
            rst.push_back(nums[i]);
            rst.push_back(nums[n + i]);
        }
        return rst;
    }
};
