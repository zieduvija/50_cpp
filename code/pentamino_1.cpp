#include <iostream>

int main() {
    int x;
    std::cin >> x;

    bool field[8][8];

    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            field[i][j] = false;

    for (int i = 0; i < x; i++) {
        char type; int col, row;
        std::cin >> type >> col >> row;
        col--; row--;
        row = 7 - row;

        if (type == 'A') {
            field[row][col] = field[row+1][col] = field[row+2][col] = field[row+2][col+1] = field[row+2][col+2] = true;
        } else if (type == 'B') {
            field[row][col] = field[row+1][col] = field[row+2][col] = field[row][col+1] = field[row+1][col+1] = true;
        } else if (type == 'C') {
            field[row][col] = field[row][col-1] = field[row][col-2] = field[row][col-3] = field[row-1][col] = true;
        }


    }

    int count = 0;

    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            if(field[i][j] == true)
                count++;

    std::cout << count;

    return 0;
}
