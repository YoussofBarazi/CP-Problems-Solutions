#include <bits/stdc++.h>

#define F first
#define S second
#define ll long long
#define pb push_back
#define vl vector<ll>
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
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

    vector <int> a(n);
    int cnt_odd = 0;
    for (auto &x : a) {
        cin >> x;

        cnt_odd += x % 2;
    }

    if (cnt_odd > 0) {
        cout << n - cnt_odd << endl;
        return ;
    }

    int mn = INT_MAX;

    for (int i = 0 ; i < n ; i ++) {

        int c = 0;

        while (a[i] % 2 == 0) {
            a[i] /= 2;
            c ++;
        }

        mn = min(mn, c);
    }

    cout << mn + n - 1 << endl;
}

int main()
{
    IOS;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}