class Solution {
public:
    // To get the index of the next element of the sequence
    unordered_map<int, int> indexMap;
    unordered_map<int, unordered_map<int, int>> dp; 
    int n;

    int fib(vector<int>& arr, int first, int second) {
        int next_element = first + second;
        
        // If next_element is not present in the array, return base length of 2
        if (indexMap.find(next_element) == indexMap.end())
        {
            return 2; 
        }
        // Fetching the index of the next_element
        int next_index = indexMap[next_element];

        // Cache check
        if (dp[first][second]) 
        {
            return dp[first][second];
        }

        dp[first][second] = 1 + fib(arr, second, arr[next_index]);
        
        return dp[first][second];
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        n = arr.size();
        
        // Storing the index of each element
        for (int i = 0; i < n; i++) 
        {
            indexMap[arr[i]] = i;
        }

        int ans = 0;

        // Try all pairs {i, j} as the start of a Fibonacci-like sequence
        for (int i = 0; i < n; i++) 
        {
            for (int j = i + 1; j < n; j++) 
            {
                ans = max(ans, fib(arr, arr[i], arr[j]));
            }
        }

        return (ans > 2) ? ans : 0; 
    }
};