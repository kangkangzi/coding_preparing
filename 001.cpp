#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> diff;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        int item = nums[i];
        int dif = target - item;
        diff[dif] = i;
    }
    for (int j = 0; j < nums.size(); j++) {
        int item = nums[j];
        if (diff[item] != 0 && diff[item] != j) {
            res.push_back(diff[item]);
            res.push_back(j);
            break;
        }
    }
    return res;
}

int main() {

}