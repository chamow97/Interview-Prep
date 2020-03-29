class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int answer = 0;
        int n = A.size();
        int i = 0, j = 0;
        int currZero = 0;
        if(A[0] == 0) {
            currZero++;
        }
        while(i <= j && j < n) {
            if(currZero <= K) {
                answer = max(answer, j - i + 1);
                j++;
                if(j < n && A[j] == 0) {
                    currZero++;
                }
            } else {
                if(A[i] == 0) {
                    currZero--;
                }
                i++;
                if(i > j && i < n) {
                    j = i;
                    if(A[j] == 0) {
                        currZero = 1;
                    } else {
                        currZero = 0;
                    }
                }
            }
        }
        return answer;
    }
};
