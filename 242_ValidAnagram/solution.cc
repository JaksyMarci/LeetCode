#include <string>
#include <unordered_map>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::unordered_map<char, int> map;
        for (char letter : s){
          map[letter]++;
          
          
        }
      for (char letter : t){
        map[letter]--;
        
      }
      for (int i =0; i < map.size(); i++){
        if (map[i] != 0){
            return false;
        }
        
      }
      return true;
    }
    
};