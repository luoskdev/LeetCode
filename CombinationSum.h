/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-19
 * Email		: luoshikai@gmail.com
 *************************************/

/**************************************
 * Given a set of candidate numbers (C) and a target number (T), find all unique 
 * combinations in C where the candidate numbers sums to T.
 *
 * The same repeated number may be chosen from C unlimited number of times.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending order. 
 * (ie, a1 ≤ a2 ≤ … ≤ ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 2,3,6,7 and target 7,
 * A solution set is:
 * [7]
 * [2, 2, 3]
 *************************************/


class Solution
{
public:
    vector<vector<int> > res;
    vector<vector<int> > combinationSum(vector<int> &candidates, int target)
    {
        res.clear();
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        combinationSumRe(candidates, temp, 0, target);
        return res;
    }
    
    void combinationSumRe(vector<int> &candidates, vector<int> &temp, int pos, int target)
    {
        if (target == 0)
        {
            res.push_back(temp);
        }
        else
        {
            for (int i = pos; i < candidates.size(); ++i)
            {
                if (candidates[i] <= target)
                {
                    temp.push_back(candidates[i]);
                    combinationSumRe(candidates, temp, i, target - candidates[i]);
                    temp.pop_back();
                }
            }
        }
    }
};