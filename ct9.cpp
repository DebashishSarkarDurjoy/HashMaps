#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int countTriangles(vector<pair<int, int>> points) {
    unordered_map<int,int> map_x;
    unordered_map<int,int> map_y;

    for (auto p: points) {
        map_x[p.first]++;
        map_y[p.second]++;
    }

    int total = 0;
    for (auto p: points) {
        total += (map_x[p.first] - 1) * (map_y[p.second] - 1);
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