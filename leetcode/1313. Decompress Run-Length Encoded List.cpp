class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int freq, num;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i+=2){
            freq = nums[i];
            num = nums[i + 1];
            while(freq--) {
                ans.push_back(num);  
            } 
        }
        return ans;
    }
};
