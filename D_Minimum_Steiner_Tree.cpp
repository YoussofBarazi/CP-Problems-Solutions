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

vector <int> adj[N];
set <int> s;
int ans = 0;
bool DFS(int u, int par) {
    bool exist = false;
    if (s.count(u)) {
        s.erase(u);
        exist = true;
    } 

    for (auto v : adj[u]) {
        if (v == par) {
            continue;
        }
        bool f = DFS(v, u);
        ans = ans + f;
        exist |= f;
    }

    return exist;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0 ; i < n - 1 ; i ++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0 ; i < k ; i ++) {
        int v;
        cin >> v;

        s.insert(v);
    }
    DFS(*s.begin(), -1);
    cout << ans + 1 << endl;
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