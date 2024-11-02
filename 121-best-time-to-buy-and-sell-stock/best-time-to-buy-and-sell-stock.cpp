class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mins = prices[0];
        int maxs = -1;
        int size = prices.size();
        for (int i =1;i<size;i++){
            maxs = max(maxs,prices[i]-mins);
            mins = min(mins,prices[i]);
        }
        return maxs ==-1? 0:maxs;
    }
};