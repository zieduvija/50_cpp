#include <iostream>

int main() {
    std::string word;
    char x, y;
    std::cin >> word >> x >> y;

    for(int i = 0 ; i< word.length(); i++)
        if(word[i] == x) word[i] = y;

    std::cout<< word;

}