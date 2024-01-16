#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

void moveZeroes(vector<int>& nums) {
    int count = 0;
    int size = nums.size();
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            nums.erase(nums.begin() + i);
            nums.push_back(0);
            i--;
            count++;
        }
        if(count > size) {
            break;
        }
    }
    return;
}

int main() {
    vector<int> test_arr;
    test_arr.push_back(0);
    test_arr.push_back(0);
    test_arr.push_back(1);
    test_arr.push_back(1);
    test_arr.push_back(0);
    test_arr.push_back(0);
    test_arr.push_back(2);
    test_arr.push_back(3);
    moveZeroes(test_arr);
    for (int i = 0; i < test_arr.size(); i++) {
        printf("--%d--momoqingiqng\n", test_arr[i]);
    }
    return 0;
}