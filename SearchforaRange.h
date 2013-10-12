/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-12
 * Email		: luoshikai@gmail.com
 *************************************/
 
/**************************************
 * Given a sorted array of integers, find the starting and ending position of a
 * given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 *************************************/
 

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) 
    {
        vector<int> res;
        
        res.push_back(findStart(A, n, target));
        res.push_back(findEnd(A, n, target));
        
        return res;
    }
    
    int findStart(int A[], int n, int target)
    {
    	int low = 0, high = n - 1;
    	while (low <= high)
    	{
    		int mid = (low + high) / 2;
    		if (A[mid] < target) low = mid + 1;
    		else high = mid - 1;
    	}
    
    	if (A[low] == target) return low;
    	else return -1;
    }
    
    int findEnd(int A[], int n, int target)
    {
    	int low = 0, high = n - 1;
    	while (low <= high)
    	{
    		int mid = (low + high) / 2;
    		if (A[mid] <= target) low = mid + 1;
    		else high = mid - 1;
    	}
    	if (A[high] == target) return high;
    	return -1;
    }
};