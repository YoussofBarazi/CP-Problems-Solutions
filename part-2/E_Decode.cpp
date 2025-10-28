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

void solve()
{
    string s;
    cin >> s;

    int psum = 0 , n = s.size();
    int ans = 0 , mod = 1e9 + 7;
    map <int , ll> freq;

    freq[0] = 1;

    for (int i = 0 ; i < n ; i ++)
    {
        psum += s[i] == '1';
        psum -= s[i] == '0';

        ans += freq[psum] * (n - i) % mod;
        ans %= mod;

        freq[psum] += i + 2;
    }

    cout << ans << endl;
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