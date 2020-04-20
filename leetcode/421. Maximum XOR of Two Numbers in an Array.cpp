class Solution {
public:
    struct node {
        node *next[2];
        node() {
            next[0] = next[1] = NULL;
        }
    };
    node *root;
    
    void insertVal(string str) {
        node *temp = root;
        for(int i = 0; i < str.length(); i++) {
            if(temp -> next[str[i] - '0'] == NULL) {
                temp -> next[str[i] - '0'] = new node();
            }
            temp = temp -> next[str[i] - '0'];
        }
    }
    
    int getMaxValue(string str) {
        node *temp = root;
        int value = 0;
        for(int i = 0; i < str.length(); i++) {
            if(temp -> next[1 - (int)(str[i] - '0')] != NULL) {
                value += (pow(2, 32 - i - 1));
                temp = temp -> next[1 - (int)(str[i] - '0')];
            } else {
                temp = temp -> next[str[i] - '0'];
            }
        }
        return value;
    }
    
    string get32Bit(int value) {
        string str = "";
        while(value) {
            str = (char)((value % 2) + '0') + str;
            value /= 2;
        }
        while(str.length() < 32) {
            str = '0' + str;
        }
        return str;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        root = new node();
        insertVal(get32Bit(nums[0]));
        int maxValue = 0;
        for(int i = 1; i < nums.size(); i++) {
            string currValAsStr = get32Bit(nums[i]);
            maxValue = max(maxValue, getMaxValue(currValAsStr));
            insertVal(currValAsStr);
        }
        return maxValue;
    }
};
