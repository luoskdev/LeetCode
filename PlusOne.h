/**************************************
 * Author       : luoshikai
 * Version      : 1.0
 * Date         : 2013-10-22
 * Email        : luoshikai@gmail.com
 *************************************/

/**************************************
 * Given a number represented as an array of digits, plus one to the number.
 *************************************/


class Solution {
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 0, pos = 0;
        reverse(digits.begin(), digits.end());
        if (digits.size() == 0)
        {
            digits.push_back(1);
            return digits;
        }

        do
        {
            digits[pos] += 1;
            carry = digits[pos] / 10;
            digits[pos++] %= 10;
        }while (carry != 0 && pos < digits.size())

        if (carry) digits.push_back(1);

        reverse(digits.begin(), digits.end());
        return digits;
    }
} 
