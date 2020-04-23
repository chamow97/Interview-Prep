class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> freq(26, 0);
        int n = s.length();
        for(int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }
        // We can see, number of odd number of characters matter here
        // each of k words can take atmost 1 odd words, so if odd words > k
        // then not possible
        // other observation is where the letters with even frequencies
        // doesnt matter so lets give that extra 1 in odd to even out to some
        // of the k letters, pretty unlucky huh? :( after that we have to given even
        // to each of k as a pair, while doing this if we run out of string then no
        // else yes for every possible case
        int soFarOdd = 0;
        for(int i = 0; i < 26; i++) {
            if(freq[i] % 2 == 1) {
                soFarOdd++;
            }
        }
        return (soFarOdd <= k && n >= k);
    }
};
