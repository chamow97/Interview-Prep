#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long int n;
        cin >> n;
        long long int answer = (sqrt(2 * n + 0.25) - 0.5);
        cout << answer << '\n';
    }
    return 0;
}   