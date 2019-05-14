// Given an array nums of n integers and an integer target, are there elements
// a, b, c, and d in nums such that a + b + c + d = target? Find all unique
// quadruplets in the array which gives the sum of target.
// 
// Note:
// The solution set must not contain duplicate quadruplets.
// 
// Example:
// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        multiset<int> ms(nums.begin(), nums.end()); // n^4 -> n^3
        set<string> s; // not contain duplicate
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                auto s1 = nums[i] + nums[j];
                for (int k = j + 1, d; k < nums.size(); ++k) {
                    auto s2 = s1 + nums[k];
                    if ((d = target - s2) < nums[k])
                        break;
                    auto pd = ms.find(d);
                    if (pd != ms.end()) {
                        int cnt = 1;
                        cnt += ((nums[i] == d) + (nums[j] == d) + (nums[k] == d));
                        if (ms.count(d) < cnt)
                            continue;
                        string t = to_string(nums[i]) + ','
                            + to_string(nums[j]) + ','
                            + to_string(nums[k]) + ','
                            + to_string(d);
                        if (s.empty() || s.find(t) == s.end()) {
                            vector<int> v ({nums[i], nums[j], nums[k], d});
                            ans.push_back(v);
                            s.insert(t);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
