class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int ptr1 = 0, ptr2 = n - 1;
        int ans = 0;
        while(ptr1 < n && ptr2 >= 0 && ptr1 <= ptr2) {
            if(ptr1 == ptr2) {
                ans++;
                ptr1++;
                ptr2--;
            }
            else if((people[ptr1] + people[ptr2]) <= limit) {
                ans++;
                ptr1++;
                ptr2--;
            } else {
                ans++;
                ptr2--;
            }
        }
        return ans;
    }
};
