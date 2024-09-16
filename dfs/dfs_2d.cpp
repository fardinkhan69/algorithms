#include<bits/stdc++.h>

using namespace std;
int n,m;
char a[20][20];
bool vis[20][20];
vector<pair<int,int>>d = {{0,1},{0,-1},{-1,0},{1,0}};
bool valid(int si , int sj){
    if(si<0 || si >= n || sj<0|| sj >= m)
        return false;
    return true;
}
void dfs(int si,int sj){
    cout<< si<<" " << sj <<endl;
    vis[si][sj] = true;

    for(int i = 0;i<4;i++){
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(valid(ci,cj) && vis[ci][cj] == false){
            dfs(ci,cj);
        }
    }
}

int main(){
    cin>>n>>m;

    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            char x;
            cin>>x;
            a[i][j] = x;
        }
    }

    memset(vis,false,sizeof(vis));
    int si,sj;
    cin>>si>>sj;

    dfs(si,sj);

    
    return 0;
}