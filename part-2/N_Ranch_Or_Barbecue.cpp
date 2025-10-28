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

const int N = 10000009;

int GPF[N];
int index[N];

void precalc()
{
    int cnt = 0;
    GPF[0] = 0 , GPF[1] = 0;

    for (int i = 2 ; i < N ; i ++)
        if (!GPF[i])
        {    
            for (int j = i ; j < N ; j += i)
                GPF[j] = i , index[j] = cnt;
            
            cnt ++;
        }
}

void solve()
{
    precalc();

    int n , d;
    cin >> n >> d;

    vector <int> a(n);
    for (auto &x : a)
        cin >> x;

    ll r = 0 , b = 0;

    for (int i = 0 ; i < d ; i ++)
    {
        int ndx = i % n;
        
        if (index[GPF[a[ndx]]] % 2)
            r += GPF[a[ndx]];
        else
            b += GPF[a[ndx]];

        a[ndx] /= ((GPF[a[ndx]] > 0) ? GPF[a[ndx]] : 1);

        if (b >= r)
            cout << "R" << endl;
        else 
            cout << "B" << endl;
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