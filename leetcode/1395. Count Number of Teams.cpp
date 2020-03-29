class Solution {
public:
    int numTeams(vector<int>& arr) {
        int teams = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    if(arr[i] < arr[j] && arr[j] < arr[k]) {
                        teams++;
                    }
                    if(arr[i] > arr[j] && arr[j] > arr[k]) {
                        teams++;
                    }
                }
            }
        }
        return teams;
    }
};
