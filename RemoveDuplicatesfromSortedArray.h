/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-11
 * Email		: luoshikai@gmail.com
 *************************************/
 
/**************************************
 * Given a sorted array, remove the duplicates in place such that each element 
 * appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place 
 * ith constant memory.
 *
 * For example,
 * Given input array A = [1,1,2],
 *
 * Your function should return length = 2, and A is now [1,2].
 *************************************/
 
class Solution {
public:
    int removeDuplicates(int A[], int n) 
    {   
        int front = 0, back = 0;
        if (n <= 1) return n;
        
        while (front < n)
        {
            A[back++] = A[front]; 
            while (A[back-1] == A[front]) ++front;
        }
        
        return back;
    }
};