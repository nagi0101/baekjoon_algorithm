#include <iostream>
#include <string>
#include <stack>


using namespace std;

const int MAX_S = 100001;

int N;

int main()
{
    int ans = 0;

    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        string s;
        cin >> s;

        stack<char> st;
        for(char c : s)
        {
            if(st.empty() || st.top() != c)
            {
                st.push(c);
            }
            else
            {
                st.pop();
            }
        }
        if(st.empty())
        {
            ++ans;
        }
    }

    cout << ans << '\n';

    return 0;
}