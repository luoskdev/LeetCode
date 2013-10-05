#include <vector>
#include <algorithm>
using namespace std;

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