/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-11-05
 * Email		: luoshikai@gmail.com
 *************************************/
 
/**************************************
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 *
 * Each element in the array represents your maximum jump length at that 
 * position.
 * 
 * Determine if you are able to reach the last index.
 *
 * For example:
 * A = [2,3,1,1,4], return true.
 *
 * A = [3,2,1,0,4], return false.
 *************************************/
 
 
 
class Solution {
public:
    bool canJump(int A[], int n) 
    {
        if (n <= 1) return true;
        int pos = 0;
        
        while (pos < n-1)
        {
            if (A[pos] == 0)
            {
                int i = 1;
                while (A[pos] < i)
                {
                    --pos;
                    ++i;
                }
                if (pos < 0) return false;
            }
            pos = A[pos] + pos;
        }
        return true;
    }
};