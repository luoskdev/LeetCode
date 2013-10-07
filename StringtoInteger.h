/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-07
 * Email		: luoshikai@gmail.com
 *************************************/
 
/**************************************
 * Implement atoi to convert a string to an integer.
 *
 * Hint: Carefully consider all possible input cases. If you want a challenge, 
 * please do not see below and ask yourself what are the possible input cases.
 *
 * Notes: It is intended for this problem to be specified vaguely (ie, no given
 * input specs). You are responsible to gather all the input requirements up 
 * front.
 * 
 * spoilers alert... click to show requirements for atoi.
 *
 * Requirements for atoi:
 * The function first discards as many whitespace characters as necessary until
 * the first non-whitespace character is found. Then, starting from this 
 * character, takes an optional initial plus or minus sign followed by as many 
 * numerical digits as possible, and interprets them as a numerical value.
 *
 * The string can contain additional characters after those that form the 
 * integral number, which are ignored and have no effect on the behavior of 
 * this function.
 * 
 *
 * If the first sequence of non-whitespace characters in str is not a valid 
 * integral number, or if no such sequence exists because either str is empty 
 * or it contains only whitespace characters, no conversion is performed.
 *
 * If no valid conversion could be performed, a zero value is returned. If the
 * correct value is out of the range of representable values, INT_MAX 
 * (2147483647) or INT_MIN (-2147483648) is returned.
 *************************************/
 
class Solution 
{
public:
    int atoi(const char *str) 
    {
		int pos = 0, sign = 1;
		double result = 0;
		if (str == NULL)
		{
			return 0;
		}
		while (str[pos] == ' ' || str[pos] == '"')
		{
			++pos;
		}

		if (str[pos] == '-')
		{
			sign = -1;
			++pos;
		}
		if (str[pos] == '+')
		{
			++pos;
		}

		while (str[pos] >= '0' && str[pos] <= '9')
		{
			if (result > INT_MAX)
			{
				break;
			}
			result = result * 10 + str[pos++] - '0';
		}

		if (result > INT_MAX)
		{
			return (sign == -1) ? INT_MIN : INT_MAX;
		}

		return result * sign;
    }
};