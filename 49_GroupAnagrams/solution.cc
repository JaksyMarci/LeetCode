#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        vector<vector<string>> answer;
        

        for (auto str : strs){
            string sorted_string = str;
            sort(sorted_string.begin(), sorted_string.end());
            if (groups[sorted_string].empty()){
                vector<string> v;
                v.push_back(str);
                groups[sorted_string] = v;
            }
            else{
                groups[sorted_string].push_back(str);
            }
            
        }
        for (auto key : groups){

            vector<string> v;
            
            for (auto item : key.second){
                v.push_back(item);
            }
            answer.push_back(v);
        }
        return answer;
    }
};
