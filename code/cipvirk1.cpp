#include <iostream>

int main(){
    int a1, a2, n;
    std::cin >> a1 >> a2 >> n;


    if (n == 2) {
        std::cout << a2;
        return 0;
    }

    int a3;
    for (int i = 3; i <= n; i++) {
        a3 = (a1 + a2) % 10; a1 = a2; a2 = a3;
    }

    std::cout << a3;
    return 0;
}