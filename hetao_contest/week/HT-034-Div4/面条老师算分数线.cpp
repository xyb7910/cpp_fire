#include <iostream>

int main() {
    int n, m;  
    std::cin >> n >> m;

  
    int entry_level_second_prize = (n >= 250) ? 170 : 80;
    int entry_level_third_prize = (n >= 250) ? 80 : -1; 


    int advanced_level_second_prize = (m >= 165) ? 105 : 60;
    int advanced_level_third_prize = (m >= 165) ? 60 : -1; 

    
    std::cout << entry_level_second_prize << " " << entry_level_third_prize << std::endl;
    std::cout << advanced_level_second_prize << " " << advanced_level_third_prize << std::endl;

    return 0;
}