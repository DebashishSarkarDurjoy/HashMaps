#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countTriangles(vector<pair<int, int>> &points) {
    int total = 0;

    unordered_map<int, int> freq_x;
    unordered_map<int, int> freq_y;

    for (auto point: points) {
        freq_x[point.first]++;
        freq_y[point.second]++;
    }

    for (auto point: points) {
        total += (freq_x[point.first] - 1) * (freq_y[point.second] - 1);
    }

    return total;
}


int main(void) {
    vector<pair<int, int>> points;
    int n;
    cin >> n;

    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        points.push_back({x, y});
    }

    cout << "No. of triangles: " << countTriangles(points) << endl;

    return 0;
}
