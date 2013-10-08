/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-08
 * Email		: luoshikai@gmail.com
 *************************************/
 
/**************************************
 * Write a function to find the longest common prefix string amongst an array 
 * of strings.
 *************************************/
 
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) 
    {
        string res;
        if (strs.size() == 0) return res;
        int index = 0, minLength = INT_MAX;
        for (int i = 0; i < strs.size(); ++i)
        {
            minLength = minLength < strs[i].length() ? minLength : strs[i].length();
        }
        
        while (index < minLength)
        {
            char c = strs[0][index];
            for (int i = 1; i < strs.size(); ++i)
            {
                if (strs[i][index] != c)
                {
                    return res;
                }
            }
            ++index;
            res += c;
        }
        return res;
    }
};