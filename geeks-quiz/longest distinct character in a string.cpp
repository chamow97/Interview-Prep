#include <bits/stdc++.h>
using namespace std;

int frequencyTable[26];
void clearFrequency()
{
    for(int i = 0; i < 26; i++)
    {
        frequencyTable[i] = 0;
    }
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string inputString;
	    cin>>inputString;
	    int stringLength = inputString.length();
	    int maxDistinct = 0;
	    clearFrequency();
	    int startPtr = 0, endPtr = 0;
	    while(startPtr < stringLength && endPtr < stringLength)
	    {
	        if(frequencyTable[inputString[endPtr] - 'a'] == 0)
	        {
	            frequencyTable[inputString[endPtr] - 'a']++;
	            endPtr++;
	        }
	        else
	        {
	            maxDistinct = max(maxDistinct, endPtr - startPtr);
	            frequencyTable[inputString[startPtr] - 'a']--;
	            startPtr++;
	        }
	    }
	    maxDistinct = max(maxDistinct, endPtr - startPtr);
	    cout<<maxDistinct<<'\n';
	}
	return 0;
}