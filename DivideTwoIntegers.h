/**************************************
 * Author		: luoshikai
 * Version		: 1.0
 * Date			: 2013-10-11
 * Email		: luoshikai@gmail.com
 *************************************/
 
/**************************************
 * Divide two integers without using multiplication, division and mod operator.
 *************************************/
 

class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        int sign = 1;
        if (dividend < 0) sign *= -1;
        if (divisor < 0) sign *= -1;

        unsigned a = abs(dividend);
        unsigned b = abs(divisor);
        
        return exp(log(abs(a)) - log(abs(b))) * sign;
    }
};