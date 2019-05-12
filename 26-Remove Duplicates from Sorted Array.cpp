// Given a sorted array nums, remove the duplicates in-place such that each element
// appear only once and return the new length.
// 
// Do not allocate extra space for another array, you must do this by modifying the
// input array in-place with O(1) extra memory.
// 
// Example 1:
// Given nums = [1,1,2],
// Your function should return length = 2, with the first two elements of nums 
// being1 and 2 respectively.
// It doesn't matter what you leave beyond the returned length.
// 
// Example 2:
// Given nums = [0,0,1,1,1,2,2,3,3,4],
// Your function should return length = 5, with the first five elements of nums 
// being modified to 0, 1, 2, 3, and 4 respectively.
// It doesn't matter what values are set beyond the returned length.

class Solution {
public:
    int removeDuplicates_(vector<int>& nums) {
        if (nums.empty())   return 0;
        int i = 0, l = nums[i++];
        for (; i < nums.size(); ) {
            if (nums[i] == l)   nums.erase(nums.begin()+i);
            else                l = nums[i++];
        }
        return nums.size();
    }
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())   return 0;
        auto p = nums.end();
        for (auto q = p + 1; q != nums.end(); ++q) {
            if (*p != *q) {
                nums.erase(++p, q);
                q = p;
            }
        }
        if (++p != nums.end()) {
            nums.erase(p, nums.end());
        }
        return nums.size();
    }
};
