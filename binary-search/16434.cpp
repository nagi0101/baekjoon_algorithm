#include <iostream>
#include <stdint.h>

using namespace std;

struct Room
{
    int t;
    int a;
    int h;
};

int N;
int ATK;
Room Rooms[123456 + 1];

// bool b(int64_t hpm)
// {
//     int64_t hp = hpm;
//     int64_t curATK = ATK;
//     for(size_t i = 0; i < N; ++i)
//     {
//         if(Rooms[i].t == 1)
//         {
//             int64_t mhp = Rooms[i].h;
//             while(true)
//             {
//                 mhp -= curATK;
//                 if(mhp <= 0) break;
//                 hp -= Rooms[i].a;
//                 if(hp <= 0) return false;
//             }
//         }
//         else
//         {
//             curATK += Rooms[i].a;
//             hp = min(hp + Rooms[i].h, hpm);
//         }
//     }
//     return true;
// }

bool b(int64_t hpm)
{
    int64_t hp = hpm;
    int64_t curATK = ATK;
    for(size_t i = 0; i < N; ++i)
    {
        if(Rooms[i].t == 1)
        {
            if (((Rooms[i].h - 1) / curATK) > ((hp - 1) / Rooms[i].a))
                    return false;
            hp -= (Rooms[i].h - 1) / curATK * Rooms[i].a;
        }
        else
        {
            curATK += Rooms[i].a;
            hp = min(hp + Rooms[i].h, hpm);
        }
    }
    return true;
}


int main()
{
    cin >> N;
    cin >> ATK;
    for(size_t i = 0; i < N; ++i)
    {
        cin >> Rooms[i].t;
        cin >> Rooms[i].a;
        cin >> Rooms[i].h;
    }

    int64_t l = 1;
    int64_t r = 9e18;
    int64_t ans = r;
    while(l <= r)
    {
        int64_t hpm = (l + r) / 2;

        if(b(hpm))
        {
            ans = hpm;
            r = hpm - 1;
        }
        else
        {
            l = hpm + 1;
        }

    }

    cout << ans << '\n';


    return 0;
}
