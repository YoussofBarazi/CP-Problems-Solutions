#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 10000010;

vector <int> adj[N];
int in[N], out[N], timer = 0;

void dfs_order(int u , int p)
{
    in[u] = ++timer;
 
    for (auto v : adj[u])
        if (p != v)
            dfs_order(v , u);
 
    out[u] = timer;
}

int n;

struct seg_tree {
 
    #define lc (p << 1)
    #define rc (lc | 1)
    #define mid ((l + r) >> 1)

    vector < ll > seg , lazy ;
 
    seg_tree (int sz = n , int val = 0){
        seg.resize(sz << 2 , 0) ;
    }
 
 
    ll merge(ll a , ll b) {

        return a + b ;
 
    }
 
    void push(int p , int l , int r)
    {
        if (lazy[p] == 0)
            return ;

        if (l != r)
        {
            lazy[lc] = lazy[p];
            lazy[rc] = lazy[p];
        }

        seg[p] = lazy[p];
        lazy[p] = 0;
    }

    void update(int S , int E , int v , int p = 1 , int l = 1 , int r = n){

        push(p , l , r);

        if(S <= l && r <= E) {
            
            lazy[p] = v ;
            push(p , l , r);

            return ;
        }
 
        if(l > E || r < S) return ;
  
        update(S , E , v , lc , l       , mid) ;
        update(S , E , v , rc , mid + 1 , r  ) ;
 
        seg[p] = seg[lc] + seg[rc];
    }
 
    ll query(int S , int E , int p = 1 , int l = 1 , int r = n){
        
        push(p , l , r);

        if (S <= l && r <= E)
            return seg[p];
        
        if (S > r || l > E)
            return 0;

        return query(S , E , lc , l , mid) + query(S , E , rc , mid + 1 , r);
    }
 
};

bool is_prime[N];
vector <int> primes;

void sieve ()
{
    memset(is_prime , false , sizeof is_prime);
    is_prime[0] = is_prime[1];

    for (int i = 2 ; i < N ; i ++)
        if (is_prime[i])
        {
            for (int j = i * i ; j < N ; j += i)
                is_prime[j] = false;

            primes.pb(i);
        }
}

void solve()
{
    cin >> n;

    vector <int> a(n + 1);

    for (int i = 1 ; i <= n ; i ++)
        cin >> a[i];

    for (int i = 0 ; i < n - 1 ; i ++)
    {
        int u , v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs_order(1 , -1);

    seg_tree st;
    /*for (int i = 1 ; i <= n ; i ++)
    {
        st.update(in[i] , in[i] , a[i]);    
    }*/

    int q;
    cin >> q;

    for (int i = 0 ; i < q ; i ++)
    {
        int t , u;
        cin >> t >> u;

        if (t == 1)
        {
            int val;
            cin >> val;

            st.update(in[u] , out[u] , val);
        }
        else 
        {
            ll sum = st.query(in[u] , out[u]);

            if (sum % 2 == 0)
                cout << "YES" << endl;
            else 
            {
                bool ok = true;

                if (sum - 2 < N)
                {
                    if (is_prime[sum - 2])
                        cout << "YES" << endl;
                    else   
                        cout << "NO" << endl;
                }
                else 
                {
                    ll t = sum;

                    for (auto x : primes)
                    {
                        ll p = x;

                        if (p * p > sum)
                            break;

                        while (sum % p == 0)
                            sum /= p;
                    }

                    if (sum != t)
                        cout << "NO" << endl;
                    else 
                        cout << "YES" << endl;
                }
            }
        }
    }
}

int main()
{
    // IO("name");
    IOS;

    sieve();

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}

void IO(string name = "") {

	cin.tie(0)->sync_with_stdio(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}

}