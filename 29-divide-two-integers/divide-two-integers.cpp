class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case (INT_MIN divided by -1)
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        int result;
        result = dividend / divisor;

        return result;
    }
};