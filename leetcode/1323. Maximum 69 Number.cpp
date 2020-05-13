class Solution {
public:
    int maximum69Number (int num) {
        int newNumber = 0;
        int bestPossibleIndex = -1;
        int i = 0;
        int temp = num;
        while(temp) {
            if(temp % 10 == 6) {
                bestPossibleIndex = i;
            }
            temp /= 10;
            i++;
        }
        if(bestPossibleIndex == -1) {
            return num;
        }
        i = 0;
        cout << bestPossibleIndex;
        while(num) {
            if(i == bestPossibleIndex) {
                newNumber = ((newNumber * 10) + 9);
            } else {
                newNumber = ((newNumber * 10) + (num % 10));
            }
            num /= 10;
            i++;
        }
        int newN = 0;
        while(newNumber) {
            newN = ((newN * 10) + (newNumber % 10));
            newNumber /= 10;
        }
        return newN;
    }
};
