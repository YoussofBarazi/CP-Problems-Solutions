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

const int N = 25;

int k[N];
int n;
ll ans = 1e15 , total = 0;

void bruteforce(int i = 0 , ll s = 0) {
    if (i == n) {
        ans = min({ans , max(s , total - s)});
        return ;
    }

    bruteforce(i + 1 , s + k[i]);
    bruteforce(i + 1 , s);
}

void solve()
{
    cin >> n;

    for (int i = 0 ; i < n ; i ++) {
        cin >> k[i];
        total += k[i];
    }

    bruteforce();

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