/**************************************
 * Author 	: luoshikai
 * Version 	: 1.0
 * Date 	: 2013-10-30
 * Email	: luoshikai@gmail.com
 *************************************/
 
/**************************************
 * Given two binary strings, return their sum (also a binary string).
 * 
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 *************************************/
 
 
class Solution {
public:
    string addBinary(string a, string b) 
    {
        string res;
        int sum = 0, carry = 0;
        int i = a.length() - 1, j = b.length() - 1;
        while (i >= 0 || j >= 0)
        {
            sum = 0;
            
            if (i >= 0) sum += (a[i--] - '0');
            if (j >= 0) sum += (b[j--] - '0');
            
            res.push_back(((sum + carry) % 2) + '0');
            carry = (sum + carry) / 2;
        }
        if (carry) res += (carry + '0');
        reverse(res.begin(), res.end());
        
        return res;
    }
};