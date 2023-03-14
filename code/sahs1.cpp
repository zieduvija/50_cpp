#include <iostream>
// 17/17
// 3/7/2023



int main() {
    std::string position; std::cin >> position;

    int pos[] = {0,0}; char field[8][8];

    pos[1] = position[0] - 96 - 1;
    pos[0] =  7 - (position[1]  - 48 - 1);

    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++) {
            if(i == pos[0] && j == pos[1])
                field[i][j] = '0';
            else if(i == pos[0] || j == pos[1])
                field[i][j] = '1';
            else field[i][j] = '2';

        }

    for(int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            std::cout << field[i][j];
    std::cout << std::endl;
    }

    return 0;
}
