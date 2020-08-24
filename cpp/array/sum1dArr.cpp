#include <iostream>
#include <vector>

using namespace std;

/*
 * Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
 * Return the running sum of nums.
 */

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> rst;
        rst.reserve(nums.size());
        int tmp = 0;
        for (int i = 0; i < nums.size(); i++) {
            tmp += nums[i];
            rst.push_back(tmp);
        }
        return rst;
    }
};
