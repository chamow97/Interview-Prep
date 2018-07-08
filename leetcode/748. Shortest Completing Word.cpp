class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> frequency(26, 0);
        int totLength = 0;
        for(int i = 0; i < licensePlate.length(); i++)
        {
            if(licensePlate[i] >= 65 && licensePlate[i] <= 90)
            {
                licensePlate[i] += 32;
            }
            if(licensePlate[i] >= 97 && licensePlate[i] <= 122)
            {
                frequency[licensePlate[i] - 'a']++;
                totLength++;
            }
        }
        int minLength = 1000000;
        string ans = "";
        for(int i = 0; i < words.size(); i++)
        {
            vector<int> currFrequency(26, 0);
            for(int j = 0; j < words[i].length(); j++)
            {
                if(words[i][j] >= 65 && words[i][j] <= 90)
                {
                    words[i][j] += 32;
                }
                if(words[i][j] >= 97 && words[i][j] <= 122)
                {
                    currFrequency[words[i][j] - 'a']++;
                }
            }
            bool isP = true;
            int currAns = 0;
            for(int j = 0; j < 26; j++)
            {
                if(frequency[j] > 0 &&  currFrequency[j] > 0)
                {
                    if(currFrequency[j] >= frequency[j])
                    currAns += frequency[j];                   
                }
            }
            if(currAns != totLength)
            {
                isP = false;
            }
            if(isP)
            {
                if(words[i].length() < minLength)
                {
                    minLength = words[i].length();
                    ans = words[i];
                }
            }
        }
        return ans;
        
    }
};