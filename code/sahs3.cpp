#include <iostream>
bool pastav(int rinda, int kollona);
void drawQueen(int pos[], char number);
char field[8][8];

// 17/17

int main() {
    std::string position;
    std::cin >> position;

    int pos[] = {position[0] - 96 - 1, 7 - (position[1] - 48 - 1)};

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            field[i][j] = '*';


    drawQueen(pos, '1');
    field[pos[1]][pos[0]] = '0';

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if(field[i][j] == '*')
                field[i][j] = '2';


    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            std::cout << field[i][j];
        std::cout << std::endl;
    }

    return 0;
}


bool pastav(int rinda, int kollona) {
    if (rinda >= 0 && kollona >= 0 && rinda < 8 && kollona < 8)
        return true;
    else
        return false;
}


void drawQueen(int pos[], char number) {
    int row = pos[1]; int col = pos[0];
    for (int i = 0; i < 8; i++) {
        if (pastav(row + i, col + i) && field[row + i][col + i] == '*')
            field[row + i][col + i] = number;
        if (pastav(row + i, col - i) && field[row + i][col - i] == '*' )
            field[row + i][col - i] = number;
        if (pastav(row - i, col + i) && field[row - i][col + i] == '*' )
            field[row - i][col + i] = number;
        if (pastav(row - i, col - i) && field[row - i][col - i] == '*' )
            field[row - i][col - i] = number;
        if(pastav(row + i, col) && field[row + i][col] == '*')
            field[row + i][col] = number;
        if(pastav(row - i, col) && field[row - i][col] == '*')
            field[row - i][col] = number;
        if(pastav(row, col + i) && field[row][col + i] == '*')
            field[row][col + i] = number;
        if(pastav(row, col - i) && field[row][col - i] == '*')
            field[row][col - i] = number;

    }

}





