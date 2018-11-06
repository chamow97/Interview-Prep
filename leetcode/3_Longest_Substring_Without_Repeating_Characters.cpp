class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if(len < 2)
        {
            return len;
        }
        int ctr = 0;
        for(int i = 0; i < len; i++)
        {
            if(s[i] == ' ')
            {
                ctr++;
            }
        }
        if(ctr == len)
        {
            return 1;
        }
        if(len == 2)
        {
            if(s[0] == s[1])
            {
                return 1;
            }
            return 2;
        }
        int ptr1 = 0, ptr2 = 1;
        map<char, int> m;
        m[s[ptr1]]++;
        m[s[ptr2]]++;
        int ans = 0;
            map<char, int> :: iterator it;
        while(ptr2 < len)
        {
            // cout << ptr1 << ' ' << ptr2 << '\n';
            bool possible = true;
            for(it = m.begin(); it  != m.end(); it++)
            {
                
                if(m[it -> first] > 1)
                {
               possible = false;
                    break;
                }
            }
            if(possible)
            {
                ptr2++;
                if(ptr2 >= len)
                {
                    break;
                }
                m[s[ptr2]]++;
            }
            else
            {
                ans = max(ans, ptr2 - ptr1);
                m[s[ptr1]]--;
                ptr1++;
            }
        }
        bool possible = true;
        for(it = m.begin(); it  != m.end(); it++)
        {

            if(m[it -> first] > 1)
            {
           possible = false;
                break;
            }
        }
        if(possible)
        {
            ans = max(ans, ptr2 - ptr1);
        }
        return ans;
        
    }
};