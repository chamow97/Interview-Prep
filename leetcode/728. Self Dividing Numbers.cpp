class Solution {
public:
    bool possible(int n) {
        int temp = n;
        while(temp) {
            if((temp % 10 == 0) or (n % (temp % 10)) != 0) {
                return false;
            }
            temp /= 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++) {
            if(possible(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
