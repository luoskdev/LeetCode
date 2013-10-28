/**************************************
 * Author	: luoshikai
 * Version	: 1.0
 * Date		: 2013-10-28
 * Email	: luoshikai@gmail.com
 * Source	: http://oj.leetcode.com/problems/multiply-strings/
 *************************************/
 

/**************************************
 * Given two numbers represented as strings, return multiplication of the 
 * numbers as a string.
 *
 * Note: The numbers can be arbitrarily large and are non-negative.
 *************************************/
 

class Solution {
public:
    string multiply(string num1, string num2) 
    {
        if (num1.length() == 0 || num2.length() == 0) return num1;
        string res(num1.length() + num2.length(), '0');
        
        for (int i = num1.length() - 1; i >= 0; --i)
        {
            int carry = 0;
            for (int j = num2.length() - 1; j >= 0; --j)
            {
                int sum = (num1[i] - '0') * (num2[j] - '0') + carry + (res[i + j + 1] - '0');
                carry = sum / 10;
                res[i + j + 1] = sum % 10 + '0';
            }
            res[i] += carry;
        }
        
        while (res.length() > 1 && res[0] == '0') res.erase(res.begin());
        return res;
    }
};