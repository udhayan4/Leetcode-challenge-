class Solution {
public:
    string countAndSay(int n) {
        if (n > 1) {
            string tempStr = countAndSay(n - 1);
            string result = "";
            char tempDigit;
            int tempDigitCnt = 0;

            for (int i = 0; i < tempStr.size(); i++) {
                if (i == 0) {
                    tempDigit = tempStr[i];
                } else if (tempDigit != tempStr[i]) {
                    result += to_string(tempDigitCnt) + tempDigit;
                    tempDigit = tempStr[i];
                    tempDigitCnt = 0;
                }
                tempDigitCnt++;
            }

            result += to_string(tempDigitCnt) + tempDigit;
            return result;
        }
        return "1";
    }
};