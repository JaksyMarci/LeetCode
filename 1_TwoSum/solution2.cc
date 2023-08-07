#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        for (int i=0; i < nums.size(); i++){
            map[i] = target-nums[i];
        }
        for (int i = 0; i < nums.size(); i++){
            
            if (map.find(nums[i]) != map.end()){
                
                std::vector<int> answer;
                answer.push_back(map[i]); //would need the key here, not the value
                answer.push_back(i);

                return answer;
            }
        }
        return nums;
    }
};