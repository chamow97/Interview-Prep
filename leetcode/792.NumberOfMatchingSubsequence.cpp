class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<int> *freq = new vector<int>[56];
        int answer = 0;
        for(int i = 0; i < S.length(); i++)
        {
            freq[S[i] - 'a'].push_back(i);
        }
        for(int i = 0; i < words.size(); i++)
        {
            bool isP = true;
            int pos = 0;
            for(int j = 0; j < words[i].length(); j++)
            {
            	if(freq[words[i][j] - 'a'].size() == 0)
            	{
            		isP = false;
            		break;
            	}
                int posNow = lower_bound(freq[words[i][j] - 'a'].begin(), freq[words[i][j] - 'a'].end(), pos) - freq[words[i][j] - 'a'].begin();
                int pos1 = *lower_bound(freq[words[i][j] - 'a'].begin(), freq[words[i][j] - 'a'].end(), pos);
                if(posNow == freq[words[i][j] - 'a'].size())
                {
                    isP = false;
                    break;
                }
                pos = pos1 + 1;
            }
            if(isP)
            {
                ++answer;
            }
        }
        return answer;
    }
};