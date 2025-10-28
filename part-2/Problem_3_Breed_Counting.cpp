#include <bits/stdc++.h>
#define vi vector<int>
#define ll long long
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define oo INT_MAX
#define OO LONG_MAX
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allrev(v) v.rbegin(), v.rend() 
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

void solve()
{
    int n , q;
    cin >> n >> q;

    int a , b , c;
    a = b = c = 0;

    vi s1(n + 1 , 0) , s2(n + 1 , 0) , s3(n + 1 , 0);
    for (size_t i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        if (x == 1) a ++;
        else if (x == 2) b ++;
        else c ++;
        s1[i] = a;
        s2[i] = b;
        s3[i] = c;
    }
    
    for (size_t i = 0; i < q; i++)
    {
        int l , r;
        cin >> l >> r;

        cout << s1[r] - s1[l - 1] << " "
         << s2[r] - s2[l - 1] << " "
         << s3[r] - s3[l - 1] << endl;
    }
}

int main()
{
    //IOS;
    freopen("bcount.in","r",stdin);
	freopen("bcount.out","w",stdout);

    int t = 1;
    //cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}