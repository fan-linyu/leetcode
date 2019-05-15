// Given two binary strings, return their sum (also a binary string).
// 
// The input strings are both non-empty and contains only characters 1 or 0.
// 
// Example 1:
// Input: a = "11", b = "1"
// Output: "100"
//
// Example 2:
// Input: a = "1010", b = "1011"
// Output: "10101"

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int c = 0;
        for (int i = a.size()-1, j = b.size()-1; i >=0 || j >= 0; --i, --j) {
            auto d = (i < 0 ? 0 : a[i] - '0'),
                 e = (j < 0 ? 0 : b[j] - '0'),
                 f = c + d + e;
            ans = to_string(f % 2) + ans;
            c = f / 2;
        }
        if (c)
            ans = to_string(c) + ans;
        return ans;
    }
};
