class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> str;
        
        int i = 0;
        int j = 1;
        while(i < target.size()) {
            if(target[i] == j) {
                str.push_back("Push");
                i++;
                j++;
            } else {
                str.push_back("Push");
                str.push_back("Pop");
                j++;
            }
        }
        return str;
    }
};
