class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // if sum of gas < sum of cost then not at all possible
        if(accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }
        int currSum = 0, start = 0, total = 0;
        for(int i = 0; i < cost.size(); i++) {
            currSum += (gas[i] - cost[i]);
            if(currSum < 0) {
                // it means it cant be started here
                total += currSum;
                start = i + 1;
                currSum = 0;
            }
        }
        total += currSum;
        if(total < 0) {
            return -1;
        }
        return start;
    }   
};
