#include <iostream>

using namespace std;

const int MAX_N = 1001;

int N;
int dp[MAX_N] = { 0, };

int main()
{
    cin >> N;

    dp[1] = 1;
    dp[2] = 3;
    for(int n = 3; n <= N; ++n)
    {
        dp[n] = dp[n - 2] * 2 + dp[n - 1];
        dp[n] %= 10007;
    }

    cout << dp[N] << '\n';
    return 0;
}