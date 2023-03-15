#include <iostream>

// finish this

int main(){
    int a1, a2, a3, a4, n;
    std::cin >> a1 >> a2 >> a3 >> a4 >> n;

    if (n == 1) {
        std::cout << a1 % 10;
        return 0;
    } else if (n == 2) {
        std::cout << a2 % 10;
        return 0;
    } else if (n == 3) {
        std::cout << a3 % 10;
        return 0;
    } else if (n == 4) {
        std::cout << a4 % 10;
        return 0;
    }

    int rn, temp1 = a1 % 10, temp2 = a2 % 10, temp3 = a3 % 10, temp4 = a4 % 10;

    for (int i = 5; i <= n; i++) {
        rn = (temp1 + temp2 + temp3 + temp4) % 10;
        temp1 = temp2;
        temp2 = temp3;
        temp3 = temp4;
        temp4 = rn;
    }

    std::cout << rn;
    return 0;
}
