class Solution {
public:
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

int walk(vector<vector<int>>& forest, pii origin, pii dest){
	const int ROWS = forest.size();
	const int COLS = forest[0].size();
	vector<vector<int>> steps(ROWS, vector<int>(COLS, -1));
	vector<vector<bool>> inQueue(ROWS, vector<bool>(COLS, false));
	queue<pii> q;

	q.push(origin);
	inQueue[origin.first][origin.second] = true;
	steps[origin.first][origin.second] = 0;
	while (!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		inQueue[x][y] = false;
		q.pop();

		int dirs[] = { 1, 0, -1, 0, 1 };
		for (int i = 0; i < 4; ++i){
			int nx = x + dirs[i];
			int ny = y + dirs[i + 1];

			if (nx >= 0 && nx < ROWS && ny >= 0 && ny < COLS && forest[nx][ny] > 0){
				if (steps[nx][ny] == -1 || steps[nx][ny] > steps[x][y] + 1){
					steps[nx][ny] = steps[x][y] + 1;
					if (!inQueue[nx][ny]){
						q.push(mp(nx, ny));
						inQueue[nx][ny] = true;
					}
				}
			}
		}
	}

	return steps[dest.first][dest.second];
}

int cutOffTree(vector<vector<int>>& forest) {
	if (forest.size() == 0 || forest[0].size() == 0){
		return 0;
	}

	const int ROWS = forest.size();
	const int COLS = forest[0].size();

	vector<pair<int, pii>> nodes;
	for (int row = 0; row < ROWS; ++row){
		for (int col = 0; col < COLS; ++col){
			if (forest[row][col] > 0){
				nodes.push_back(mp(forest[row][col], mp(row, col)));
			}
		}
	}

	sort(begin(nodes), end(nodes));

	int ret = 0;
	pii last = { 0, 0 };
	for (int i = 0; i < nodes.size(); ++i){
		auto dest = nodes[i].second;

		// printf("x = %d, y = %d, ", dest.first, dest.second);

		int step = walk(forest, last, dest);
		if (step >= 0) ret += step;
		else return -1;

		// printf("step = %d\n", step);

		last = dest;
	}

	return ret;
}
};