#ifndef __H_ID_SORT_VECTOR__
#define __H_ID_SORT_VECTOR__

#include <map>

template<typename TID, typename TSORT>
class IdSortVector {
public:
	struct IdSortElement {
		TID id;
		TSORT sort;
		IdSortElement(TID id, TSORT sort) : id(id), sort(sort) {};
	};

public:
	IdSortVector() {}

	void insert(TID id, TSORT sort) {
		_idMap[id] = sort;
		_sortMap[sort] = id;
	}

	IdSortElement least() {
		std::pair<TSORT, TID> leastPair = *_sortMap.begin();
		return IdSortElement(leastPair.second, leastPair.first);
	}

	bool exist(TID id) {
		return _idMap.count(id) > 0;
	}

	IdSortElement get(TID id) {
		return IdSortElement(id, _idMap[id]);
	}

	void erase(TID id) {
		TSORT sort = _idMap[id];
		_idMap.erase(id);
		_sortMap.erase(sort);
	}

	void setSort(TID id, TSORT sort) {
		TSORT oldSort = _idMap[id];
		_sortMap[sort] = _sortMap[oldSort];
		_sortMap.erase(oldSort);
		_idMap[id] = sort;
	}

	size_t size() {
		return _idMap.size();
	}

private:
	std::map<TID, TSORT> _idMap;
	std::map<TSORT, TID> _sortMap;
};

#endif
