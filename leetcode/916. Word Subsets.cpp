class Solution {
public:
    vector<int> getCounter(string a)
    {
        vector<int> counter(26, 0);
        for(int i = 0; i < a.length(); i++)
        {
            counter[a[i] - 'a']++;
        }
        return counter;
    }
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> unique(26, 0), temp(26, 0);
        for(string b : B)
        {
            vector<int> counter = getCounter(b);
            for(int i = 0; i < 26; i++)
            {
                unique[i] = max(unique[i], counter[i]);
            }
        }
        vector<string> answer;
        for(int i = 0; i < A.size(); i++)
        {
            temp = getCounter(A[i]);
            int j = 0;
            for(j = 0; j < 26; j++)
            {
                if(temp[j] < unique[j])
                {
                    break;
                }
            }
            if(j == 26)
            {
                answer.push_back(A[i]);
            }
        }
        return answer;
    }
};