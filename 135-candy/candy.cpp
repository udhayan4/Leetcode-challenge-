class Solution {
public:
    static int candy(vector<int>& ratings) {
         const int n=ratings.size();
        vector<int> c(n, 1);

        for (int i=1; i<n; i++){
            if (ratings[i]>ratings[i-1]) 
                c[i]=c[i-1]+1;
        }
        int ans=c.back();
        for (int i=n-2; i>=0; i--){
            if (ratings[i]>ratings[i+1]) 
                c[i]=max(c[i], c[i+1]+1);
            ans+=c[i];
        }
        return ans;
    }
};