class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int best = 0;
        int start = 0;
        int end = 0;
        deque<int> minQ;
        deque<int> maxQ;
        while(end < nums.size()) {
            int curr = nums[end];
            while(!minQ.empty() && nums[minQ.back()] >= curr) {
                minQ.pop_back();
            }
            minQ.push_back(end);
            
            
            while(!maxQ.empty() && nums[maxQ.back()] <= curr) {
                maxQ.pop_back();
            }
            
            maxQ.push_back(end);
            
            int minI = *minQ.begin();
            int minVal = nums[minI];
            int maxI = *maxQ.begin();
            int maxVal = nums[maxI];
            
            if(maxVal - minVal > limit) {
                start++;
                if(!minQ.empty() && start > *minQ.begin()) {
                    minQ.pop_front();
                }
                if(!maxQ.empty() && start > *maxQ.begin()) {
                    maxQ.pop_front();
                } 
            } else {
                if(end - start + 1 > best) {
                    best = end - start + 1;
                }
                end++;
            }
        }
        return best;
    }
};
