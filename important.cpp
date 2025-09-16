#include <bits/stdc++.h>
#define vi vector<int>
#define ll long long
#define vl vector<ll>
#define pii pair<int, int>
#define pl pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

ll logb(ll a, ll b)
{
    return log2(a) / log2(b);
}

/* important notes :

    GCD(x,y) = GCD(x−y,y)

    if gcd(a,b) = g, then a / g and b / g should be coprimes
*/

ll POW(ll x, ll y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x;

    long long ans = POW(x, y / 2);

    if (y & 1)
        return ans * ans * x;
    return ans * ans;
}


ll powerStrings(string sa, string sb, ll MOD)
{
    ll a = 0, b = 0;

    for (int i = 0; i < sa.length(); i++)
        a = (a * 10 + (sa[i] - '0')) % MOD;

    for (int i = 0; i < sb.length(); i++)
        b = (b * 10 + (sb[i] - '0')) % (MOD - 1);

    return POW_M(a, b, MOD);
}

ll MOD(ll x, ll mod)
{
    return (x % mod + mod) % mod;
}

ll POW_M(ll x, ll y, ll mod)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return MOD(x, mod);

    ll ans = POW_M(x, y / 2, mod);

    if (y & 1)
        return MOD(MOD(ans * ans, mod) * x, mod);
    return MOD(ans * ans, mod);
}

ll inv(ll y, ll mod)
{
    return POW_M(y, mod - 2, mod);
}

int mod = 1e9 + 7;
int inv(int i)
{
    return i <= 1 ? i : mod - (long long)(mod / i) * inv(mod % i) % mod;
}

vector<int> get_mod_inverse(int m)
{
    vector<int> inv(m);
    inv[1] = 1;
    for (int i = 2; i < m; ++i)
        inv[i] = m - (long long)(m / i) * inv[m % i] % m;

    return inv;
}

int sumofFactors(int n)
{
    int res = 1;
    for (int i = 2; i * i <= n; i++)
    {
        int curr_sum = 1;
        int curr_term = 1;
        while (n % i == 0)
        {
            n = n / i;

            curr_term *= i;
            curr_sum += curr_term;
        }

        res *= curr_sum;
    }

    if (n >= 2)
        res *= (1 + n);

    return res;
}

bool composite[N + 1];
vector<int> prime;

