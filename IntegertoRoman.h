/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-07
 * Email		: luoshikai@gmail.com
 *************************************/

/**************************************
 * Given an integer, convert it to a roman numeral.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 *************************************/
 
class Solution 
{
public:
    string intToRoman(int num) 
	{
		string ge[] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
		string shi[] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
		string bai[] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
		string qian[] = {"M", "MM", "MMM"};

		string res;
		int digit = 0;

		if (num >= 1000)
		{
			digit = num / 1000;
			res += qian[digit-1];
			num %= 1000;
		}
		
		if (num >= 100)
		{
			digit = num / 100;
			res += bai[digit-1];
			num %= 100;
		}

		if (num >= 10)
		{
			digit = num / 10;
			res += shi[digit-1];
			num %= 10;
		}

		if (num != 0)
		{
			res += ge[num-1];
		}
		
		return res;
    }
};