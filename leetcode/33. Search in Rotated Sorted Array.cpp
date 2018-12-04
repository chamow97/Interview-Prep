class Solution {
public:
    vector<int> arr;
    int index;
    int n;
    void getIndex(int low, int high)
    {
        if(high < low)
        {
            return;
        }
        
        int mid = (low + high) / 2;
        if(arr[mid] < arr[n - 1])
        {
            high = mid - 1;
        }
        else
        {
            if(mid != n - 1)
            index = mid;
            low = mid + 1;
        }
        getIndex(low, high);
    }
    int search(vector<int>& nums, int target) {
        arr = nums;
        n = arr.size();
        if(n == 0)
        {
            return -1;
        }
        getIndex(0, n - 1);
        int pos1 = (lower_bound(arr.begin(), arr.begin() + index + 1, target) - arr.begin());
        if(pos1 >= 0 && pos1 <= index && arr[pos1] == target)
        {
            return pos1;
        }
        else
        {
             int pos2 = (lower_bound(arr.begin() + index + 1, arr.end(), target) - arr.begin());
            if(pos2 >= 0 && pos2 < n && arr[pos2] == target)
            {
                return pos2;
            }
            return -1;
        }
    }
};