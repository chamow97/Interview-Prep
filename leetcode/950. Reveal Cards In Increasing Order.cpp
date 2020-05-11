class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end(), greater<int>());
        deque<int> q;
        int i = 0;
        q.push_back(deck[i]);
        i = 1;
        while(i < deck.size()) {
            int backVal = q.back();
            q.pop_back();
            q.push_front(backVal);
            q.push_front(deck[i]);
            i++;
        }
        vector<int> ans(q.begin(), q.end());
        return ans;
    }
};
