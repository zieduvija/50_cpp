#include <iostream>

int main() {
    std:: string temp, result;
    for(int i = 0 ; i< 5; i++){
        std::cin >> temp;
        result += temp[0];
    }
    std::cout << result;
}