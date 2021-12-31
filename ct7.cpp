#include <iostream>
#include <unordered_map>
#include <vector>

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

int countTri(vector<Point> points) {
    unordered_map<int, int> freq_x;
    unordered_map<int, int> freq_y;

    for (auto p:points) {
        freq_x[p.x]++;
        freq_y[p.y]++;
    }

    int ans = 0;
    for (auto p:points) {
        int count_x = freq_x[p.x];
        int count_y = freq_y[p.y];

        ans += (count_x - 1) * (count_y - 1);
    }

    return ans;
}

int main(void) {
    int N;
    cin >> N;

    vector<Point> points;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        Point p(x, y);
        points.push_back(p);
    }

    cout << countTri(points) << endl;

    return 0;
}
