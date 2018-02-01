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
#include <stdio.h>

#define mp make_pair
typedef long long ll;

using namespace std;

vector<pair<ll, ll>> neigh[100006];
queue<ll> q;
bool inqueue[100006] = { 0 };
ll dist[100006] = { 0 };

int main() {
	ll N, M, S, T;
	scanf("%lld %lld %lld %lld", &N, &M, &S, &T);

	for (ll i = 0; i < M; ++i) {
		ll u, v, len;
		scanf("%lld %lld %lld", &u, &v, &len);
		neigh[u].push_back(mp(v, len));
		neigh[v].push_back(mp(u, len));
	}

	for (ll i = 1; i <= N; ++i) {
		dist[i] = LLONG_MAX;
	}

	q.push(S);
	dist[S] = 0;
	inqueue[S] = true;
	while (!q.empty()) {
		ll curNode = q.front();
		q.pop();
		inqueue[curNode] = false;

		for (auto path : neigh[curNode]) {
			ll nextNode = path.first;
			ll cost = path.second;

			if (dist[nextNode] > dist[curNode] + cost) {
				dist[nextNode] = dist[curNode] + cost;
				if (!inqueue[nextNode]) {
					q.push(nextNode);
					inqueue[nextNode] = true;
				}
			}
		}
	}

	cout << dist[T];
}