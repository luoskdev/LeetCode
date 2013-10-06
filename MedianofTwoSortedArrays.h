/**************************************
 * Author 	: luoshikai
 * Version 	: 1.0
 * Date 	: 2013-10-06
 * Email	: luoshikai@gmail.com
 *************************************/

/**************************************
 * There are two sorted arrays A and B of size m and n respectively. Find the 
 * median of the two sorted arrays. The overall run time complexity should be 
 * O(log (m+n)).
 *************************************/
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) 
    {
        double res = 0;
        int i = 0, j = 0, k = (m + n + 1) / 2;
        int first = 0, second = 0;
        while (k >= 0)
        {
            second = first;
            if (A[i] <= B[j] && i < m) first = A[i++];
            else if (A[i] > B[j] && j < n) first = B[j++];
            else if (i == m) first = B[j++];
            else first = A[i++];
            k--;
        }
        
        if ((m + n) % 2 == 0) res = (first + second) / 2.0;
        else res = second;
        
        return res;
    }
};