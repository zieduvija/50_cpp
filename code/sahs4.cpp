#include <iostream>
bool pastav(int rinda, int kollona);
void drawKing(int pos[], char number);
char field[8][8];
// 17/17

int main() {
    std::string position;
    std::cin >> position;

    int pos[] = {position[0] - 96 - 1, 7 - (position[1] - 48 - 1)};

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            field[i][j] = '*';

    drawKing(pos, 49);
    int testNum = 49;
    bool full = false;
    while(!full){
        full = true;
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
            {
                if(field[i][j] == testNum)
                {
                    drawKing(new int [2] {j, i}, testNum + 1);
                    full = false;
                }
            }
        testNum++;
    }

    field[pos[1]][pos[0]] = '0';


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


void drawKing(int pos[], char number) {
    int row = pos[1]; int col = pos[0];

    //top
    if(pastav(row - 1, col) && field[row - 1][col] == '*')
        field[row - 1][col] = number;

    //bottom
    if(pastav(row + 1, col) && field[row + 1][col] == '*')
        field[row + 1][col] = number;

    //left
    if(pastav(row, col - 1) && field[row][col - 1] == '*')
        field[row][col - 1] = number;

    //right
    if(pastav(row, col + 1) && field[row][col + 1] == '*')
        field[row][col + 1] = number;

    //top left
    if(pastav(row - 1, col - 1) && field[row - 1][col - 1] == '*')
        field[row - 1][col - 1] = number;

    //top right
    if(pastav(row - 1, col + 1) && field[row - 1][col + 1] == '*')
        field[row - 1][col + 1] = number;

    //bottom left
    if(pastav(row + 1, col - 1) && field[row + 1][col - 1] == '*')
        field[row + 1][col - 1] = number;

    //bottom right
    if(pastav(row + 1, col + 1) && field[row + 1][col + 1] == '*')
        field[row + 1][col + 1] = number;





}





