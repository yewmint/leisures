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
#include <string.h>

#pragma warning(disable:4996)

#define mp make_pair
typedef long long ll;
using namespace std;

int main() {
	int N;
	cin >> N;

	map<string, vector<string>> nameMail;
	map<string, vector<string>> mailName;
	map<string, int> nameOrder;
	for (int i = 0; i < N; ++i) {
		string name;
		cin >> name;
		nameOrder[name] = i;

		int K;
		cin >> K;
		while (K--) {
			string mail;
			cin >> mail;

			nameMail[name].push_back(mail);
			mailName[mail].push_back(name);
		}
	}

	vector<vector<string>> rets;
	for (int i = 0; nameMail.size() > 0; ++i) {
		set<string> mails;
		set<string> names;

		names.insert(nameMail.begin()->first);
		mails.insert(nameMail.begin()->second.begin(), nameMail.begin()->second.end());
		nameMail.erase(nameMail.begin());

		bool isFound = true;
		while (isFound) {
			isFound = false;
			for (auto mail : mails) {
				if (mailName.count(mail) > 0) {
					isFound = true;
					auto curNames = mailName[mail];
					names.insert(curNames.begin(), curNames.end());
					mailName.erase(mail);
				}
			}
			for (auto name : names) {
				if (nameMail.count(name) > 0) {
					isFound = true;
					auto curMails = nameMail[name];
					mails.insert(curMails.begin(), curMails.end());
					nameMail.erase(name);
				}
			}
		}

		map<int, string> reorder;
		for (auto name : names) {
			reorder[nameOrder[name]] = name;
		}

		rets.push_back(vector<string>());
		for (auto orderNamePair : reorder) {
			rets[i].push_back(orderNamePair.second);
		}
	}

	map<int, vector<string>> reorder;
	for (auto ret : rets) {
		reorder[nameOrder[ret[0]]] = ret;
	}
	for (auto orderRetPair : reorder) {
		for (auto name : orderRetPair.second) {
			cout << name << " ";
		}
		cout << endl;
	}
}