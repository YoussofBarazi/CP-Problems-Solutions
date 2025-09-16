#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std ;
using namespace __gnu_pbds ; 

#define F first
#define S second
#define pb push_back
#define ll long long 
#define ld long double
#define rev greater < int >()
#define all(x) (x).rbegin () , (x).rend ()
#define RF(F) freopen(F , "r" , stdin ) 
#define WF(F) freopen(F , "w" , stdout) 
#define IOS ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
#define ordered_set tree < int , null_type , less < int > , rb_tree_tag , tree_order_statistics_node_update > 


typedef pair < int , int > pii ;
typedef pair < long long , long long > pll ;
typedef map  < int , int > mii ; 
typedef map  < long long , long long > mll ;
typedef vector < int > vi ;
typedef vector < long long > vl ;


const ld  pi  = 3.14159265359 ;
const ld  eps = 1e-9 ;
const ll  INF = 1e9 ;
const int MAX_N = 200000 + 7 ;

int n;

vector <int> adj[MAX_N];
vector <int> ans(MAX_N);
vector <bool> vis(MAX_N , false);
multiset <int> MEX;
int a[MAX_N];

void dfs(int u , int mex)
{
    MEX.insert(a[u]);

    while (MEX.find(mex) != MEX.end())
        mex++;

    vis[u] = true;

    ans[u] = mex;

    for (auto v : adj[u])
    {
        if (!vis[v])
            dfs(v , mex);
    }

    MEX.erase(MEX.find(a[u]));
}

void solve(int testCase){

    scanf("%d" , &n);

    for (int i = 0 ; i < n ; i ++)
        ans[i] = 0 , adj[i].clear() , vis[i] = false;

    for (int i = 0 ; i < n ; i ++)
        scanf("%d" , &a[i]);

    for (int i = 1 ; i < n ; i ++)
    {
        int p;
        scanf("%d" , &p);
        p --;

        adj[p].push_back(i);
        adj[i].push_back(p);
    }

    dfs(0 , 0);

    for (int i = 0 ; i < n ; i ++)  
        printf("%d " , ans[i]);
    printf("\n");

}


int main() {

    int testCase = 1;
    scanf("%d" , &testCase);

    for(int T = 1 ; T <= testCase ; T ++){
        solve(T) ;
    }

    return 0 ;
}
