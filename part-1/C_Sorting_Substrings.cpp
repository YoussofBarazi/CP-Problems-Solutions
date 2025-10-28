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
    vector<int> p , c , logs;
    vector<pair<char, int>> t;
    vector <vector<int>> C;
    suffix_array(string &s)
    {
        s += '$';
        n = s.size();
        p.resize(n) , c.resize(n) , t.resize(n) , logs.resize(n + 1 , 0);
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
    int lower_bound(int i , int len , string &s)
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
    int compare(int i, int j, int len) 
    {
        int k = logs[len];
        pair<int, int> a = {C[k][i] , C[k][(i + len - (1 << k)) % n]};
        pair<int, int> b = {C[k][j] , C[k][(j + len - (1 << k)) % n]};
        return a == b ? 0 : a < b ? -1 : 1;
    }
};


void solve()
{
    string s; int n;
    cin >> s >> n;

    suffix_array suf(s);
    
    vector <array<int , 4>> x;

    while (n --)
    {
        int l , r;
        cin >> l >> r;

        l -- , r --;

        x.push_back({suf.lower_bound(l , r - l + 1 , s) , r - l + 1 , l , r});
    }

    sort(all(x));

    for (auto t : x)
        cout << t[2] + 1 << " " << t[3] + 1 << endl;
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