class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maximum = -1;
        for(int i = arr.size() - 1; i >= 0; i--) {
            int temp = arr[i];
            arr[i] = maximum;
            maximum = max(maximum, temp);
        }
        return arr;
    }
};
