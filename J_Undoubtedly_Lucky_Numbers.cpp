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

int n;

int count(int x, int y, ll num) {

    int cnt = 0;

    if (num * 10 + x <= n && !(num == 0 && x == 0)){
        cnt += count(x, y, num * 10 + x) + 1;
    }

    if (num * 10 + y <= n) {
        cnt += count(x, y, num * 10 + y) + 1;
    }

    return cnt;
}

int O_O(int x) {

    if (x == 0) {
        return 0;
    }
    
    int cnt = 0;
    ll num = 0;

    while (num * 10 + x <= n) {
        num = num * 10 + x;
        cnt ++;
    }

    return cnt;
}

void solve()
{
    cin >> n;

    int ans = 0;
    vector <int> c(10, 0);

    for (int i = 0 ; i < 10 ; i ++) {
        c[i] = O_O(i);
    }

    for (int x = 0 ; x <= 9 ; x ++) {
        for (int y = x + 1 ; y <= 9 ; y ++) {
            ans += count(x, y, 0) - c[x] - c[y]; 
        }

        ans += c[x];
    }

    cout << ans << endl;
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