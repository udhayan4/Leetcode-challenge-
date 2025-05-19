class Solution {
public:

    void generate(vector<string> &ans, string s, int n, int l, int r){
        // Base case: all left and right brackets are used
        if (l == n && r == n) {
            ans.push_back(s);
            return;
        }
        // Option to add '(' if we haven't used all
        if (l < n) {
            generate(ans, s + '(', n, l + 1, r);
        }
        // Option to add ')' only if it won’t break balance
        if (l > r && r < n) {
            generate(ans, s + ')', n, l, r + 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "(";
        generate(ans, s, n, 1, 0); // We start with 1 '(' already placed
        return ans;
    }
};