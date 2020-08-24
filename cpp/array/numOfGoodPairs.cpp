#include<iostream>
#include<vector>
using namespace std;

/*
 * Given an array of integers nums.

 * A pair (i,j) is called good if nums[i] == nums[j] and i < j.

 * Return the number of good pairs.
 */

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int rst = 0;
        if (nums.size() == 1) {
            return rst;
        }
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    rst++;
                }
            }
        }
        return rst;
    }
};
