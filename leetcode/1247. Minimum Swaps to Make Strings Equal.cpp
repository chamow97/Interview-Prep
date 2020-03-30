class Solution {
public:
    int minimumSwap(string s1, string s2) {
        // xy can match to xy in 1 move
        // yx can match to yx in 1 move
        // xy -> yx or yx -> xy takes 2 moves
        int n = min(s1.length(), s2.length());
        int xy = 0, yx = 0;
        for(int i = 0; i < n; i++) {
            if(s1[i] == s2[i]) {
                continue;
            }
            if(s1[i] == 'x' && s2[i] == 'y') {
                xy++;
            } else {
                yx++;
            }
        }
        int ans = 0;
        ans = ((xy / 2) + (yx / 2));
        xy -= (2 * (xy / 2));
        yx -= (2 * (yx / 2));
        if(xy != yx) {
            return -1;
        }
        ans += (2 * xy);
        return ans;
    }
};
