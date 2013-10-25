/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-24
 * Email		: luoshikai@gmail.com
 *************************************/
 
 
/**************************************
 * Implement wildcard pattern matching with support for '?' and '*'.
 *
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 *
 * The matching should cover the entire input string (not partial).
 *
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 *
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "*") → true
 * isMatch("aa", "a*") → true
 * isMatch("ab", "?*") → true
 * isMatch("aab", "c*a*b") → false
 *************************************/
 
 
class Solution {
public:
	bool isMatch(const char *s, const char *p)
	{
		const char *ss = NULL, *pp = NULL;
		while (*s)
		{
			if (*p == *s || *p == '?')
			{
				++p;
				++s;
			}
			else if (*p == '*')
			{
				while (*p == '*') ++p;				// remove duplicate '*'
				if (*p == '\0) return true;			// if ends with '*' then match
				ss = s;								// recorde the position
				pp = p;
			}
			else if ((*p == '\0' || *s != *p) && ss)
			{
				s = ++ss;
				p = pp;
			}
			else
			{
				return false;
			}
		}
		
		while (*p == '*') ++p;
		
		return *p == '\0' && *s == '\0';
	}
	
    bool isMatch1(const char *s, const char *p)  // Time Limit Exceeded
    {
        string s1 = s, s2;
        
        while (*p != '\0')
        {
            s2 += *p++;
            while (s2[s2.size()-1] == '*' && *p == '*')
            {
                ++p;
            }
        }
        
        int N = s1.size(), M = s2.size();
        vector<bool> res(M + 1);
        res[0] = true;

        for (int i = 0; i <= M; ++i) res[i] = s2[0] == '*';
        
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= M; ++j)
            {
                bool match = res[j-1] && s1[i-1] == s2[j-1]
                        || res[j-1] && s2[j-1] == '?'
                        || res[j] && s2[j-1] == '*';
                res[j-1] = match;
            }
        }

        return res[M];
    }
	
	bool isMatch2(const char *s, const char *p)  // Memory Limit Exceeded
    {
        string s1 = s, s2;
        while (*p != '\0')
        {
            s2 += *p++;
            while (s2[s2.size()-1] == '*' && *p == '*')
            {
                ++p;
            }
        }
        int N = s1.size(), M = s2.size();
        vector<vector<bool> > res(N + 1);
        for (int i = 0; i <= N; ++i) res[i].resize(M + 1);
        res[0][0] = true;
        
        for (int i = 0; i <= N; ++i) res[i][0] = false;
        for (int j = 0; j <= M; ++j) res[0][j] = s2[0] == '*';
        
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= M; ++j)
            {
                res[i][j] = res[i-1][j-1] && s1[i-1] == s2[j-1]
                    || res[i-1][j-1] && s2[j-1] == '?'
                    || res[i-1][j] && s2[j-1] == '*';
            }
        }

        return res[N][M];
    }
};