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

struct suffix_array 
{
    int n;
    vector<int> p, c, lcp , logs;
    vector<pair<char, int>> t;
    vector <vector<int>> C;
    suffix_array(vector <int> &s)
    {
        s.push_back(0);
        n = s.size();
        p.resize(n) , c.resize(n) , t.resize(n) , lcp.resize(n , 0) , logs.resize(n + 1 , 0);
        for (int i = 0; i < n; i++) t[i] = {s[i], i};
        sort(t.begin() , t.end());
        for (int i = 0; i < n; i++) p[i] = t[i].S;
        c[p[0]] = 0;
        for (int i = 1; i < n; i++) c[p[i]] = c[p[i - 1]] + (t[i].F != t[i - 1].F);
        C.push_back(c);
        int k = 0;
        while ((1 << k) < n)
        {
            for (int i = 0 ; i < n ; i ++) p[i] = (p[i] - (1 << k) + n) % n;
            count_sort(p , c);
            vector <int> c_new(n);       
            c_new[p[0]] = 0;
            for (int i = 1; i < n; i++)
            {
                pair<int, int> now  = {c[p[i]]     , c[(p[i]     + (1 << k)) % n]};
                pair<int, int> prev = {c[p[i - 1]] , c[(p[i - 1] + (1 << k)) % n]};
                
                c_new[p[i]] = c_new[p[i - 1]];
                c_new[p[i]] += (now != prev);
            }
            c = c_new;
            C.push_back(c);
            k++;
        }
        build_LCP(s);
        for (int i = 1 ; i <= n ; i ++)
        {
            logs[i] = log2(i);
        }
    }
    void count_sort(vector <int> &p , vector <int> &c)
    {
        vector <int> cnt(n);
        for (auto x : c) cnt[x] ++;
        vector<int> p_new(n);
        vector <int> pos(n);
        pos[0] = 0;
        for (int i = 1 ; i < n ; i ++) pos[i] = pos[i - 1] + cnt[i - 1];
        for (auto x : p)
        {
            int i = c[x];
            p_new[pos[i]] = x;
            pos[i]++;
        }
        p = p_new;
    }
    int upper_bound(int i , int len , vector <int> &s)
    {
        int l = 0 , r = s.size() - 1;
        while (l < r)
        {
            int m = (l + r + 1) / 2;
            if (compare(i , p[m] , len) >= 0) l = m;
            else r = m - 1;
        }
        return l;
    }
    int lower_bound(int i , int len , vector <int> &s)
    {
        int l = 0 , r = s.size() - 1;
        while (l < r)
        {
            int m = (l + r) / 2;
            if (compare(i , p[m] , len) <= 0) r = m;
            else l = m + 1;
        }
        return r;
    }
    int substr_count(int i , int len , vector <int> &s)
    {
        return upper_bound(i , len , s) - lower_bound(i , len , s) + 1;
    }
    void build_LCP(vector <int> &s)
    {
        int k = 0;
        for (int i = 0 ; i < n - 1 ; i ++)
        {
            int pos = c[i];
            int j = p[pos - 1];
            while (s[i + k] == s[j + k]) k ++;
            lcp[pos] = k;
            k = max(k - 1 , 0);
        }
    }
    int compare(int i, int j, int l) 
    {
        int k = logs[l];
        pair<int, int> a = {C[k][i] , C[k][(i + l - (1 << k)) % n]};
        pair<int, int> b = {C[k][j] , C[k][(j + l - (1 << k)) % n]};
        return a == b ? 0 : a < b ? -1 : 1;
    }
};

void solve()
{
    int n , m;
    cin >> n >> m;

    vector <int> a(n);
    for (auto &x : a)
        cin >> x;

    suffix_array suf(a);

    vector <int> pos = {-1};
    
    for (int i = 1 ; i < n ; i ++)
    {
        if (suf.lcp[i] == 0)
            pos.push_back(i);
    }

    pos.push_back(n);
    ll mx = n , l = 0 , r = n - 1;
    for (int i = 1 ; i < pos.size() ; i ++)
    {
        for (int j = pos[i - 1] + 1 ; j < pos[i] ; j ++)
        {
            if (1ll * suf.substr_count(suf.p[j] , suf.lcp[j + 1] , a) * suf.lcp[j + 1] > mx)
            {    
                mx = 1ll * suf.substr_count(suf.p[j] , suf.lcp[j + 1] , a) * suf.lcp[j + 1];
                l = suf.p[j] , r = suf.p[j] + suf.lcp[j + 1] - 1;
            }
        }
    }

    cout << mx << endl;
    cout << r - l + 1 << endl;
    for (int i = l ; i <= r ; i ++)
        cout << a[i] << " ";
    cout << endl;
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