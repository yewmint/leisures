#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>
#include <functional>
#include <climits>
#include <stdio.h>
#include "IdSortVector.h"

#pragma warning(disable:4996)

#define mp make_pair
#define mt make_tuple
typedef long long ll;
using namespace std;

#define MAXN 10006



int main() {
	int NNUM, ENUM, ST, ED;
	scanf("%d%d%d%d", &NNUM, &ENUM, &ST, &ED);
	ST--;
	ED--;

	vector<vector<pair<int, int>>> neighs(NNUM);
	for (int i = 0; i < ENUM; ++i) {
		int from, to, cost;
		scanf("%d%d%d", &from, &to, &cost);
		neighs[from - 1].push_back(mp(to - 1, cost));
	}

	map<int, bool> visited;
	IdSortVector<int, int> vec;
	vec.insert(ST, 0);
	while (vec.size() > 0) {
		auto node = vec.least();
		vec.erase(node.id);

		if (node.id == ED) {
			printf("%d", node.sort);
			break;
		}
		
		for (auto neigh : neighs[node.id]) {
			int neighId = neigh.first;
			int neighCost = neigh.second;

			if (visited[neighId]) {
				continue;
			}

			if (vec.exist(neighId)) {
				auto neighElem = vec.get(neighId);
				if (neighElem.sort > node.sort + neighCost) {
					vec.setSort(neighId, node.sort + neighCost);
				}
			}
			else {
				vec.insert(neighId, node.sort + neighCost);
			}
		}
	}
}