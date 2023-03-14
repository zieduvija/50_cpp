#include <iostream>


void drawRook(int pos[], int number);
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
    drawRook(pos, 49);

    int testNum = 49;
    bool full = false;
    while(!full){
        full = true;
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
            {
                if(field[i][j] == testNum)
                {
                    drawRook(new int [2] {j, i},testNum + 1);
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

void drawRook(int pos[], int number) {
    int row = pos[1];
    int col = pos[0];

    bool right = true, left = true, up = true, down = true;

    for(int i = 0; i< 8; i++)
    {
        //right
        if(right)
        {
            if(pastav(row, col + i) && field[row][col + i] == '*')
                field[row][col + i] = number;
            else if(pastav(row, col + i) && field[row][col + i] == 69)
                right = false;


        }
        //left
        if(left)
        {
            if(pastav(row, col - i) && field[row][col - i] == '*')
                field[row][col - i] = number;
            else if(pastav(row, col - i) && field[row][col - i] == 69)
                left = false;

        }
        //up
        if(up)
        {
            if(pastav(row - i, col) && field[row - i][col] == '*')
                field[row - i][col] = number;
            else if(pastav(row - i, col) && field[row - i][col] == 69)
                up = false;

        }
        //down
        if(down)
        {
            if(pastav(row + i, col) && field[row + i][col] == '*')
                field[row + i][col] = number;
            else if(pastav(row + i, col) && field[row + i][col] == 69)
                down = false;

        }

    }
}
