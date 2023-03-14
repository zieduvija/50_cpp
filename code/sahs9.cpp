#include <iostream>


void drawKing(int pos[], int number);
bool pastav(int rinda, int kollona);
char field[8][8];

// 17/17


int main() {
    std::string position; std::cin >> position;
    std::string obsticle; std::cin >> obsticle;


    int pos[] = {position[0] - 96 - 1,7 - (position[1]  - 48 - 1)};
    int obsticlepos[] = {obsticle[0] - 96 - 1,7 - (obsticle[1]  - 48 - 1)};

    for(int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            field[i][j] = '*';


    field[obsticlepos[1]][obsticlepos[0]] = 69;
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
                    drawKing(new int [2] {j, i},testNum + 1);
                    full = false;
                }
            }
        testNum++;
    }

    field[pos[1]][pos[0]] = 48;
    field[obsticlepos[1]][obsticlepos[0]] = 42;





    for(int i = 0; i < 8; i++) {
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

void drawKing(int pos[], int number) {
    int row = pos[1];
    int col = pos[0];

    bool topRight = true, topLeft = true, bottomRight = true, bottomLeft = true, top = true, bottom = true, left = true, right = true;

        if(topRight)
        {
            if(pastav(row - 1, col + 1) && field[row - 1][col + 1] == 42)
                field[row - 1][col + 1] = number;
            else if(pastav(row - 1, col + 1) && field[row - 1][col + 1] == 69)
                topRight = false;

        }
        if(topLeft)
        {
            if(pastav(row - 1, col - 1) && field[row - 1][col - 1] == 42)
                field[row - 1][col - 1] = number;
            else if(pastav(row - 1, col - 1) && field[row - 1][col - 1] == 69)
                topLeft = false;
        }
        if(bottomRight)
        {
            if(pastav(row + 1, col + 1) && field[row + 1][col + 1] == 42)
                field[row + 1][col + 1] = number;
            else if(pastav(row + 1, col + 1) && field[row + 1][col + 1] == 69)
                bottomRight = false;
        }
        if(bottomLeft)
        {
            if(pastav(row + 1, col - 1) && field[row + 1][col - 1] == 42)
                field[row + 1][col - 1] = number;
            else if(pastav(row + 1, col - 1) && field[row + 1][col - 1] == 69)
                bottomLeft = false;
        }
        if(top)
        {
            if(pastav(row - 1, col) && field[row - 1][col] == 42)
                field[row - 1][col] = number;
            else if(pastav(row - 1, col) && field[row - 1][col] == 69)
                top = false;
        }
        if(bottom)
        {
            if(pastav(row + 1, col) && field[row + 1][col] == 42)
                field[row + 1][col] = number;
            else if(pastav(row + 1, col) && field[row + 1][col] == 69)
                bottom = false;
        }
        if(left)
        {
            if(pastav(row, col - 1) && field[row][col - 1] == 42)
                field[row][col - 1] = number;
            else if(pastav(row, col - 1) && field[row][col - 1] == 69)
                left = false;
        }
        if(right)
        {
            if(pastav(row, col + 1) && field[row][col + 1] == 42)
                field[row][col + 1] = number;
            else if(pastav(row, col + 1) && field[row][col + 1] == 69)
                right = false;
        }



}
