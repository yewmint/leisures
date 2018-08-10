#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

template<typename T>
ll scll(T val){
	return static_cast<ll>(val);
}

int N;

int main() {
	scanf("%d", &N);
	while (N--){
		int salary;
		scanf("%d", &salary);
		salary -= 5000;

		int tax = 0;

		if (salary > 0){
			tax += round(min(3000, (salary - 0)) * 0.03);
		}

		if (salary > 3000){
			tax += round(min(9000, (salary - 3000)) * 0.1);
		}

		if (salary > 12000){
			tax += round(min(13000, (salary - 12000)) * 0.2);
		}

		if (salary > 25000){
			tax += round(min(10000, (salary - 25000)) * 0.25);
		}

		if (salary > 35000){
			tax += round(min(20000, (salary - 35000)) * 0.3);
		}

		if (salary > 55000){
			tax += round(min(25000, (salary - 55000)) * 0.35);
		}

		if (salary > 80000){
			tax += round((salary - 80000) * 0.45);
		}

		printf("%d\n", tax);
	}
}