class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        vector<int> answer;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[abs(arr[i]) - 1] > 0) {
                arr[abs(arr[i]) - 1] *= (-1);
            }
        }
        for(int i = 0; i < arr.size(); i++) {
            arr[abs(arr[i]) - 1] *= (-1);
        }
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] < 0) {
                answer.push_back(i + 1);
            }
        }
        return answer;
    }
};
