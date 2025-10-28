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

    vector <pii> p(n);
    for (int i = 0 ; i < n ; i ++)
    {
        cin >> p[i].F;
        p[i].S = i;
    }

    sort(all(p));

    vector <int> predator(n , 0) , prey(n , 0);

    for (int i = 0 ; i < n ; i ++)
    {
        pii x = {p[i].F - b + 1 , 0};
        int ind1 = lower_bound(all(p) , x) - p.begin();
        x = {p[i].F - a + 1 , 0};
        int ind2 = lower_bound(all(p) , x) - p.begin();

        //cout << ind1 << " " << ind2 << endl;

        prey[p[i].S] = ind2 - ind1;

        x = {p[i].F + b , 0};
        ind2 = lower_bound(all(p) , x) - p.begin();
        x = {p[i].F + a , 0};
        ind1 = lower_bound(all(p) , x) - p.begin();

        predator[p[i].S] = ind2 - ind1 + 1 - (ind2 == n || p[ind2].F >= p[i].F + b);
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