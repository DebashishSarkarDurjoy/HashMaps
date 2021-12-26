#include <iostream>
#include <unordered_map>
#include <vector>
#include <iterator>

using namespace std;

class Point {
public:
    int x;
    int y;

    Point(int a, int b) {
        this->x = a;
        this->y = b;
    }
};

int count_tri(vector<Point> points) {
    int ans = 0;

    unordered_map<int, int> freq_x;
    unordered_map<int, int> freq_y;
    for (auto p: points) {
        freq_x[p.x]++;
        freq_y[p.y]++;
    }

    for (auto p: points) {
        int count_x = freq_x[p.x];
        int count_y = freq_y[p.y];

        ans += (count_x - 1) * (count_y - 1);
        
    }

    return ans;
}

int main(void) {
    vector<Point> points;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        Point p(x, y);
        points.push_back(p);
    }

    cout << "No. of triangles: " << count_tri(points) << endl;

    // for (auto p: points) {
    //     cout << p.x << " " << p.y << endl;
    // }

    return 0;
}
