#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> d;
        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            int y = target - x;
            auto it = d.find(y);
            if (it != d.end()) {
                return {it->second, i};
            }
            d[x] = i;
        }
        return {};
    }
};

int main() {
    // Get input from the user
    int n;
    cout << "Enter the number of elements (must be at least 2): ";
    cin >> n;

    if (n < 2) {
        cout << "Invalid input. The number of elements must be at least 2." << endl;
        return 1;
    }

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    // Check for duplicates
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
        if (freq[num] > 1) {
            cout << "Warning: The number " << num << " appears multiple times in the input." << endl;
        }
    }

    // Call the twoSum function
    Solution solution;
    vector<int> indices = solution.twoSum(nums, target);

    // Output the result
    if (indices.empty()) {
        cout << "No two numbers add up to the target sum of " << target << "." << endl;
    } else {
        cout << "Indices of the two numbers that add up to the target (" << target << "): "
             << indices[0] << " and " << indices[1] << " (" << nums[indices[0]] << " + " << nums[indices[1]] << " = " << target << ")" << endl;
    }

    return 0;
}
