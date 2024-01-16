#include <iostream>
#include <vector>
#include <map>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    map<int, int> numcount;
    int res = 1;
    int maxlengh = 1;

    for (int i = 0; i < nums.size(); i++) {
        int curr_num = nums[i];
        numcount[curr_num] += 1;
    }

    for (auto iter = numcount.begin(); iter != numcount.end(); iter++) {
        auto next = iter;
        auto nextnext = next;
        nextnext++;
        if (nextnext == numcount.end()) {
            break;
        } else {
            next++;
        }
        if(iter->first + 1 == next->first) {
            maxlengh += 1;
            if (maxlengh > res) {
                res = maxlengh;
            }
        } else {
            maxlengh = 1;
        }
    }
    return res;
}

int main() {
    vector<int> test;
    test.push_back(0);
    test.push_back(3);
    test.push_back(7);
    test.push_back(2);
    test.push_back(5);
    test.push_back(8);
    test.push_back(4);
    test.push_back(6);
    test.push_back(0);
    test.push_back(1);
    printf("%d\n", longestConsecutive(test));
    return 0;
}