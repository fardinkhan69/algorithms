#include <bits/stdc++.h>

using namespace std;
class Edge
{
public:
    long long int u, v, c;
    Edge(long long int u, long long int v, long long int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
const int N = 1e5 + 5;
const long long INF = 1e18;
long long dis[N];

int main()
{
    long long int n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while (e--)
    {
        long long int u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }
    for (long long int i = 1; i <= n; i++) {
        dis[i] = LLONG_MAX;
    }
    long long int src;
    cin >> src;
    dis[src] = 0;
    for (long long int i = 1; i <= n - 1; i++)
    {
        for (auto ed : EdgeList)
        {
            long long int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if (dis[u] < LLONG_MAX && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }
    int cycle = 0;
    for (auto ed : EdgeList)
    {
        long long int u, v, c;
        u = ed.u;
        v = ed.v;
        c = ed.c;
        if (dis[u] < LLONG_MAX && dis[u] + c < dis[v])
        {
            cycle = 1;
            break;
        }
    }
    if (cycle == 0)
    {
        int t;
        cin >> t;
        while (t--)
        {
            int d;
            cin >> d;
            long long int x = dis[d];
            if(x == LLONG_MAX){
                cout<<"Not Possible"<<endl;
            }else{
                cout<<x<<endl;
            }
        }
    }else{
        cout<<"Negative Cycle Detected"<<endl;
    }


    return 0;
}