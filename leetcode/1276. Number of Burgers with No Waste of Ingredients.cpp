class Solution {
public:
    vector<int> numOfBurgers(int t, int c) {
        if(t % 2 == 0 && t >= 2 * c && t <= 4 * c) {
            // answer is possible
            return {(t / 2) - c, (2 * c) - (t / 2)};
        } 
        return {};
    }
};
