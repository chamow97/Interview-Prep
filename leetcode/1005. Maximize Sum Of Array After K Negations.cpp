class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        for(int i = 0; i < A.size(); i++) {
            if(K == 0 || A[i] >= 0) {
                break;
            }
            A[i] *= (-1);
            K--;
        }
        return (accumulate(A.begin(), A.end(), 0) - ((K % 2) * *min_element(A.begin(), A.end()) * 2));
    }
};
