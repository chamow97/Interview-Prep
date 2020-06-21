class Solution {
public:
    int perm(int n) {
        int curr = 1;
        for(int i = 2; i <= n; i++) {
            curr *= i;
        }
        return curr;
    }
    string getPermutation(int n, int k) {
        set<int> s;
        string ans = "";
        for(int i = 1; i <= n; i++) {
            s.insert(i);
        }
        int tot = n;
        while(tot > 0) {
            int currPerm = perm(tot - 1);
            int newK = k / currPerm;
            if(currPerm * newK < k) {
                newK++;
            } else if(newK == 0) {
                newK = tot;
            }
            int test = (k / currPerm) * currPerm;
            if(test != 0) {
                k = k % test;
            }
            int index = 1;
            for(set<int> :: iterator it = s.begin(); it != s.end(); it++) {
                if(index == newK) {
                    ans += (char(*it + '0'));
                    s.erase(it);
                    break;
                }
                index++;
            }
            tot--;
        }
        return ans;
    }
};
