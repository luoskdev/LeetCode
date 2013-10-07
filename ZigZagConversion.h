/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-07
 * Email		: luoshikai@gmail.com
 *************************************/
 
/**************************************
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a 
 * number of rows:

 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 *************************************/

 
class Solution 
{
public:
    string convert(string s, int nRows) 
    {
		vector<string> str(nRows);
		string result;
		int direction = 1;
		if (nRows == 1)
		{
			return s;
		}

		for (int i = 0, j = 0; j < s.length();i += direction, ++j)
		{
			if (i < 0)
			{
				i = 1;
				direction = 1;
			}
			
			if (i == nRows)
			{
				i = nRows - 2;
				direction = -1;
			}
			str[i].push_back(s[j]);
		}

		for (int i = 0; i < nRows; ++i)
		{
			result += str[i];
		}

		return result;
    }
};

