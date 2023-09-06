#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

struct Point {
	int x;
	int y;

	Point(int x = 0, int y = 0) : x(x), y(y) {}
};

bool cmp_x(const Point& lhs, const Point& rhs) {
	return lhs.x < rhs.x;
}

bool cmp_y(const Point& lhs, const Point& rhs) {
	return lhs.y < rhs.y;
}

double distance(const Point& p1, const Point& p2) {
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double findMinDistance(const std::vector<Point>& points, int left, int right) {
	if (left >= right) {
		return INT32_MAX;
	}
	if (right - left == 1) {
		return distance(points[left], points[right]);
	}
	int middle = (left + right) / 2;
	long long middleLine = ((double)points[middle].x + points[middle + 1].x) / 2;
	double d1 = findMinDistance(points, left, middle);
	double d2 = findMinDistance(points, middle + 1, right);
	double d = std::min(d1, d2);
	std::vector<Point> temp_points;
	for (int i = left; i <= right; ++i) {
		if (abs(points[i].x - middleLine) < d) {
			temp_points.push_back(points[i]);
		}
	}
	std::sort(temp_points.begin(), temp_points.end(), cmp_y);
	for (int i = 0; i < temp_points.size(); ++i) {
		for (int j = 0; j < 7; ++j) {
			if (i + 1 + j == temp_points.size()) break;
			d = std::min(d, distance(temp_points[i], temp_points[i + 1 + j]));
		}
	}
	return d;
}

void taskA() {
	int n;
	std::cin >> n;
	std::vector<Point> points(n);
	for (int i = 0; i < n; ++i) {
		int x, y;
		std::cin >> x >> y;
		Point point(x, y);
		points[i] = point;
	}
	std::sort(points.begin(), points.end(), cmp_x);
	std::cout << std::fixed << std::setprecision(6) << findMinDistance(points, 0, n - 1);
}

int main() {
	taskA();
}