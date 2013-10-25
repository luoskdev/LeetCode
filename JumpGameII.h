/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-23
 * Email		: luoshikai@gmail.com
 *************************************/
 

/**************************************
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 *
 * Each element in the array represents your maximum jump length at that 
 * position.
 *
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 * For example:
 * Given array A = [2,3,1,1,4]
 *
 * The minimum number of jumps to reach the last index is 2. (Jump 1 step from 
 * index 0 to 1, then 3 steps to the last index.)
 *************************************/
 
 
class Solution {
public:
    int jump(int A[], int n) 
    {
        int start = 0, res = 0;
        while (start < n - 1)
        {
            ++res;
            if (start + A[start] >= n - 1) return res;
            int mx = start;
            for (int i = start + 1; i <= start + A[start]; ++i)
            {
                if (i + A[i] >= mx + A[mx])
                {
                    mx = i;
                }
            }
            start = mx;
        }
    }
};