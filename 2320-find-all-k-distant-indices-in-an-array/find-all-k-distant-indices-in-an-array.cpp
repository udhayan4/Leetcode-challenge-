class Solution 
{
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) 
    {
        // Step 1: Store indices where nums[i] == key
        vector<int> keyIndices;  

        // Step 1: Traverse the array to collect key positions
        for (int i = 0; i < nums.size(); ++i) 
        {
            if (nums[i] == key) 
            {
                keyIndices.push_back(i);  // Save index where key is found
            }
        }

        // Step 2: Will store final answer
        vector<int> result;  

        // Step 2: For every index in the array
        for (int i = 0; i < nums.size(); ++i) 
        {
            // Step 2: Check against all key positions
            for (int j : keyIndices) 
            {
                if (abs(i - j) <= k) 
                {
                    result.push_back(i);  // Valid i found, add to result
                    break;  // Stop checking further once one match is found
                }
            }
        }

        // Step 3: Return all valid indices
        return result;
    }
};