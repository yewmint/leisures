#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>
#include <functional>
#include <climits>

using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

#define mp make_pair

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int maxPoints(vector<Point>& points) {
	int ans = 0;

	for (int i = 0; i < points.size(); ++i) {
		auto origin = points[i];
		int overlap = 0;
		int curMax = 0;
		map<pair<int, int>, int> slopeCnts;

		for (int j = i + 1; j < points.size(); ++j) {
			auto point = points[j];

			if (origin.x == point.x && origin.y == point.y) {
				overlap++;
			}
			else {
				int dx = point.x - origin.x;
				int dy = point.y - origin.y;

				if (dx != 0 && dy != 0) {
					int gcdNum = gcd(dx, dy);
					dx /= gcdNum;
					dy /= gcdNum;
				}
				else {
					dx = dx ? 1 : 0;
					dy = dy ? 1 : 0;
				}

				slopeCnts[mp(dx, dy)]++;
				curMax = max(curMax, slopeCnts[mp(dx, dy)]);
			}
		}

		ans = max(ans, curMax + overlap + 1);
	}

	return ans;
}

int main() {
	vector<Point> arg0 = { {0, 0}, {1, 1}, {2, 2}, {1, 2}, {1, 0}, {1, 3} };
	cout << maxPoints(arg0) << endl;

	cin.get();
}