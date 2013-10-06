/**************************************
 * Author 	: luoshikai
 * Version 	: 1.0
 * Date 	: 2013-10-06
 * Email	: luoshikai@gmail.com
 *************************************/
 
/**************************************
 * Given an array S of n integers, are there elements a, b, c in S such that 
 * a + b + c = 0? Find all unique triplets in the array which gives the sum of 
 * zero.
 * 
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 *   For example, given array S = {-1 0 1 2 -1 -4},
 *
 *   A solution set is:
 *   (-1, 0, 1)
 *   (-1, -1, 2)
 *************************************/
 

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num)
    {
		vector<vector<int> > res;
        if (num.size() < 3)
        {
            return res;
        }
		sort(num.begin(), num.end());
		
		for (int i = 0; i < num.size() && num[i] <= 0; ++i)
		{
			int l = i+1, r = num.size()-1;
			int twosum = 0 - num[i];

			while (l < r)
			{
				if (num[l] + num[r] < twosum) ++l;
				else if (num[l] + num[r] > twosum) --r;
				else
				{
					addResult(res, num[i], num[l], num[r]);
					while (l < r && num[l] == num[l+1]) ++l;
					while (l < r && num[r] == num[r-1]) --r;
					++l;--r;
				}
			}
			while (i < num.size() && num[i] == num[i+1]) ++i;
		}

		return res;
    }

	void addResult(vector<vector<int> > &res, int a, int b, int c)
	{
		vector<int> temp;
		temp.push_back(a);
		temp.push_back(b);
		temp.push_back(c);

		res.push_back(temp);
	}
};