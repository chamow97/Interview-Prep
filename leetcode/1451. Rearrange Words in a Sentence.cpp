class Solution {
public:
    static bool myFunc(pair<string, int> p1, pair<string, int> p2) {
        if(p1.first.length() == p2.first.length()) {
            return p1.second < p2.second;
        }
        return p1.first.length() < p2.first.length();
    }
    string arrangeWords(string text) {
        stringstream s(text); // Used for breaking words 
        string word; // to store individual words 
    
        vector< pair<string, int> > arr;
        int i = 0;
        while (s >> word) {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            arr.push_back({word, i});
            i++;
        }
        sort(arr.begin(), arr.end(), myFunc);
        if(arr.size() > 0) {
            arr[0].first[0] -= 32;
        }
        string ans = "";
        for(int i = 0; i < arr.size(); i++) {
            ans += (arr[i].first + " ");
        }
        string total(ans.begin(), ans.begin() + ans.length() - 1);
        return total;
    }
};
