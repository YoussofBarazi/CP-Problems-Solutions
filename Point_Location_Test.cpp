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

template <typename T>
struct TPoint {
  T x;
  T y;
  int id;
 
  TPoint() : x(0), y(0), id(-1) {}
  TPoint(const T& x_, const T& y_) : x(x_), y(y_), id(-1) {}
  TPoint(const T& x_, const T& y_, int id_) : x(x_), y(y_), id(id_) {}
 
  static constexpr T eps = static_cast<T>(1e-9);
 
  inline TPoint operator+(const TPoint& rhs) const { return TPoint(x + rhs.x, y + rhs.y); }
  inline TPoint operator-(const TPoint& rhs) const { return TPoint(x - rhs.x, y - rhs.y); }
  inline TPoint operator*(const T& rhs) const { return TPoint(x * rhs, y * rhs); }
  inline TPoint operator/(const T& rhs) const { return TPoint(x / rhs, y / rhs); }
 
  friend T dot(const TPoint& a, const TPoint& b) { // Dot Product
    return a.x * b.x + a.y * b.y;
  }
 
  friend T cross(const TPoint& a, const TPoint& b) { // Cross Product
    return a.x * b.y - a.y * b.x;
  }
 
  inline T abs2() const {
    return x * x + y * y;
  }
 
  inline bool operator<(const TPoint& rhs) const {
    return (y < rhs.y || (y == rhs.y && x < rhs.x));
  }
 
  inline bool operator==(const TPoint& rhs) const {
    return (y == rhs.y && x == rhs.x);
  }
 
  inline bool is_upper() const {
    return (y > eps || (abs(y) <= eps && x > eps));
  }
 
  inline int cmp_polar(const TPoint& rhs) const {
    assert(abs(x) > eps || abs(y) > eps);
    assert(abs(rhs.x) > eps || abs(rhs.y) > eps);
    bool a = is_upper();
    bool b = rhs.is_upper();
    if (a != b) {
      return (a ? -1 : 1);
    }
    long long v = x * rhs.y - y * rhs.x;
    return (v > eps ? -1 : (v < -eps ? 1 : 0));
  }
};
 
using point = TPoint<long long>;
//using point = TPoint<long double>;
 
template <typename T>
string to_string(const TPoint<T>& p) {
  return "(" + to_string(p.x) + ", " + to_string(p.y) + ")";
}

void solve()
{
    int x1 , x2 , y1 , y2 , x3 , y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    point p1(x1 , y1) , p2(x2 , y2) , p3(x3 , y3);

    ll c = cross(p2 - p1 , p3 - p1);

    if (c > 0) cout << "LEFT\n";
    else if (c < 0) cout << "RIGHT\n";
    else cout << "TOUCH\n";  
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