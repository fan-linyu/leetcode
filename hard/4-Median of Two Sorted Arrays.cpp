// There are two sorted arrays nums1 and nums2 of size m and n respectively.
// 
// Find the median of the two sorted arrays. The overall run time complexity
// should be O(log (m+n)).
// 
// You may assume nums1 and nums2 cannot be both empty.
// 
// Example 1:
// nums1 = [1, 3]
// nums2 = [2]
// The median is 2.0
//
// Example 2:
// nums1 = [1, 2]
// nums2 = [3, 4]
// The median is (2 + 3)/2 = 2.5

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        bool f = nums1.empty();
        auto first = (!f ? nums1 : nums2),
             second = (f ? nums1 : nums2);
        long tmp = first.size() - 1, h = tmp, l = 0, mid;
        while (l <= h) { // binary search -> log(m)
            mid = (l + h) >> 1;
            int x = first[mid];
            // binary search -> log(n)
            auto p = lower_bound(second.begin(), second.end(), x);
            long ll = mid + (p - second.begin()), 
                 rl = (tmp - mid) + (second.end() - p),
                 t = ll - rl;
            if (t == 0 || (t == -2 && p != second.end() && *p == x))
                return x;
            if (t == 1) {
                int t1 = (mid ? first[mid-1] : INT_MIN),
                t2 = (p == second.begin() ? INT_MIN : *(--p));
                return  (x + max(t1, t2)) / 2.0d;    
            }
            if (t == -1) {
                int t1 = (mid == first.size()-1 ? INT_MAX : first[mid+1]),
                t2 = (p == second.end() ? INT_MAX : *p);
                return (x + min(t1, t2)) / 2.0d;
            }
            if (t < -1) {
                l = mid + 1;
            }
            else if (t > 1) {
                h = mid - 1;
            }
        }
        return findMedianSortedArrays(nums2, nums1);
    }
};
