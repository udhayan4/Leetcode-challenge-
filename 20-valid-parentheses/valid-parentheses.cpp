#include <stack>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> pairs = {{')', '('}, {'}', '{'}, {']', '['}};

        for (char c : s) {
            if (pairs.count(c)) { // Closing bracket
                if (st.empty() || st.top() != pairs[c]) {
                    return false;
                }
                st.pop();
            } else { // Opening bracket
                st.push(c);
            }
        }

        return st.empty();
    }
};