void linear_sieve(int N)
{
    composite[0] = composite[1] = 1;
    for (int i = 2; i <= N; ++i)
    {
        if (!composite[i])
        {
            prime.push_back(i);
        }
        for (int j = 0; j < (int)prime.size() && i * prime[j] <= N; ++j)
        {
            composite[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

// This can also be used to calculate the Euler-Totient function φ(n)
// and can be used in some inclusion-exclusion DP to precalculate the array dp[x] = all pairs i < j such that [gcd(ai,aj)=x]
// where a1,a2,…,an is an array with 1 ≤ ai ≤ 10^6.
int a[N], cnt[N];
ll dp[N];
void precalc()
{
    // input a[1], a[2], ..., a[n]
    // ...
    for (int i = 1; i <= n; i++)
        cnt[a[i]]++;
    for (int i = N - 1; i >= 1; --i)
    {
        long long num_mul = 0; // number of multiples of i
        for (int j = i; j < N; j += i)
            num_mul += (long long)cnt[j];

        dp[i] = (num_mul * (num_mul - 1)) / 2; // number of pairs that are divisible by i

        for (int j = i + i; j < N; j += i)
            dp[i] -= dp[j]; // subtract all dp[j] for j > i and i divides j
    }
}

int fib(int N)
{
    return round(pow((1 + sqrt(5)) / 2, N) / sqrt(5));
}

int n;
const int x = 31; // the number of bits
string w = bitset<x>(n).to_string();

ll arithmetic_progression(ll first, ll last, ll size)
{
    return ((first + last) * size) / 2;
}

double Geometric_Progression(ll first, ll r, ll size)
{
    return (first * (1 - pow(r, size))) / (1 - r);
}

int bascal_triangle(int n, int k, int p)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 0; i <= n; i++)
    {

        dp[i][0] = 1;

        if (i <= k)
        {
            dp[i][i] = 1;
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= min(i, k); j++)
        {
            if (i != j)
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % p;
            }
        }
    }

    return dp[n][k];
}

vector<ll> calc_derangments(int n)
{
    vector<ll> derangments(n + 1);
    ll mod = 1e9 + 7;
    derangments[0] = 1, derangments[1] = 0;

    for (ll i = 2; i <= n; i++)
        derangments[i] = ((i - 1) * (derangments[i - 1] + derangments[i - 2]) % mod) % mod;

    return derangments;
}

/*Euler's totient function (phi function)

    calculate the number of integers between 1 and n which are coprime to n.

    proberties :

        1- phi(p) = p - 1 ; p is prime

        2- phi(p ^ k) = (p ^ k) / p = (p ^ k) - (p ^ (k - 1))

        3- phi(a * b) = phi(a) * phi(b)

        4- the sum of phi(x) for all x such that (x | n) is equal to n
*/

int phi(int n) // O(sqrt(n))
{
    int result = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

void phi_1_to_n(int n) // O(n * log(log(n)))
{
    vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}

/*line equation :

        y = m * x + b

        m = dy / dx = (y2 - y1) / (x2 - x1) = tan(t)

        (y - y1) = m * (x - x1)
*/

/*Note : 
        If you have all sides of a rectangle (width = a , hight = b) 
        and 2 corners of it (the first point at the origin),
        the third corner is (b * x / a , b * y / a)
*/

vector<pl> adj[N];
bool included[N];

ll Prim_MST(int u)
{
    priority_queue<pl, vector<pl>, greater<pl>> q;

    q.push({0, u});

    ll ans = 0;

    while (!q.empty())
    {
        pl p = q.top();
        q.pop();

        if (included[p.S])
            continue;

        included[p.S] = true;

        ans += p.F;

        for (auto v : adj[p.S])
        {
            if (included[v.S])
                continue;

            q.push(v);
        }
    }

    return ans;
}

int LIS(vector<int> a)
{

    vector<int> dp;

    for (int i : a)
    {

        int pos = lower_bound(dp.begin(), dp.end(), i) - dp.begin();

        if (pos == dp.size())
        {
            // we can have a new, longer increasing subsequence!
            dp.push_back(i);
        }
        else
        {
            // oh ok, at least we can make the ending element smaller
            dp[pos] = i;
        }
    }

    return dp.size();
}

// KMP

/*
    - The smallest period of some string t can be calculated as follows: 
      compute prefix-function for t, and if |t| is divisible by |t| - p[last] (p[last] is the last value of prefix-function), 
      then the length of the smallest period is |t| - p[last] (if not, then the length of the smallest period is |t|).

    - what is the next smaller prefix < j  that is also a suffix ending at position  i ? 
      The prefix of length  pi[pi[i] - 1]

    - What is the number of new different substrings those appeared when we add a new char C to S ?
      let T = S + C, and reverse T, then compute pi for T, 
      now the number of new substrings is (|T| - max(pi[i])) 
*/

vector<int> KMP(string s){
    int n = s.size();
    vector<int> pi(n);

    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];

        if (s[i] == s[j])
            j++;

        pi[i] = j;
    }

    return pi;
}

void compute_automaton(string s, vector<vector<int>>& aut) {
    s += '#';
    int n = s.size();
    vector<int> pi = KMP(s);
    aut.assign(n, vector<int>(26));
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 26; c++) {
            if (i > 0 && 'a' + c != s[i])
                aut[i][c] = aut[pi[i-1]][c];
            else
                aut[i][c] = i + ('a' + c == s[i]);
        }
    }
}

// String Hashing
vector<ll> pre1(N), pre2(N), p1(N), p2(N);
ll mod1 = 1e9 + 7, mod2 = 998244353;
ll base = 29;

// Indeces from 1 (not 0) 

pair<ll, ll> calc_hash(string s)
{
    pre1[0] = pre2[0] = 0, p1[0] = p2[0] = 1;

    for (int i = 1; i < s.size(); i++)
    {
        p1[i] = p1[i - 1] * base % mod1;
        p2[i] = p2[i - 1] * base % mod2;

        pre1[i] = pre1[i - 1] * base + s[i] - 'A' + 1;
        pre1[i] %= mod1;
        pre2[i] = pre2[i - 1] * base + s[i] - 'A' + 1;
        pre2[i] %= mod2;
    }

    return {pre1[s.size() - 1], pre2[s.size() - 1]};
}

pair<ll, ll> get_subhash(int l, int r)
{
    ll x = (pre1[r] - pre1[l - 1] * p1[r - l + 1] % mod1 + mod1) % mod1;
    ll y = (pre2[r] - pre2[l - 1] * p2[r - l + 1] % mod2 + mod2) % mod2;

    return {x, y};
}

// Z

/*
    - compute the Z-function of  s , loop through all  i  such that  i  divides  n .
      Stop at the first i such that i + z[i] = n . Then, the string s can be 
      compressed to the length  i .

    - What is the number of new different substrings those appeared when we add a new char C to S ?
      let T = S + C, and reverse T, then compute z-function for T, 
      now the number of new substrings is (|T| - max(z[i]))
*/
vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

// Floyd's algorithm for cycles detecting (functional-successor graph)

