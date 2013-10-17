/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-17
 * Email		: luoshikai@gmail.com
 *************************************/

/**************************************
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 *
 * Note: The sequence of integers will be represented as a string.
 *************************************/
 
class Solution {
public:
    string countAndSay(int n) 
    {
        string res = "1";
        
        while (--n)
        {
            int start = 0;
            string temp;
            while (start < res.length())
            {
                temp += countAndSayRe(res, start);
            }
            res = temp;
        }
        
        return res;
    }
    
    string countAndSayRe(string &str, int &pos)
    {
        int start = pos, num = str[pos], repeat = 1;
        string res;
        while (start < str.length() && str[start] == str[start+1])
        {
            ++start;
            ++repeat;
        }
        res += (repeat + '0');
        res += num;
        pos += repeat;
        
        return res;
    }
};