class Solution {
public:
    string sortString(string s) {
        vector<int> freq(26, 0);
        for(auto i : s) {
            freq[i - 'a']++;
        }
        string ans = "";
        while(1) {
            // go forward
            bool isPossible = false;
            for(int i = 0; i < 26; i++) {
                if(freq[i] > 0) {
                    isPossible = true;
                    ans += ((i + 'a'));
                    freq[i]--;
                }
            }
            if(!isPossible) {
                break;
            }
            isPossible = false;
            for(int i = 25; i >= 0; i--) {
                if(freq[i] > 0) {
                    isPossible = true;
                    ans += ((i + 'a'));
                    freq[i]--;
                }
            }
            if(!isPossible) {
                break;
            }
        }
        return ans;
    }
};
