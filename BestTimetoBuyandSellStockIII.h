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
 * Design an algorithm to find the maximum profit. You may complete at most two
 * transactions.
 *
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must 
 * sell the stock before you buy again).
 *************************************/
 
 

class Solution {
public:
    int maxProfit(vector<int> &prices) 
    {
        int res = 0;
        
        int *ltor = (int *)malloc(sizeof(int) * prices.size());
        int *rtol = (int *)malloc(sizeof(int) * prices.size());
        ltor[0] = 0;
        rtol[prices.size()-1] = 0;

        for (int i = 1, imin = 0, temp = 0; i < prices.size(); ++i)
        {
            if (prices[i] < prices[imin]) imin = i;
            temp = max(temp, prices[i] - prices[imin]);
            ltor[i] = temp;
        }
        
        for (int i = prices.size()-2, imax = prices.size()-1, temp = 0; i >= 0; --i)
        {
            if (prices[i] > prices[imax]) imax = i;
            temp = max(temp, prices[imax] - prices[i]);
            rtol[i] = temp;
        }
        
        for (int i = 0; i < prices.size(); ++i)
        {
            res = max(res, ltor[i] + rtol[i]);
        }
        
        return res;
    }
};