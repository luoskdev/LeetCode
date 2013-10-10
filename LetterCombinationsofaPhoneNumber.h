/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-10
 * Email		: luoshikai@gmail.com
 *************************************/

 
/**************************************
 * A mapping of digit to letters (just like on the telephone buttons) is given 
 * below.
 *
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * Note:
 * Although the above answer is in lexicographical order, your answer could be 
 * in any order you want.
 *************************************/


class Solution 
{
public:
    vector<string> letterCombinations(string digits) 
    {
    	string keyboard[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		vector<string> res;
        
		if (digits.length() == 0)
		{
			res.push_back(digits);
			return res;
		}

        res.resize(keyboard[digits[0]-'0'].length());
        for (int j = 0; j < res.size(); ++j)
        {
            res[j].push_back(keyboard[digits[0]-'0'][j]);
        }
        
		for (int i = 1; i < digits.length(); ++i)
		{
			string keys = keyboard[digits[i]-'0'];
			int size = res.size();
			for (int j = 0; j < size; ++j)
			{
				for(int k = 1; k < keys.length(); ++k)
				{
					string temp = res[j] + keys[k];
					res.push_back(temp);
				}
				res[j].push_back(keys[0]);
			}
		}

		return res;
    }
};