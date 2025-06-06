class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 1;
        int curr_len = 0;
        unordered_set<int>mpp;
        if(nums.size() == 0) return 0;
        for(int i = 0; i<nums.size(); i++){
            mpp.insert(nums[i]);
        }
        for(int num : mpp){
            if(mpp.find(num - 1) == mpp.end()){
                curr_len = 1;
                int curr_num = num;
                while(mpp.find(curr_num + 1) != mpp.end()){
                    curr_len++;
                    curr_num++;
                }
                ans = max(ans,curr_len);
            }
        }
        return ans;
    }
};