class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        if(digits[n] < 9) {
                digits[n] = digits[n] + 1;
                return digits;
        }

        vector<int> result;
         int carry = 1;
        
        for(int i = n; i >= 0; i--) {
            int sum = digits[i] + carry;
            if(sum == 10) {
                result.insert(result.begin(), 0);
                carry = 1;
            } else {
                result.insert(result.begin(), sum);
                carry = 0;
            }
        }
        
        if(carry == 1) {
            result.insert(result.begin(), 1);
        }
        
        // int i = 0;
        // while(i <= n) {
        //     if(digits[i] == 9) {
        //         result[i - 1] = result[i] + 1;
        //         result.push_back(0);
        //         i = i - 1;
        //     }else {
        //         result.push_back(digits[i]);
        //     }
        // }
        return result;
    }
};