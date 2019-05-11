// Given a string, find the length of the longest substring without repeating 
// characters.
// 
// Example 1:
// Input: "abcabcbb"
// Output: 3 
// Explanation: The answer is "abc", with the length of 3. 
// 
// Example 2:
// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// 
// Example 3:
// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3. 
// Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> m;
        int l = 0, len = 0, ans = 0;
        for (int r = 0 ; r < s.size(); ++r) {
            if (m.find(s[r]) == m.end()) { // no repeat
                if (++len > ans)
		    ans = len;
                m.insert(s[r]);
            } else {  // repeat
                for (int i = l; i < r; ++i) {
                    if (s[i] == s[r]) {
                        l = i + 1;
                        break;
                    }
                    m.erase(m.find(s[i]));
                    --len;
                }
            }
        }
        return ans;
    }
};
