// Given a string s, find the longest palindromic substring in s. You may assume
// that the maximum length of s is 1000.
// 
// Example 1:
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
//
// Example 2:
// Input: "cbbd"
// Output: "bb"

class Solution {
public:
    string longestPalindrome(string s) {
        for (int len = s.length(); len > 0; --len) {
            int r = (len - 1) / 2, c = !(len&1);
            for (int j = r; j < s.length() - r; ++j) {
                bool f = true;
                for (int t = r ; t >= 0; --t) {
                    if (s[j-t] != s[j+t+c]) {
                        f = false;
                        break;
                    }
                }
                if (f)
                    return s.substr(j-r, len);
            }
        }
        return "";
    }
};
