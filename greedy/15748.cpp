#include <iostream>
#include <stdint.h>
#include <vector>
#include <algorithm>

using namespace std;

int32_t L, N, rf, rb;
vector<pair<int32_t, int32_t>> v;

bool comp(const pair<int32_t, int32_t> &a, const pair<int32_t, int32_t> &b)
{
    if(a.first > b.first)
    {
        return a.second > b.second;
    }
    return a.second > b.second;
}

int main()
{
    cin >> L;
    cin >> N;
    cin >> rf;
    cin >> rb;

    for(int i=0; i < N; ++i)
    {
        pair<int32_t, int32_t> p;
        cin >> p.first;
        cin >> p.second;
        v.push_back(p);
    }

    sort(v.begin(), v.end(), comp);

    int32_t lp = 0;
    int64_t s = 0;
    for(auto iter = v.begin(); iter != v.end(); ++iter)
    {
        if(lp >= iter->first) continue;

        s += (int64_t)(iter->second) * (iter->first - lp) * (rf - rb);
        lp = iter->first;
    }
    cout << s << endl;

    return 0;
}