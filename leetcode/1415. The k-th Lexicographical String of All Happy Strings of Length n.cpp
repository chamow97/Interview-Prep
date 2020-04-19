class Solution {
public:
    vector<string> allS;
    void generateString(int n, int i, string curr) {
        if(i == n) {
            allS.push_back(curr);
            return;
        }
        if(i == 0) {
            generateString(n, i + 1, curr + "a");
            generateString(n, i + 1, curr + "b");
            generateString(n, i + 1, curr + "c");
        } else {
            char lastChar = curr[curr.length() - 1];
            if(lastChar != 'a') {
                generateString(n, i + 1, curr + "a");
            }
            if(lastChar != 'b') {
                generateString(n, i + 1, curr + "b");
            }
            if(lastChar != 'c') {
                generateString(n, i + 1, curr + "c");
            }  
        }
    }
    string getHappyString(int n, int k) {
        allS.resize(0);
        generateString(n, 0, "");
        if(k > allS.size()) {
            return "";
        } else {
            sort(allS.begin(), allS.end());
            return allS[k - 1];
        }
    }
};
