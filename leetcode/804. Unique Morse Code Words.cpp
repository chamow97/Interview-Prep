class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string alpha[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> s;
        for(int i = 0; i < words.size(); i++)
        {
            string str = "";
            for(int j = 0; j < words[i].size(); j++)
            {
                str += (alpha[words[i][j] - 'a']);
            }
            s.insert(str);
        }
        return ((int)s.size());
    }
};