#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> answer;
        map<int, int> m;
        for(int i = 0; i < n; i++)
        {
            bool possible = true;
            int now;
            cin >> now;
            int temp = now;
            while(temp)
            {
                if(temp % 10 <= 0 || temp % 10 >= 4)
                {
                    possible = false;
                    break;   
                }
                temp /= 10;
            }
            if(possible)
            answer.push_back(now);
        }
        if(answer.size() > 0)
        {
            sort(answer.begin(), answer.end());
            for(int i = 0; i < answer.size(); i++)
            {
                cout << answer[i] << ' ';
            }
        }
        else
        {
            cout << -1;
        }
        cout << '\n';
        
    }
	return 0;
}