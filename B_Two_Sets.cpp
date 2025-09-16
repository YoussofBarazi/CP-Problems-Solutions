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

int par[N];

int find(int a)
{
    return par[a] = (par[a] == a)? a : find(par[a]);
}

void join(int a , int b)
{
    a = find(a);
    b = find(b);

    if (a == b)
        return ;

    par[a] = b;
}

void solve()
{
    int n , a , b;
    cin >> n >> a >> b;

    vector <int> p(n + 1);
    map <int , int> ex;

    for (int i = 1 ; i <= n ; i ++)
    {
        cin >> p[i];

        ex[p[i]] = i;
    }

    for (int i = 1 ; i <= n + 2 ; i ++)
        par[i] = i;

    for (int i = 1 ; i <= n ; i ++)
    {
        int ndx = ex[a - p[i]];

        if (par[i] != i)
            continue;

        if (ndx == 0 || ndx == i || par[ndx] != ndx)
        {
            ndx = ex[b - p[i]];

            if (ndx != 0 && ndx != i && par[ndx] == ndx)
            {    
                join(ndx , n + 2);
                join(i , n + 2);
            }
        }
        else 
        {
            join(ndx , n + 1);
            join(i , n + 1);
        }

        if (par[i] == i)
        {
            cout << "NO" << endl;
            return ; 
        }
    }

    cout << "YES" << endl;

    for (int i = 1 ; i <= n ; i ++)
    {
        if (par[i] == n + 1)
            cout << "0 ";
        else 
            cout << "1 ";
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