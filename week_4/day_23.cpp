/**

Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4
Example 2:

Input: [0,1]
Output: 0

**/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n)
    {
        int res = 0;
        for(int i = 30; i >= 0; i--)
        {
            bool b_1 = m & (1 << i);
            bool b_2 = n & (1 << i);
            if(b_1 != b_2) break;
            else if(b_1) res |= 1 << i;
        }
        return res;
    }
};