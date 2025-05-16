class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>v;
        if(n < 4) return {};
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-3;i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1;j<n-2;j++){
                if(j > i + 1 && nums[j] == nums[j-1]) continue;
                int low = j+1;
                int end = n-1;
                while(low < end){
                    long long sum = (long long)nums[i]+nums[j]+nums[low]+nums[end];
                    if(sum == target){
                        v.push_back({nums[i], nums[j], nums[low], nums[end]});
                        while(low < end && nums[low] == nums[low+1]) low++;
                        while(low < end && nums[end] == nums[end-1]) end--;
                        low++;
                        end--;
                    }
                    else if(sum > target){
                        end--;
                    }
                    else{
                        low++;
                    }
                }
            }
        }
        return v;
    }
};