#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Point {
public:
    int x;
    int y;

    Point (int a, int b) {
        this->x = a;
        this->y = b;
    }
};

class Compare {
public:
    bool operator()(Point a, Point b) {
        if (a.x == b.x) {
            return a.y < b.y;
        }
        else {
            return a.x < b.x;
        }
    }
};

int countRectangles(set<Point, Compare> s) {
    int ans = 0;

    for (auto it = s.begin(); it != prev(s.end()); it++) {
        Point p1 = *it;
        for (auto jt = next(it); jt != s.end(); jt++) {
            Point p2 = *jt;

            if (p1.x == p2.x || p2.y == p1.y) continue;

            Point p3(p2.x, p1.y);
            Point p4(p1.x, p2.y);

            if ( (s.find(p3) != s.end()) && (s.find(p4) != s.end()) ) {
                ans++;
            }
        }
    }

    return ans/2;
}

// int countRectangles(vector<pair<int,int>> points) {
//     unordered_map<
// }

int main(void) {
    int n;
    cin >> n;
    int x, y;

    set<Point, Compare> s;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        Point p(x, y);
        s.insert(p);
        // points.push_back(make_pair{x, y});
    }

    cout << "no. of rectangles: " << countRectangles(s) << endl;

    return 0;
}