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
    set <int> done; 

    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }

    sort(allr(a));
    int cnt = 0;

    for (int i = 0 ; i < n ; i ++) {
        
        if (a[i] % 2) continue;

        while (done.find(a[i]) == done.end() && a[i] % 2 == 0) {
            done.insert(a[i]);
            a[i] /= 2;
            cnt ++;
        }
    }
    
    cout << cnt << endl;
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