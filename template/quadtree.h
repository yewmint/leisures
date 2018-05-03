#ifndef __H_QUADTREE__
#define __H_QUADTREE__

#include "geometry.h"
#include <vector>

class QuadTreeNode {
public:
	QuadTreeNode(Rectangle area) : _area(area) {
		_initChildren();
	}

	QuadTreeNode(Point a, Point b) : _area(a, b) {
		_initChildren();
	}

	bool contains(Point & pt) const {
		return _area.contains(pt);
	}

	bool isOverlap(Rectangle rect) const {
		return _area.isOverlap(rect);
	}

	void add(Point pt, int value) {
		_value += value;

		if (_children.empty() && (_area.a != pt || _area.b != pt)) {
			throw std::logic_error("ERROR: Traverse to wrong node.");
		}

		for (auto & child : _children) {
			if (child.contains(pt)) {
				child.add(pt, value);
				break;
			}
		}
	}

	int sum(Rectangle rect) const {
		if (!_area.isOverlap(rect)) {
			return 0;
		}

		auto overlap = _area.overlap(rect);
		if (overlap == _area) {
			return _value;
		}

		int ret = 0;
		for (auto & child : _children) {
			ret += child.sum(rect);
		}

		return ret;
	}

private:
	void _initChildren() {
		if (_area.a != _area.b) {
			Point _a = _area.a;
			Point _b = _area.b;

			Point mid = (_a + _b) / 2;

			Point rta = mid + Point(1, 1);
			Point rtb = _b;
			if (rta <= rtb) {
				_children.push_back(QuadTreeNode(rta, rtb));
			}

			Point lta(_a.x, mid.y + 1);
			Point ltb(mid.x, _b.y);
			if (lta <= ltb) {
				_children.push_back(QuadTreeNode(lta, ltb));
			}

			Point lba = _a;
			Point lbb = mid;
			if (lba <= lbb) {
				_children.push_back(QuadTreeNode(lba, lbb));
			}

			Point rba(mid.x + 1, _a.y);
			Point rbb(_b.x, mid.y);
			if (rba <= rbb) {
				_children.push_back(QuadTreeNode(rba, rbb));
			}
		}
	}

public:
	Rectangle _area;
	int _value = 0;
	std::vector<QuadTreeNode> _children;
};

#endif
