/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-17
 * Email		: luoshikai@gmail.com
 *************************************/

/**************************************
 * Given an unsorted integer array, find the first missing positive integer.
 *
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 *
 * Your algorithm should run in O(n) time and uses constant space.
 *************************************/
 

 
class Solution {
public:
    int firstMissingPositive(int A[], int n) 
    {
        int i = 0;
        while (i < n)
            if (A[i] != i+1 && A[i] <= n && A[i] > 0 && A[A[i]-1] != A[i]) swap(A[i], A[A[i]-1]);
            else ++i;

        for (int i = 0; i < n; ++i) if (A[i] != (i+1)) return i+1;
        return n+1;
    }
};