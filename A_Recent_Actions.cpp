#include <bits/stdc++.h>
#define vi vector<int>
#define ll long long
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define oo INT_MAX
#define OO LONG_MAX
#define pb push_back
#define F first
#define S second
#define Sort(a) sort(a.begin(), a.end())
#define Rsort(a) sort(a.rbegin(), a.rend())
#define UB(a, t) upper_bound(a.begin(), a.end(), t) - a.begin()
#define LB(a, t) lower_bound(a.begin(), a.end(), t) - a.begin()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

void solve()
{
    int n , m;
    cin >> n >> m;

    deque <int> s;
    set <int> exist;
    vi a(n + 1);
    for (size_t i = 1; i <= n; i++)
    {
        s.push_back(i);
        exist.insert(i);
        a[i] = -1;
    }
    
    for (size_t i = 0; i < m; i++)
    {
        int p;
        cin >> p;

        if (exist.find(p) == exist.end()) s.push_front(p) , a[(s.back() <= n)? s.back() : 0] = i + 1 , exist.erase(s.back()) , s.pop_back() , exist.insert(p);
    }
    for (int i = 1 ; i <= n ; i ++) cout << a[i] << " ";
    cout << endl;
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