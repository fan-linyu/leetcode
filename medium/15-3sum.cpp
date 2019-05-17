// Given an array nums of n integers, are there elements a, b, c in nums such
// that a + b + c = 0? Find all unique triplets in the array which gives the
// sum of zero.
// 
// Note:
// The solution set must not contain duplicate triplets.
// 
// Example:
// Given array nums = [-1, 0, 1, 2, -1, -4],
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i + 2 < nums.size(); ++i) {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                auto t = nums[i] + nums[j] + nums[k];
                if (t == 0) {
                    vector<int> v {nums[i], nums[j], nums[k]};
                    ans.push_back(v);
                }   
                while (t <= 0 && j + 1 <= k && nums[j] == nums[++j]);
                while (t >= 0 && k - 1 >= j && nums[k] == nums[--k]);
            }
        }
        return ans;
    }
};

int main(int argc, char *args[]) {
    vector<int> v {-1,0,1,2,-1,-4};
    for (auto c : threeSum(v)) {
	for (auto p : c)
	    cout << p << " ";
	cout << '\n';
    }
    return 0;    
}
