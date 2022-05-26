#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int gpTriplets(vector<int> inputs, int r) {
    unordered_map<long, long> left, right;
    int totalWays = 0;

    for (int val: inputs) {
        left[val] = 0;
        right[val]++;
    }

    for (int i = 0; i < inputs.size(); i++) {
        if (inputs[i] % r == 0) {
            long a = inputs[i] / r;
            long b = inputs[i];
            long c = inputs[i] * r;

            totalWays += (left[a]) * (right[c]);
        }

        left[inputs[i]]++;
        right[inputs[i]]--;
    }

    return totalWays;
}

int main(void) {
    vector<int> nums;

    int n, r;
    cin >> n >> r;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        nums.push_back(input);
    }

    cout << "Number of ways of gp triplets: " << gpTriplets(nums, r) << endl;

    return 0;
}
