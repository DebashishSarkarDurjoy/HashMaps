#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int countTriplets(vector<int> nums, int r) {
    unordered_map<long, long> left, right;

    for (auto num: nums) {
        left[num] = 0;
        right[num]++;
    }

    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        right[nums[i]]--;
        if (nums[i] % r == 0) {
            int a = nums[i] / r;
            int b = nums[i];
            int c = nums[i] * r;

            ans += left[a] * right[c];
        }

        left[nums[i]]++;
    }

    return ans;
}

int main(void) {
    vector<int> inputs;
    int r;
    int n;

    cin >> n >> r;
    for (int i = 0; i < n; i++) {
        int in;
        cin >> in;
        inputs.push_back(in);
    }

    cout << "No. of Triplets: " << countTriplets(inputs, r) << endl;

    return 0;
}
