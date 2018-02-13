#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>
#include <functional>
#include <climits>

using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

#define mp make_pair

vector<string> firstDigits = {
	"Zero", "One", "Two", "Three", "Four", "Five",
	"Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",
	"Thirteen", "Fourteen", "Fifteen",
	"Sixteen", "Seventeen", "Eighteen", "Nineteen"
};

vector<string> secondDigits = {
	"None", "None", "Twenty", "Thirty", "Forty",
	"Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
};

vector<string> measures = {
	"None", "Thousand", "Million", "Billion",
	"Trillion", "Quadrillion", "Quintillion",
	"Sextillion", "Septillion", "Octillion",
	"Nonillion", "Decillion"
};

string numberToWords(int num) {
	if (num == 0) {
		return "Zero";
	}

	string ans = "";
	int slice = 0;
	while (num > 0) {
		string section = "";
		int digit = 0;

		if (num > 0) {
			digit = num % 100;
			num /= 100;

			if (digit > 0) {
				if (digit < 20) {
					section = firstDigits[digit];
				}
				else {
					section = secondDigits[digit / 10];
					if (digit % 10 > 0) {
						section += " " + firstDigits[digit % 10];
					}
				}
			}
		}

		if (num > 0) {
			digit = num % 10;
			num /= 10;

			if (digit > 0) {
				string hundred = firstDigits[digit] + " Hundred";
				if (section.size() > 0) {
					section = hundred + " " + section;
				}
				else {
					section = hundred;
				}
			}
		}

		if (section.size() > 0 && slice > 0) {
			section += " " + measures[slice];
		}

		if (section.size() > 0) {
			if (ans.size() > 0) {
				ans = section + " " + ans;
			}
			else {
				ans = section;
			}
		}

		slice++;
	}

	return ans;
}

int main() {
	cout << numberToWords(100);
	cin.get();
}