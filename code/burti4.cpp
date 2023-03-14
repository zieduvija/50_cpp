#include <iostream>

int main() {
    std::string word; int count = 0; char x;
    std::cin >> word>> x;
    for(int i = 0 ; i<word.length(); i++)
        if(word[i] == x)
            count++;
    std::cout << count;
}