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

const int N = 1000009;

int parent[N], Size[N];

int get(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = get(parent[v]);
}

bool join(int a, int b)
{
    a = get(a);
    b = get(b);

    if (a == b)
        return false;

    if (Size[a] < Size[b])
        swap(a, b);

    parent[b] = a;

    Size[a] += Size[b];

    return true;
}

void solve()
{
    int n , m;
    cin >> n >> m;

    for (int i = 0 ; i <= n ; i ++)
        parent[i] = i , Size[i] = 1;

    for (int i = 0 ; i < m ; i ++)
    {
        int k;
        cin >> k;

        vector <int> g(k);
        
        for (int i = 0 ; i < k ; i ++)
        {
            cin >> g[i];
        }

        sort(all(g));

        for (int i = 1 ; i < k ; i ++)
        {
            join(g[0] , g[i]);
        }
    }

    for (int i = 1 ; i <= n ; i ++)
    {
        cout << Size[get(i)] << " ";
    }
    cout << endl;
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}

void IO(string name = "") {

	cin.tie(0)->sync_with_stdio(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}

}