/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-10
 * Email		: luoshikai@gmail.com
 *************************************/

/**************************************
 * Given a string containing just the characters '(', ')', '{', '}', '[' and 
 * ']', determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are all 
 * valid but "(]" and "([)]" are not.
 *************************************/

class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st;
        for (int i = 0; i < s.length(); ++i)
        {
            switch(s[i])
            {
                case '(':
                case '[':
                case '{':
                    st.push(s[i]);
                    break;
                case ')':
                case ']':
                case '}':
                    if (st.empty() || abs(st.top() - s[i]) > 2)
                        return false;
                    st.pop();
                    break;
                default:
                    break;
            }
        }
        return st.empty();
    }
};