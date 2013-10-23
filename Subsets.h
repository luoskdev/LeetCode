/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-23
 * Email		: luoshikai@gmail.com
 *************************************/

/**************************************
 * Given a set of distinct integers, S, return all possible subsets.
 *
 * Note:
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 * For example,
 * If S = [1,2,3], a solution is:
 *
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 *************************************/
 
 
class Solution {
public:
    vector<vector<int> > res;
    vector<vector<int> > subsets(vector<int> &S) 
    {
        if (S.size() == 0) return res;
        sort(S.begin(), S.end());
        
        res.clear();
        for (int i = 0; i <= S.size(); ++i)
        {
            vector<int> subset;
            subsetsRe(S, S.size(), i, subset, -1);
        }
        
        return res;
    }
    
    void subsetsRe(vector<int> &S, int n, int k, vector<int> &subset, int last)
    {
        if (k == 0)
        {
            res.push_back(subset);
            return;
        }
        for (int i = last+1; i < n; ++i)
        {
            subset.push_back(S[i]);
            subsetsRe(S, n, k-1, subset, i);
            subset.pop_back();
        }
    }
};