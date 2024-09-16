#include<bits/stdc++.h>

using namespace std;
vector<int> v[1005];
bool vis[1005];
int level[1005];
int parent[1005];

void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src]=true;
    level[src] = 0;

    while(!q.empty()){
        int par = q.front();
        q.pop();

        for(int child:v[par]){
            if(vis[child] == false){
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
            }
        }
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }

    int qu;
    cin>>qu;
    while(qu--){
        int a,b;
        cin>>a>>b;
        memset(vis,false,sizeof(vis));
        memset(level,-1,sizeof(level));
        memset(parent,-1,sizeof(parent));

        bfs(a);

        if(parent[b] == a){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}