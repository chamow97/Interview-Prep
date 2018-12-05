class Solution {
public:
    string toGoatLatin(string S) {
        stringstream words(S);
        string word;
        int counter = 0;
        string ans = "";
        while(words >> word){
            string curr = "";
            counter++;
            if(word[0] == 'a' || word[0] == 'A' || word[0] == 'e' || word[0] == 'E' || word[0] == 'i' || word[0] == 'I' || word[0] == 'o' || word[0] == 'O' || word[0] == 'u' || word[0] == 'U'){
                curr = word + "ma";
            }
            else{
                curr = word.substr(1);
                curr += word[0];
                curr += "ma";
        }
        
                for(int i = 0; i < counter; i++)
                {
                    curr += 'a';
                }
            ans += (curr + " ");
    }
        ans = ans.substr(0, ans.length()-1);
        return ans;
    }
};