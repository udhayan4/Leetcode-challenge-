class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long shifts = 0;
        while (k != 1) {
            int i = 63 - __builtin_clzll(k);
            if ((1LL << i) == k) i--;
            k -= (1LL << i);
            if (operations[i]) shifts++;
        }
        return char((shifts % 26) + 97);
    }
};