// Implement int sqrt(int x).
// 
// Compute and return the square root of x, where x is guaranteed to be a
// non-negative integer.
// 
// Since the return type is an integer, the decimal digits are truncated and
// only the integer part of the result is returned.
// 
// Example 1:
// Input: 4
// Output: 2
//
// Example 2:
// Input: 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since
//              the decimal part is truncated, 2 is returned.
 
#include <bits/stdc++.h>
using namespace std;
int mySqrt(int x) {
    int l = 0, h = x;
    long m, t;
    while (l <= h) {
        m = (l + h) >> 1;
        t = m * m - x;
        if (t == 0) return m;
        if (t < 0)  
            l = m + 1;
        else
            h = m - 1;
    }
    if (t < 0)
        return -t < ((m + 1) * (m + 1) - x) ? m : m + 1;
    return t < (x - (m - 1) * (m - 1)) ? m : m - 1;
}
int main() {
    int n;
    while (cin >> n) {
	cout << mySqrt(n) << '\n';
    }
    return 0;
}
