class Solution 
{
public:
    char kthCharacter(int k) 
    {
        // Step 1: Find the minimum level such that 2^level >= k
        int level = 0;
        while ((1 << level) < k) 
        {
            level++;
        }

        // Step 2: Start recursive helper to find k-th character at that level
        return helper(k, level);
    }

private:
    char helper(int k, int level) 
    {
        // Step 3: Base case — level 0 is just 'a'
        if (level == 0)
        {
            return 'a';
        } 

        // Step 4: Calculate first half size
        int half = 1 << (level - 1); 

        if (k <= half) 
        {
            // Step 5: k is in the first half — same as previous level
            return helper(k, level - 1);
        } 
        else 
        {
            // Step 6: k is in second half — map to first half and shift result
            char ch = helper(k - half, level - 1);
        
            // Step 7: Shift character
            return ((ch - 'a' + 1) % 26) + 'a'; 
        }
    }
};