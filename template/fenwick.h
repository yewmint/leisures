#ifndef __H_FENWICK__
#define __H_FENWICK__

#include <vector>

namespace yewmint {

/**
* Fenwick tree to count sum of [0, k] elements in O(logn)
* Caveat: Index of fenwick tree behaves like vector in range [0, Fenwick::size() - 1]
*
* @typename T type of value to be counted
*/
template <typename T>
class Fenwick {
public:
	/**
	* Construct empty fenwick tree with specified lengh
	*
	* @param [len = 0] length of fenwick tree
	*/
	Fenwick(int len = 0) : _data(std::vector<T>(len + 1, 0)) {}

	/**
	* Construct fenwick tree with specified elements
	*
	* @param nums initial elements of fenwick tree
	*/
	Fenwick(std::vector<T> & nums) : _data(std::vector<T>(nums.size() + 1, 0)) {
		for (int i = 0; i < nums.size(); ++i) {
			this->add(i, nums[i]);
		}
	}

	/**
	* Add value to a specified element
	*
	* @param index index of element
	* @param value value to be added
	*/
	void add(int index, T value) {
		if (index < 0) {
			return;
		}

		index++;

		while (index <= this->size()) {
			this->_data[index] += value;
			index += index & (-index);
		}
	}

	/**
	* Get sum of elements in [0, index] where index < Fenwick::size()
	*
	* @param sum index of last included element
	*/
	T sum(int index) {
		if (index < 0) {
			return 0;
		}

		T sum = 0;
		index++;

		while (index > 0) {
			sum += this->_data[index];
			index -= index & (-index);
		}
		return sum;
	}

	/**
	* Get size of fenwick tree
	*/
	int size() {
		return this->_data.size() - 1;
	}

private:
	std::vector<T> _data;
};

} // namespace yewmint

#endif