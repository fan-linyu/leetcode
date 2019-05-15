// The count-and-say sequence is the sequence of integers with the first five
// terms as following:
// 
// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// 
// Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the
// count-and-say sequence.
// 
// Note: Each term of the sequence of integers will be represented as a string.
// 
// Example 1:
// Input: 1
// Output: "1"
// 
// Example 2:
// Input: 4
// Output: "1211"

class Solution {
public:
    string countAndSay(int n) {
        vector<string> v(n); // n >= 1
        v.push_back("1");
        for (int i = 1, cnt = 1; i < n; ++i) {
            string s = v.back(), ans; // !s.empty()
            auto p = s.begin(), q = p + 1;
            for (; q != s.end(); ++q) {
                if (*p != *q) {
                    ans += to_string(cnt) + *p;
                    p = q;
                    cnt = 1;
                }
                else
                    ++cnt;
            }
            ans += to_string(cnt) + *p;
            v.push_back(ans);
        }
        return v.back();
    }
};
