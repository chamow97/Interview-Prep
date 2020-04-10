class Solution {
public:
    char firstPossibleCharacter(string S, int &index) {
        int backspace = 0;
        while(index >= 0) {
            while(index >= 0 && S[index] == '#') {
                backspace++;
                index--;
            }
            while(index >= 0 && backspace > 0 && S[index] != '#') {
                backspace--;
                index--;
            }
            if(backspace == 0 && (index < 0 || S[index] != '#')) {
                break;
            }
        }
        if(index < 0) {
            return '$';
        }
        return S[index];
    }
    bool backspaceCompare(string S, string T) {
        int i = S.length() - 1;
        int j = T.length() - 1;
        int aB = 0, bB = 0;
        while(i >= 0 || j >= 0) {
            char a = firstPossibleCharacter(S, i);
            char b = firstPossibleCharacter(T, j);
            cout << a << ' ' << b << '\n';
            if(a != b) {
                return false;
            }
            i--;
            j--;
        }
        return true;
    }
};
