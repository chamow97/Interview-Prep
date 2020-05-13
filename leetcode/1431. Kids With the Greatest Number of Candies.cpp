class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxElement = *max_element(candies.begin(), candies.end());
        vector<bool> ans;
        for(auto i : candies) {
            ans.push_back(i + extraCandies >= maxElement);
        }
        return ans;
    }
};
