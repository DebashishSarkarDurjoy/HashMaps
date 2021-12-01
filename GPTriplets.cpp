#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


int count_triplets(vector<int> arr, int r) {
    int n = arr.size();
    unordered_map<long, long> left, right;

    // Init the right with freq and left with 0
    for (auto x: arr) {
        right[x]++;
        left[x] = 0;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        right[arr[i]]--;

        if (arr[i] % r == 0) {
            int a = arr[i] / r;
            int b = arr[i];
            int c = arr[i] * r;

            ans += left[a] * right[c];
        }

        left[arr[i]]++;
    }

    return ans;
}

int main(void) {
    int n, r;
    cin >> n >> r;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << count_triplets(arr, r) << endl;

    return 0;
}
