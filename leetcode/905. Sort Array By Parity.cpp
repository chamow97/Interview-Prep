class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        auto is_even = [] (auto e) {return !(e & 1);};
        partition(A.begin(), A.end(), is_even);
        return A;
    }
};
