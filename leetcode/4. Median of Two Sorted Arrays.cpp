class Solution {
public:
    vector<int> num1, num2;
    int s1, s2;
    double ans;bool isEven;
    
    void binarySearch(int low, int high)
    {
        if(high < low)
        {
            return;
        }
        int ptr1 = (low + high) / 2;
        int ptr2 = (s1 + s2 + 1) / 2 - ptr1;
        int minLeftX = (ptr1 == 0) ? INT_MIN : num1[ptr1-1];
        int maxRightX = (ptr1 == s1) ? INT_MAX : num1[ptr1];
        int minLeftY = (ptr2 == 0) ? INT_MIN : num2[ptr2 - 1];
        int maxRightY = (ptr2 == s2) ? INT_MAX : num2[ptr2];
        if(minLeftX <= maxRightY && minLeftY <= maxRightX)
        {
            if(isEven)
            {
                ans = (((max(minLeftX, minLeftY) + min(maxRightY, maxRightX)) * 1.00) / (2 * 1.00));
            }
            else
            {
                ans = double((max(minLeftX, minLeftY)));
            }
            return;
        }
        else if(minLeftX > maxRightY)
        {
            high = ptr1 - 1;
        }
        else
        {
            low = ptr1 + 1;
        }
        binarySearch(low, high);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        isEven = false;
        int n = nums1.size();
        int m = nums2.size();
        if(n > m)
        {
            swap(n, m);
            swap(nums1, nums2);
        }
        num1 = nums1;
        num2 = nums2;
        s1 = n;
        s2 = m;
        if((n + m) % 2 == 0)
        {
            isEven = true;
        }
        binarySearch(0, n);
        return ans;
    }
};