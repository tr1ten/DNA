#include <bits/stdc++.h>
using namespace std;

// input
int t = 1;

// solve here
void bfs(vector<pair<int, int>> &starts, vector<vector<char>> &grid, vector<vector<int>> &dist, vector<vector<string>> &move)
{
    int N = grid.size();
    int M = grid[0].size();
    queue<pair<int, int>> q;
    for (auto &p : starts)
    {
        q.push(p);
        dist[p.first][p.second] = 0;
    }
    vector<pair<int, int>> adj = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<char> dirs = {'R', 'L', 'D', 'U'};
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        int y = p.first;
        int x = p.second;
        for (int i = 0; i < 4; ++i)
        {
            int dy = adj[i].second;
            int dx = adj[i].first;
            int nx = x + dx;
            int ny = y + dy;
            if (0 <= nx && nx < M && 0 <= ny && ny < N && grid[ny][nx] == '.' && dist[ny][nx] > dist[y][x] + 1)
            {
                dist[ny][nx] = dist[y][x] + 1;
                move[ny][nx] = dirs[i];
                q.push({ny, nx});
            }
        }
    }
}
void bfs2(vector<pair<int, int>> &starts, vector<vector<char>> &grid, vector<vector<int>> &dist)
{
    int N = grid.size();
    int M = grid[0].size();
    queue<pair<int, int>> q;
    for (auto &p : starts)
    {
        q.push(p);
        dist[p.first][p.second] = 0;
    }
    vector<pair<int, int>> adj = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        int y = p.first;
        int x = p.second;
        for (int i = 0; i < 4; ++i)
        {
            int dx = adj[i].second;
            int dy = adj[i].first;
            int nx = x + dx;
            int ny = y + dy;
            if (0 <= nx && nx < M && 0 <= ny && ny < N && grid[ny][nx] != '#' && dist[ny][nx] > dist[y][x] + 1)
            {
                dist[ny][nx] = dist[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
}

// input processing
int main()
{
    for (int _ = 0; _ < t; ++_)
    {
        int N, M;
        cin >> N >> M;
        vector<vector<char>> grid(N, vector<char>(M));
        vector<pair<int, int>> a_start;
        vector<pair<int, int>> m_start;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                cin >> grid[i][j];
                if (grid[i][j] == 'A')
                {
                    a_start.push_back({i, j});
                }
                if (grid[i][j] == 'M')
                {
                    m_start.push_back({i, j});
                }
            }
        }
        vector<vector<int>> dist1(N, vector<int>(M, INT_MAX));
        vector<vector<string>> moves(N, vector<string>(M, ""));
        bfs(a_start, grid, dist1, moves);
        vector<vector<int>> dist2(N, vector<int>(M, INT_MAX));
        bfs2(m_start, grid, dist2);
        bool flag = false;
        vector<pair<int, int>> cs;
        
        for(auto i:{0,N-1})
        {
            for (int j = 0; j < M; j++)
            {
                if (grid[i][j] != '#' && dist1[i][j] != INT_MAX && dist1[i][j] < dist2[i][j])
                {
                    cs.push_back(make_pair(i, j));
                    flag = true;
                    break;
                }
            }
        }
        if (!flag)
        {
            for(auto j:{0,M-1})
            {
                for (int i = 0; i < N; i++)
                {
                    if (grid[i][j] != '#' && dist1[i][j] != INT_MAX && dist1[i][j] < dist2[i][j])
                    {
                        cs.push_back(make_pair(i, j));
                        flag = true;
                        break;
                    }
                }
            }
        }
        if (!flag)
            cout << "NO" << endl;
        else
        {
            int i = cs[0].first, j = cs[0].second;
            cout << "YES" << endl;
            int si = a_start[0].first, sj = a_start[0].second;
            map<string, pair<int, int>> dxy = {{"L", {1, 0}}, {"R", {-1, 0}}, {"U", {0, 1}}, {"D", {0, -1}}};
            cout << dist1[i][j] << endl;
            if (dist1[i][j] == 0)
                continue;
            string rm = "";
            while (moves[i][j]!="")
            {
                string m = moves[i][j];
                rm += m;
                int dx = dxy[m].first, dy = dxy[m].second;
                i += dy, j += dx;
            }
            reverse(rm.begin(), rm.end());
            cout << rm << endl;
        }
    }
}