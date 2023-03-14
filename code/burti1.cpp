#include <iostream>
int main() {
    std::string word;
    int count = 0;
    std::cin >> word;
    for(int i = 0; i<word.length(); i++)
        if(word[i] == 'a') count++;
    std::cout << count;
}