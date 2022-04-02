#include <iostream>

using namespace std;

long long int pow(int a, int b, int c)
{
    if(b==1)
        return (a % c);
    
    long long int p = pow(a, b/2, c) % c;

    int r = b % 2;
    if (r==0)
    {
        return (p * p) % c;
    }
    return ((p * p) % c) * (a % c) % c;
}

int main()
{
    int a, b, c;

    cin >> a >> b >> c;

    long long int m = pow(a, b, c);

    cout << m << endl;
    
    return 0;
}