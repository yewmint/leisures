#ifndef __H_GEOMETRY__
#define __H_GEOMETRY__

#include <stdexcept>
#include <algorithm>
#include <vector>

struct Point {
	int x, y;
	Point(int x, int y) : x(x), y(y) {};
};

bool operator==(const Point & lhs, const Point & rhs) { return lhs.x == rhs.x && lhs.y == rhs.y; };
bool operator!=(const Point & lhs, const Point & rhs) { return lhs.x != rhs.x || lhs.y != rhs.y; };

struct Rect {
	Point leftBottom, rightTop;
	Rect(Point leftBottom, Point rightTop) : leftBottom(leftBottom), rightTop(rightTop) {};
};

bool operator==(const Rect & lhs, const Rect & rhs) { return lhs.leftBottom == rhs.leftBottom && lhs.rightTop == rhs.rightTop; };

inline Point middle(const Point & a, const Point & b) {
	return Point((a.x + b.x) / 2, (a.y + b.y) / 2);
}

inline bool isOverlay(const Rect & a, const Rect & b) {
	return !(
		a.leftBottom.x > b.rightTop.x ||
		a.leftBottom.y > b.rightTop.y ||
		b.leftBottom.x > a.rightTop.x ||
		b.leftBottom.y > a.rightTop.y
	);
}

inline Rect overlay(const Rect & a, const Rect & b) {
	if (!isOverlay(a, b)) {
		throw std::logic_error("Can't overlay seperate rectangles.");
	}

	Point lb(std::max(a.leftBottom.x, b.leftBottom.x), std::max(a.leftBottom.y, b.leftBottom.y));
	Point rt(std::min(a.rightTop.x, b.rightTop.x), std::min(a.rightTop.y, b.rightTop.y));

	return Rect(lb, rt);
}

inline int rectSize(const Rect & rect) {
	return (rect.rightTop.x - rect.leftBottom.x) * (rect.rightTop.y - rect.leftBottom.y);
}

inline bool contains(const Rect & rect, const Point & pt) {
	return (
		rect.leftBottom.x <= pt.x &&
		rect.rightTop.x >= pt.x &&
		rect.leftBottom.y <= pt.y &&
		rect.rightTop.y >= pt.y
	);
}

inline bool canSplit(const Rect & rect) {
	return rect.leftBottom != rect.rightTop;
}

inline std::vector<Rect> split(const Rect & rect) {
	if (!canSplit(rect)) {
		throw std::logic_error("Can't split empty rectangle.");
	}

	if (rect == Rect(Point(2, 2), Point(3, 3))) {
		Point a(1, 1);
	}

	const Point & lb = rect.leftBottom;
	const Point & rt = rect.rightTop;

	std::vector<Rect> ret;

	Point lblb = lb;
	Point lbrt = middle(lb, rt);
	ret.push_back(Rect(lblb, lbrt));

	if (rt.y > lbrt.y) {
		Point ltlb(lblb.x, lbrt.y + 1);
		Point ltrt(lbrt.x, rt.y);
		ret.push_back(Rect(ltlb, ltrt));
	}

	if (rt.x > lbrt.x) {
		Point rblb(lbrt.x + 1, lblb.y);
		Point rbrt(rt.x, lbrt.y);
		ret.push_back(Rect(rblb, rbrt));
	}

	if (rt.y > lbrt.y && rt.x > lbrt.x) {
		Point rtlb(lbrt.x + 1, lbrt.y + 1);
		Point rtrt = rt;
		ret.push_back(Rect(rtlb, rtrt));
	}

	return ret;
}

#endif
