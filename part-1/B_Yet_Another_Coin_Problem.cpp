#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

vector<int> a = {15 , 10 , 6 , 3 , 1};

int O_O(int i, int n)
{
    if (n == 0)
        return 0;
    if (i == 5)
        return n;

    int ans = min(O_O(i + 1, n % a[i]) + n / a[i] , O_O(i + 1, n));

    if (n / a[i] > 1)
        ans = min(ans , O_O(i + 1 , n % a[i] + a[i]) + n / a[i] - 1);

    return ans;
}

void solve()
{
    int n;
    cin >> n;

    ll ans = O_O(0 , n);

    cout << ans << endl;
}

int main()
{


    // IO("name");
    IOS;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}

void IO(string name = "")
{

    cin.tie(0)->sync_with_stdio(0);
    if (name.size())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}