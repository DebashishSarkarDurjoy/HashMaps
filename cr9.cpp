#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Point {
public:
    int x;
    int y;

    Point(int X, int Y) {
        this->x = X;
        this->y = Y;
    }
};

class Compare {
public:
    bool operator()(const Point p1, const Point p2) {
        if (p1.x == p2.x) {
            return p1.y < p2.y;
        }
        else {
            return p1.x < p2.x;
        }
    }
};

int countRectangles(set<Point, Compare> s) {
    int ans = 0;

    for (auto it = s.begin(); it != prev(s.end()); it++) {
        for (auto jt = next(it); jt != s.end(); jt++) {
            Point p1 = *it;
            Point p2 = *jt;

            if (p1.x == p2.x || p1.y == p2.y) continue;

            Point p3(p1.x, p2.y);
            Point p4(p2.x, p1.y);

            if (s.find(p3) != s.end() && s.find(p4) != s.end()) {
                ans++;
            }
        }
    }

    return ans / 2;
}


int main(void) {
    int n;
    cin >> n;
    int x, y;

    set<Point, Compare> s;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        Point p(x, y);

        s.insert(p);
    }

    cout << "no. of rectangles: " << countRectangles(s) << endl;

    return 0;
}
