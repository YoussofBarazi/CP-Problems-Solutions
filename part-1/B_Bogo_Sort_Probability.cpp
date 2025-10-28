#include <bits/stdc++.h>

#define F first
#define S second
#define ll long long
#define pb push_back
#define vl vector<ll>
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

const int N = 200009;

int mod = 1e9 + 7;
int inv(int i)
{
    return i <= 1 ? i : mod - (long long)(mod / i) * inv(mod % i) % mod;
}

void solve()
{
    int n , m;
    cin >> n >> m;

    vector <int> a(n);
    map <int , int> freq;

    for (auto &x : a)
    {    
        cin >> x;
        freq[x]++;
    }

    vector <ll> fact(n + 1 , 1);

    for (int i = 2 ; i <= n ; i ++)
    {
        fact[i] = fact[i - 1] * i % mod;
    }

    
}

int main()
{
    IOS;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}