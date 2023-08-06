#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> numSet;
        for (int elem : nums){
          numSet.insert(elem);
        }
        return nums.size() > numSet.size();
    }
};
