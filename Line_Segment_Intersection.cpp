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
    int x1 , x2 , x3 , x4 , y1 , y2 , y3 , y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    point a(x1 , y1) , b(x2 , y2) , c(x3 , y3) , d(x4 , y4);

    ll  c1 = cross(c - a , b - a),
        c2 = cross(d - a , b - a),
        c3 = cross(a - c , d - c),
        c4 = cross(b - c , d - c);

    auto S = [&](long long x_) {
        return (x_ < 0 ? -1 : (x_ > 0 ? 1 : 0));
    };

    bool b1 = S(c1) * S(c2) < 0;
    bool b2 = S(c3) * S(c4) < 0;

    if (b1 && b2) {
        cout << "YES" << endl;
        return ;
    }

    auto inside_rect = [&](point A, point B, point P) { 
        return (min(A.x, B.x) <= P.x && P.x <= max(A.x, B.x) && min(A.y, B.y) <= P.y && P.y <= max(A.y, B.y));
    };

    if (c1 == 0 && inside_rect(a , b , c)) {
        cout << "YES";
    } else if (c2 == 0 && inside_rect(a , b , d)) {
        cout << "YES";
    } else if (c3 == 0 && inside_rect(c , d , a)) {
        cout << "YES";
    } else if (c4 == 0 && inside_rect(c , d , b)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << endl;
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