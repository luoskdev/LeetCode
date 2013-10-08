/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-08
 * Email		: luoshikai@gmail.com
 *************************************/

/**************************************
 * Given an array S of n integers, are there elements a, b, c, and d in S such 
 * that a + b + c + d = target? Find all unique quadruplets in the array which
 * gives the sum of target.
 *
 * Note:
 * Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
 * The solution set must not contain duplicate quadruplets.
 *    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 *
 *    A solution set is:
 *    (-1,  0, 0, 1)
 *    (-2, -1, 1, 2)
 *    (-2,  0, 0, 2)
 *************************************/
 
class Solution 
{
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) 
	{
		vector<vector<int> > res;
		if (num.size() < 4)
		{
			return res;
		}
		sort(num.begin(), num.end());

		for (int a = 0; a < num.size(); ++a)
		{
			int threesum = target - num[a];
			for (int i = a+1; i < num.size(); ++i)
			{
				int twosum = threesum - num[i];
				int l = i+1, r = num.size()-1;

				while (l < r)
				{
					if (num[l]+num[r] < twosum) ++l;
					else if (num[l] + num[r] > twosum) --r;
					else 
					{
						addResult(res, num[a], num[i], num[l], num[r]);
						while (l < r && num[l] == num[l+1]) ++l;
						while (l < r && num[r] == num[r-1]) --r;
						++l; --r;
					}
				}
				while(i < num.size()-1 && num[i] == num[i+1]) ++i;
			}
			while (a < num.size()-1 && num[a] == num[a+1]) ++a;
		}

		return res;
	}

	void addResult(vector<vector<int> > &res, int a, int b, int c, int d)
	{
		vector<int> temp;
		temp.push_back(a);
		temp.push_back(b);
		temp.push_back(c);
		temp.push_back(d);

		res.push_back(temp);
	}
};