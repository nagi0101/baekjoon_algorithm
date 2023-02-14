#include <iostream>
#include <stdint.h>

using namespace std;

#define MAX_K 10001

int K;
int N;
int L[MAX_K];

int main()
{
    cin >> K;
    cin >> N;
    int maxN = 0;
    for(size_t i = 0; i < K; ++i)
    {
        cin >> L[i];
        maxN = max(maxN, L[i]);
    }


    int64_t m = 1;
    int64_t l = maxN;
    int64_t res = maxN;
    while(m <= l)
    {   
        int64_t f = (m + l) / 2;
        
        int64_t n = 0;
        for(size_t i = 0; i < K; ++i)
        {
            n += L[i] / f;
        }

        if(n >= N)
        {
            m = f + 1;
            res = f;
        }
        else
        {
            l = f - 1;
        }
    }

    cout << res << '\n';

    return 0;
}