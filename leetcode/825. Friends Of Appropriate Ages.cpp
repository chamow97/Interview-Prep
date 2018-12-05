class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size();
        map<int, int> m;
        for(int i = 0; i < n; i++)
        {
            m[ages[i]]++;
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int maxAge = (0.5 * ages[i]) + 7;
            maxAge += 1;
            if(maxAge > ages[i])
            {
                continue;
            }
            for(int j = maxAge; j < ages[i]; j++)
            {
                ans += m[j];
            }
            ans += (m[ages[i]] - 1);
        }
        return ans;
    }
};