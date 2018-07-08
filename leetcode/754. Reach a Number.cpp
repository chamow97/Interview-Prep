class Solution {
public:
    
    
    int reachNumber(int target) {
        target = abs(target);
       int step = 0, step_sum = 0;
        while(1)
        {
            step++;
            step_sum += step;
            if(step_sum >= target && (step_sum - target) % 2 == 0){
                break;
            }
        }
        return step;
    }
};