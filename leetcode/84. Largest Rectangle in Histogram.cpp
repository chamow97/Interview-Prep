class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int maxArea = 0;
        int n = heights.size();
        for(int i = 0; i < n; i++) {
            while(!s.empty() && heights[s.top()] >= heights[i]) {
                int currH = heights[s.top()];
                s.pop();
                int nextIndex = s.empty() ? -1 : s.top();
                maxArea = max(maxArea, currH * (i - nextIndex - 1));
            }
            s.push(i);
        }
        while(!s.empty()) {
            int currH = heights[s.top()];
            s.pop();
            int nextIndex = s.empty() ? -1 : s.top();
            maxArea = max(maxArea, currH * (n - nextIndex - 1));
        }
        return maxArea;
    }
};
