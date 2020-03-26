class Solution {
    public:
    int ans=0;
    int maxLength(vector<string>& arr) {
        vector<int> counter(26, 0);
        vector<string> brr;
        for(int i = 0; i < arr.size(); i++) {
            vector<int> freq(26, 0);
            bool isUnique = true;
            for(int j = 0; j < arr[i].length(); j++) {
                freq[arr[i][j] - 'a']++;
            }
            for(int j = 0; j < 26; j++) {
                if(freq[j] > 1) {
                    isUnique = false;
                    break;
                }
            }
            if(isUnique) {
                brr.push_back(arr[i]);
            }
        }
        helper(brr,"",0, counter);
        return ans;
    }
    void helper(vector<string>& arr,string curr,int index, vector<int> &freq)
    {
        if(index==arr.size() && unique(curr, freq)>ans)
        {
            ans=curr.length();
            return;
        }
        
        if(index==arr.size())
        {
            return;
        }
        helper(arr,curr,index+1, freq);
        bool canBeUsed = true;
        for(int i = 0; i < arr[index].length(); i++) {
            if(freq[arr[index][i] - 'a'] > 0) {
                canBeUsed = false;
                break;
            }
        }
        if(canBeUsed) {
            for(int i = 0; i < arr[index].length(); i++) {
                freq[arr[index][i] - 'a']++;
            }
            helper(arr,curr+arr[index],index+1, freq);
            for(int i = 0; i < arr[index].length(); i++) {
                freq[arr[index][i] - 'a']--;
            }
        }
    }
    int unique(string curr, vector<int> &freq)
    {
        int unique = 0;
        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) {
                unique++;
            }
        }
        if(curr.length() != unique) {
            return -1;
        }
        return curr.length();
    }
};
