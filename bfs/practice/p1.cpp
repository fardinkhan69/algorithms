#include<bits/stdc++.h>

using namespace std;
vector<int> v[1005];
bool vis[1005];
int level[1005];
int parent[1005];
void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;

    while(!q.empty()){
        int par = q.front();
        q.pop();

        for(int child: v[par]){
            if(vis[child] == false){
                q.push(child);
                vis[child] = true;
                level[child] = level[par]+1;
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
        v[b].push_back(a);

    }

    int q;
    cin>>q;
    
    while(q--){
        memset(vis,false,sizeof(vis));
        memset(level,-1,sizeof(level));
        memset(parent,-1,sizeof(parent));
        int s,d;
        cin>>s>>d;
        if (s == d) {
            cout << s << endl;
            continue;
        }
        bfs(s);
        int x = d;
        vector<int> ans;
        if(parent[d] != -1){
            int cnt = -1;
            while(x != -1){
                ans.push_back(x);
                cnt++;
                x = parent[x];
            }
            reverse(ans.begin(),ans.end());
            cout<<cnt<<endl;
            
        }else{
            cout<<-1<<endl;
        }

    }
    return 0;
}