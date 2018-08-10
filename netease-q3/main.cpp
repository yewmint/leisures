#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

template<typename T>
ll scll(T val){
	return static_cast<ll>(val);
}

int T;
int Q, N, M;

int main() {
	scanf("%d", &T);
	while (T--){
		scanf("%d%d%d", &Q, &N, &M);

		vector<vector<int>> rankScores;
		while (N--){
			int l, r, s;
			scanf("%d%d%d", &l, &r, &s);
			rankScores.push_back({ l, r, s });
		}

		vector<int> killScores;
		for (int i = 0; i <= M; ++i){
			int s;
			scanf("%d", &s);
			killScores.push_back(s);
		}

		int A, B;
		scanf("%d%d", &A, &B);
		
		map<string, int> killCounts;
		map<string, int> scores;
		int rank = Q;
		for (int i = 1; i < Q; ++i){
			int curTime;
			string killer, victim;
			cin >> curTime >> killer >> victim;

			for (auto rankScore : rankScores){
				if (rankScore[0] <= rank && rank <= rankScore[1]){
					scores[victim] += rankScore[2];
					break;
				}
			}

			rank--;

			if (killer != victim){
				int killScore = killScores[min(killCounts[victim], M)];
				scores[killer] += killScore;
			}

			scores[victim] += A * curTime + B;

			killCounts[killer]++;

			if (i == Q - 1){
				for (auto rankScore : rankScores){
					if (rankScore[0] <= 1 && 1 <= rankScore[1]){
						scores[killer] += rankScore[2];
						break;
					}
				}

				scores[killer] += A * curTime + B;
			}
		}

		for (auto nameScore : scores){
			cout << nameScore.first << " " << nameScore.second << endl;
		}
	}
}