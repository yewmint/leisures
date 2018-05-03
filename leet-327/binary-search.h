#ifndef __H_BINARY_SEARCH__
#define __H_BINARY_SEARCH__

#include <vector>

namespace yewmint {

template <typename T1, typename T2>
int binarySearchUpper(std::vector<T1> & nums, T2 value) {
	int l = 0;
	int r = nums.size() - 1;
	int m = 0;

	while (l <= r) {
		m = l + (r - l) / 2;

		if (nums[m] <= value) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}

	return l;
}

}

#endif
