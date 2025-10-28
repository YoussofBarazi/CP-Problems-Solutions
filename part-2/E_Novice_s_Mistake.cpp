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

void solve()
{
    int n;
    cin >> n;

    string s = to_string(n) , t = "";  
    int sz = s.size();

    vector <pii> ans;

    for (int a = 1 ; a <= 1e4 ; a ++)
    {
        t += s;

        for (int s = 1 ; s <= 6 ; s ++)
        {
            int b = a * sz - s;

            if (b > 1e4 || b <= 0)
                continue;

            string int_res = to_string(a * n - b);
            string str_res = t.substr(0 , s);

            if (int_res == str_res)
            {
                ans.push_back({a , b});
            }
        }
    }

    cout << ans.size() << endl;

    for (auto x : ans)
        cout << x.F << " " << x.S << endl;
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