void floyd(vector<int> &succ, int start)
{
    int a = succ[start];
    int b = succ[succ[start]];

    while (a != b)
    {
        a = succ[a];
        b = succ[succ[b]];
    }

    /*
        At this point, the pointer a has walked k steps and the pointer b has walked
        2k steps, so the length of the cycle divides k. Thus, the first node that belongs
        to the cycle can be found by moving the pointer a to node x and advancing the
        pointers step by step until they meet again.
    */

    a = x;
    while (a != b)
    {
        a = succ[a];
        b = succ[b];
    }

    int first = a;

    // After this, the length of the cycle can be calculated as follows:

    b = succ[a];
    int length = 1;
    while (a != b)
    {
        b = succ[b];
        length++;
    }
}

priority_queue<int, vector<int>, greater<int>> q;

struct Node {

    ll sum , pref , suf , seg;

    Node()
    {
        sum = pref = suf = seg = 0;
    }

    Node(int v)
    {
        sum = pref = suf = seg = v;
    }
};

int n;

struct ST {

    #define lc (id << 1)
    #define rc ((id << 1) | 1)
    #define mid ((l + r) >> 1)

    vector <Node> seg;

    ST ()
    {
        Node t = Node();

        seg.resize(4 * n , t);
    }

    Node merge(int id)
    {
        Node a , b = seg[lc] , c = seg[rc];

        a.seg = max ({ b.seg , c.seg , b.suf + c.pref });
        a.pref = max({ b.pref , b.sum + c.pref });
        a.suf = max({ c.suf , b.suf + c.sum });
        a.sum = b.sum + c.sum;

        return a;
    }

    void update (int ndx , int val , int id = 1 , int l = 1 , int r = n)
    {
        if (l == r)
        {
            seg[id] = Node(val);
            return;
        }

        if (ndx <= mid)
            update (ndx , val , lc , l , mid);
        else 
            update(ndx , val , rc , mid + 1 , r);
        
        seg[id] = merge(id);
    }
};

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

// k-th permutation of a sequence

vector<int> applyPermutation(vector<int> sequence, vector<int> permutation) {
    vector<int> newSequence(sequence.size());
    for(int i = 0; i < sequence.size(); i++) {
        newSequence[i] = sequence[permutation[i]];
    }
    return newSequence;
}

vector<int> permute(vector<int> sequence, vector<int> permutation, long long k) {
    while (k > 0) {
        if (k & 1) {
            sequence = applyPermutation(sequence, permutation);
        }
        permutation = applyPermutation(permutation, permutation);
        k >>= 1;
    }
    return sequence;
}


// Find Bridges

vector <int> adj[N];
vector<bool> visited;
vector<int> tin, low;
vector<pii> bridges;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (int to : adj[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
            {
                bridges.push_back({v , to});
            }
        }
    }
}

