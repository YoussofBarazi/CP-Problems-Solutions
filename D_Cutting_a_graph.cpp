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

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

const int N = 50009;

int parent[N] , sz[N];

int find(int a)
{
    if (parent[a] == a)
        return a;
    return parent[a] = find(parent[a]);
}

void join(int a , int b)
{
    a = find(a);
    b = find(b);

    if (a == b)
        return ;

    if (sz[a] < sz[b])
        swap(a , b);

    sz[a] += sz[b];
    parent[b] = a;
}

void solve()
{
    int n , m , k;
    cin >> n >> m >> k;

    for (int i = 1 ; i <= n ; i ++)
        parent[i] = i , sz[i] = 1;
    
    while (m --)
    {
        int u , v;
        cin >> u >> v;
    }

    vector <array<int , 3>> query;

    while (k --)
    {
        string s; int u , v;
        cin >> s >> u >> v;

        query.push_back({s == "cut" , u , v});
    }

    reverse(all(query));

    vector <string> ans;

    for (auto q : query)
    {
        if (q[0])
        {
            join(q[1] , q[2]);
        }
        else 
        {
            if (find(q[1]) == find(q[2]))
                ans.push_back("YES");
            else 
                ans.push_back("NO");
        }
    }

    reverse(all(ans));

    for (auto x : ans)
        cout << x << endl;
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