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

vector <int> ans;
bool ok = false;

void fun(int a, int b) {

    if (a == b) {
        ans.push_back(a);

        cout << "YES" << endl;
        cout << ans.size() << endl;
        for (int i : ans) {
            cout << i << " ";
        }
        cout << endl;
        ok = true;
        return ;
    }

    if (a > b) {
        return ;
    }

    ans.push_back(a);
    fun(a * 2, b);
    fun(a * 10 + 1, b);
    ans.pop_back();
}

void solve()
{
    int a , b;
    cin >> a >> b;

    fun(a, b);

    if (!ok) {
        cout << "NO" << endl;
    }
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