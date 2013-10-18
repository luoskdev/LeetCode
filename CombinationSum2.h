/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-19
 * Email		: luoshikai@gmail.com
 *************************************/

/**************************************
 * Given a collection of candidate numbers (C) and a target number (T), 
 * find all unique combinations in C where the candidate numbers sums to T.
 *
 * Each number in C may only be used once in the combination.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending order. 
 * (ie, a1 ≤ a2 ≤ … ≤ ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 10,1,2,7,6,1,5 and target 8,
 * A solution set is:
 * [1, 7]
 * [1, 2, 5]
 * [2, 6]
 * [1, 1, 6]
 ***********************************/


class Solution {
public:
    vector<vector<int> > res;
    vector<vector<int> > combinationSum2(vector<int> &num, int target)
    {
        res.clear();
        vector<int> temp;
        sort(num.begin(), num.end());
        combinationSum2Re(num, temp, 0, target);
        return res;
    }
    
    void combinationSum2Re(vector<int> &num, vector<int> &temp, int pos, int target)
    {
        if (target == 0)
        {
            res.push_back(temp);
        }
        else
        {
            for (int i = pos; i < num.size(); ++i)
            {
                if (num[i] <= target)
                {
                    temp.push_back(num[i]);
                    combinationSum2Re(num, temp, i + 1, target - num[i]);
                    temp.pop_back();
                    while (num[i] == num[i+1]) ++i;
                }
            }
        }
    }
};