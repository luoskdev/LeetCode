/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-06
 * Email		: luoshikai@gmail.com
 *************************************/

/**************************************
 * Given a string S, find the longest palindromic substring in S. You may 
 * assume that the maximum length of S is 1000, and there exists one unique 
 * longest palindromic substring.
 *************************************/

class Solution 
{
public:
    string longestPalindrome(string s) 
	{
		int start = 0, end = 0, cur_len = 0, longest = 0, lStart = 0, lEnd = 0;

		for (int i = 0; i < s.length(); ++i)
		{
			if (start > 0 && s[start-1] == s[i])
			{
				start--;
				cur_len += 2;
			}
			else if (isPalindrome(s, start, i))
			{
				cur_len++;
			}
			else
			{
				while (!isPalindrome(s, start, i))
				{
					start++;
				}
				cur_len = i - start + 1;
			}

			if (longest < cur_len)
			{
				longest = cur_len;
				lStart = start;
				lEnd = i;
			}
		}

		return s.substr(lStart, longest);
    }

	bool isPalindrome(string s, int start, int end)
	{
		for (;start < end; ++start, --end)
		{
			if (s[start] != s[end])
			{
				return false;
			}	
		}
		return true;
	}
};