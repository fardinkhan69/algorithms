#include <bits/stdc++.h>

using namespace std;
bool vis[1005][1005];
int dis[1005][1005];
vector<pair<int, int>> d = {{-2,1},{-2,-1},{2,1},{2,-1},{-1,-2},{-1,2},{1,-2},{1,2}};
int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});

    vis[si][sj] = true;
    dis[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        int p = par.first;
        int b = par.second;

        for (int i = 0; i < 8; i++)
        {
            int ci = p + d[i].first;
            int cj = b + d[i].second;

            if (valid(ci, cj) && vis[ci][cj] == false)
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[p][b] + 1;
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;

        int si, sj,di,dj;
        cin >> si >> sj>>di>>dj;
        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));
        bfs(si, sj);

        if(dis[di][dj] == -1){
            cout<<-1<<endl;
        }else{
            cout<<dis[di][dj]<<endl;
        }
    }

    return 0;
}