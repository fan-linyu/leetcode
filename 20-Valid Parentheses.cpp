// Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
// determine if the input string is valid.
// 
// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Note that an empty string is also considered valid.
// 
// Example 1:
// Input: "()"
// Output: true
// 
// Example 2:
// Input: "()[]{}"
// Output: true
// 
// Example 3:
// Input: "(]"
// Output: false
// 
// Example 4:
// Input: "([)]"
// Output: false
// 
// Example 5:
// Input: "{[]}"
// Output: true

class Solution {
public:
    bool isValid(string s) {
        if (s.size() & 1)   return false;
        vector<char> v(s.size()>>2);
        v.clear();
        map<char, char> m {{')', '('}, {'}', '{'}, {']', '['}};
        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[') {
                v.push_back(c);
            }
            else {
                if (!v.empty() && m[c] == v.back()) // match
                    v.pop_back();
                else
                    return false;
            }
        }
        return v.empty();
    }
};
