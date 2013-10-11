/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-11
 * Email		: luoshikai@gmail.com
 *************************************/
 
/**************************************
 * Given an array and a value, remove all instances of that value in place and
 * return the new length.
 *
 * The order of elements can be changed. It doesn't matter what you leave 
 * beyond the new length.
 *************************************/
 
class Solution {
public:
    int removeElement(int A[], int n, int elem) 
    {
        int l = 0, r = 0;
        if (n <= 0) return 0;
        for (l = -1, r = 0; r < n; ++r)
        {
            if (A[r] != elem)
            {
                A[++l] = A[r];
            }
        }
        return l+1;
    }
};