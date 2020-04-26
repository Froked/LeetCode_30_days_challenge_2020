/**

Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True
Note:
The string size will be in the range [1, 100].

**/


// my solution: DP. I saw the greedy approach after solving this, but that
// does not seem intuitive to me.

class Solution {
public:
    int dp[105][105];
    bool f(string &s, int index, int open)
    {
        if(index == s.size()) return open == 0;
        int &ret = dp[index][open];
        if(ret != -1) return ret;
        if(s[index] == '(') ret = f(s, index + 1, open + 1);
        else if(s[index] == ')') ret = (open && f(s, index + 1, open - 1));
        else
            ret = f(s, index + 1, open + 1) || (open && f(s, index + 1, open - 1)) || f(s, index + 1, open);
        return ret;
    }
    bool checkValidString(string s) {
        memset(dp, -1, sizeof(dp));
        return f(s, 0, 0);
    }
};