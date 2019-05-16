// Given a string s consists of upper/lower-case alphabets and empty space
// characters ' ', return the length of last word in the string.
// 
// If the last word does not exist, return 0.
// 
// Note: A word is defined as a character sequence consists of non-space
// characters only.
// 
// Example:
// Input: "Hello World"
// Output: 5

class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        for (auto p = s.rbegin(); p != s.rend(); ++p) {
            if (*p == ' ' && cnt)
                break;
            if (*p != ' ')
                ++cnt;
        }
        return cnt;
    }
};
