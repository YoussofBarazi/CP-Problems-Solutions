#include   <bits/stdc++.h>
#define ll       long long
#define vi     vector<int>
#define vl      vector<ll>
#define pii pair<int, int>
#define pll   pair<ll, ll>
#define pb       push_back
#define F            first
#define S           second
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

int par[N] , sz[N] , son[N];

int find(int a)
{
    return ((par[a] == a)? a : find(par[a]));
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
    par[b] = a;
    son[a] = b;
}

void solve()
{
    int n , m;
    cin >> n >> m;

    vector <pii> monkey(n + 1 , {-1 , -1});

    for(int i = 1 ; i <= n ; i ++)
    {
        int l , r;
        cin >> l >> r;

        monkey[i] = {l , r};
    }

    vector <pii> query(m);
    
    int sec = m;

    while (m --)
    {
        int p , h;
        cin >> p >> h;

        query[m] = {p , h};
    }

    vector <int> ans(n + 1 , -1);

    for(int i = 1 ; i <= n ; i ++)
        son[i] = par[i] = i , sz[i] = 1;
    sz[1] = 1e6;

    vector <pii> rel(n + 1 , {false , false});  

    for (auto q : query)
        if (q.S == 1)
            rel[q.F].F = true;
        else 
            rel[q.F].S = true;

    for (int i = 1 ; i <= n ; i ++)
    {
        if (!rel[i].F)
            join(monkey[i].F , i);
        if (!rel[i].S)
            join(monkey[i].S , i);
    }

    for (auto q : query)
    {
        sec--;

        int m = q.F;

        if (q.S == 1 && monkey[q.F].F > -1)
        {
            if (m == 1 || ans[m] != -1)
                m = monkey[q.F].F;

            join(q.F , monkey[q.F].F);
        }
        else if (monkey[q.F].S > -1)
        {
            if (m == 1 || ans[m] != -1)
                m = monkey[q.F].S;
             
            join(q.F , monkey[q.F].S);
        }

        if (find(m) == 1)
        {    
            ans[m] = max(sec , ans[m]);

            int x = m;
            while (son[x] != x)
            {
                ans[x] = max(sec , ans[x]);

                x = son[x];
            }
            ans[x] = max(sec , ans[x]);
        }
    }

    for (int i = 1 ; i <= n ; i ++)
        cout << ans[i] << endl;
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