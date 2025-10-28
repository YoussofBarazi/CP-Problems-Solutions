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

    ll sum = 1ll * n * (n + 1) / 2;
    if (sum % 2) {
        cout << "NO" << endl;
        return ;
    }

    vector <bool> used(n + 1 , false);
    vector <int> ans1 , ans2;
    ll t = sum / 2;
    
    cout << "YES" << endl;

    for (int i = n ; i >= 1 ; i --) {
        if (t - i >= 0) {
            ans1.push_back(i);
            used[i] = true;
            t -= i;
        }
    }

    for (int i = 1 ; i <= n ; i ++) {
        if (!used[i]) {
            ans2.push_back(i);
        }
    }

    cout << ans1.size() << endl;

    for (int i : ans1) cout << i << ' ';

    cout << endl;
    cout << ans2.size() << endl;

    for (int i : ans2) cout << i << ' ';

}

int main()
{
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}