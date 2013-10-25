/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-24
 * Email		: luoshikai@gmail.com
 *************************************/

/**************************************
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and 
 * s2.
 *
 * For example,
 * Given:
 * s1 = "aabcc",
 * s2 = "dbbca",
 *
 * When s3 = "aadbbcbcac", return true.
 * When s3 = "aadbbbaccc", return false.
 *************************************/
 
 

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3)
	{
		int M = s1.size(), N = s2.size(); K = s3.size();
		if (M + N != K) return false;
		if (K == 0) return true;
		
		vector<vector<bool> > res(M + 1);
		for (int i = 0; i <= M; ++i) res[i].resize(N + 1)；
		res[0][0] = true;
		
		for (int i = 0; i <= M; ++i) res[i][0] = s1[i-1] == s3[i-1];
		for (int j = 0; j <= N; ++j) res[0][j] = s2[j-1] == s3[j-1];
		
		for (int i = 1; i <= M; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				res[i][j] = res[i-1][j] && s1[i-1] == s3[i+j-1]
					|| res[i][j-1] && s2[j-1] == s3[i+j-1];
			}
		}
		
		return res[M][N];
	}

    bool isInterleave1(string s1, string s2, string s3) 
    {
        return isInterleaveRe(s1.c_str(), s2.c_str(), s3.c_str());
    }
    
    bool isInterleaveRe(const char *s1, const char *s2, const char *s3)  // Time Limit Exceeded
    {
        if (*s1 == '\0' && *s2 == '\0' && *s3 == '\0') return true;
        if (*s3 == '\0') return false;
        if (*s1 == '\0') return strcmp(s2, s3) == 0;
        if (*s2 == '\0') return strcmp(s1, s3) == 0;
        
        return *s1 == *s3 && isInterleaveRe(s1+1, s2, s3+1)
            || *s2 == *s3 && isInterleaveRe(s1, s2+1, s3+1);
    }
};