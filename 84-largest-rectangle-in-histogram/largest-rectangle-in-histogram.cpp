class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>stk;
        int i=0;
        int n=heights.size();
        int maxArea = 0;
        while(i < n)
            {   

    if(stk.empty() or( heights[stk.top()] <= heights[i] ))
            {
                stk.push(i++);
            }
            else
            {
                int minBarIndex = stk.top();
                stk.pop();
                int width = i;
                if(!stk.empty())  width = i - 1 - stk.top();
                int area = heights[minBarIndex] * width;
                maxArea = max(maxArea , area);
            }
        }

        while(!stk.empty())
        {
            int minBarIndex = stk.top();
            stk.pop();
            int width = i;
            if(!stk.empty())  width = i - 1 - stk.top();
            int area = heights[minBarIndex] * width;
            maxArea = max(maxArea , area);
        }
        return maxArea;
    }
};