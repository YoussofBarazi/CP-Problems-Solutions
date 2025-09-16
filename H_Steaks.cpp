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
#define all(x) (x).begin () , (x).end ()
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
const int mod = 1e9 + 7 ;
const int MAX_N = 1e6 + 7 ;


int a[MAX_N] ;


string get_string() {

    const int MAX_SIZE = 1e6 + 7 ;
    char s[MAX_SIZE] ;

    scanf("%s" , s) ;

    return s ;

}

void solve(int testCase){
    
    ll n , k;
    cin >> n >> k;

    if (k * 2 >= n)
        cout << 10 << endl;
    else 
        cout << ((n * 2 + k * 2 - 1) / (k * 2)) * 5 << endl;

}   

int main() {

    int testCase = 1 ;

    for(int T = 1 ; T <= testCase ; T ++){
        solve(T) ;
    }

    return 0 ;
}
