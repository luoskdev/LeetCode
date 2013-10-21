/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-21
 * Email		: luoshikai@gmail.com
 *************************************/

/**************************************
 * You are given an n x n 2D matrix representing an image.
 *
 * Rotate the image by 90 degrees (clockwise).
 *
 * Follow up:
 * Could you do this in-place?
 *************************************/
 

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) 
    {
        int length = matrix.size();
        for (int i = 0; i < length; ++i)
        {
            for (int j = 0, k = length - 1; j < k; ++j, --k)
            {
                swap(matrix[j][i], matrix[k][i]);
            }
        }
        
        for (int i = 0; i < length; ++i)
        {
            for (int j = i+1; j < length; ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
};