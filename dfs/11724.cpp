#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1001;

int N, M;
vector<int> adj[MAX_N];
bool visited[MAX_N];

void dfs(int node)
{
    visited[node] = true;
    for(int i : adj[node])
    {
        if(visited[i] == false)
        {
            dfs(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    cin >> M;
    for(int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u;
        cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    fill(visited, visited + N, false);

    int ans = 0;
    for(int i = 1; i <= N; ++i)
    {
        if(visited[i] == false) 
        {
            ans++;
            dfs(i);
        }
    }

    cout << ans << '\n';

    return 0;
}