class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        vector<int> freq(1001, 0);
        int n = stones.size();
        for(int i = 0; i < n; i++) {
            freq[stones[i]]++;
        }
        int i = 1000;
        while(i > 0) {
            if(freq[i] % 2 == 0) {
                i--;
                continue;
            } else {
                int j = i - 1;
                while(j > 0 && freq[j] == 0) {
                    j--;
                }
                if(j <= 0) {
                    return i;
                }
                freq[i - j]++;
                freq[j]--;
                freq[i]--;
            }
            
        }
        return 0;
    }
};
