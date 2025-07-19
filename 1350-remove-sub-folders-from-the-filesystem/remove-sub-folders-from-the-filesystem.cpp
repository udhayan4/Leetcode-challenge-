class Solution 
{
public:
    vector<string> removeSubfolders(vector<string>& folder) 
    {
        // Step 1: Sort the folders
        sort(folder.begin(), folder.end());

        // Step 2: Create a result list
        vector<string> result;
        string prev = "";

        // Step 3: Loop through each folder in the sorted list
        for (const string& curr : folder) 
        {
            if (prev.empty() || curr.find(prev + "/") != 0) 
            {
                result.push_back(curr);
                prev = curr;
            }
        }

        // Step 4: Return the result
        return result;
    }
};