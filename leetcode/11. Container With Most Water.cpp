class Solution {
public:
    int maxArea(vector<int>& height) {
        int maximum = 0;
        int n = height.size();
        int ptr1 = 0, ptr2 = n - 1;
        while(ptr1 < ptr2 && ptr1 < n)
        {
            int curr = min(height[ptr1], height[ptr2]) * (ptr2 - ptr1);
            maximum = max(maximum, curr);
            if(height[ptr1] < height[ptr2])
            {
                ptr1++;
            }
            else
            {
                ptr2--;
            }
        }
        return maximum;
    }
};