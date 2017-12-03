class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        int temp = N;
        string str = "";
        while(temp)
        {
            int t = temp % 10;
            str = char(t + 48) + str;
            temp /= 10;
        }
        int j = str.length() - 1;
        while(j > 0)
        {
            if(str[j] < str[j-1])
            {
                int ptr = j - 1;
                while(ptr >= 0 && str[ptr] != '0')
                {
                    str[ptr] = str[ptr] - 1;
                   
                    for(int k = ptr + 1; k < str.length(); k++)
                    {
                        str[k] = '9';
                    }
                    j = ptr;
                    break;
                }
            }
            else
            {
                --j;
            }
                
        }
        int i = 0;
        while(str[i] == '0')
        {
            i++;
        }
        int answer = 0;
        for(int j = i; j < str.length(); j++)
        {
            answer = (answer * 10) + (str[j] - '0');
        }
        return answer;
    }
};