#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n, m;
        ll s1, s2, d1, d2;
        cin>>n>>m;
        cin>>s1>>s2>>d1>>d2;
        queue< pair<ll, ll> > q;
        q.push(mp(s1, s2));
        ll path[n+1][m+1];
        for(ll i = 0; i <= n ; i++)
        {
            for(ll j = 0; j <= m; j++)
            {
                path[i][j] = -1;
            }
        }
        path[s1][s2] = 0;
        while(!q.empty())
        {
            pair<ll, ll> top = q.front();
            q.pop();
            //top
            ll row = top.first;
            ll col = top.second;
            // cout<<row<<" "<<col<<'\n';
            // cout<<path[row][col];
            if((row-2) >= 1 && (col-1) >= 1)
            {
                if(path[row-2][col-1] == -1)
                {
                    path[row-2][col-1] = (1 + path[row][col]);
                    q.push(mp(row-2, col-1));
                }
                
            }
            if((row-2) >= 1 && (col+1) <= m)
            {
                if(path[row-2][col+1] == -1)
                {
                    path[row-2][col+1] = (1 + path[row][col]);
                    q.push(mp(row-2, col+1));
                }
                
            }
            //down
            if((row+2) <= n && (col-1) >= 1)
            {
                if(path[row+2][col-1] == -1)
                {
                    path[row+2][col-1] = (1 + path[row][col]);
                    q.push(mp(row+2, col-1));
                }
                
            }
            if((row+2) <= n && (col+1) <= m)
            {
                if(path[row+2][col+1] == -1)
                {
                    path[row+2][col+1] = (1 + path[row][col]);
                    q.push(mp(row+2, col+1));
                }
                
            }
            //left
            if((row-1) >= 1 && (col-2) >= 1)
            {
                if(path[row-1][col-2] == -1)
                {
                    path[row-1][col-2] = (1 + path[row][col]);
                    q.push(mp(row-1, col-2));
                }
                
            }
            if((row+1) <= n && (col-2) >= 1)
            {
                if(path[row+1][col-2] == -1)
                {
                    path[row+1][col-2] = (1 + path[row][col]);
                    q.push(mp(row+1, col-2));
                }
                
            }
            //right
            if((row-1) >= 1 && (col+2) <= m)
            {
                if(path[row-1][col+2] == -1)
                {
                    path[row-1][col+2] = (1 + path[row][col]);
                    q.push(mp(row-1, col+2));
                }
                
            }
            if((row+1) <= n && (col+2) <= m)
            {
                if(path[row+1][col+2] == -1)
                {
                    path[row+1][col+2] = (1 + path[row][col]);
                    q.push(mp(row+1, col+2));
                }
                
            }
        }
        cout<<path[d1][d2]<<'\n';
    }
    return 0;
}
