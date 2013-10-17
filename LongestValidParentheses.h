/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-17
 * Email		: luoshikai@gmail.com
 *************************************/

/**************************************
 * Given a string containing just the characters '(' and ')', find the length 
 * of the longest valid (well-formed) parentheses substring.
 *
 * For "(()", the longest valid parentheses substring is "()", which has 
 * length = 2.
 *
 * Another example is ")()())", where the longest valid parentheses substring 
 * is "()()", which has length = 4.
 *************************************/
 
class Solution {
public:
    int longestValidParentheses(string s) 
    {
        stack<int> stk;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(') stk.push(i);
            else if (!stk.empty())
            {
                s[stk.top()] = '*';
                s[i] = '*';
                stk.pop();
            }
        }
        
        int res = 0, part = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '*') ++part;
            else
            {
                res = max(res, part);
                part = 0;
            }
        }
        res = max(res, part);
        
        return res;
    }
};