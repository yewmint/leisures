#ifndef __H_HEAP_LIST__
#define __H_HEAP_LIST__

#include <list>
#include <set>
#include <vector>

template <typename T>
class HeapList {
private:
	// define number
	typedef std::pair<T, size_t> Number;

	// define list
	typedef std::list<Number> List;

	// define pair of number and iterator
	struct NumberIterator {
		Number number;
		List::iterator iterator;
		NumberIterator(Number num, List::iterator it) : number(num), iterator(it) {};
	};

	// define compare function
	auto comp = [](NumberIterator & a, NumberIterator & b) { return a.number > b.number };

	// define heap
	typedef std::set<NumberIterator> Heap;

	// define iterator
	typedef List::iterator Iterator;

	// alias
	auto mp = std::make_pair;

public:
	HeapList(std::vector<T> nums) {
		for (T num : nums) {
			insert(list.end(), num);
		}
	}

	Iterator top() {
		return queue.begin()->iterator;
	}

	Iterator bottom() {
		return (--queue.end())->iterator;
	}

	T biggest() {
		return top()->first;
	}

	T smallest() {
		return bottom()->first;
	}

	void insert(Iterator it, T value) {
		auto element = mp(value, nextIdx++);
		list.insert(it, element);
		queue.insert(NumberIterator(element, --it));
	}

	void erase(Iterator it) {
		queue.erase(NumberIterator(*it, it));
		list.erase(it);
	}

private:
	List list;
	Heap queue = Heap(comp);
	size_t nextIdx;
};

#endif
