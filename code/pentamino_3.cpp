#include <iostream>

bool checkFit(char type, int row, int col);
bool pastav(int row, int col);
bool field[8][8];

int main() {
    int x;
    std::cin >> x;

    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            field[i][j] = false;
    
    char type;
    int col, row;
    for (int i = 0; i < x; i++) {
        std::cin >> type >> col >> row;
        col--; row--;
        row = 7 - row;

        if (type == 'A')
            field[row][col] = field[row+1][col] = field[row+2][col] = field[row+2][col+1] = field[row+2][col+2] = true;
        else if (type == 'B')
            field[row][col] = field[row+1][col] = field[row+2][col] = field[row][col+1] = field[row+1][col+1] = true;
        else if (type == 'C')
            field[row][col] = field[row][col-1] = field[row+1][col-1] = field[row][col+1] = field[row+1][col+1] = true;
        else if (type == 'D')
            field[row][col] = field[row][col-1] = field[row][col-2] = field[row][col-3] = field[row-1][col] = true;
        else
            field[row][col] = field[row-1][col] = field[row][col-1] = field[row][col-2] = field[row+1][col-2] = true;
    }

    char fitType; std::cin >> fitType;
    int count = 0;

    for(int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (checkFit(fitType, i, j))
                count++;




    std::cout << count;

    return 0;
}

bool checkFit(char type, int row, int col) {
    row = 7-row;
    if (type == 'A')
        return pastav(row, col) && pastav(row+1, col) && pastav(row+2, col) && pastav(row+2, col+1) && pastav(row+2, col+2) && !field[row][col] && !field[row+1][col] && !field[row+2][col] && !field[row+2][col+1] && !field[row+2][col+2];
    else if (type == 'B')
        return pastav(row, col) && pastav(row+1, col) && pastav(row+2, col) && pastav(row, col+1) && pastav(row+1, col+1) && !field[row][col] && !field[row+1][col] && !field[row+2][col] && !field[row][col+1] && !field[row+1][col+1];
    else if (type == 'C')
        return pastav(row, col) && pastav(row, col-1) && pastav(row+1, col-1) && pastav(row, col+1) && pastav(row+1, col+1) && !field[row][col] && !field[row][col-1] && !field[row+1][col-1] && !field[row][col+1] && !field[row+1][col+1];
    else if (type == 'D')
        return pastav(row, col) && pastav(row, col-1) && pastav(row, col-2) && pastav(row, col-3) && pastav(row-1, col) && !field[row][col] && !field[row][col-1] && !field[row][col-2] && !field[row][col-3] && !field[row-1][col];
    else
        return pastav(row, col) && pastav(row-1, col) && pastav(row, col-1) && pastav(row, col-2) && pastav(row+1, col-2) && !field[row][col] && !field[row-1][col] && !field[row][col-1] && !field[row][col-2] && !field[row+1][col-2];


}

bool pastav(int row, int col) {
    return row >= 0 && row < 8 && col >= 0 && col < 8;
}