class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int, int> m;
        int x = 0;
        if(deck.size() == 1)
        {
            return false;
        }
        for(int i = 0; i < deck.size(); i++)
        {
            m[deck[i]]++;
        }
        for(int i = 0; i < deck.size(); i++)
        {
            x = __gcd(x, m[deck[i]]);
        }
        if(x >= 2 || m[x] == deck.size())
        {
            return true;
        }
        return false;
    }
};