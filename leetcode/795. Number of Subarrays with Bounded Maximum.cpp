class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int n = A.size();
        vector<int> newArr(n, 0);
        for(int  i = 0; i < n; i++)
        {
            if(A[i] >= L && A[i] <= R)
            {
                newArr[i] = 1;
            }
            else if(A[i] < L)
            {
                newArr[i] = 0;
            }
            else if(A[i] > R)
            {
                newArr[i] = 2;                
            }
        }
        int solution = 0, totalCount = 0, zeroCount = 0, temp = 0;
        for(int  i = 0; i < n; i++)
        {
            if(newArr[i] == 2)
            {
                solution += ((totalCount * (totalCount + 1))/2);
                temp += ((zeroCount * (zeroCount + 1))/2);
                solution -= temp;
                totalCount = 0;
                zeroCount = 0;
                temp = 0;
            }
            else if(newArr[i] == 1)
            {
                temp += ((zeroCount * (zeroCount + 1))/2);
                totalCount++;
                zeroCount = 0;
            }
            else 
            {
                totalCount++;
                zeroCount++;
            }
        }
        temp += ((zeroCount * (zeroCount + 1))/2);
        solution += ((totalCount * (totalCount + 1))/2);
        solution -= temp;
        return solution;
    }
};