/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-13
 * Email		: luoshikai@gmail.com
 *************************************/
 
/**************************************
 * Given a collection of numbers, return all possible permutations.
 *
 * For example,
 * [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 *************************************/
 
class Solution {
public:
    vector<vector<int> > res;
    vector<vector<int> > permute(vector<int> &num) 
    {
        res.clear();
        permuteRe(num, 0, num.size());
        return res;
    }
    
    void permuteRe(vector<int> &num, int k, int n)
    {
        if (k == n)
        {
            res.push_back(num);
            return;
        }
        
        for (int i = k; i < n; ++i)
        {
            swap(num[i], num[k]);
            permuteRe(num, k+1, n);
            swap(num[i], num[k]);
        }
    }
};