#include <bits/stdc++.h>

using namespace std;
int n, m;
char a[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
vector<int> room;
int c = 0;
bool valid(int si, int sj)
{
    if (si < 0 || si >= n || sj < 0 || sj >= m)
        return false;
    return true;
}
void dfs(int si, int sj)
{
    vis[si][sj] = true;
    c++;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) && vis[ci][cj] == false && a[ci][cj] != '#')
        {
            dfs(ci, cj);
        }
    }
}

void countApartment()
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // notun room paile mane age visit hoy nai emon .
            if (a[i][j] == '.' && !vis[i][j])
            {
                dfs(i, j);
                room.push_back(c);
                c = 0;
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char x;
            cin >> x;
            a[i][j] = x;
        }
    }

    memset(vis, false, sizeof(vis));
    countApartment();
    sort(room.begin(), room.end());
    if (!room.empty())
    {
        for (int x : room)
            cout << x << ' ';
    }else{
        cout<<0;
    }

    return 0;
}