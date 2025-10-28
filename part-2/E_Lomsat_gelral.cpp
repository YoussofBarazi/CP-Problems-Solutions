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

struct T {
    // int sum, mx;
    map<int , int> freq;
};

vector <int> adj[N];
int c[N];
vector <map<int , int>> mp(N);
vector <ll> sum(N , 0);
vector <int> mx(N , 0);

void dfs(int u , int p) {
    mp[u][c[u]] ++;
    mx[u] = 1;
    sum[u] = c[u];

    for (int v : adj[u]) {
        if (v == p) continue;

        dfs(v , u);

        if (mp[u].size() < mp[v].size()) {
            swap(mp[u] , mp[v]);
            sum[u] = sum[v];
            mx[u] = mx[v];
        }

        for (auto [k , val] : mp[v]) {
            int x = mp[u][k] += val;
            if (mx[u] < x) {
                mx[u] = x;
                sum[u] = k;
            } else if (mx[u] == x) {
                sum[u] += k;
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 1 ; i <= n ; i ++) {
        cin >> c[i];
    }

    for (int i = 0 ; i < n - 1 ; i ++) {
        int a , b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1 , 0);

    for (int i = 1 ; i <= n ; i ++) {
        cout << sum[i] << " ";
    }
    cout << endl;
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