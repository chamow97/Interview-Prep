#define ll long long
#define vec vector<int>
class Solution {
public:
		int counter;
		Solution()
		{
			counter = 0;
		}
		void computeLPS(string& pattern, vec &lps, ll m)
		{
		    ll len = 0;
		    lps[0] = 0;
		    ll i = 1;
		    while(i < m)
		    {
		        if(pattern[i] == pattern[len])
		        {
		            len++;
		            lps[i] = len;
		            i++;
		        }
		        else if(pattern[i] != pattern[len] && len != 0)
		        {
		            len = lps[len-1];
		        }
		        else
		        {
		            lps[i] = 0;
		            ++i;
		        }
		    }
		}
		void KMP(string& text, string& pattern)
		{
		    ll n = text.length();
		    ll m = pattern.length();
		    vec lps(m,0);
		    
		    computeLPS(pattern, lps, m);
		    ll i = 0, j = 0;
		    while(i < n)
		    {
		        if(text[i] == pattern[j])
		        {
		            i++;
		            j++;
		        }
		        if(j == m)
		        {
		        		++counter;
		            j = lps[j-1];
		        }
		        else if(i < n && pattern[j] != text[i])
		        {
		            if(j != 0)
		            {
		                j = lps[j-1];
		            }
		            else
		            {
		                i = i + 1;
		            }
		        }
		        
		    }
		}
		
    bool rotateString(string A, string B) {
        if(A.length() != B.length())
        {
            return false;
        }
        A += A;
        KMP(A, B);
        if(counter > 0)
        return true;
      	return false;
    }
};