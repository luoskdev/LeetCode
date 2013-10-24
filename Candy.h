/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-23
 * Email		: luoshikai@gmail.com
 *************************************/
 

/**************************************
 * There are N children standing in a line. Each child is assigned a rating 
 * value.
 *
 * You are giving candies to these children subjected to the following 
 * requirements:
 * 
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * What is the minimum candies you must give?
 *************************************/
 
 

class Solution {
public:
    int candy(vector<int> &ratings) 
    {
        vector<int> candy(ratings.size(), 1);
        int res = 0;
        for (int i = 1; i < candy.size(); ++i)
        {
            if (ratings[i] > ratings[i-1]) candy[i] = max(candy[i], candy[i-1]+1);
        }
        
        for (int i = candy.size() - 1; i > 0; --i)
        {
            if (ratings[i] < ratings[i-1]) candy[i-1] = max(candy[i-1], candy[i]+1);
        }
        
        for (int i = 0; i < candy.size(); ++i)
        {
            res += candy[i];
        }
        
        return res;
    }
};