#include<bits/stdc++.h>

using namespace std;
#define ll long long int
const long long int Inf = 1e18+5;
int main(){
    int n,e,q;
    cin>>n>>e>>q;
    ll adj[n+5][n+5];
    for(int i =1;i<=n;i++){
        for(int j=1;j<=n;j++){
            adj[i][j] = Inf;
            if(i==j)
                adj[i][j] = 0;
        }
    }
    while(e--){
        ll a,b,c;
        cin>>a>>b>>c;
        adj[a][b] = min(adj[a][b],c);
    }

    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(adj[i][k] + adj[k][j]<adj[i][j]){
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    while(q--){
        
    }
    return 0;
}