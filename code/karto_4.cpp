#include <iostream>
#include <algorithm>

int main(){
    std::string toReplace, replaceWith; std::cin >> toReplace >> replaceWith;
    int n; std::cin >> n;
    std::string array[n];
    for(int i = 0; i < n; i++)
        std::cin >> array[i];

    for (int i = 0; i < n; ++i)
        if(array[i] == toReplace)
            array[i] = replaceWith;


    std::sort(array, array + n);

    for(int i = 0; i < n; i++)
        std::cout << array[i] << std::endl;

    return 0;
}