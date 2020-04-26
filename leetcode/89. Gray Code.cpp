class Solution {
public:
    vector< vector< string> > getGrayCode(int n) {
        vector< vector<string> > grayCode(n + 1);
        grayCode[1].push_back("0");
        grayCode[1].push_back("1");
        for(int i = 2; i <= n; i++) {
            // first half append 0 to i - 1 to its left 
            for(int j = 0; j < pow(2, i - 1); j++) {
                grayCode[i].push_back("0" + grayCode[i - 1][j]);
            }
            // second half append 1 to i - 1 to its right in reverse order
            for(int j = pow(2, i - 1) - 1; j >= 0; j--) {
                grayCode[i].push_back("1" + grayCode[i - 1][j]);
            }
        }
        return grayCode;
    }
    int stringToIntBinary(string bin) {
        int result = 0;
        for(int i = bin.length() - 1; i >= 0; i--) {
            if(bin[i] == '1') {
                result = result + pow(2, bin.length() - i - 1);
            }
        }
        return result;
    }
    vector<int> grayCode(int n) {
        vector< int > result;
        if(n == 0) {
            return vector<int>(1, 0);
        }
        vector< vector<string> > grayCode = getGrayCode(n);
        for(int i = 0; i < grayCode[n].size(); i++) {
            result.push_back(stringToIntBinary(grayCode[n][i]));
        }
        return result;
    }
};
