#include<bits/stdc++.h>

using namespace std;
int n,m;
char a[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>>d = {{0,1},{0,-1},{-1,0},{1,0}};
int flag = 0;
bool valid(int si , int sj){
    if(si<0 || si >= n || sj<0|| sj >= m)
        return false;
    return true;
}
void dfs(int si,int sj){

    vis[si][sj] = true;

    for(int i = 0;i<4;i++){
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(valid(ci,cj) && vis[ci][cj] == false && (a[ci][cj] == '.' || a[ci][cj] == 'B')){
            if(a[ci][cj] == 'B'){
                flag = 1;
                return;
            }
            dfs(ci,cj);
            if(flag == 1)
            return;
        }
    }
}

int main(){
    cin>>n>>m;
    pair<int,int> A;
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            char x;
            cin>>x;
            if(x == 'A'){
                A={i,j};
            }
            a[i][j] = x;
        }
    }

    memset(vis,false,sizeof(vis));

    dfs(A.first,A.second);
    if(flag){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO";
    }

    
    return 0;
}