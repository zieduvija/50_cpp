#include <iostream>
#include <algorithm>

int main(){
    int n; std::cin >> n;
    int array[n];
    for(int i = 0; i < n; i++)
        std::cin >> array[i];

    bool hasZero = false;

    for(int i = 0; i < n; i++)
        if(array[i] == 0)
            hasZero = true;

    if(hasZero)
        for (int i = 0; i < n; i++)
            array[i] = array[i] - (array[i] * 2);

    std::sort(array, array + n);

    for(int i = 0; i < n; i++)
        std::cout << array[i] << std::endl;

    return 0;
}