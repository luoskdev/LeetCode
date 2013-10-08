/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-08
 * Email		: luoshikai@gmail.com
 *************************************/

/**************************************
 * Given an array S of n integers, find three integers in S such that the sum 
 * is closest to a given number, target. Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
 *
 *
 *  For example, given array S = {-1 2 1 -4}, and target = 1.
 *
 *  The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *************************************/
 
class Solution 
{
public:
    int threeSumClosest(vector<int> &num, int target) 
	{
		int closest = INT_MAX, temp = 0;
		sort(num.begin(), num.end());

		for (int i = 0; i < num.size(); ++i)
		{
			int l = i+1, r = num.size()-1;
			int twosum = target - num[i];

			while (l < r)
			{				
				while (num[l+1] + num[r] <= twosum && l < r-1) ++l;
				while (num[l] + num[r-1] >= twosum && l < r-1) --r;
				
				closest = getClose(closest, num[l]+num[r]-twosum);

				if (num[l]+num[r] < twosum) ++l;
				else if (num[l] + num[r] > twosum) --r;
				else return target;

				while (l < r && num[l] == num[l+1]) ++l;
				while (l < r && num[r] == num[r-1]) --r;
			}

			while (i < num.size()-1 && num[i] == num[i+1]) ++i;
		}

		return target+closest;
    }

	int getClose(int min_close, int cur_close)
	{
		return (abs(min_close) < abs(cur_close)) ? min_close : cur_close;
	}
};