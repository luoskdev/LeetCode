/**************************************
 * Author 	: luoshikai
 * Version 	: 1.0
 * Date 	: 2013-10-22
 * Email	: luoshikai@gmail.com
 *************************************/
 
/**************************************
 * Given an array with n objects colored red, white or blue, sort them so that
 * objects of the same color are adjacent, with the colors in the order red, 
 * white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red, 
 * white, and blue respectively.
 * 
 * Note:
 * You are not suppose to use the library's sort function for this problem.
 *
 * click to show follow up.
 *
 * Follow up:
 * A rather straight forward solution is a two-pass algorithm using counting 
 * sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then 
 * overwrite array with total number of 0's, then 1's and followed by 2's.
 *
 * Could you come up with an one-pass algorithm using only constant space?
 *************************************/
 
 
class Solution {
public:
    void sortColors(int A[], int n) 
    {
        int zeros = 0, ones = 0, twos = 0;
        for (int i = 0; i < n; ++i)
        {
            if (A[i] == 0) zeros++;
            if (A[i] == 1) ones++;
            if (A[i] == 2) twos++;
        }
        
        int i = 0;
        for (int j = 0; j < zeros; ++i, ++j) A[i] = 0;
        for (int j = 0; j < ones; ++i, ++j) A[i] = 1;
        for (int j = 0; j < twos; ++i, ++j) A[i] = 2;
    }
};