class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        stringstream ss(paragraph);
        map<string, bool> m1;
        map<string, int> m2;
        string now;
        int maximum = 0;
        for(int i = 0; i < banned.size(); i++)
        {
            m1[banned[i]] = true;
        }
        string word;
        while(ss >> now)
        {
            transform(now.begin(), now.end(), now.begin(), ::tolower);
            if(now[now.length() - 1] == ',' || now[now.length() - 1] == '.' || now[now.length() - 1] == '!' || now[now.length() - 1] == '?'  || now[now.length() - 1] == ';' || now[now.length() - 1] == '\'')
                {
                    now = now.substr(0, now.length() - 1);
                }
            if(!m1[now])
            {
                
                    
                m2[now]++;
                // cout << now << ' ';
                if(maximum < m2[now])
                {
                    word = now;
                    maximum = m2[now];
                }
            }
        }
        return word;
        
    }
};