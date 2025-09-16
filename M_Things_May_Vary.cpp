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

const int N = 1000009;

ll a[N];
ll mx[N] , mx2[N] , mn[N] , mn2[N];
int mx_freq[N];
vector <map<ll , int>> freq(N);
vector <int> adj[N];
tuple <ll , ll , int> ans (-1 , 1 , 0);
bool inf = false;

void dfs (int u , int p) {
    freq[u][a[u]]++;
    mx_freq[u] = 1;
    mn[u] = mx[u] = a[u];
    mn2[u] = LLONG_MAX;
    mx2[u] = LLONG_MIN;

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v , u);

        if (mn[u] < mn[v]) {
            mn2[u] = min(mn2[u] , mn[v]);
        } else {
            mn2[u] = min(mn[u] , mn2[v]);
        }

        if (mx[u] > mx[v]) {
            mx2[u] = max(mx[v] , mx2[u]);
        } else {
            mx2[u] = max(mx[u] , mx2[v]);
        }

        mn[u] = min(mn[u] , mn[v]);
        mx[u] = max(mx[u] , mx[v]);

        if (freq[u].size() < freq[v].size()) {
            swap(freq[u] , freq[v]);
            swap(mx_freq[u] , mx_freq[v]);
        }

        for (auto [k , val] : freq[v]) {
            mx_freq[u] = max(mx_freq[u] , freq[u][k] += val);
        }
    }

    ll x = (mn2[u] == LLONG_MAX)? 0 : mx_freq[u];
    ll y = (mx2[u] == LLONG_MIN)? 1 : (mx[u] - mx2[u]) ^ (mn2[u] - mn[u]);

    auto [a , b , v] = ans;

    if (y == 0) {
        inf = true;
    } else {
        if (x * b > a * y) ans = {x , y , u};
        else if (x * b == a * y) ans = {x , y , min(u , v)};
    }
}

void solve()
{
    int n;
    cin >> n;

    ans = {-1 , 1 , 0};
    inf = false;
    for (int i = 0 ; i <= n ; i ++) {
        freq[i].clear();
        adj[i].clear();
    }

    for (int i = 2 ; i <= n ; i ++) {
        int j;
        cin >> j;

        adj[j].push_back(i);
    }

    for (int i = 1 ; i <= n ; i ++) {
        cin >> a[i];
    }

    dfs(1 , 0);

    if (inf) cout << "Inf" << endl;
    else cout << get<2>(ans) << endl;
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