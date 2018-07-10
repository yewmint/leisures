#include <bits/stdc++.h>

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

inline int getZ (const Point & A, const Point & B){
	return A.x * B.y - A.y * B.x;
}

inline int sqrDistance (const Point & vec){
	return vec.x * vec.x + vec.y * vec.y;
}

inline Point getVec (const Point & lhs, const Point & rhs){
	return Point(rhs.x - lhs.x, rhs.y - lhs.y);
}

vector<Point> outerTrees(vector<Point>& points) {
	// 1. get bottom left point as root
	// 2. sort all points by radians to root
	// 3. connect root and first node
	// 4. as each point in list, if angle with last segment is concave, pop
	// 5. if angle with last segment is convex, push
	// caveat: preserve all point in a single line

	// corner case
	if (points.size() <= 3){
		return points;
	}

	// 1
	Point root(INT_MAX, INT_MAX);
	for (const auto & pt : points){
		if ((pt.y < root.y) || (pt.y == root.y && pt.x < root.x)){
			root = pt;
		}
	}

	// 2
	vector<Point> others;
	others.reserve(points.size() - 1);
	for (const auto & pt : points){
		if (pt.x != root.x || pt.y != root.y){
			others.push_back(pt);
		}
	}
	sort(others.begin(), others.end(), 
		[&] (const Point & lhs, const Point & rhs) -> bool {
			Point lhsVec = getVec(root, lhs);
			Point rhsVec = getVec(root, rhs);
			int z = getZ(lhsVec, rhsVec);

			if (z != 0){
				return z > 0;
			}
			else {
				return sqrDistance(lhsVec) < sqrDistance(rhsVec);
			}
		}
	);

	// 3
	vector<Point> borders({ root, others.front() });
	vector<Point> inLastLine;
	for (int i = 1; i < others.size(); ++i){
		const Point & node = others[i];
		bool isConvex = true;

		do {
			const Point & lastFirst = *borders.rbegin();
			const Point & lastSecond = *next(borders.rbegin());

			int z = getZ(getVec(lastSecond, lastFirst), getVec(lastFirst, node));
			if (z < 0){
				if (getZ(getVec(root, lastFirst), getVec(root, others.back())) == 0){
					inLastLine.push_back(lastFirst);
				}

				isConvex = false;
				borders.pop_back();
			}
			else {
				isConvex = true;
			}
		} while (!isConvex);

		borders.push_back(node);
	}

	borders.insert(borders.end(), inLastLine.begin(), inLastLine.end());

	return borders;
}

int main() {
	// vector<Point> arg0 = {
	// 	{1,1},{2,2},{2,0},{2,4},{3,3},{4,2}
	// };
	vector<Point> arg0 = {
		{1,2},{2,2},{4,2}
	};
	auto ans = outerTrees(arg0);
	for (auto pt : ans){
		cout << pt.x << ", " << pt.y << endl;
	}

	cout << "finished" << endl;
	cin.get();
}