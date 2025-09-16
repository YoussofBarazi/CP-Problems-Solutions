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
    vector<int> p, c, lcp;
    vector<pair<char, int>> t;
    suffix_array(string &s)
    {
        s += '$';
        n = s.size();
        p.resize(n) , c.resize(n) , t.resize(n) , lcp.resize(n , 0);
        for (int i = 0; i < n; i++) t[i] = {s[i], i};
        sort(t.begin() , t.end());
        for (int i = 0; i < n; i++) p[i] = t[i].S;
        c[p[0]] = 0;
        for (int i = 1; i < n; i++) c[p[i]] = c[p[i - 1]] + (t[i].F != t[i - 1].F);
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
            k++;
        }
        build_LCP(s);
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
};

void solve()
{
    string s , t;
    cin >> s >> t;

    int sz = s.size();
    s = s + '%' + t;

    suffix_array suf(s);

    int l = 0 , max_sz = 0;

    for (int i = 1 ; i < suf.n ; i ++)
    {
        if (suf.lcp[i] > max_sz && (suf.p[i - 1] > sz != suf.p[i] > sz))
            max_sz = suf.lcp[i] , l = suf.p[i];
    }

    cout << s.substr(l , max_sz) << endl; 
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