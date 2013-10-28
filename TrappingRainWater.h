/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-28
 * Email		: luoshikai@gmail.com
 * Source		: http://oj.leetcode.com/problems/trapping-rain-water/
 *************************************/
 

/**************************************
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 *
 * For example, 
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
 * In this case, 6 units of rain water (blue section) are being trapped. 
 * Thanks Marcos for contributing this image!
 *************************************/
 
 

class Solution {
public:
    int trap(int A[], int n) 
    {
        int res = 0, lmax = 0, rmax = n - 1, total = 0;
        while (lmax < rmax)
        {
            if (A[lmax] < A[rmax])
            {
                int i = 0;
                for (i = lmax + 1; i < rmax && A[i] <= A[lmax]; ++i)
                {
                    total += A[i];
                }
                res += A[lmax] * (i - lmax - 1);
                lmax = i;
            }
            else
            {
                int i = 0;
                for (i = rmax - 1; i > lmax && A[i] <= A[rmax]; --i)
                {
                    total += A[i];
                }
                res += A[rmax] * (rmax - i - 1);
                rmax = i;
            }
        }
        
        return res - total;
    }
};

