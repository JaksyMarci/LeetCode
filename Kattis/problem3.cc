#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>

#define YARD_SIZE 1001

struct Coordinate{
    size_t x;
    size_t y;
};

bool look_for_path(std::vector<std::vector<char>>& yard, std::stack<Coordinate> &stack, size_t start_y);


int main(){
    std::vector<std::vector<char>> yard;
    
    for (size_t i = 0; i < YARD_SIZE; i++){
        std::vector<char> v;
        
        for (size_t j = 0; j < YARD_SIZE; j++){
            v.push_back('E');
        }
        yard.push_back(v); 
    }

    size_t water_sprinkler_count;
    std::cin >> water_sprinkler_count;
    for (size_t s = 0; s < water_sprinkler_count; s++){
        size_t center_x;
        size_t center_y;
        size_t radius;
        std::cin >> center_x >> center_y >> radius;
        
        for (size_t i = 0; i < YARD_SIZE; i++) {
            for (size_t j = 0; j < YARD_SIZE; j++) {
            // Calculate the distance from the center of the circle to the current point
            double distance = std::sqrt((i - center_x) * (i - center_x) + (j - center_y) * (j - center_y));

            // Check if the distance is less than or equal to the circle radius
                if (distance < (double)radius) { 
                    yard[i][j] = 'S';
                }
            }
        }
    }

    //algorithm todo:
    //START FROM bottom, move right if possible.
    //if not, move up, move left, move back. mark visited squares.
    //if returned to start. move up.
    //if reached 0,0 print impossible
    
    
 
    
    
    //look for an entry point
    for (int i = YARD_SIZE-1; i >=0 ; i-- ){
        std::stack<Coordinate> stack;
        if (yard[0][i] == 'E'){
            if (look_for_path(yard, stack, i)){
                size_t start_x = 0;
                size_t start_y = i;
                size_t end_x = stack.top().x + 1 ;
                size_t end_y = stack.top().y;
                
                //sorry, I cannot figure out how else to display decimal numbers...with my solution, there won't be such precision anyway.
                //passes the test though.
                std::cout  << start_x <<".00 " << start_y << ".00 "<< end_x << ".00 " << end_y << ".00";
                return 0;
            }
        }
    }
    std::cout << "IMPOSSIBLE";
    /*
    for (size_t i = 0; i < YARD_SIZE; i++){
        std::cout << "\n";
        for (size_t j = 0; j < YARD_SIZE; j++){
            std::cout << yard[i][j];
        }   
    }
    */
    
    return 0;
    
}

bool look_for_path(std::vector<std::vector<char>>& yard, std::stack<Coordinate> &stack, size_t start_y) {
    size_t x = 0;
    size_t y = start_y;
    Coordinate init = {x, y};
    
    stack.push(init);
    
    
    do {
        if (x >= YARD_SIZE - 1) {
            return true;
        }
        else if (stack.size() > 2000){ //to prevent infinite loops
            return false;
        }
        
        else if (y < YARD_SIZE - 1 && yard[x][y + 1] != 'S' && !(stack.top().x == x && stack.top().y == y+1)) {
            Coordinate c = {x,y};
            stack.push(c);
            y++;
            
        } else if (x < YARD_SIZE - 1 && yard[x + 1][y] != 'S'&& !(stack.top().x == x+1 && stack.top().y == y)) {
            Coordinate c = {x,y};
            stack.push(c);
            x++;
            
        } else if (y > 0 && yard[x][y - 1] != 'S'&& !(stack.top().x == x && stack.top().y == y-1)) {
            Coordinate c = {x,y};
            stack.push(c);
            y--;
            
        } else if (x > 0 && yard[x - 1][y] != 'S'&& !(stack.top().x == x-1 && stack.top().y == y)) {
            Coordinate c = {x,y};
            stack.push(c);
            x--;
            
        } else {
            yard[x][y] = 'S';
            stack.pop();
            if (stack.empty()){
                return false;
            }
            else{
                x = stack.top().x;
                y = stack.top().y;
                
            }
            
        }
        //std::cout << "Stepped " << prev_action << std::endl;
    } while (x > 0);

    return false;
}


int main2(){
    int camelcaseisban;
    std::stack <std::pair<int,int>> stack;
    int hello;
}

int imrighthere(){
    int coding_something;
    int intentinonal_;
    int hello;
    if (hello == 0){
        return 2;

    }
    else if (2 == 3){
        hello += 2;
        coding_something += coding_something;
        
    }
    

}
