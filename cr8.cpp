#include <iostream>
#include <iterator>
#include <set>

using namespace std;

class Point {
public:
    int x;
    int y;

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

class Compare {
public:
    bool operator()(const Point p1, const Point p2) {
        if (p1.x == p2.x) return p1.y < p2.y;
        return p1.x < p2.x;
    }
};

int countRect(set<Point, Compare> s) {
    int ans = 0;

    for (auto it = s.begin(); it != prev(s.end()); it++) {
        for (auto jt = next(it); jt != s.end(); jt++) {
            Point p1 = *it;
            Point p2 = *jt;

            if ( (p1.x == p2.x) || (p1.y == p2.y) ) continue;

            Point p3(p1.x, p2.y);
            Point p4(p2.x, p1.y);

            if ( (s.find(p3) != s.end()) && (s.find(p4) != s.end()) ) ans += 1;
        }
    }

    return ans / 2;
}

int main(void) {
    set<Point, Compare> s;

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        Point p(x, y);
        s.insert(p);
    }

    cout << countRect(s) << endl;

    return 0;
}
