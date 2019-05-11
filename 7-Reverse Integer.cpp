// Given a 32-bit signed integer, reverse digits of an integer.
// 
// Example 1:
// Input: 123
// Output: 321
// 
// Example 2:
// Input: -123
// Output: -321
// 
// Example 3:
// Input: 120
// Output: 21
// Note:
// Assume we are dealing with an environment which could only store integers 
// within the 32-bit signed integer range: [−2^31,  2^31 − 1]. 
// For the purpose of this problem, assume that your function returns 0 when 
// the reversed integer overflows.

class Solution {
public:
    int reverse(int x) {
        long lx = (long)x; // if x = -2^31, then (int)-x will overflow
        string s = to_string(lx < 0 ? -lx : lx);
        std::reverse(s.begin(), s.end());
        long ans = stol(s);
        if ((lx < 0 && (ans = -ans) < INT_MIN) ||
            (lx > 0 && ans > INT_MAX)) {
            return 0;
        }
        return (int)ans;
    }
};
