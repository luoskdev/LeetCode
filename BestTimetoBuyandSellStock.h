/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-31
 * Email		: luoshikai@gmail.com
 *************************************/

/**************************************
 * Say you have an array for which the ith element is the price of a given 
 * stock on day i.
 *
 * If you were only permitted to complete at most one transaction (ie, buy one
 * and sell one share of the stock), design an algorithm to find the maximum 
 * profit.
 *************************************/
 
 
 
class Solution {
public:
    int maxProfit(vector<int> &prices) 
    {
        int imin = 0, res = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] < prices[imin]) imin = i;
            res = max(res, prices[i] - prices[imin]);
        }
        return res;
    }
};