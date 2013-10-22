/**************************************
 * Author 	: luoshikai
 * Version 	: 1.0
 * Date 	: 2013-10-22
 * Email	: luoshikai@gmail.com
 *************************************/
 
/**************************************
 * Given two integers n and k, return all possible combinations of k numbers 
 * out of 1 ... n.
 *
 * For example,
 * If n = 4 and k = 2, a solution is:
 *
 * [
 *   [2,4],
 *   [3,4],
 *   [2,3], 
 *   [1,2],
 *   [1,3],
 *   [1,4],
 * ]
 *************************************/
 
 
class Solution {
public:
    vector<vector<int> > res;
    vector<vector<int> > combine(int n, int k) 
    {
        res.clear();
        vector<int> com;
        combineRe(n, k, com, -1, 0);
        return res;
    }
    
    void combineRe(int n, int k, vector<int> & com, int last, int deep)
    {
        if (k == 0)
        {
            res.push_back(com);
            return;
        }
        
        for (int i = last+1; i < n; ++i)
        {
            com.push_back(i+1);
            combineRe(n, k-1, com, i, deep+1);
            com.pop_back();
        }
    }
};