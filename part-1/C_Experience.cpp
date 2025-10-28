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

const int N = 200009;

int parent[N] , sz[N];
ll XP[N];

int get(int a)
{
    if (parent[a] == a)
        return a;

    return get(parent[a]);
}

void join(int a , int b)
{    
    a = get(a);
    b = get(b);
 
    if (a == b)
        return ;

    if (sz[a] < sz[b])
        swap(a , b);

    XP[b] -= XP[a];
    sz[a] += sz[b];
    parent[b] = a;
}

void solve()
{
    int n , m;
    cin >> n >> m;

    for (int i = 0 ; i <= n ; i ++)
        parent[i] = i , sz[i] = 1;

    while (m --)
    {
        string s; int x;
        cin >> s >> x;

        if (s == "join")
        {
            int y;
            cin >> y;

            join(x , y);
        }
        else if (s == "add")
        {
            int v;
            cin >> v;

            XP[get(x)] += v;
        }
        else 
        {
            ll ans = 0;

            while (parent[x] != x)
            {
                ans += XP[x];
                x = parent[x];    
            }

            ans += XP[x];

            cout << ans << endl;
        }
    }
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