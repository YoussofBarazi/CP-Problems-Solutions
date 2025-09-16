#include <bits/stdc++.h>

using namespace std;


struct Edge {

	int a, b, w;
};

/* alternatively,

class Edge {

    public:

        int a,b,w;

};

*/


int main() {

	int M = 4;

	vector<Edge> v;

	for (int i = 0; i < M; ++i) {

		int a, b, w;

		cin >> a >> b >> w;

		v.push_back({a, b, w});
	}
    sort(v.begin() , v.end() , [](Edge x , Edge y)
    {
        if (x.w != y.w) return x.w < y.w;
		if (x.a != y.a) return x.a < y.a;
        return x.b < y.b;
    });

	for (Edge e : v) cout << e.a << " " << e.b << " " << e.w << "\n";

}