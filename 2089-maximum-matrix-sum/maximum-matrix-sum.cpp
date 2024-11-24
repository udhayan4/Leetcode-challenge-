class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        int nc = 0;
        int m = INT_MAX;
        long long sum = 0;
        for(auto a: matrix){
            for(auto b: a){
                if(b < 0){
                    nc++;
                }
                m = min(m, abs(b));
                sum += abs(b);
            }
        }
        if(m == 0) return sum;
        if(nc & 1){
            sum -= (2*m);
        }
        return sum;
    }
};