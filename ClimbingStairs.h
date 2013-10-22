/**************************************
 * Author 	: luoshikai
 * Version 	: 1.0
 * Date 	: 2013-10-22
 * Email	: luoshikai@gmail.com
 *************************************/
 
/**************************************
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can 
 * you climb to the top?
 *************************************/
 
 
class Solution {
public:
    int climbStairs(int n) 
    {
        int first = 2, last = 1;
        while (--n)
        {
            first = first + last;
            last = first - last;
        }
        return last;
    }
};