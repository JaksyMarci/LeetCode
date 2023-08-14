#include <iostream>
#include <string>

int main(){
    size_t amount_of_lines;
    std::cin >> amount_of_lines;
    size_t official_minutes = 0;
    size_t measured_seconds = 0;
    
    for (size_t i = 0; i < amount_of_lines; i++){
        size_t first;
        size_t second;
        std::cin >> first >> second;
        official_minutes+=first;
        measured_seconds+=second;
    }
    double answer =  (double)measured_seconds / (double)(official_minutes * 60);
    std::cout.precision(20);
    answer > 1.0 ? std::cout << answer : std::cout <<"measurement error\n";
    return 0;

}