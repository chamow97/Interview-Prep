class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int maxSoFar = 0, maximum = 0, minSoFar = 0, minimum = 0;
        int n = A.size();
        int sum = accumulate(A.begin(), A.end(), 0);
        for(int i = 0; i < A.size(); i++) {
            maxSoFar += A[i];
            minSoFar += A[i];
            if(minSoFar > 0) {
                minSoFar = 0;
            }
            if(maxSoFar < 0) {
                maxSoFar = 0;
            }
            minimum = min(minimum, minSoFar);
            maximum = max(maximum, maxSoFar);
        }
        if(maximum == 0) {
            maximum = INT_MIN;
            for(auto i : A) {
                if(i <= 0) {
                    maximum = max(maximum, i);
                }
            }
            return maximum;
        }
        return max(maximum, sum - minimum);
    }
};
