/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-10
 * Email		: luoshikai@gmail.com
 *************************************/
 
/**************************************
 * Given n pairs of parentheses, write a function to generate all combinations 
 * of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 * 
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 *************************************/
 

class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) 
    {
        res.clear();
        generateParenthesisRe(n, n, "");
        return res;
    }
    
    void generateParenthesisRe(int left, int right, string str)
    {
        if (left == 0 && right == 0) res.push_back(str);
        if (left > 0) generateParenthesisRe(left-1, right, str+"(");
        if (right > left) generateParenthesisRe(left, right-1, str+")");
    }
};