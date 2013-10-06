/**************************************
 * Author 	: luoshikai
 * Version 	: 1.0
 * Date 	: 2013-10-06
 * Email	: luoshikai@gmail.com
 *************************************/

/**************************************
 * Given a string S, find the longest palindromic substring in S. You may 
 * assume that the maximum length of S is 1000, and there exists one unique 
 * longest palindromic substring.
 *************************************/
 
class Solution
{
public:
    int lengthOfLongestSubstring(string s) 
    {
		int longest = 0;
		string temp;
		for (int i = 0; i < s.length(); ++i)
		{
			string::size_type pos = temp.find(s[i]);
			if (pos == string::npos)
			{
				temp.push_back(s[i]);				
			}
			else
			{
				temp = temp.substr(pos+1);
				temp.push_back(s[i]);
			}
			longest = max(longest, temp.length());
		}

		return longest;
    }
    int max(int a, int b)
	{
		return a > b ? a : b;
	}
};