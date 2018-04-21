#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>
#include <functional>
#include <climits>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <stdio.h>
#include "quadtree.h"

#pragma warning(disable:4996)

#define mp make_pair
typedef long long ll;
using namespace std;

int A[1006];
int profits[1006][1006];
int sums[1006];

int main() {
	QuadTreeNode root(Point(0, 0), Point(1, 1));
	root.add(Point(0, 1), 10);
	root.add(Point(0, 0), 10);
	cout << root.sum(Rectangle(Point(0, 1), Point(1, 1))) << endl;

	cin.get();
}