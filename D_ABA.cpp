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

    int n = s.size();
    vector <vector<int>> freq(n , vector <int> (26 , 0));

    for (int i = 0 ; i < n ; i ++) {
        freq[i][s[i] - 'A']++;
    }
    for (int c = 0 ; c < 26 ; c ++) {
        for (int i = 1 ; i < n ; i ++) {
            freq[i][c] += freq[i - 1][c];
        }
    }

    ll ans = 0;

    for (int i = 1 ; i < n - 1 ; i ++) {
        for (int c = 0 ; c < 26 ; c ++) {
            ans += 1ll * freq[i - 1][c] * (freq[n - 1][c] - freq[i][c]);
        }
    }

    cout << ans << endl;
}

int main()
{
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}