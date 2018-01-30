#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>
#include <functional>

using namespace std;

struct Node {
	int wordNum;
	int weight;
	bool isLeaf;
	Node(int wordNum, int weight) : wordNum(wordNum), weight(weight), isLeaf(true) {};
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int u, v;
		cin >> u >> v;
		string signal;
		cin >> signal;

		map<char, int> sigCnt;
		for (char ch : signal) {
			sigCnt[ch]++;
		}

		auto cmp = [](Node &a, Node &b) { return a.weight > b.weight; };
		priority_queue<Node, vector<Node>, decltype(cmp)> sigQue(cmp);
		for (char ch = '0'; ch <= '9'; ++ch) {
			if (sigCnt[ch] > 0) {
				Node node(sigCnt[ch], sigCnt[ch]);
				sigQue.push(node);
			}
		}
		for (char ch = 'a'; ch <= 'e'; ++ch) {
			if (sigCnt[ch] > 0) {
				Node node(sigCnt[ch], sigCnt[ch]);
				sigQue.push(node);
			}
		}

		while (sigQue.size() >= 2) {
			auto vnode = sigQue.top();
			sigQue.pop();
			auto unode = sigQue.top();
			sigQue.pop();

			Node newNode(vnode.wordNum + unode.wordNum, 0);
			newNode.isLeaf = false;
			if (vnode.isLeaf) {
				newNode.weight += vnode.wordNum * v;
			}
			else {
				newNode.weight += vnode.wordNum * v + vnode.weight;
			}
			if (unode.isLeaf) {
				newNode.weight += unode.wordNum * u;
			}
			else {
				newNode.weight += unode.wordNum * u + unode.weight;
			}

			sigQue.push(newNode);
		}

		cout << sigQue.top().weight << endl;
		// TODO: Not optimal solution, failed at 3rd test case
	}
}