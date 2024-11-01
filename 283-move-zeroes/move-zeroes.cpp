class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int i = 0 , z=1;
        while(z<size){
            if (nums[i]==0){
                if (nums[z]!=0){
                    swap(nums[i],nums[z]);
                    i++;
                    z++;

                }else z++;
            } else{
                i++, z++;
            }

                
            }
        }

    
};