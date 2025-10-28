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

ll calc_score(ll first, ll last, ll size)
{
    return ((first + last) * size) / 2;
}

vector <int> a;
vector <int> b;

ll calc(int x)
{
    ll cnt = 0;
    for (int i = 0 ; i < a.size() ; i ++)
    {   
        ll t = max((a[i] - x + b[i] - 1) / b[i] , 0);
        cnt += t;
    }

    return cnt;
}

void solve()
{
    int n , k;
    cin >> n >> k;

    a.resize(n) , b.resize(n);
    priority_queue <pii> q;

    for (int i = 0 ; i < n ; i ++)
    {
        cin >> a[i];
    }

    for (int i = 0 ; i < n ; i ++)
    {
        cin >> b[i];
    }

    int l = 0 , r = *max_element(all(a));

    while (l < r)
    {
        int m = (l + r) / 2;

        if (calc(m) <= k)
            r = m;
        else 
            l = m + 1;
    }

    int x = l;
    ll score = 0;

    for (int i = 0 ; i < n ; i ++)
    {
        ll t = max((a[i] - x + b[i] - 1) / b[i] , 0);

        score += calc_score(a[i] , a[i] - (t - 1) * b[i] , t);        
        
        a[i] -= t * b[i];
        
        q.push({a[i] , b[i]});

        k -= t;
    }

    q.push({0 , -1});

    while (!q.empty() && k > 0)
    {
        pii t = q.top();
        q.pop();

        if (t.F <= 0)
            break;

        score += t.F;
        
        t.F -= t.S;
        k --;
        q.push(t);
    }

    cout << score << endl;
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