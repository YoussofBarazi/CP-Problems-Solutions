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

const int N = 1000009;

vector <bool> done(N , false);
vector <int> new_val(N , 1e9);
void solve()
{
    int n;
    cin >> n;

    vector <int> a(n);
    for (auto &x : a)
    {    
        cin >> x;
        new_val[x] = x;
    }

    sort(all(a));
    done.assign(N , false);

    for (int x : a)
    {
        if (!done[x])
            for (int j = x ; j < N ; j += x)
            {
                if (!done[j])
                    new_val[j] = x;
                
                done[j] = true;
            }
    }

    ll sum = 0;

    for (int x : a)
    {
        sum += new_val[x];
    }

    cout << sum << endl;
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;
    cin >> t;

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