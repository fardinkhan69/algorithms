#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const long long int INF = 1e18+5;
int main()
{
    ll n, e,q;
    cin >> n >> e;
    ll adj[n+5][n+5];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            adj[i][j] = INF;
            if (i == j)
                adj[i][j] = 0;
        }
    }
    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = min(adj[a][b],c);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj[i][k] + adj[k][j] < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
    cin>>q;
    while(q--){
        ll x,y;
        cin>>x>>y;
        if(adj[x][y] == INF){
            cout<<-1<<endl;
        }else{
            cout<<adj[x][y]<<endl;
        }

    }
    return 0;
}