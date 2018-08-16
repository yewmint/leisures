#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

template<typename T>
ll scll(T val){
	return static_cast<ll>(val);
}

int n;

struct Point {
	int x, y, cost;
};

bool operator<(Point & a, Point & b){
	if (a.x < b.x){
		return true;
	}
	else if (a.x == b.x){
		return a.y < b.y;
	}
	else {
		return false;
	}
}

bool canForm(vector<Point> points){
	sort(points.begin(), points.end());
	return (points[0].x == points[1].x) &&
		(points[2].x == points[3].x) &&
		(points[0].y == points[2].y) &&
		(points[1].y == points[3].y) &&
		(points[1].y > points[0].y) &&
		(points[2].x > points[0].x) &&
		(points[1].y - points[0].y == points[2].x - points[0].x);
}

int main() {
	scanf("%d", &n);
	while (n--){
		vector<vector<Point>> candidates;
		for (int i = 0; i < 4; ++i){
			int x, y, a, b;
			scanf("%d%d%d%d", &a, &b, &x, &y);

			int dx = a - x;
			int dy = b - y;

			candidates.push_back({
				{ a, b, 0 },
				{ x - dy, y + dx, 1 },
				{ x - dx, y - dy, 2 },
				{ x + dy, y - dx, 3 },
			});
		}

		int minCost = INT_MAX;
		int curCost = 0;

		vector<Point> curPoints;
		for (int a = 0; a < 4; ++a){
			auto pta = candidates[0][a];
			curPoints.push_back(pta);
			curCost += pta.cost;
			for (int b = 0; b < 4; ++b){
				auto ptb = candidates[1][b];
				curPoints.push_back(ptb);
				curCost += ptb.cost;
				for (int c = 0; c < 4; ++c){
					auto ptc = candidates[2][c];
					curPoints.push_back(ptc);
					curCost += ptc.cost;
					for (int d = 0; d < 4; ++d){
						auto ptd = candidates[3][d];
						curPoints.push_back(ptd);
						curCost += ptd.cost;
						if (canForm(curPoints)){
							minCost = min(minCost, curCost);
						}
						curPoints.pop_back();
						curCost -= ptd.cost;
					}
					curPoints.pop_back();
					curCost -= ptc.cost;
				}
				curPoints.pop_back();
				curCost -= ptb.cost;
			}
			curPoints.pop_back();
			curCost -= pta.cost;
		}

		if (minCost == INT_MAX){
			printf("-1\n");
		}
		else {
			printf("%d\n", minCost);
		}
	}
}