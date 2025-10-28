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

const int N = 200009;

void solve()
{
    int n , a , b;
    cin >> n >> a >> b;

    vector <int> p(n);

    for (auto &x : p)
        cin >> x;

    vector <int> predator(n , 0) , prey(n , 0);

    for (int i = 0 ; i < n ; i ++)
    {
        for (int j = 0 ; j < n ; j ++)
        {
            if (p[i] - p[j] >= a && p[i] - p[j] < b)
                prey[i]++;
            else if (p[j] - p[i] >= a && p[j] - p[i] < b)
                predator[i] ++;
        }
    }

    for (int i = 0 ; i < n ; i ++)
        cout << predator[i] << " " << prey[i] << endl;
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