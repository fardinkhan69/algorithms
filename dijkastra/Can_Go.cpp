#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e5 + 5;
vector<pair<long long int, long long int>> v[N];
long long int dis[N];
class cmp
{
public:
    bool operator()(pair<long long int, long long int> a, pair<long long int, long long int> b)
    {
        return a.second > b.second;
    }
};
void dijkstra(int src)
{
    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, cmp> q;
    q.push({src, 0});

    dis[src] = 0;

    while (!q.empty())
    {
        pair<long long int, long long int> parent = q.top();
        q.pop();
        long long int node = parent.first;
        long long int cost = parent.second;
        if (cost > dis[node])
            continue;

        for (pair<long long int, long long int> child : v[node])
        {
            long long int childNode = child.first;
            long long int childCost = child.second;
            if (childCost + cost < dis[childNode])
            {
                dis[childNode] = childCost + cost;
                q.push({childNode, dis[childNode]});
            }
        }
    }
}
int main()
{
    long long int n, e;
    cin >> n >> e;

    while (e--)
    {
        long long int a, b;
        long long int c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = LLONG_MAX;
    }
    long long int src;
    cin >> src;
    dijkstra(src);
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int des;
        long long dw;
        cin >> des >> dw;

        if (dis[des] <= dw)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}