/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-23
 * Email		: luoshikai@gmail.com
 *************************************/
 

/**************************************
 * Given two words word1 and word2, find the minimum number of steps required 
 * to convert word1 to word2. (each operation is counted as 1 step.)
 *
 * You have the following 3 operations permitted on a word:
 *
 * a) Insert a character
 * b) Delete a character
 * c) Replace a character
 *************************************/
 
 
class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int N = word1.length(), M = word2.length();
        if (N == 0) return M;
        if (M == 0) return N;
        
        vector<vector<int> > dp(N+1);
        for (int i = 0; i <= N; ++i) dp[i].resize(M+1, 0);
        
        for (int i = 0; i <= N; ++i) dp[i][0] = i;
        for (int j = 0; j <= M; ++j) dp[0][j] = j;
        
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= M; ++j)
            {
                if (word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] =min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            }
        }
        
        return dp[N][M];
    }
};