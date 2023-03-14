#include <iostream>
#include <algorithm>

int main(){
    int n; std::cin >> n;
    std::string array[n];
    for(int i = 0; i < n; i++)
        std::cin >> array[i];

    std::sort(array, array + n);

    for(int i = 0; i < n; i++)
        std::cout << array[i] << std::endl;

    return 0;
}