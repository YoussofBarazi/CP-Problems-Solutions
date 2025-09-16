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
    suffix_array(string &s)
    {
        s += '$';
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
    bool substr_search(string &t , string &s)
    {
        int l = 0 , r = s.size() - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            string sub = s.substr(p[m] , t.size());
            if (sub == t) return true;
            else if (sub < t) l = m + 1;
            else r = m - 1;
        }
        return false;
    }
    int upper_bound(string &t , string &s)
    {
        int l = 0 , r = s.size() - 1;
        while (l < r)
        {
            int m = (l + r + 1) / 2;
            string sub = s.substr(p[m] , t.size());
            if (sub <= t) l = m;
            else r = m - 1;
        }
        return l;
    }
    int lower_bound(string &t , string &s)
    {
        int l = 0 , r = s.size() - 1;
        while (l < r)
        {
            int m = (l + r) / 2;
            string sub = s.substr(p[m] , t.size());
            if (sub >= t) r = m;
            else l = m + 1;
        }
        return r;
    }
    int substr_count(string &t , string &s)
    {
        if (!substr_search(t , s)) return 0;
        return upper_bound(t , s) - lower_bound(t , s) + 1;
    }
    void build_LCP(string &s)
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
    string s;
    cin >> s;

    suffix_array suf(s);

    int last = 0 , cnt = 1 , ans = 1;

    for (int i = 1 ; i < s.size() ; i ++)
    {
        if (suf.lcp[i] - suf.lcp[i - 1] != last)
        {    
            ans = max(ans , cnt);
            cnt = 2;
            last = suf.lcp[i] - suf.lcp[i - 1];
        }
        else cnt ++;

        cout << last << endl;
    }
    
    ans = max(ans , cnt);

    for (int i = 0 ; i < s.size() ; i ++)
        cout << i << " " << suf.lcp[i] << " "  << suf.p[i] << " " << s.substr(suf.p[i]) << endl; 
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