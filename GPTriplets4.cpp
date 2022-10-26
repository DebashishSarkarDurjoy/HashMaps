#include <iostream>
#include <unordered_map>
#include <vector>
#include <math.h>

using namespace std;

int gpTriplets(vector<double> nums, int ratio) {
    unordered_map<double, int> left;
    unordered_map<double, int> right;

    for (auto n: nums) {
        right[n]++;
        // left[n] = 0;
    }

    right[nums[0]]--;
    left[nums[0]]++;
    int total = 0;
    for (int i = 1; i < nums.size()-1; i++) {
        right[nums[i]]--;
        if (fmod(nums[i], ratio) == 0) {
            double current = nums[i];
            double first = current / ratio;
            double second = current * ratio;

            total += left[first] * right[second];
        }

        left[nums[i]]++;
    }

    return total;
}

int main(void) {
    vector<double> nums;

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