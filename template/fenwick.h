#ifndef __H_FENWICK__
#define __H_FENWICK__

#include <vector>

namespace yewmint {

template <typename T>
class Fenwick {
public:
	Fenwick(int len = 0) : _data(std::vector<T>(len + 1, 0)) {}

	Fenwick(std::vector<T> & nums) : _data(std::vector<T>(nums.size() + 1, 0)) {
		for (int i = 0; i < nums.size(); ++i) {
			this->add(i, nums[i]);
		}
	}

	void add(int index, T value) {
		index++;

		while (index <= this->size()) {
			this->_data[index] += value;
			index += index & (-index);
		}
	}

	T sum(int index) {
		T sum = 0;
		index++;

		while (index > 0) {
			sum += this->_data[index];
			index -= index & (-index);
		}
		return sum;
	}

	int size() {
		return this->_data.size() - 1;
	}

private:
	std::vector<T> _data;
};

} // namespace yewmint

#endif