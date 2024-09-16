#include<bits/stdc++.h>

using namespace std;
int n,m;
char a[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>>d = {{0,1},{0,-1},{-1,0},{1,0}};
bool valid(int si , int sj){
    if(si<0 || si >= n || sj<0|| sj >= m )
        return false;
    return true;
}
void dfs(int si,int sj){
    vis[si][sj] = true;

    for(int i = 0;i<4;i++){
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(valid(ci,cj) && vis[ci][cj] == false && a[ci][cj] != '#'){
            dfs(ci,cj);
        }
    }
}

int countApartment(){
    int total = 0;

    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            //notun room paile mane age visit hoy nai emon .
            if(a[i][j] == '.' && !vis[i][j]){
                total++;
                dfs(i,j);
            }
        }
    }
    return total;
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

    int ans = countApartment();
    cout<<ans<<endl;
    
    return 0;
}