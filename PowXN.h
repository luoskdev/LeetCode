/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-21
 * Email		: luoshikai@gmail.com
 *************************************/

/**************************************
 * Implement pow(x, n).
 *************************************/
 
 
 
class Solution {
public:
    double pow(double x, int n) 
    {
        double res = 0;
        int sign = n < 0 ? -1 : 1;
        n = abs(n);
        if (n == 0)
        {
            return 1;
        }
        
        if (n & 1)
        {
            res = pow(x, n / 2);
            res *= res;
            res *= x;
        }
        else
        {
            res = pow(x, n/ 2);
            res *= res;
        }
        
        if (sign == -1)
        {
            return 1 / res;
        }
        return res;
    }
};