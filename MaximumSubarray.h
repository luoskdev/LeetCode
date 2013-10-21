/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-21
 * Email		: luoshikai@gmail.com
 *************************************/

/**************************************
 * Find the contiguous subarray within an array (containing at least one 
 * number) which has the largest sum.
 *
 * For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 * the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 *
 * click to show more practice.
 *
 * More practice:
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 *************************************/
 
 
 
class Solution {
public:
    int maxSubArray(int A[], int n) 
    {
        int res = INT_MIN, temp = A[0];
        
        for (int i = 0; i < n; ++i)
        {
            if (i == 0) temp = A[i];
            else if (temp < 0) temp = A[i];
            else temp += A[i];
            
            res = max(res, temp);
        }
        
        return res;
    }
};