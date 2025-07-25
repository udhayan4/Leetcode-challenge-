class Solution 
{
public:
    int maxSum(std::vector<int>& nums) 
    {
        // Step 1 : Initialization of Sum
        int totalSum = 0;

        // Step 2 : Initialization of Maximum Tracker
        int maxElement = INT_MIN;

        // Step 3 : Initialization of Uniqueness Set
        std::unordered_set<int> used;

        // Step 4 : Iteration and Processing
        for (int num : nums) 
        {
            maxElement = std::max(maxElement, num);
            if (num > 0 && used.insert(num).second) 
            {
                totalSum += num;
            }
        }

        // Step 5 : Final Decision (Edge Case Handling)
        return totalSum > 0 ? totalSum : maxElement;
    }
};