
vector<int> makeNext(string line) {
	if (line.size() <= 1) {
		return vector<int>(line.size(), -1);
	}

	vector<int> next(line.size(), -1);
	next[1] = 0;

	for (int i = 2; i < line.size(); ++i) {
		int j = i - 1;
		while (j > 0 && line[next[j]] != line[i - 1]) {
			j = next[j];
		}
		next[i] = next[j] + 1;
	}

	return next;
}

vector<int> makeNextVal(string line) {
	vector<int> next = makeNext(line);
	vector<int> nextVal(next);

	for (int i = 1; i < nextVal.size(); ++i) {
		if (line[i] == line[nextVal[i]]) {
			nextVal[i] = nextVal[next[i]];
		}
	}

	return nextVal;
}