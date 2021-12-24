#include <iostream>
#include <set>
#include <iterator>

using namespace std;

// class Point {
// public:
//     int x;
//     int y;
//
//     Point(int x, int y) {
//         this->x = x;
//         this->y = y;
//     }
// };

class Compare {
public:
    bool operator()(const pair<int, int> p1, const pair<int, int> p2) {
        if (p1.first == p2.first) return p1.second < p2.second;
        return p1.first < p2.first;
    }
};

int count_rect(set<pair<int, int>, Compare> s) {
    int ans = 0;

    for (auto it = s.begin(); it != prev(s.end()); it++) {
        for (auto jt = next(it); jt != s.end(); jt++) {
            pair<int, int> p1 = *it;
            pair<int, int> p2 = *jt;

            if ( (p1.first == p2.first) || (p1.second == p2.second) ) continue;

            pair<int, int> p3{p1.first, p2.second};
            pair<int, int> p4{p2.first, p1.second};

            if ( (s.find(p3) != s.end()) && (s.find(p4) != s.end()) ) ans += 1;
        }
    }

    return ans / 2;
}

int main(void) {
    set<pair<int, int>, Compare> s;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        pair<int, int> p{x, y};
        s.insert(p);
    }

    cout << "No. of rectangles: " << count_rect(s) << endl;

    return 0;
}
