#include<iostream>
#include<algorithm>

using namespace std;

/*
 * Given the array candies and the integer extraCandies, where candies[i] represents the number of candies that the ith kid has.

 * For each kid check if there is a way to distribute extraCandies among the kids such that he or she can have the greatest number of candies among them. Notice that multiple kids can have the greatest number of candies.
 */

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<int>::iterator maxIt;
        vector<bool> rst;
        rst.reserve(candies.size());
        maxIt = std::max_element(candies.begin(), candies.end());
        for (const int &elem : candies) {
            if (elem + extraCandies >= *maxIt) {
                rst.push_back(true);
            } else {
                rst.push_back(false);
            }
        }
        return rst;
    }
};
