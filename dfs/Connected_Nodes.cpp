#include<bits/stdc++.h>

using namespace std;
vector<int> v[1005];
bool vis[1005];

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
        int x;
        cin>>x;
        vector<int> ans;
        for(int i : v[x]){
            ans.push_back(i);
        }
        sort(ans.begin(),ans.end(),greater<int>());
        if(!ans.empty()){
            for(int i:ans)
                cout<<i<<" ";
        }else{
            cout<<-1;
        }
        cout<<endl;

    }
    return 0;
}