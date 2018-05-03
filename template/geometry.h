#ifndef __H_GEOMETRY__
#define __H_GEOMETRY__

/**
* @file geometry.h
* @author yewmint
*/

#include <stdexcept>

/**
* Point template
* 
* @typename T type of coordinates
*/
template<typename T>
struct Point_ {
	T x, y;
	Point_(int x, int y) : x(x), y(y) {};

	Point_ operator+(const Point_ & pt) const { return Point_(x + pt.x, y + pt.y); }
	Point_ operator-(const Point_ & pt) const { return Point_(x - pt.x, y - pt.y); }
	Point_ operator*(int val) const { return Point_(x * val, y * val); }
	Point_ operator/(int val) const { return Point_(x / val, y / val); }

	void operator+=(const Point_ & pt) { x += pt.x; y += pt.y; }
	void operator-=(const Point_ & pt) { x -= pt.x; y -= pt.y; }
	void operator*=(int val) { x *= val; y *= val; }
	void operator/=(int val) { x /= val; y /= val; }

	bool operator==(const Point_ & pt) const { return x == pt.x && y == pt.y; }
	bool operator!=(const Point_ & pt) const { return x != pt.x || y != pt.y; }
	bool operator<(const Point_ & pt) const { return x < pt.x && y < pt.y; }
	bool operator<=(const Point_ & pt) const { return x <= pt.x && y <= pt.y; }
	bool operator>(const Point_ & pt) const { return x > pt.x && y > pt.y; }
	bool operator>=(const Point_ & pt) const { return x >= pt.x && y >= pt.y; }
};

/**
* format output to std::cout
*
* @param os output stream
* @param pt point
*/
template<typename T>
std::ostream &operator<<(std::ostream &os, Point_<T> const &pt) {
	return os << "(" << pt.x << ", " << pt.y << ")";
}

/**
* Rectangle template
* 
* @typename T type of points
*/
template<typename T>
struct Rectangle_ {
	Point_<T> a, b;
	Rectangle_(Point_<T> a, Point_<T> b) : a(a), b(b) {};

	bool operator==(const Rectangle_ & rect) const { return a == rect.a && b == rect.b; }

	/**
	* check if this rectangle is disjoint with another
	*
	* @param rect another rectangle
	*/
	bool isDisjoint(const Rectangle_ rect) const {
		return a.x > rect.b.x || a.y > rect.b.y || b.x < rect.a.x || b.y < rect.a.y;
	}

	/**
	* check if this rectangle is overlap with another
	*
	* @param rect another rectangle
	*/
	bool isOverlap(const Rectangle_ rect) const {
		return !isDisjoint(rect);
	}

	/**
	* check if this rectangle contains a point
	*
	* @param pt point
	*/
	bool contains(const Point_<T> pt) const {
		return pt.x >= a.x && pt.x <= b.x && pt.y >= a.y && pt.y <= b.y;
	}

	/**
	* calculate overlap of 2 rectangles
	*
	* @param rect another rectangle
	*/
	Rectangle_ overlap(const Rectangle_ rect) const {
		Point_<T> newA(std::max(a.x, rect.a.x), std::max(a.y, rect.a.y));
		Point_<T> newB(std::min(b.x, rect.b.x), std::min(b.y, rect.b.y));

		if (newA <= newB) {
			return Rectangle_(newA, newB);
		}
		else {
			throw std::logic_error("ERROR: Can't overlap 2 disjoint rectangles.");
		}
	}
};

/**
* format output to std::cout
*
* @param os output stream
* @param rect rectangle
*/
template<typename T>
std::ostream &operator<<(std::ostream &os, Rectangle_<T> const &rect) {
	return os << rect.a << " -> " << rect.b;
}

typedef Point_<int> Point;
typedef Rectangle_<int> Rectangle;

#endif
