class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversed_half = 0;
        while (x > reversed_half) {
            // Extract the last digit and build the reversed number
            reversed_half = reversed_half * 10 + x % 10;
            x /= 10;
        }

        // Compare the two halves (discard the middle digit for odd-length numbers)
        return x == reversed_half || x == reversed_half / 10;
    }
};