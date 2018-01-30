#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;

	while (T--) {
		int cnt9 = 0;
		int cnt7 = 0;
		int cnt0 = 0;
		int cnt6 = 0;

		string line;
		cin >> line;

		for (char ch : line) {
			switch (ch) {
			case '9':
				cnt9++;
				break;
			case '7':
				if (cnt9 > 0) {
					cnt9--;
					cnt7++;
				}
				break;
			case '0':
				if (cnt7 > 0) {
					cnt7--;
					cnt0++;
				}
				break;
			case '6':
				if (cnt0 > 0) {
					cnt0--;
					cnt6++;
				}
				break;
			default:
				break;
			}
		}

		cout << cnt6 << endl;
	}
}