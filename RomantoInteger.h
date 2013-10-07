/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-07
 * Email		: luoshikai@gmail.com
 *************************************/
 
/**************************************
 * Given a roman numeral, convert it to an integer.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 *************************************/

 
class Solution 
{
public:
    int romanToInt(string s) 
	{
		map<char, int> roman;
		roman['M'] = 1000;
		roman['D'] = 500;
		roman['C'] = 100;
		roman['L'] = 50;
		roman['X'] = 10;
		roman['V'] = 5;
		roman['I'] = 1;

		int res = 0, i = 0;
		for (i = 0; i < s.length()-1; ++i)
		{
			if (roman[s[i]] < roman[s[i+1]])
				res -= roman[s[i]];
			else
				res += roman[s[i]];
		}
		res += roman[s[i]];

		return res;
    }
};