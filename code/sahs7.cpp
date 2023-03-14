#include <iostream>


void drawBishop(int pos[], int number);
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
    drawBishop(pos, 49);

    int testNum = 49;
    bool full = false;
    while(!full){
        full = true;
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
            {
                if(field[i][j] == testNum)
                {
                    drawBishop(new int [2] {j, i},testNum + 1);
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

void drawBishop(int pos[], int number) {
    int row = pos[1];
    int col = pos[0];

    bool topRight = true, topLeft = true, bottomRight = true, bottomLeft = true;

    for(int i = 0; i< 8; i++)
    {
        if(topRight)
        {
            if(pastav(row - i, col + i) && field[row - i][col + i] == 42)
                field[row - i][col + i] = number;
            else if(pastav(row - i, col + i) && field[row - i][col + i] == 69)
                topRight = false;

        }
        if(topLeft)
        {
            if(pastav(row - i, col - i) && field[row - i][col - i] == 42)
                field[row - i][col - i] = number;
            else if(pastav(row - i, col - i) && field[row - i][col - i] == 69)
                topLeft = false;
        }
        if(bottomRight)
        {
            if(pastav(row + i, col + i) && field[row + i][col + i] == 42)
                field[row + i][col + i] = number;
            else if(pastav(row + i, col + i) && field[row + i][col + i] == 69)
                bottomRight = false;
        }
        if(bottomLeft)
        {
            if(pastav(row + i, col - i) && field[row + i][col - i] == 42)
                field[row + i][col - i] = number;
            else if(pastav(row + i, col - i) && field[row + i][col - i] == 69)
                bottomLeft = false;
        }


    }
}
