class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int n = A.size();
        vector<int> maximum(n, 1000000);
        vector<int> minimum(n, 0);
        maximum[0] = A[0];
        for(int i = 1; i < n; i++)
        {
            maximum[i] = max(maximum[i - 1], A[i]);
        }
        minimum[n - 1] = A[n-1];
        for(int i = n - 2; i >= 0; i--)
        {
            minimum[i] = min(minimum[i + 1], A[i]);
        }
        int answer = 0;
        for(int i = 0; i < n - 1; i++)
        {
            if(maximum[i] <= minimum[i+1])
            {
                answer = i + 1;
                break;
            }
        }
        return answer;
    }
};