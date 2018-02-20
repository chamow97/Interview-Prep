class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int>  m;
        vector<int> answer;
        for(int i = 0; i < nums.size(); i++)
        {
            int other = target - nums[i];
            if(m.find(other) != m.end())
            {
                answer.push_back(m.find(other)->second);
                answer.push_back(i);
            }
            m[nums[i]] = i;           
            
        }
        
        return answer;
    }
};