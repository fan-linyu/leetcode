// Write a function to find the longest common prefix string 
// amongst an array of strings.
//
// If there is no common prefix, return an empty string "".
// 
// Example 1:
// Input: ["flower","flow","flight"]
// Output: "fl"
//
// Example 2:
// Input: ["dog","racecar","car"]
// Output: ""
// 
// Explanation: There is no common prefix among the input strings.
// Note:
// All given inputs are in lowercase letters a-z.
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())   return "";
        string p = "", v = strs[0], s;
        int mlen = v.length();
        for (int i = 1; i < strs.size(); ++i) {
            s = strs[i];
            if (mlen > s.length())
                mlen = s.length();
            for (int j = 0; j < mlen; ++j)
                if (v[j] != s[j])
                    mlen = j;
        }
        return p + v.substr(0, mlen);
    }
};
