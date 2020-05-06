class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majority1 = 0, majority2 = 0, counter1 = 0, counter2 = 0;
        for(int i : nums) {
            if(i == majority1) {
                counter1++;
            } else if(i == majority2) {
                counter2++;
            } else if(counter1 == 0) {
                majority1 = i;
                counter1 = 1;
            } else if(counter2 == 0) {
                majority2 = i;
                counter2 = 1;
            } else {
                counter1--;
                counter2--;
            }
        }
        vector<int> ans;
        int count1 = 0;
        int count2 = 0;
        for(int i : nums) {
            if(i == majority1) {
                count1++;
            }
            else if(i == majority2) {
                count2++;
            }
        }
        if(count1 > (n / 3)) {
            ans.push_back(majority1);
        }
        if(count2 > (n / 3)) {
            ans.push_back(majority2);
        }
        return ans;
    }
};
