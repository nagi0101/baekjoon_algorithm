#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX_N = 1001;
const int MAX_M = 10001;

int N;
int M;
int V;

vector<int> adj[MAX_N];

bool dvisited[MAX_N] = { 0, };
bool bvisited[MAX_N] = { 0, };


void dfs(int v)
{
    cout << v << ' ';
    dvisited[v] = true;
    for(int i : adj[v])
    {
        if(dvisited[i] == false)
        {
            dfs(i);
        }
    }
}

void bfs(int v)
{
    queue<int> q;
    q.push(v);
    bvisited[v] = true;
    while(!q.empty())
    {
        int n = q.front();
        cout << n << ' ';
        for(int i : adj[n])
        {
            if(bvisited[i] == false)
            {
                q.push(i);
                bvisited[i] = true;
            }
        }
        q.pop();
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> V;
    for(int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= N; ++i)
    {
        auto v = adj[i];
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(V);
    cout << '\n';
    bfs(V);

    return 0;
}