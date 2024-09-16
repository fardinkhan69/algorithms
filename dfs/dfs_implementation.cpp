#include<bits/stdc++.h>

using namespace std;
vector<int> v[100];
bool vis[100];
void bfs(int src){
    cout<<src<<endl;
    vis[src] = true;

    for(int children : v[src]){
        if(vis[children] == false){
            bfs(children);
        }
    }
}
int main(){
    //Algorithm 
    // Print yourselfs
    //Check visitied
    //Print childrens
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    int src;
    cin>>src;
    bfs(src);

    
    return 0;
}