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
    int n;
    cin >> n;

    vector <ll> a(n + 1 , 0);
    for (int i = 1 ; i <= n ; i ++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    string s;
    cin >> s;

    s = '*' + s;

    ll ans = 0;

    stack <int> st;

    for (int i = 1 ; i <= n ; i ++)
        if (s[i] == 'R')
            st.push(i);

    for (int i = 1 ; i <= n ; i ++)
        if (s[i] == 'L' && st.size() && st.top() >= i)
            ans += a[st.top()] - a[i - 1] , st.pop();

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