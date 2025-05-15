class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
       vector<string>pattern(min(numRows,int(s.size())));
       int cycle = 2*numRows-2;

       for(int i=0;i<s.size();i++){
        int pos = i % cycle;
        int row = (pos < numRows) ? pos : cycle-pos;
        pattern[row] += s[i];
       } 
       string ans;
       for(string row : pattern) ans += row;
       return ans;
    }
};
