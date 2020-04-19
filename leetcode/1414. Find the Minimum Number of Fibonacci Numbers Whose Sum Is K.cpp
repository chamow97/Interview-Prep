class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> febTerms;
        febTerms.push_back(0);
        febTerms.push_back(1);
        febTerms.push_back(1);
        int i = 3;
        while(1) {
            int curr = febTerms[i - 1] + febTerms[i - 2];
            if(curr > k) {
                break;
            }
            febTerms.push_back(curr);
            i++;
        }
        int j = febTerms.size() - 1;
        int count = 0;
        while(k > 0) {
            count += (k / febTerms[j]);
            k %= febTerms[j];
            j--;
        }
        return count;
    }
};