void find_bridges(int n) {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

class SparseTable {
    int K , N;
    vector <vector<ll>> st;

    public :

    SparseTable(int k , int n , vector<ll> &arr) {
        K = k; 
        N = n; 
        st.assign(k + 1 , vector<ll>(n + 1 , LLONG_MAX));
        build(arr);
    }

    void build(vector<ll> &arr) {
        for (int i = 0 ; i < arr.size() ; i ++) {
            st[0][i] = arr[i];
        }
        
        for (int i = 1; i <= K; i++)
            for (int j = 0; j + (1 << i) <= N; j++)
                st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }

    ll f(ll &x , ll &y) {
        return min(x, y); 
    }

    // c++20
    // int log2_floor(unsigned long i) {
    //     return std::bit_width(i) - 1;
    // }

    // pre C++20
    int log2_floor(unsigned long long i) {
        return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
    }
    
    ll query(int l , int r) {
        int i = log2_floor(r - l + 1);
        return f(st[i][l], st[i][r - (1 << i) + 1]);
    }
    // ll sum(int l , int r) {
    //    long long sum = 0;
    //    for (int i = K; i >= 0; i--) {
    //       if ((1 << i) <= r - l + 1) {
    //          sum += st[i][l];
    //          l += 1 << i;
    //       }
    //    }
    // }
};

// Geometry

template <typename T>
struct TPoint
{
    T x;
    T y;
    int id;

    TPoint() : x(0), y(0), id(-1) {}
    TPoint(const T &x_, const T &y_) : x(x_), y(y_), id(-1) {}
    TPoint(const T &x_, const T &y_, int id_) : x(x_), y(y_), id(id_) {}

    static constexpr T eps = static_cast<T>(1e-9);

    inline TPoint operator+(const TPoint &rhs) const { return TPoint(x + rhs.x, y + rhs.y); }
    inline TPoint operator-(const TPoint &rhs) const { return TPoint(x - rhs.x, y - rhs.y); }
    inline TPoint operator*(const T &rhs) const { return TPoint(x * rhs, y * rhs); }
    inline TPoint operator/(const T &rhs) const { return TPoint(x / rhs, y / rhs); }

    friend T dot(const TPoint &a, const TPoint &b)
    { // Dot Product
        return a.x * b.x + a.y * b.y;
    }

    friend T cross(const TPoint &a, const TPoint &b)
    { // Cross Product
        return a.x * b.y - a.y * b.x;
    }

    inline T abs2() const
    {
        return x * x + y * y;
    }

    inline bool operator<(const TPoint &rhs) const
    {
        // return (y < rhs.y || (y == rhs.y && x < rhs.x));
        return (x < rhs.x || (x == rhs.x && y < rhs.y));
    }

    inline bool operator==(const TPoint &rhs) const
    {
        return (y == rhs.y && x == rhs.x);
    }

    inline bool is_upper() const
    {
        return (y > eps || (abs(y) <= eps && x > eps));
    }

    inline int cmp_polar(const TPoint &rhs) const
    {
        assert(abs(x) > eps || abs(y) > eps);
        assert(abs(rhs.x) > eps || abs(rhs.y) > eps);
        bool a = is_upper();
        bool b = rhs.is_upper();
        if (a != b)
        {
            return (a ? -1 : 1);
        }
        long long v = x * rhs.y - y * rhs.x;
        return (v > eps ? -1 : (v < -eps ? 1 : 0));
    }

    friend bool inside_rect(TPoint A, TPoint B, TPoint P)
    {
        return (min(A.x, B.x) <= P.x && P.x <= max(A.x, B.x) && min(A.y, B.y) <= P.y && P.y <= max(A.y, B.y));
    };
};

using point = TPoint<long long>;
// using point = TPoint<long double>;

template <typename T>
string to_string(const TPoint<T> &p)
{
    return "(" + to_string(p.x) + ", " + to_string(p.y) + ")";
}

vector<point> convex_hull(vector<point> &points) {

    vector <point> hull;

	// sort with respect to the x and y coordinates
    
	sort(points.begin(), points.end());

	// distinct the points

	points.erase(unique(points.begin(), points.end()), points.end());

	int n = points.size();


	// 1 or 2 points are always in the convex hull

	if (n < 3) {
		hull = points;
		return hull;
	}


	// lower hull

	for (int i = 0; i < n; i++) {

		// if with the new point points[i], a right turn will be formed,

		// then we remove the last point in the hull and test further

		while (hull.size() > 1 && cross(hull.back() - hull[hull.size() - 2] , points[i] - hull[hull.size() - 2]) < 0)
			hull.pop_back();

		// otherwise, add the point to the hull

		hull.push_back(points[i]);
	}

	// upper hull, following the same logic as the lower hull

	auto lower_hull_length = hull.size();

	for (int i = n - 2; i >= 0; i--) {

		// we can only remove a point if there are still points left in the

		// upper hull

		while (hull.size() > lower_hull_length && cross(hull.back() - hull[hull.size() - 2] , points[i] - hull[hull.size() - 2]) < 0)
			hull.pop_back();

		hull.push_back(points[i]);
	}

	// delete point[0] that has been added twice

	hull.pop_back();

    return hull;
}

vector<point> convex_hull(vector<point> pts, bool cyclic = false) {
  int n = (int) pts.size();
  sort(pts.begin(), pts.end());
  vector<point> ch(1, pts[0]);
  for (int rot = 0, sz = 0; rot < 2; rot++, sz = (int) ch.size() - 1) {
    for (int i = 1; i < n; i++) {
      while ((int) ch.size() >= 2 + sz && cross(ch.back() - ch.end()[-2], pts[i] - ch.back()) > 0) {
        ch.pop_back();
      }
      ch.push_back(pts[i]);
    }
    reverse(pts.begin(), pts.end());
  }
  if (!cyclic && ch.size() > 1) {
    ch.pop_back();
  }
  return ch;
}

bool inside(point p, vector <point> &uh, vector <point> &lh) { // check a point is it inside/outside a polygon
    auto t1 = lower_bound(all(uh), p);
    if (t1 == uh.begin() || t1 == uh.end()) {
        return false;
    }
    auto t2 = t1 - 1;

    if (cross(*t1 - *t2, p - *t2) >= 0) {
        return false;
    }

    t1 = lower_bound(all(lh), p);
    if (t1 == lh.begin() || t1 == lh.end()) {
        return false;
    }
    t2 = t1 - 1;
    
    if (cross(*t1 - *t2, p - *t2) <= 0) {
        return false;
    }

    return true;
}

/*
    We denote its area by S, the number of points with integer coordinates lying strictly inside the polygon by I 
    and the number of points lying on polygon sides by B.
    
    Then, the Pick's formula states: S = I + B / 2 - 1
*/

//