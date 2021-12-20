#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int count_triangles(vector<pair<int, int>> &points) {
    int ans = 0;
    unordered_map<int, int> freq_x;
    unordered_map<int, int> freq_y;

    for (auto p: points) {
        freq_x[p.first]++;
        freq_y[p.second]++;
    }

    // for (auto it: freq_x) {
    //     cout << it.first <<  ' ' << it.second << endl;
    // }

    for (auto p: points) {
        int count_x = freq_x[p.first];
        int count_y = freq_y[p.second];

        ans += (count_x - 1) * (count_y - 1);

    }

    return ans;
}

int main(void) {
    vector<pair<int,int>> points;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        points.push_back({x, y});
    }

    cout << "No. of triangles: " << count_triangles(points) << endl;

    //
    // cout << "The points: " << endl;
    // for (auto p: points) {
    //     cout << p.first << " " << p.second << endl;
    //
    // }

    return 0;
}
