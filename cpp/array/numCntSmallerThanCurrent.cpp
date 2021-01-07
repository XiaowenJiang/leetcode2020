#include <iostream>
#include <vector>

using namespace std;

/*
 * Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it.
 * That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].
 * Return the answer in an array.

 * Constraints:

 * 2 <= nums.length <= 500
 * 0 <= nums[i] <= 100
 */

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		  // From the constraints, it's easy to know that we can prepare result for number
        // 0 - 100, find their frequencies and how many smaller ones of each number.
        vector<int> freq(101, 0);
        vector<int> cnt(101, 0);
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        for (int j = 1; j < 101; j++) {
				// this means the count of smaller numbers for value j, is the sum
            // of count for j - 1 and the frequency of value j - 1.
            cnt[j] = cnt[j - 1] + freq[j - 1];
        }
        vector<int> rst(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            rst[i] = cnt[nums[i]];
        }
        return rst;
    }
};
