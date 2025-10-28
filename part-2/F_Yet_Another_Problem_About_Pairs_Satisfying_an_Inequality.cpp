#include <bits/stdc++.h>

using namespace std;


struct Edge {

	int a, b, w , x;

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

		int a, b, w , y;

		cin >> a >> b >> w >> y;

		v.push_back({a, b, w , y});

	}

	for (Edge e : v) cout << e.a << " " << e.b << " " << e.w << " " << e.x << "\n";

}