#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <queue>
#include <stdint.h>
#include <algorithm>
#include <string>

using namespace std;

const int MAX_N = 1001;

int N, M;
int arr[MAX_N][MAX_N] = { 0, };
int visited[MAX_N][MAX_N][2] = { 0, };

struct node
{
    int n;
    int m;
    int b;
};

int bfs()
{
    queue<node> q;
    q.push(node{1, 1, 1});
    visited[1][1][1] = 1;

    while (!q.empty())
    {
        node nd = q.front();
        
        if(nd.n == N && nd.m == M)
        {
            return visited[N][M][nd.b];
        }

        pair<int, int> moveDir[] = {
            pair<int, int>(nd.n, max(nd.m - 1, 1)),
            pair<int, int>(nd.n, min(nd.m + 1, M)),
            pair<int, int>(max(nd.n - 1, 1), nd.m),
            pair<int, int>(min(nd.n + 1, N), nd.m),
        };
        for(int i = 0; i < 4; ++i)
        {
            int n = moveDir[i].first;
            int m = moveDir[i].second;
            if(arr[n][m] == 1 && nd.b == 1)
            {
                visited[n][m][0] = visited[nd.n][nd.m][1] + 1;
                q.push(node{n, m, 0});
            }
            if(arr[n][m] == 0 && visited[n][m][nd.b] == 0)
            {
                visited[n][m][nd.b] = visited[nd.n][nd.m][nd.b] + 1;
                q.push(node{n, m, nd.b});
            }
        }
        q.pop();
    }
    return -1;
}


int main()
{
    scanf("%d %d", &N, &M);
    for(int n = 1; n <= N; ++n)
    {
        for(int m = 1; m <= M; ++m)
        {
            scanf("%1d", &arr[n][m]);
        }
    }

    fill(&visited[0][0][0], &visited[MAX_N - 1][MAX_N - 1][1], 0);

    printf("%d\n", bfs());

    return 0;
}