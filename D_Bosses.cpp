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

const int N = 300009;

int boss[N] , ans[N] , r[N];

int find(int u)
{
    return boss[u] = (boss[u] == u)? u : find(boss[u]);
}

void join(int u , int v)
{
    u = find(u);
    v = find(v);

    if (u == v)
        return ;

    if (r[u] == r[v])
        r[u] ++;

    if(r[u] < r[v])
        swap(u , v);

    boss[v] = u;
    ans[v] += 1 - ans[u]; 
}

int calc(int c)
{
    return (c == boss[c])? 0 : ans[c] + calc(boss[c]);
}

void solve()
{
    int n , m;
    scanf("%d%d" , &n , &m);

    for (int i = 1 ; i <= n ; i ++)
        boss[i] = i;

    while (m --)
    {
        int t;
        scanf("%d" , &t);

        if (t == 1)
        {
            int a , b;
            cin >> a >> b;

            join(b , a);
        }
        else 
        {
            int c;
            cin >> c;

            printf("%d\n" , calc(c));
        }
    }
}

int main()
{
    // IO("name");
    // IOS;

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