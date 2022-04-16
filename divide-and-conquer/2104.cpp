#include <iostream>
#include <algorithm>

using namespace std;

long long int key(int A[], int N, int i, int j)
{
    if(i==j)
    {
        return (long long int) A[i] * (long long int) A[i];
    }
    
    int mid = (i + j) / 2;
    long long int result = max(key(A, N, i, mid), key(A, N, mid+1, j));

    int l=mid, r=mid, minh=A[mid];
    long long int rs=A[mid];
    while(r-l <= j-i)
    {
        int qh = i < l ? min(minh, A[l-1]) : minh;
        int ph = r < j ? min(minh, A[r+1]) : minh;

        long long int qs = i < l ? rs + A[l-1] : rs;
        long long int ps = r < j ? rs + A[r+1] : rs;
        
        long long int q = qs * qh;
        long long int p = ps * ph;

        if(q > p)
        {
            l--;
            minh=qh;
            rs=qs;
        }
        else
        {
            r++;
            minh=ph;
            rs=ps;
        }
        result = max(result, max(p, q));
    }
    return result;
}

int main()
{
    int A[100000];
    int N;
    int i, j;

    cin >> N;
    for(int i=0; i<N; i++)
        cin >> A[i];
    
    long long int r = key(A, N, 0, N-1);

    cout << r << endl;
    
    return 0;
}