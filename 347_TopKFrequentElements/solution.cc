#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

//TODO: slow solution: needs an additional prqueue implemented for optimal performance
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        vector<int> answer;
        for (auto item : nums){
            map[item]++;
        }
        for (int i = 0; i < k; i++){
            //get max value here and remove the associated key
            auto max_pointer = std::max_element(map.begin(), map.end(), 
            [] (const pair<int,int> &p1, const pair<int,int> &p2) {
                return p1.second < p2.second;
                }
            );
            
            answer.push_back(max_pointer->first);
            map.erase(max_pointer->first);
        }
        return answer;

    }
};
