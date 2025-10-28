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

    int ans = 0;

    vector <pii> v;

    for (int i = 0 ; i < 26 ; i ++) {
        v.push_back({s[i] , i});
    }
    sort(all(v));

    for (int i = 1 ; i < 26 ; i ++) {
        ans += abs(v[i].S - v[i - 1].S);
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