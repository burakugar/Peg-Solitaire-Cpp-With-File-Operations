// BURAK UGAR HW1 200104004100
#include <iostream>
#include "checking_functions.h"
#include "grids.h"
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <random>
#include <sstream>
#include <fstream> // for file operations
// FOR BOARD 6, UP DIRECTION MEANS RIGHT AND UP DIRECTION,
// DOWN MEANS LEFT DOWN DIRECTION.
std::vector<std::vector<grid_type> > board7 = { // 6x6 board
    {grid_type::peg, grid_type::wall, grid_type::wall, grid_type::peg, grid_type::wall, grid_type::peg},
    {grid_type::peg, grid_type::wall, grid_type::wall, grid_type::peg, grid_type::wall, grid_type::peg},
    {grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg}, 
    {grid_type::peg, grid_type::peg, grid_type::peg, grid_type::space, grid_type::peg, grid_type::peg}, 
    {grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg}, 
    {grid_type::peg, grid_type::peg, grid_type::wall, grid_type::peg, grid_type::peg, grid_type::peg}};
std::vector<std::vector<grid_type> > board8 = { // 8x8 board
    {grid_type::peg, grid_type::wall, grid_type::wall, grid_type::peg, grid_type::peg, grid_type::wall, grid_type::wall, grid_type::peg},
    {grid_type::peg, grid_type::wall, grid_type::wall, grid_type::peg, grid_type::peg, grid_type::wall, grid_type::wall, grid_type::peg},
    {grid_type::peg, grid_type::wall, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::wall, grid_type::peg},
    {grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg},
    {grid_type::peg ,grid_type::peg, grid_type::peg, grid_type::peg, grid_type::space, grid_type::peg, grid_type::peg, grid_type::peg},
    {grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg},
    {grid_type::peg, grid_type::wall, grid_type::wall, grid_type::peg, grid_type::peg, grid_type::wall, grid_type::wall, grid_type::peg},
    {grid_type::peg, grid_type::wall, grid_type::wall, grid_type::peg, grid_type::peg, grid_type::wall, grid_type::wall, grid_type::peg}};
std::vector<std::vector<grid_type> > board9 = { // 7x7 board
    {grid_type::wall, grid_type::wall, grid_type::wall, grid_type::peg, grid_type::peg, grid_type::wall, grid_type::wall},
    {grid_type::wall, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::wall},
    {grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::wall},
    {grid_type::peg, grid_type::peg, grid_type::peg, grid_type::space, grid_type::peg, grid_type::peg, grid_type::peg},
    {grid_type::wall, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg},
    {grid_type::wall, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::wall, grid_type::wall},
    {grid_type::wall, grid_type::wall, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::wall, grid_type::wall}};
enum check_direction
{
    ok = 1, // direction control enum
    notok = 0
};
double round(double d) // the function that rounds the float numbers to closest integer
{
    return floor(d + 0.5);
}
void print_last_grid(std::vector<std::vector<grid_type>> board) // function that prints the 6'th grid
{
    int counter;
    int ascii;
    int capacity = 9;
    ascii = static_cast<int>('a'); // since the coloums are named as (a,b,c..), to be able to find the corresponding col
    // numbers, i used casting
    std::cout << std::endl;
    for (int i = 0; i < 5; i++)
    {
        while (i == 0 && ascii != (char)'a' + capacity)
        {
            if (i == 0 && ascii == (char)'a')
            {
                std::cout << "  ";
            }
            std::cout << (char)ascii << "";
            ascii++;
            if (ascii == (char)'a' + capacity)
            {
                std::cout << std::endl;
            }
        }
        std::cout << i + 1 << ' ';
        for (int j = 0; j < 9; j++)
        {

            if (board[i][j] == grid_type::peg)
            {
                std::cout << "P"; // pegs are shown as P
            }
            else if (board[i][j] == grid_type::wall)
            {
                std::cout << " "; // walls are shown as whitespaces
            }
            else if (board[i][j] == grid_type::space)
            {
                std::cout << "*"; // spaces are shown as *
            }
        }
        std::cout << std::endl;
        counter++;
    }
}
void print_grid(std::vector<std::vector<grid_type>> board)
{ // function that firstly determines the board type using
    // capacity function then prints it into the screen. Also it is returning the capacity which is the one dimension of
    // the grid such as 7,8 or 9{
    int ascii;
    int counter = 1;
    int capacity = board.capacity();
        if (capacity == 6) // for boards which are 6x6
    {
        ascii = static_cast<int>('a'); //  since the coloums are named as (a,b,c..), to be able to find the corresponding col
                                       // numbers, i used casting
        std::cout << std::endl;
        for (int i = 0; i < 6; i++)
        {
            while (i == 0 && ascii != (char)'a' + capacity)
            {
                if (i == 0 && ascii == (char)'a')
                {
                    std::cout << "  ";
                }
                std::cout << (char)ascii << "";
                ascii++;
                if (ascii == (char)'a' + capacity)
                {
                    std::cout << std::endl;
                }
            }
            std::cout << i + 1 << ' ';
            for (int j = 0; j < 6; j++)
            {

                if (board[i][j] == grid_type::peg)
                {
                    std::cout << "P"; // pegs are shown as P
                }
                else if (board[i][j] == grid_type::wall)
                {
                    std::cout << " "; // walls are shown as whitespaces
                }
                else if (board[i][j] == grid_type::space)
                {
                    std::cout << "*"; // spaces are shown as *
                }
            }
            std::cout << std::endl;
            counter++;
        }
    }
    else if (capacity == 7) // for boards which are 7x7
    {
        ascii = static_cast<int>('a'); //  since the coloums are named as (a,b,c..), to be able to find the corresponding col
                                       // numbers, i used casting
        std::cout << std::endl;
        for (int i = 0; i < 7; i++)
        {
            while (i == 0 && ascii != (char)'a' + capacity)
            {
                if (i == 0 && ascii == (char)'a')
                {
                    std::cout << "  ";
                }
                std::cout << (char)ascii << "";
                ascii++;
                if (ascii == (char)'a' + capacity)
                {
                    std::cout << std::endl;
                }
            }
            std::cout << i + 1 << ' ';
            for (int j = 0; j < 7; j++)
            {

                if (board[i][j] == grid_type::peg)
                {
                    std::cout << "P"; // pegs are shown as P
                }
                else if (board[i][j] == grid_type::wall)
                {
                    std::cout << " "; // walls are shown as whitespaces
                }
                else if (board[i][j] == grid_type::space)
                {
                    std::cout << "*"; // spaces are shown as *
                }
            }
            std::cout << std::endl;
            counter++;
        }
    }
    else if (capacity == 8) // for boards which are 8x8
    {
        ascii = static_cast<int>('a');
        std::cout << std::endl;
        for (int i = 0; i < 8; i++)
        {
            while (i == 0 && ascii != (char)'a' + capacity) // same casting as shown below
            {
                if (i == 0 && ascii == (char)'a')
                {
                    std::cout << "  ";
                }
                std::cout << (char)ascii << "";
                ascii++;
                if (ascii == (char)'a' + capacity)
                {
                    std::cout << std::endl;
                }
            }
            std::cout << i + 1 << ' ';

            for (int j = 0; j < 8; j++)
            {
                if (board[i][j] == grid_type::peg)
                {
                    std::cout << "P"; // pegs are shown as P
                }
                else if (board[i][j] == grid_type::wall)
                {
                    std::cout << " "; // walls are shown as whitespaces
                }
                else if (board[i][j] == grid_type::space)
                {
                    std::cout << "*"; // spaces are shown as *
                }
            }
            std::cout << std::endl;
        }
    }
    else if (capacity == 9) // for boards which are 9x9
    {
        ascii = static_cast<int>('a'); // casting
        std::cout << std::endl;
        for (int i = 0; i < 9; i++)
        {
            while (i == 0 && ascii != (char)'a' + capacity)
            {
                if (i == 0 && ascii == (char)'a')
                {
                    std::cout << "  ";
                }
                std::cout << (char)ascii << "";
                ascii++;
                if (ascii == (char)'a' + capacity)
                {
                    std::cout << std::endl;
                }
            }
            std::cout << i + 1 << ' ';
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == grid_type::peg) // pegs are shown as *
                {
                    std::cout << "P";
                }
                else if (board[i][j] == grid_type::wall) // walls are shown as whitespaces
                {
                    std::cout << " ";
                }
                else if (board[i][j] == grid_type::space) // spaces are shown as *
                {
                    std::cout << "*";
                }
            }
            std::cout << std::endl;
        }
    }
}
void print_grid1(std::vector<std::vector<grid_type>> board,int capacity)
{ // function that firstly determines the board type using
    // capacity function then prints it into the screen. Also it is returning the capacity which is the one dimension of
    // the grid such as 7,8 or 9{
    int ascii;
    int counter = 1;
        if (capacity == 6) // for boards which are 6x6
    {
        ascii = static_cast<int>('a'); //  since the coloums are named as (a,b,c..), to be able to find the corresponding col
                                       // numbers, i used casting
        std::cout << std::endl;
        for (int i = 0; i < 6; i++)
        {
            while (i == 0 && ascii != (char)'a' + capacity)
            {
                if (i == 0 && ascii == (char)'a')
                {
                    std::cout << "  ";
                }
                std::cout << (char)ascii << "";
                ascii++;
                if (ascii == (char)'a' + capacity)
                {
                    std::cout << std::endl;
                }
            }
            std::cout << i + 1 << ' ';
            for (int j = 0; j < 6; j++)
            {

                if (board[i][j] == grid_type::peg)
                {
                    std::cout << "P"; // pegs are shown as P
                }
                else if (board[i][j] == grid_type::wall)
                {
                    std::cout << " "; // walls are shown as whitespaces
                }
                else if (board[i][j] == grid_type::space)
                {
                    std::cout << "*"; // spaces are shown as *
                }
            }
            std::cout << std::endl;
            counter++;
        }
    }
    else if (capacity == 7) // for boards which are 7x7
    {
        ascii = static_cast<int>('a'); //  since the coloums are named as (a,b,c..), to be able to find the corresponding col
                                       // numbers, i used casting
        std::cout << std::endl;
        for (int i = 0; i < 7; i++)
        {
            while (i == 0 && ascii != (char)'a' + capacity)
            {
                if (i == 0 && ascii == (char)'a')
                {
                    std::cout << "  ";
                }
                std::cout << (char)ascii << "";
                ascii++;
                if (ascii == (char)'a' + capacity)
                {
                    std::cout << std::endl;
                }
            }
            std::cout << i + 1 << ' ';
            for (int j = 0; j < 7; j++)
            {

                if (board[i][j] == grid_type::peg)
                {
                    std::cout << "P"; // pegs are shown as P
                }
                else if (board[i][j] == grid_type::wall)
                {
                    std::cout << " "; // walls are shown as whitespaces
                }
                else if (board[i][j] == grid_type::space)
                {
                    std::cout << "*"; // spaces are shown as *
                }
            }
            std::cout << std::endl;
            counter++;
        }
    }
    else if (capacity == 8) // for boards which are 8x8
    {
        ascii = static_cast<int>('a');
        std::cout << std::endl;
        for (int i = 0; i < 8; i++)
        {
            while (i == 0 && ascii != (char)'a' + capacity) // same casting as shown below
            {
                if (i == 0 && ascii == (char)'a')
                {
                    std::cout << "  ";
                }
                std::cout << (char)ascii << "";
                ascii++;
                if (ascii == (char)'a' + capacity)
                {
                    std::cout << std::endl;
                }
            }
            std::cout << i + 1 << ' ';

            for (int j = 0; j < 8; j++)
            {
                if (board[i][j] == grid_type::peg)
                {
                    std::cout << "P"; // pegs are shown as P
                }
                else if (board[i][j] == grid_type::wall)
                {
                    std::cout << " "; // walls are shown as whitespaces
                }
                else if (board[i][j] == grid_type::space)
                {
                    std::cout << "*"; // spaces are shown as *
                }
            }
            std::cout << std::endl;
        }
    }
    else if (capacity == 9) // for boards which are 9x9
    {
        ascii = static_cast<int>('a'); // casting
        std::cout << std::endl;
        for (int i = 0; i < 9; i++)
        {
            while (i == 0 && ascii != (char)'a' + capacity)
            {
                if (i == 0 && ascii == (char)'a')
                {
                    std::cout << "  ";
                }
                std::cout << (char)ascii << "";
                ascii++;
                if (ascii == (char)'a' + capacity)
                {
                    std::cout << std::endl;
                }
            }
            std::cout << i + 1 << ' ';
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == grid_type::peg) // pegs are shown as *
                {
                    std::cout << "P";
                }
                else if (board[i][j] == grid_type::wall) // walls are shown as whitespaces
                {
                    std::cout << " ";
                }
                else if (board[i][j] == grid_type::space) // spaces are shown as *
                {
                    std::cout << "*";
                }
            }
            std::cout << std::endl;
        }
    }
}
int check_left(std::vector<std::vector<grid_type>> board, int i, int j)
// function that checks a given cell of the grid 1,2,3,4 and 5 so that
//whether it has a left move or not
{
    int capacity = board.capacity();                                // capacity of the square matrix as one dimension
    if (j >= 2 && j <= capacity - 1 && i >= 0 && i <= capacity - 1) // a cell has at least this conditions to move in left direction
    {
        if (board[i][j - 1] == grid_type::peg && board[i][j - 2] == grid_type::space)
        {
            return 1; // move is eligable
        }
        else
            return 0;
    }
    else
        return 0;
}
int check_down(std::vector<std::vector<grid_type>> board, int i, int j)
// function that checks a given cell of the grid 1,2,3,4 and 5 so that
//whether it has a down move or not
{
    int capacity = board.capacity();

    if (j >= 0 && j <= capacity - 1 && i >= 0 && i <= capacity - 3) // a cell has at least this conditions to move in down direction
    {
        if (board[i + 1][j] == grid_type::peg && board[i + 2][j] == grid_type::space)
        {
            return 1; // move is eligable
        }
        else
            return 0;
    }
    else
        return 0;
}
int check_up(std::vector<std::vector<grid_type>> board, int i, int j)
// function that checks a given cell of the grid 1,2,3,4 and 5 so that
//whether it has a up move or not
{
    int capacity = board.capacity();
    if (j >= 0 && j <= capacity - 1 && i >= 2 && i <= capacity - 1)
    {
        if (board[i - 1][j] == grid_type::peg && board[i - 2][j] == grid_type::space) // a cell has at least this conditions to move in up direction
        {
            return 1; // move is eligable
        }
        else
            return 0;
    }
    else
        return 0;
}
int check_right(std::vector<std::vector<grid_type>> board, int i, int j)
// function that checks a given cell of the grid 1,2,3,4 and 5 so that
//whether it has a right move or not
{
    int capacity = board.capacity();
    if (j >= 0 && j <= capacity - 3 && i >= 0 && i <= capacity - 1)
    {
        if (board[i][j + 1] == grid_type::peg && board[i][j + 2] == grid_type::space) // a cell has at least this conditions to move in right direction
        {
            return 1; // move is eligable
        }
        else
            return 0;
    }
    else
        return 0;
}
int check_game_is_done(std::vector<std::vector<grid_type>> board)
{                                    // this function takes the board and checks whether there is any move left that a user can make
    int capacity = board.capacity(); // takes the capacity of the board
    int total = 1;
    int count = 0, number_of_pegs = 0;
    for (int i = 0; i < capacity; i++)
    {
        for (int j = 0; j < capacity; j++)
        {
            if (board[i][j] == grid_type::peg)
            {
                number_of_pegs++; // if a cell is peg, count it
                total = check_left(board, i, j) + check_right(board, i, j) + check_up(board, i, j) + check_down(board, i, j);
                // checking in every direction of the given cell, if the control functions returns 0 that means
                // there is no move that cell can make
                if (total == 0)
                {
                    count++;
                }
            }
        }
    }
    if (number_of_pegs == count)
    {
        return 1; // if all of the pegs in the board has no move then game is done
    }
    else
        return 0; // else game is not done
}
int number_of_peg_left(std::vector<std::vector<grid_type>> board)
// this function takes the board 1,2,3,4 and 5 and counts the number of pegs
{
    int capacity = board.capacity();
    int count = 0;
    for (int i = 0; i < capacity; ++i)
    {
        for (int j = 0; j < capacity; ++j)
        {
            if (board[i][j] == grid_type::peg)
            {
                count++;
            }
        }
    }
    return count;
}
int parse_command(int *row, char *direction, int *col,string* filename)
{ // this function parse the command as string
    std::string command;
    std::cout << "Enter the command: ";
    fflush(stdin);
    std::getline(std::cin, command);
    std::string delimiter = ".";
    auto pos = 0;
    string s;
    std::string token;
    std::string temp;
    int flag;
    int found;
    int found1;
    if(command[0]=='L' && command[1]=='O' && command[2]=='A' && command[3]=='D'){
        flag=1;
        found = command.find_first_of(".");
    }
    else if(command[0]=='S' && command[1]=='A' && command[2]=='V' && command[3]=='E'){
        flag=2;
        int len= command.length();
        for(int i=0;i<len;i++){
            if(command[i]=='.'){
                found=i;
                break;
            }
        }
    }
    else{
        flag=3;
    }
    *filename="";
    if(flag==1 && command[found+1]=='t'&& command[found+2]=='x'&&command[found+3]=='t'){
        found1 = command.find_first_of(" ");
        for(int i=found1+1;i<found;i++){
            (*filename).push_back(command[i]);
        }
        return 1; // load to file
    }
    else if(flag==2 && command[found+1]=='t'&& command[found+2]=='x'&&command[found+3]=='t'){
        found1 = command.find_first_of(" ");
        for(int i=found1+1;i<found;i++){
            (*filename).push_back(command[i]); // save to file
        }
        return 2;
    }
    else
    {
        *row = (int)command[1] - '0' - 1; // command will given as b3-r : first char will be the col number
        // second will be the row number and the last one is direction
        if ((int)command[0] >= 65 && (int)command[0] <= 90)
        {
            *col = (int)command[0] - 'A';
        }
        else if ((int)command[0] >= 97 && (int)command[0] <= 122)
        {
            *col = (int)command[0] - 'a';
        }
        *direction = command[3]; // last one is direction
        return 0;
    }
    
}
void manage_game(std::vector<std::vector<grid_type>> *board, int row, char direction, int col)
{
    std::vector<std::vector<grid_type> > temp = *board; // we are copying the initial board
    if (direction == 'R' || direction == 'r')           // if the direction was chosen as right, control the right of the given
    // cell, if it is ok to move right, then make the move
    { // changing the peg's location and make the move
        if (check_right(temp, row, col))
        {
            temp[row][col + 2] = temp[row][col];
            temp[row][col] = grid_type::space;
            temp[row][col + 1] = grid_type::space;
        }
        else
            std::cout << "Please choose a valid move !" << std::endl;
    }
    else if (direction == 'L' || direction == 'l') // if the direction was chosen as left, control the left of the given
    // cell, if it is ok to move left, then make the move,if it has a chance to move than it is making the move
    // and returning 1 indicates that cell has a capability to move which is the knowledge we need to hold stopping
    // the game
    {
        if (check_left(temp, row, col))
        {
            temp[row][col - 2] = temp[row][col];
            temp[row][col] = grid_type::space;
            temp[row][col - 1] = grid_type::space;
        }
        else
            std::cout << "Please choose a valid move !" << std::endl;
    }
    else if (direction == 'U' || direction == 'u') // if the direction was chosen as up, control the up of the given
    // cell, if it is ok to move up, then make the move,if it has a chance to move than it is making the move
    // and returning 1 indicates that cell has a capability to move which is the knowledge we need to hold stopping
    // the game
    {
        if (check_up(temp, row, col))
        {
            temp[row - 2][col] = temp[row][col];
            temp[row][col] = grid_type::space;
            temp[row - 1][col] = grid_type::space;
        }
        else
            std::cout << "Please choose a valid move !" << std::endl;
    }
    else if (direction == 'D' || direction == 'd') // if the direction was chosen as down, control the down of the given
    // cell, if it is ok to move down, then make the move,if it has a chance to move than it is making the move
    // and returning 1 indicates that cell has a capability to move which is the knowledge we need to hold stopping
    // the game
    {
        if (check_down(temp, row, col))
        {
            temp[row + 2][col] = temp[row][col];
            temp[row][col] = grid_type::space;
            temp[row + 1][col] = grid_type::space;
        }
        else
            std::cout << "Please choose a valid move !" << std::endl;
    }
    *board = temp;
}
int ask_user_to_continue()
{ // this function asks user in computer game whether will we continue or not
    int ans;
    std::cout << "Do you want computer to continue(1) or enter a command(2)? ";
    std::cin >> ans;
    if (ans==1)
    {
        return 1;
    }
    else
        return 2;
}
int check_right_for_board_6(std::vector<std::vector<grid_type>> *board, int i, int j)
{ // This function controls the 6'th board right move
    std::vector<std::vector<grid_type> > temp = *board;
    if (i == 4 && j == 0 && temp[4][0] == grid_type::peg && temp[4][2] == grid_type::peg && temp[4][4] == grid_type::space)
    {
        temp[4][4] = grid_type::peg;
        temp[4][0] = grid_type::space;
        temp[4][2] = grid_type::space;
        *board = temp;
        return 1;
    }
    else if (i == 4 && j == 2 && temp[4][2] == grid_type::peg && temp[4][4] == grid_type::peg && temp[4][6] == grid_type::space)
    {
        temp[4][6] = grid_type::peg;
        temp[4][4] = grid_type::space;
        temp[4][2] = grid_type::space;
        *board = temp;
        return 1;
    }
    else if (i == 4 && j == 4 && temp[4][4] == grid_type::peg && temp[4][6] == grid_type::peg && temp[4][8] == grid_type::space)
    {
        temp[4][4] = grid_type::peg;
        temp[4][6] = grid_type::space;
        temp[4][8] = grid_type::space;
        *board = temp;
        return 1;
    }
    else if (i == 3 && j == 1 && temp[3][1] == grid_type::peg && temp[3][3] == grid_type::peg && temp[3][5] == grid_type::space)
    {
        temp[3][3] = grid_type::space;
        temp[3][1] = grid_type::peg;
        temp[3][5] = grid_type::space;
        *board = temp;
        return 1;
    }
    else if (i == 3 && j == 3 && temp[3][3] == grid_type::peg && temp[3][5] == grid_type::peg && temp[3][7] == grid_type::space)
    {
        temp[3][7] = grid_type::peg;
        temp[3][5] = grid_type::space;
        temp[3][3] = grid_type::space;
        *board = temp;
        return 1;
    }
    else if (i == 2 && j == 2 && temp[2][2] == grid_type::peg && temp[2][4] == grid_type::peg && temp[2][6] == grid_type::space)
    {
        temp[2][6] = grid_type::peg;
        temp[2][4] = grid_type::space;
        temp[2][2] = grid_type::space;
        *board = temp;
        return 1;
    }
    else
    {
        // if the table does not have right move return 0
        return 0;
    }
}
int check_left_for_board_6(std::vector<std::vector<grid_type>> *board, int i, int j)
{ // This function controls the 6'th board left move
    std::vector<std::vector<grid_type> > temp = *board;
    if (i == 2 && j == 6 && temp[2][6] == grid_type::peg && temp[2][4] == grid_type::peg && temp[2][2] == grid_type::space)
    {
        temp[2][2] = grid_type::peg;
        temp[2][6] = grid_type::space;
        temp[2][4] = grid_type::space;
        *board = temp;
        return 1;
    }
    else if (i == 3 && j == 7 && temp[3][7] == grid_type::peg && temp[3][5] == grid_type::peg && temp[3][3] == grid_type::space)
    {
        temp[3][3] = grid_type::peg;
        temp[3][7] = grid_type::space;
        temp[3][5] = grid_type::space;
        *board = temp;
        return 1;
    }
    else if (i == 3 && j == 5 && temp[3][5] == grid_type::peg && temp[3][3] == grid_type::peg && temp[3][1] == grid_type::space)
    {
        temp[3][1] = grid_type::peg;
        temp[3][3] = grid_type::space;
        temp[3][5] = grid_type::space;
        *board = temp;
        return 1;
    }
    else if (i == 4 && j == 8 && temp[4][8] == grid_type::peg && temp[4][6] == grid_type::peg && temp[4][4] == grid_type::space)
    {
        temp[4][4] = grid_type::peg;
        temp[4][6] = grid_type::space;
        temp[4][8] = grid_type::space;
        *board = temp;
        return 1;
    }
    else if (i == 4 && j == 6 && temp[4][6] == grid_type::peg && temp[4][4] == grid_type::peg && temp[4][2] == grid_type::space)
    {
        temp[4][2] = grid_type::peg;
        temp[4][6] = grid_type::space;
        temp[4][4] = grid_type::space;
        *board = temp;
        return 1;
    }
    else if (i == 4 && j == 4 && temp[4][4] == grid_type::peg && temp[4][2] == grid_type::peg && temp[4][0] == grid_type::space)
    {
        temp[4][0] = grid_type::peg;
        temp[4][2] = grid_type::space;
        temp[4][4] = grid_type::space;
        *board = temp;
        return 1;
    }
    else
    {

        return 0;
    }
}
int check_down_for_board_6(std::vector<std::vector<grid_type>> *board, int i, int j)
{ // This function controls the 6'th board down move, if it has a chance to move than it is making the move
    // and returning 1 indicates that cell has a capability to move which is the knowledge we need to hold stopping
    // the game
    std::vector<std::vector<grid_type> > temp = *board;
    if (i == 0 && j == 4 && temp[0][4] == grid_type::peg && temp[1][3] == grid_type::peg && temp[2][2] == grid_type::space)
    {
        temp[2][2] = grid_type::peg;
        temp[0][4] = grid_type::space;
        temp[1][3] = grid_type::space;
        *board = temp;
        return 1;
    }
    else if (i == 1 && j == 3 && temp[1][3] == grid_type::peg && temp[2][2] == grid_type::peg && temp[3][1] == grid_type::space)
    {
        temp[3][1] = grid_type::peg;
        temp[1][3] = grid_type::space;
        temp[2][2] = grid_type::space;
        *board = temp;
        return 1;
    }
    else if (i == 1 && j == 5 && temp[1][5] == grid_type::peg && temp[2][4] == grid_type::peg && temp[3][3] == grid_type::space)
    {
        temp[3][3] = grid_type::peg;
        temp[1][5] = grid_type::space;
        temp[2][4] = grid_type::space;
        *board = temp;
        return 1;
    }
    else if (i == 2 && j == 2 && temp[2][2] == grid_type::peg && temp[3][1] == grid_type::peg && temp[4][0] == grid_type::space)
    {
        temp[4][0] = grid_type::peg;
        temp[2][2] = grid_type::space;
        temp[3][1] = grid_type::space;
        *board = temp;
        return 1;
    }
    else if (i == 2 && j == 4 && temp[2][4] == grid_type::peg && temp[3][3] == grid_type::peg && temp[4][2] == grid_type::space)
    {
        temp[4][2] = grid_type::peg;
        temp[2][4] = grid_type::space;
        temp[3][3] = grid_type::space;
        *board = temp;
        return 1;
    }
    else if (i == 2 && j == 6 && temp[2][6] == grid_type::peg && temp[3][5] == grid_type::peg && temp[4][4] == grid_type::space)
    {
        temp[4][4] = grid_type::peg;
        temp[2][6] = grid_type::space;
        temp[3][5] = grid_type::space;
        *board = temp;
        return 1;
    }
    else
    {

        return 0;
    }
}
// FOR BOARD 6, UP DIRECTION MEANS RIGHT AND UP DIRECTION,
// DOWN MEANS LEFT DOWN DIRECTION.
int check_up_for_board_6(std::vector<std::vector<grid_type>> *board, int i, int j)
{ // This function controls the 6'th board up move
    std::vector<std::vector<grid_type> > temp = *board;
    if (i == 2 && j == 2 && temp[2][2] == grid_type::peg && temp[1][3] == grid_type::peg && temp[0][4] == grid_type::space)
    {
        temp[0][4] = grid_type::peg;
        temp[1][3] = grid_type::space;
        temp[2][2] = grid_type::space;
        *board = temp;
        return 1;
    }
    else if (i == 3 && j == 1 && temp[3][1] == grid_type::peg && temp[2][2] == grid_type::peg && temp[1][3] == grid_type::space)
    {
        temp[1][3] = grid_type::peg;
        temp[2][2] = grid_type::space;
        temp[3][1] = grid_type::space;
        *board = temp;
        return 1;
    }
    else if (i == 4 && j == 0 && temp[4][0] == grid_type::peg && temp[3][1] == grid_type::peg && temp[2][2] == grid_type::space)
    {
        temp[2][2] = grid_type::peg;
        temp[3][1] = grid_type::space;
        temp[4][0] = grid_type::space;
        *board = temp;
        return 1;
    }
    else if (i == 4 && j == 2 && temp[4][2] == grid_type::peg && temp[3][3] == grid_type::peg && temp[2][4] == grid_type::space)
    {
        temp[2][4] = grid_type::peg;
        temp[3][3] = grid_type::space;
        temp[4][2] = grid_type::space;
        *board = temp;
        return 1;
    }
    else if (i == 3 && j == 3 && temp[3][3] == grid_type::peg && temp[2][4] == grid_type::peg && temp[1][5] == grid_type::space)
    {
        temp[1][5] = grid_type::peg;
        temp[2][4] = grid_type::space;
        temp[3][3] = grid_type::space;
        *board = temp;
        return 1;
    }
    else if (i == 4 && j == 4 && temp[4][4] == grid_type::peg && temp[3][5] == grid_type::peg && temp[2][6] == grid_type::space)
    {
        temp[2][6] = grid_type::peg;
        temp[4][4] = grid_type::space;
        temp[3][5] = grid_type::space;
        *board = temp;
        return 1;
    }
    else
    {
        return 0;
    }
}
void manage_game_for_board_6(std::vector<std::vector<grid_type>> *board, int row, char direction, int col)
{ // this function parses the command that user gave us and conrols that whether that cell has any chance
    //to move in given direction

    int ret;
    std::vector<std::vector<grid_type> > temp(*board);
    if (direction == 'R' || direction == 'r')
    { // changing the peg's location and make the move
        ret = check_right_for_board_6(&temp, row, col);
        if (!ret)
        {
            std::cout << "Please enter a valid move for table 6!" << std::endl;
        }
    }
    else if (direction == 'L' || direction == 'l')
    {
        ret = check_left_for_board_6(&temp, row, col);
        if (!ret)
        {
            std::cout << "Please enter a valid move for table 6!" << std::endl;
        }
    }
    else if (direction == 'U' || direction == 'u')
    {
        ret = check_up_for_board_6(&temp, row, col);
        if (!ret)
        {
            std::cout << "Please enter a valid move for table 6!" << std::endl;
        }
    }
    else if (direction == 'D' || direction == 'd')
    {
        ret = check_down_for_board_6(&temp, row, col);
        if (!ret)
        {
            std::cout << "Please enter a valid move for table 6!" << std::endl;
        }
    }
    *board = temp; // at the end, we are assigning the last table to our first table
}
int check_game_is_done_for_table_6(const std::vector<std::vector<grid_type>> board)
{ // this function controls whether sixth table is done or not
    std::vector<std::vector<grid_type> > board_temp(board);
    int numb = 0;
    int check = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (i == 0 && j == 4 && board[0][4] == grid_type::peg)
            {
                check = check_right_for_board_6(&board_temp, i, j) + check_left_for_board_6(&board_temp, i, j) + check_down_for_board_6(&board_temp, i, j) + check_up_for_board_6(&board_temp, i, j);
                numb++;
            }
            else if (i == 1 && j == 3 && board[1][3] == grid_type::peg)
            {
                check = check_right_for_board_6(&board_temp, i, j) + check_left_for_board_6(&board_temp, i, j) + check_down_for_board_6(&board_temp, i, j) + check_up_for_board_6(&board_temp, i, j);
                numb++;
            }
            else if (i == 1 && j == 5 && board[1][5] == grid_type::peg)
            {
                check = check_right_for_board_6(&board_temp, i, j) + check_left_for_board_6(&board_temp, i, j) + check_down_for_board_6(&board_temp, i, j) + check_up_for_board_6(&board_temp, i, j);
                numb++;
            }
            else if (i == 2 && j == 2 && board[2][2] == grid_type::peg)
            {
                check = check_right_for_board_6(&board_temp, i, j) + check_left_for_board_6(&board_temp, i, j) + check_down_for_board_6(&board_temp, i, j) + check_up_for_board_6(&board_temp, i, j);
                numb++;
            }
            else if (i == 2 && j == 4 && board[2][4] == grid_type::peg)
            {
                check = check_right_for_board_6(&board_temp, i, j) + check_left_for_board_6(&board_temp, i, j) + check_down_for_board_6(&board_temp, i, j) + check_up_for_board_6(&board_temp, i, j);
                numb++;
            }
            else if (i == 2 && j == 6 && board[2][6] == grid_type::peg)
            {
                check = check_right_for_board_6(&board_temp, i, j) + check_left_for_board_6(&board_temp, i, j) + check_down_for_board_6(&board_temp, i, j) + check_up_for_board_6(&board_temp, i, j);
                numb++;
            }
            else if (i == 3 && j == 1 && board[3][1] == grid_type::peg)
            {
                check = check_right_for_board_6(&board_temp, i, j) + check_left_for_board_6(&board_temp, i, j) + check_down_for_board_6(&board_temp, i, j) + check_up_for_board_6(&board_temp, i, j);
                numb++;
            }
            else if (i == 3 && j == 3 && board[3][3] == grid_type::peg)
            {
                check = check_right_for_board_6(&board_temp, i, j) + check_left_for_board_6(&board_temp, i, j) + check_down_for_board_6(&board_temp, i, j) + check_up_for_board_6(&board_temp, i, j);
                numb++;
            }
            else if (i == 3 && j == 5 && board[3][5] == grid_type::peg)
            {
                check = check_right_for_board_6(&board_temp, i, j) + check_left_for_board_6(&board_temp, i, j) + check_down_for_board_6(&board_temp, i, j) + check_up_for_board_6(&board_temp, i, j);
                numb++;
            }
            else if (i == 3 && j == 7 && board[3][7] == grid_type::peg)
            {
                check = check_right_for_board_6(&board_temp, i, j) + check_left_for_board_6(&board_temp, i, j) + check_down_for_board_6(&board_temp, i, j) + check_up_for_board_6(&board_temp, i, j);
                numb++;
            }
            else if (i == 4 && j == 0 && board[4][0] == grid_type::peg)
            {
                check = check_right_for_board_6(&board_temp, i, j) + check_left_for_board_6(&board_temp, i, j) + check_down_for_board_6(&board_temp, i, j) + check_up_for_board_6(&board_temp, i, j);
                numb++;
            }
            else if (i == 4 && j == 2 && board[4][2] == grid_type::peg)
            {
                check = check_right_for_board_6(&board_temp, i, j) + check_left_for_board_6(&board_temp, i, j) + check_down_for_board_6(&board_temp, i, j) + check_up_for_board_6(&board_temp, i, j);
                numb++;
            }
            else if (i == 4 && j == 4 && board[4][4] == grid_type::peg)
            {
                check = check_right_for_board_6(&board_temp, i, j) + check_left_for_board_6(&board_temp, i, j) + check_down_for_board_6(&board_temp, i, j) + check_up_for_board_6(&board_temp, i, j);
                numb++;
            }
            else if (i == 4 && j == 6 && board[4][6] == grid_type::peg)
            {
                check = check_right_for_board_6(&board_temp, i, j) + check_left_for_board_6(&board_temp, i, j) + check_down_for_board_6(&board_temp, i, j) + check_up_for_board_6(&board_temp, i, j);
                numb++;
            }
            else if (i == 4 && j == 8 && board[4][8] == grid_type::peg)
            {
                check = check_right_for_board_6(&board_temp, i, j) + check_left_for_board_6(&board_temp, i, j) + check_down_for_board_6(&board_temp, i, j) + check_up_for_board_6(&board_temp, i, j);
                numb++;
            }
            if (check != 0)
            {
                return 1; // game is not done
            }
        }
    }
    if (check == 0 || numb == 1)
    {
        return 0; // game is done
    }
    else
        return 1; // game is not done
}
int calculateScore(std::vector<std::vector<grid_type>> board)
{ // calculating the number of the pegs that left
    int capacity = board.capacity();
    int count = 0;
    for (int i = 0; i < capacity; i++)
    {
        for (int j = 0; j < capacity; j++)
        {
            if (board[i][j] == grid_type::peg)
            {
                count++;
            }
        }
    }
    return count + 1;
}
int calculateScoreforTable_6(std::vector<std::vector<grid_type>> board)
{ // calculating the number of the pegs that left in table 6
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == grid_type::peg)
            {
                count++;
            }
        }
    }
    return count + 1;
}
void human_game()
{                                                        // this function manages the human moves
    std::vector<std::vector<grid_type> > boarda(board1); // temporary boards for moving
    std::vector<std::vector<grid_type> > boardb(board2);
    std::vector<std::vector<grid_type> > boardc(board3);
    std::vector<std::vector<grid_type> > boardd(board4);
    std::vector<std::vector<grid_type> > boarde(board5);
    std::vector<std::vector<grid_type> > boardf(board6);
    string filename;
ab1:
    int choice;
    int row;
    int temp_row = 0;
    char direction;
    int col;
    choice = check_the_valid_input_grid();
    switch (choice)
    { // switching the human game
    case 1:
        do
        {
            print_grid(boarda); // printing the grid
            parse_command(&row, &direction, &col,&filename);
            manage_game(&boarda, row, direction, col);
            if (number_of_peg_left(boarda) == 1 && !(check_game_is_done(boarda)))
            {
                std::cout << "You win the game!" << std::endl;
            }
        } while (number_of_peg_left(boarda) != 0);
        std::cout << "Score is : " << calculateScore(boarda);
        std::cout << "The game is over" << std::endl;
        break;
    case 2:
        do
        {
            print_grid(boardb);
            parse_command(&row, &direction, &col,&filename);
            manage_game(&boardb, row, direction, col);
            if (number_of_peg_left(boardb) == 1)
            {
                std::cout << "You win the game!" << std::endl;
            }
        } while (number_of_peg_left(boardb) != 0 && !(check_game_is_done(boardb)));
        std::cout << "Score is : " << calculateScore(boardb);
        std::cout << "The game is over" << std::endl;
        break;
    case 3:
        do
        {
            print_grid(boardc);
            parse_command(&row, &direction, &col,&filename);
            manage_game(&boardc, row, direction, col);
            if (number_of_peg_left(boardc) == 1 && !(check_game_is_done(boardc)))
            {
                std::cout << "You win the game!" << std::endl;
            }
        } while (number_of_peg_left(boardc) != 0);
        std::cout << "Score is : " << calculateScore(boardc);
        std::cout << "The game is over" << std::endl;
        break;
    case 4:
        do
        {
            print_grid(boardd);
            parse_command(&row, &direction, &col,&filename);
            manage_game(&boardd, row, direction, col);
            if (number_of_peg_left(boardd) == 1)
            {
                std::cout << "You win the game!" << std::endl;
            }
        } while (number_of_peg_left(boardd) != 0 && !(check_game_is_done(boardd)));
        std::cout << "Score is : " << calculateScore(boardd);
        std::cout << "The game is over" << std::endl;
        break;
    case 5:
        do
        {
            print_grid(boarde);
            parse_command(&row, &direction, &col,&filename);
            manage_game(&boarde, row, direction, col);
            if (number_of_peg_left(boarde) == 1)
            {
                std::cout << "You win the game!" << std::endl;
            }
        } while (number_of_peg_left(boarde) != 0 && !(check_game_is_done(boarde)));
        std::cout << "Score is : " << calculateScore(boarde);
        std::cout << "The game is over" << std::endl;
        break;
    case 6:
        do
        {
            print_last_grid(boardf);
            parse_command(&row, &direction, &col,&filename);
            manage_game_for_board_6(&boardf, row, direction, col);
        } while (check_game_is_done_for_table_6(boardf));
        std::cout << "Score is : " << calculateScoreforTable_6(boardf);
        std::cout << "The game is over" << std::endl;
        break;
    default:
        std::cout << "Please choose a grid between 1-6" << std::endl;
        goto ab1;
    }
}
void make_a_computer_move_for_grid6(std::vector<std::vector<grid_type>> *board)
{ // this function makes the computer game moves for the 6'th table
    std::vector<std::vector<grid_type> > temp = *board;
    std::vector<std::vector<grid_type> > temp1 = *board;
    std::vector<std::vector<grid_type> > temp2 = *board;
    std::vector<std::vector<grid_type> > temp3 = *board;
    std::vector<std::vector<grid_type> > temp4 = *board;
    int valid = 0;
    int control;
    int k = 0, l = 0;
    std::vector<int> controlx;
    std::vector<int> controly;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (temp4[i][j] == grid_type::peg)
            {
                valid = check_left_for_board_6(&temp, i, j) + check_right_for_board_6(&temp1, i, j) + check_up_for_board_6(&temp2, i, j) + check_down_for_board_6(&temp3, i, j);
                if (valid != 0)
                {
                    controlx.push_back(i);
                    controly.push_back(j);
                    k++;
                }
            }
        }
    }
    std::vector<std::vector<grid_type> > temp6 = *board;
    temp = *board;
    temp1 = *board;
    temp2 = *board;
    temp3 = *board;
    temp4 = *board;
    srand((unsigned)time(NULL));
    int random = rand() % k;
    std::cout << random;
    if (check_left_for_board_6(&temp1, controlx[random], controly[random]))
    {
        check_left_for_board_6(&temp6, controlx[random], controly[random]);
    }
    else if (check_right_for_board_6(&temp2, controlx[random], controly[random]))
    {
        check_right_for_board_6(&temp6, controlx[random], controly[random]);
    }
    else if (check_up_for_board_6(&temp3, controlx[random], controly[random]))
    {
        check_up_for_board_6(&temp6, controlx[random], controly[random]);
    }
    else if (check_down_for_board_6(&temp4, controlx[random], controly[random]))
    {
        check_down_for_board_6(&temp6, controlx[random], controly[random]);
    }
    *board = temp6;
}
void save_game_to_the_file(std::vector<std::vector<grid_type>> board, int board_number, int is_it_first,string filename)
{
    int capacity = board.capacity();
    string file_name, name_of_the_file;
    string extension = ".txt";
    int number;
    filename = filename + extension;
    fstream my_file;
    ifstream game_number_read;
    ofstream game_number_write;
    std::ofstream filenames, name_individual;
    game_number_read.open("games.txt");
    game_number_read>> number;
    game_number_read.close();
    game_number_write.open("games.txt");
    number++;
    game_number_write<< number;
    game_number_write.close();
    
    my_file.open(filename, ios::out);
    if (!my_file)
    {
        std::cerr << "File was not being created!" << std::endl;
    }

    for (int i = 0; i < capacity; i++)
    {
        for (int j = 0; j < capacity; j++)
        {
            if (board[i][j] == grid_type::peg)
            {
                my_file << "P"; // pegs are shown as P
            }
            else if (board[i][j] == grid_type::wall)
            {
                my_file << " "; // walls are shown as whitespaces
            }
            else if (board[i][j] == grid_type::space)
            {
                my_file << "*"; // spaces are shown as *
            }
        }
        my_file << std::endl;
    }
    my_file.close();
    name_individual.open(name_of_the_file, ios::app);
    if (is_it_first == 1 && board_number == 1)
    {   filenames.open("filenames.txt", std::ios_base::app);
        filenames << filename << " "<< "board1" << std::endl;
        filenames.close();
    }
    else if (is_it_first == 1 && board_number == 2)
    {
        filenames.open("filenames.txt", std::ios_base::app);
        filenames << filename << " "<< "board2" << std::endl;
        filenames.close();
    }
    else if (is_it_first == 1 && board_number == 3)
    {
        filenames.open("filenames.txt", std::ios_base::app);
        filenames << filename << " "<< "board3" << std::endl;
        filenames.close();
    }
    else if (is_it_first == 1 && board_number == 4)
    {
        filenames.open("filenames.txt", std::ios_base::app);
        filenames << filename << " "<< "board4" << std::endl;
        filenames.close();
    }
    else if (is_it_first == 1 && board_number == 5)
    {
        filenames.open("filenames.txt", std::ios_base::app);
        filenames << filename << " "<< "board5" << std::endl;
        filenames.close();
    }
    else if (is_it_first == 1 && board_number == 6)
    {
        filenames.open("filenames.txt", std::ios_base::app);
        filenames << filename << " "<< "board6" << std::endl;
        filenames.close();
    }
    else if (is_it_first == 1 && board_number == 7)
    {
        filenames.open("filenames.txt", std::ios_base::app);
        filenames << filename << " "<< "board7" << std::endl;
        filenames.close();
    }
    else if (is_it_first == 1 && board_number == 8)
    {
        filenames.open("filenames.txt", std::ios_base::app);
        filenames << filename << " "<< "board8" << std::endl;
        filenames.close();
    }
    else if (is_it_first == 1 && board_number == 9)
    {
        filenames.open("filenames.txt", std::ios_base::app);
        filenames << filename << " "<< "board9" << std::endl;
        filenames.close();
    }
    name_individual.close();
}
void save_game_to_the_file_for_table_6(std::vector<std::vector<grid_type>> board, int board_number, int is_it_first,string filename)
{   int number;
    ifstream game_number_read;
    ofstream game_number_write;
    game_number_read.open("games.txt");
    game_number_read>> number;
    game_number_read.close();
    game_number_write.open("games.txt");
    number++;
    game_number_write<< number;
    game_number_write.close();
    string file_name, name_of_the_file;
    fstream my_file;
    std::ofstream filenames, name_individual;
    filenames.open("filenames.txt", std::ios_base::app);
    string extension = ".txt";
    filename = filename + extension;
    filenames << filename << std::endl;
    filenames.close();
    my_file.open(filename, ios::out);
    if (!my_file)
    {
        std::cerr << "File was not being created!" << std::endl;
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == grid_type::peg)
            {
                my_file << "P"; // pegs are shown as P
            }
            else if (board[i][j] == grid_type::wall)
            {
                my_file << " "; // walls are shown as whitespaces
            }
            else if (board[i][j] == grid_type::space)
            {
                my_file << "*"; // spaces are shown as *
            }
        }
        my_file << std::endl;
    }
    my_file.close();
    name_individual.open(name_of_the_file, ios::app);
    if (is_it_first == 1 && board_number == 6)
    {
        name_individual << "board6";
    }
    name_individual.close();
}
std::vector<std::vector<grid_type>> load_file(string filename,int* does_the_file_exist,string* board_type1)
{
    int count = 0,flag=0;
    std::vector<std::vector<grid_type>> board;
    string extension = ".txt";
    int number;
    string line;
    filename = filename + extension;
    std::ifstream input("filenames.txt");
    string board_type;
   while( getline(input, line))
    {  
        int index= line.find(' '); // example.txt board1
        string name_found; 
        for(int i=0;i<index;i++){
            name_found.push_back(line[i]);
        }
        if(name_found==filename){
            flag=1;
        }
        if(flag==1){
            int len=line.length();
            for(int i=index+1;i<len;i++){
                board_type.push_back(line[i]); // determining the type of the board such as board1, board2...
            }
            break;
        }    
    }
    *board_type1= board_type;
    if(flag==0){
        std:: cerr<< std:: endl << "There is no file with name: "<< filename;
            *does_the_file_exist=0;
            return board;
        }
    
    input.close();
    std::ifstream input1(filename);
    for (std::string line; getline(input1, line);)
    {
        count++;
    }
    input1.close();
    std::ifstream input2(filename);
    string myText;
    int k=0;
    while (getline(input2, myText))
    {  
        int size = myText.length();
            board.push_back(std::vector<grid_type>());
            for (int j = 0; j < size; j++)
            {
                if (myText[j] == 'P')
                {
                    board[k].push_back(grid_type::peg);
                
                }
                else if (myText[j] == '*')
                {
                    board[k].push_back(grid_type::space);
                    
                }
                else if (myText[j] == ' ')
                {
                    board[k].push_back(grid_type::wall);
                   
                
                }
            }
            k++;
        
    }
    *does_the_file_exist=1;
    return board;
}

void computer_game(std::vector<std::vector<grid_type>> *board,string* board_type,int initial,int boardnumber)
{ // this function manages the computer game

    int  choice,row, col, control,choice1,does_file_exist,ret,ret1;  
    string filename;
    char direction;
    int menu_choice;
        std::vector<std::vector<grid_type>> load_file_return;
        std::vector<std::vector<grid_type>> board1_temp(board1);
        std::vector<std::vector<grid_type>> board2_temp(board2);
        std::vector<std::vector<grid_type>> board3_temp(board3);
        std::vector<std::vector<grid_type>> board4_temp(board4);
        std::vector<std::vector<grid_type>> board5_temp(board5);
        std::vector<std::vector<grid_type>> board6_temp(board6);
        std::vector<std::vector<grid_type>> board7_temp(board7);
        std::vector<std::vector<grid_type>> board8_temp(board8);
        std::vector<std::vector<grid_type>> board9_temp(board9);
        std::vector<std::vector<grid_type>> boarda(board1);
        std::vector<std::vector<grid_type>> boardb(board2);
        std::vector<std::vector<grid_type>> boardc(board3);
        std::vector<std::vector<grid_type>> boardd(board4);
        std::vector<std::vector<grid_type>> boarde(board5);
        std::vector<std::vector<grid_type>> boardf(board6);
        std::vector<std::vector<grid_type>> boardk(board7);
        std::vector<std::vector<grid_type>> boardo(board8);
        std::vector<std::vector<grid_type>> boardl(board9);
        std::vector<std::vector<grid_type>> temp_board;
        std::vector<std::vector<grid_type>> printed_board;
    int random_col, random_row, capacity;
    if(initial==2){
      int user_ans;
      if(boardnumber==1){*board_type= "board1";} else if(boardnumber==2){*board_type= "board2";} else if(boardnumber==3){*board_type= "board3";} else if(boardnumber==4){*board_type= "board4";} else if(boardnumber==5){*board_type= "board5";} else if(boardnumber==6){*board_type= "board6";} else if(boardnumber==7){*board_type= "board7";} else if(boardnumber==8){*board_type= "board8";} else if(boardnumber==9){*board_type= "board9";}
      if(boardnumber==1){printed_board=boarda;} else if(boardnumber==2){printed_board=boardb;} else if(boardnumber==3){printed_board=boardc;} else if(boardnumber==4){printed_board=boardd;} else if(boardnumber==5){printed_board=boarde;} else if(boardnumber==6){printed_board=boardf;} else if(boardnumber==7){printed_board=boardk;} else if(boardnumber==8){printed_board=boardo;} else if(boardnumber==9){printed_board=boardl;} 
        do
        {
            capacity = (*board).capacity();
            int k = 0;
            int cd, cu, cr, cl, last_shuffle, last_random, last_index;
            std::vector<int> filled_id;
            auto shuffle_vector = filled_id;
            int flag = 0;
            random_col = rand() % capacity;
            random_row = rand() % capacity;
            do
            {
                random_col = rand() % capacity;
                random_row = rand() % capacity;
                cu = check_up(*board, random_row, random_col);
                cd = check_down(*board, random_row, random_col);
                cr = check_right(*board, random_row, random_col);
                cl = check_left(*board, random_row, random_col);
            } while (cd + cu + cr + cl == 0 || (*board)[random_row][random_col] != grid_type::peg);

            std::vector<int> direction_control = {cr, cl, cd, cu};

            for (int i = 0; i < 4; i++)
            {
                if (direction_control[i] != 0)
                {
                    filled_id.push_back(i);
                    k++;
                }
            }

            auto random = std::default_random_engine{};
            std::shuffle(std::begin(shuffle_vector), std::end(shuffle_vector), random);
            last_random = rand() % k;
            last_index = filled_id[last_random];

            if (last_index == 0)
            {
                (*board)[random_row][random_col + 2] = (*board)[random_row][random_col];
                (*board)[random_row][random_col] = grid_type::space;
                (*board)[random_row][random_col + 1] = grid_type::space;
            }

            else if (last_index == 1)
            {
                (*board)[random_row][random_col - 2] = (*board)[random_row][random_col];
                (*board)[random_row][random_col] = grid_type::space;
                (*board)[random_row][random_col - 1] = grid_type::space;
            }

            else if (last_index == 2)
            {
                (*board)[random_row + 2][random_col] = (*board)[random_row][random_col];
                (*board)[random_row][random_col] = grid_type::space;
                (*board)[random_row + 1][random_col] = grid_type::space;
            }
            else if (last_index == 3)
            {
                (*board)[random_row - 2][random_col] = (*board)[random_row][random_col];
                (*board)[random_row][random_col] = grid_type::space;
                (*board)[random_row - 1][random_col] = grid_type::space;
            }
            else
                std::cout << "Mistake happened";
            print_grid(*board);
            temp_board= *board;
            if(ask_user_to_continue()==2){
                        enter6:
                        ret= parse_command(&row,&direction,&col,&filename);
                        if(ret==1){
                            temp_board=load_file(filename,&does_file_exist,board_type);
                            print_grid(temp_board);
                            if(!does_file_exist){
                            std::cerr<<"Please enter a valid file name!";
                            goto enter6;
                            }
                        }
                        else if(ret==2){
                                if(*board_type=="board6"){
                                    save_game_to_the_file_for_table_6(temp_board,6,1,filename);
                                }
                                else{
                                    if(*board_type=="board1"){
                                        std:: cout<< filename;
                                        save_game_to_the_file(temp_board,1,1,filename);
                                    }
                                    else if(*board_type=="board2"){
                                        save_game_to_the_file(temp_board,2,1,filename);
                                    }
                                     else if(*board_type=="board3"){
                                        save_game_to_the_file(temp_board,3,1,filename);
                                    }
                                     else if(*board_type=="board4"){
                                        save_game_to_the_file(temp_board,4,1,filename);
                                    }
                                     else if(*board_type=="board5"){
                                        save_game_to_the_file(temp_board,5,1,filename);
                                    }
                                     else if(*board_type=="board8"){
                                        save_game_to_the_file(temp_board,8,1,filename);
                                    }
                                     else if(*board_type=="board7"){
                                        save_game_to_the_file(temp_board,7,1,filename);
                                    }
                                     else if(*board_type=="board9"){                                     
                                         save_game_to_the_file(temp_board,9,1,filename);
                                    }
                                }
                        }
            }
        } while (!(check_game_is_done(printed_board))); 
        std::cout << "Game is done! Score is: " << calculateScore(printed_board);
    }

ab2:
    choice = check_the_valid_input_grid();
    srand((unsigned)time(0)); // random timing
    switch (choice)
    {   
        case 1: // if the user select for computer game for board1
     {   int user_ans;
        *board_type= "board1";
        do
        {
            capacity = boarda.capacity();
            int k = 0;
            int cd, cu, cr, cl, last_shuffle, last_random, last_index;
            std::vector<int> filled_id;
            auto shuffle_vector = filled_id;
            int flag = 0;
            random_col = rand() % capacity;
            random_row = rand() % capacity;
            do
            {
                random_col = rand() % capacity;
                random_row = rand() % capacity;
                cu = check_up(boarda, random_row, random_col);
                cd = check_down(boarda, random_row, random_col);
                cr = check_right(boarda, random_row, random_col);
                cl = check_left(boarda, random_row, random_col);
            } while (cd + cu + cr + cl == 0 || boarda [random_row][random_col] != grid_type::peg);

            std::vector<int> direction_control = {cr, cl, cd, cu};

            for (int i = 0; i < 4; i++)
            {
                if (direction_control[i] != 0)
                {
                    filled_id.push_back(i);
                    k++;
                }
            }

            auto random = std::default_random_engine{};
            std::shuffle(std::begin(shuffle_vector), std::end(shuffle_vector), random);
            last_random = rand() % k;
            last_index = filled_id[last_random];

            if (last_index == 0)
            {
                boarda [random_row][random_col + 2] = boarda [random_row][random_col];
                boarda [random_row][random_col] = grid_type::space;
                boarda [random_row][random_col + 1] = grid_type::space;
            }

            else if (last_index == 1)
            {
                boarda [random_row][random_col - 2] = boarda [random_row][random_col];
                boarda [random_row][random_col] = grid_type::space;
                boarda [random_row][random_col - 1] = grid_type::space;
            }

            else if (last_index == 2)
            {
                boarda [random_row + 2][random_col] = boarda [random_row][random_col];
                boarda [random_row][random_col] = grid_type::space;
                boarda [random_row + 1][random_col] = grid_type::space;
            }
            else if (last_index == 3)
            {
                boarda [random_row - 2][random_col] = boarda [random_row][random_col];
                boarda [random_row][random_col] = grid_type::space;
                boarda [random_row - 1][random_col] = grid_type::space;
            }
            else
                std::cout << "Mistake happened";
            print_grid(boarda);
            temp_board= boarda;
            decltype(ask_user_to_continue()) x;
            *board_type="board1";
            if(ask_user_to_continue()==2){
                print_grid(boarda);
                        enter20:
                        ret= parse_command(&row,&direction,&col,&filename); // parsing the user command
                        std:: cout<< ret;
                        if(ret==1){
                            temp_board=load_file(filename,&does_file_exist,board_type);
                            if(!does_file_exist){
                            std::cerr<<"Please enter a valid file name!";
                            goto enter20;
                            }
                            computer_game(&temp_board,board_type,2,1);
                        }
                        else if(ret==2){ // ret==2 means user wants to save the file 
                                if(*board_type=="board6"){
                                    save_game_to_the_file_for_table_6(temp_board,6,1,filename);
                                }
                                else{
                                    if(*board_type=="board1"){
                                        std:: cout<< filename;
                                        save_game_to_the_file(temp_board,1,1,filename);
                                    }
                                    else if(*board_type=="board2"){
                                        save_game_to_the_file(temp_board,2,1,filename);
                                    }
                                     else if(*board_type=="board3"){
                                        save_game_to_the_file(temp_board,3,1,filename);
                                    }
                                     else if(*board_type=="board4"){
                                        save_game_to_the_file(temp_board,4,1,filename);
                                    }
                                     else if(*board_type=="board5"){
                                        save_game_to_the_file(temp_board,5,1,filename);
                                    }
                                     else if(*board_type=="board8"){
                                        save_game_to_the_file(temp_board,8,1,filename);
                                    }
                                     else if(*board_type=="board7"){
                                        save_game_to_the_file(temp_board,7,1,filename);
                                    }
                                     else if(*board_type=="board9"){                                      
                                         save_game_to_the_file(temp_board,9,1,filename);
                                    }
                                }
                        }
            }
        } while (!(check_game_is_done(boarda))); // until the table will be solved
        std::cout << "Game is done! Score is: " << calculateScore(boarda);
        break;
    } 

        case 2: // if the user select for computer game for board5
    {   int user_ans;
        *board_type= "board2";
        do
        {
            capacity = boardb.capacity();
            int k = 0;
            int cd, cu, cr, cl, last_shuffle, last_random, last_index;
            std::vector<int> filled_id;
            auto shuffle_vector = filled_id;
            int flag = 0;
            random_col = rand() % capacity;
            random_row = rand() % capacity;
            do
            {
                random_col = rand() % capacity;
                random_row = rand() % capacity;
                cu = check_up(boardb, random_row, random_col);
                cd = check_down(boardb, random_row, random_col);
                cr = check_right(boardb, random_row, random_col);
                cl = check_left(boardb, random_row, random_col);
            } while (cd + cu + cr + cl == 0 || boardb[random_row][random_col] != grid_type::peg);

            std::vector<int> direction_control = {cr, cl, cd, cu};

            for (int i = 0; i < 4; i++)
            {
                if (direction_control[i] != 0)
                {
                    filled_id.push_back(i);
                    k++;
                }
            }

            auto random = std::default_random_engine{};
            std::shuffle(std::begin(shuffle_vector), std::end(shuffle_vector), random);
            last_random = rand() % k;
            last_index = filled_id[last_random];

            if (last_index == 0)
            {
                boardb[random_row][random_col + 2] = boardb[random_row][random_col];
                boardb[random_row][random_col] = grid_type::space;
                boardb[random_row][random_col + 1] = grid_type::space;
            }

            else if (last_index == 1)
            {
                boardb[random_row][random_col - 2] = boardb[random_row][random_col];
                boardb[random_row][random_col] = grid_type::space;
                boardb[random_row][random_col - 1] = grid_type::space;
            }

            else if (last_index == 2)
            {
                boardb[random_row + 2][random_col] = boardb[random_row][random_col];
                boardb[random_row][random_col] = grid_type::space;
                boardb[random_row + 1][random_col] = grid_type::space;
            }
            else if (last_index == 3)
            {
                boardb[random_row - 2][random_col] = boardb[random_row][random_col];
                boardb[random_row][random_col] = grid_type::space;
                boardb[random_row - 1][random_col] = grid_type::space;
            }
            else
                std::cout << "Mistake happened";
            print_grid(boardb);
            temp_board= boardb;
            *board_type="board2";
            if(ask_user_to_continue()==2){
                print_grid(boardb);
                        enter19:
                        ret= parse_command(&row,&direction,&col,&filename);
                        std:: cout<< ret;
                        if(ret==1){
                            temp_board=load_file(filename,&does_file_exist,board_type);
                            if(!does_file_exist){
                            std::cerr<<"Please enter a valid file name!";
                            goto enter19;
                            }
                            computer_game(&temp_board,board_type,2,2);
                        }
                        else if(ret==2){
                                if(*board_type=="board6"){
                                    save_game_to_the_file_for_table_6(temp_board,6,1,filename);
                                }
                                else{
                                    if(*board_type=="board1"){
                                        std:: cout<< filename;
                                        save_game_to_the_file(temp_board,1,1,filename);
                                    }
                                    else if(*board_type=="board2"){
                                        save_game_to_the_file(temp_board,2,1,filename);
                                    }
                                     else if(*board_type=="board3"){
                                        save_game_to_the_file(temp_board,3,1,filename);
                                    }
                                     else if(*board_type=="board4"){
                                        save_game_to_the_file(temp_board,4,1,filename);
                                    }
                                     else if(*board_type=="board5"){
                                        save_game_to_the_file(temp_board,5,1,filename);
                                    }
                                     else if(*board_type=="board8"){
                                        save_game_to_the_file(temp_board,8,1,filename);
                                    }
                                     else if(*board_type=="board7"){
                                        save_game_to_the_file(temp_board,7,1,filename);
                                    }
                                     else if(*board_type=="board9"){                                      
                                         save_game_to_the_file(temp_board,9,1,filename);
                                    }
                                }
                        }
            }
        } while (!(check_game_is_done(boardb))); 
        std::cout << "Game is done! Score is: " << calculateScore(boardb);
        break;
    } 

        case 3: // if the user select for computer game for board5
    {   int user_ans;
        *board_type= "board3";
        do
        {
            capacity = boardc.capacity();
            int k = 0;
            int cd, cu, cr, cl, last_shuffle, last_random, last_index;
            std::vector<int> filled_id;
            auto shuffle_vector = filled_id;
            int flag = 0;
            random_col = rand() % capacity;
            random_row = rand() % capacity;
            do
            {
                random_col = rand() % capacity;
                random_row = rand() % capacity;
                cu = check_up(boardc, random_row, random_col);
                cd = check_down(boardc, random_row, random_col);
                cr = check_right(boardc, random_row, random_col);
                cl = check_left(boardc, random_row, random_col);
            } while (cd + cu + cr + cl == 0 || boardc[random_row][random_col] != grid_type::peg);

            std::vector<int> direction_control = {cr, cl, cd, cu};

            for (int i = 0; i < 4; i++)
            {
                if (direction_control[i] != 0)
                {
                    filled_id.push_back(i);
                    k++;
                }
            }

            auto random = std::default_random_engine{};
            std::shuffle(std::begin(shuffle_vector), std::end(shuffle_vector), random);
            last_random = rand() % k;
            last_index = filled_id[last_random];

            if (last_index == 0)
            {
                boardc[random_row][random_col + 2] = boardc[random_row][random_col];
                boardc[random_row][random_col] = grid_type::space;
                boardc[random_row][random_col + 1] = grid_type::space;
            }

            else if (last_index == 1)
            {
                boardc[random_row][random_col - 2] = boardc[random_row][random_col];
                boardc[random_row][random_col] = grid_type::space;
                boardc[random_row][random_col - 1] = grid_type::space;
            }

            else if (last_index == 2)
            {
                boardc[random_row + 2][random_col] = boardc[random_row][random_col];
                boardc[random_row][random_col] = grid_type::space;
                boardc[random_row + 1][random_col] = grid_type::space;
            }
            else if (last_index == 3)
            {
                boardc[random_row - 2][random_col] = boardc[random_row][random_col];
                boardc[random_row][random_col] = grid_type::space;
                boardc[random_row - 1][random_col] = grid_type::space;
            }
            else
                std::cout << "Mistake happened";
            print_grid(boardc);
            temp_board= boardc;
            *board_type="board7";
            if(ask_user_to_continue()==2){
                print_grid(boardc);
                        enter18:
                        ret= parse_command(&row,&direction,&col,&filename);
                        std:: cout<< ret;
                        if(ret==1){
                            temp_board=load_file(filename,&does_file_exist,board_type);
                            if(!does_file_exist){
                            std::cerr<<"Please enter a valid file name!";
                            goto enter18;
                            }
                            computer_game(&temp_board,board_type,2,3);
                        }
                        else if(ret==2){
                                if(*board_type=="board6"){
                                    save_game_to_the_file_for_table_6(temp_board,6,1,filename);
                                }
                                else{
                                    if(*board_type=="board1"){
                                        std:: cout<< filename;
                                        save_game_to_the_file(temp_board,1,1,filename);
                                    }
                                    else if(*board_type=="board2"){
                                        save_game_to_the_file(temp_board,2,1,filename);
                                    }
                                     else if(*board_type=="board3"){
                                        save_game_to_the_file(temp_board,3,1,filename);
                                    }
                                     else if(*board_type=="board4"){
                                        save_game_to_the_file(temp_board,4,1,filename);
                                    }
                                     else if(*board_type=="board5"){
                                        save_game_to_the_file(temp_board,5,1,filename);
                                    }
                                     else if(*board_type=="board8"){
                                        save_game_to_the_file(temp_board,8,1,filename);
                                    }
                                     else if(*board_type=="board7"){
                                        save_game_to_the_file(temp_board,7,1,filename);
                                    }
                                     else if(*board_type=="board9"){                                      
                                         save_game_to_the_file(temp_board,9,1,filename);
                                    }
                                }
                        }
            }
        } while (!(check_game_is_done(boardc))); 
        std::cout << "Game is done! Score is: " << calculateScore(boardc);
        break;
    } 

        case 4: // if the user select for computer game for board5
    {   int user_ans;
        *board_type= "board4";
        do
        {
            capacity = boardd.capacity();
            int k = 0;
            int cd, cu, cr, cl, last_shuffle, last_random, last_index;
            std::vector<int> filled_id;
            auto shuffle_vector = filled_id;
            int flag = 0;
            random_col = rand() % capacity;
            random_row = rand() % capacity;
            do
            {
                random_col = rand() % capacity;
                random_row = rand() % capacity;
                cu = check_up(boardd, random_row, random_col);
                cd = check_down(boardd, random_row, random_col);
                cr = check_right(boardd, random_row, random_col);
                cl = check_left(boardd, random_row, random_col);
            } while (cd + cu + cr + cl == 0 || boardd[random_row][random_col] != grid_type::peg);

            std::vector<int> direction_control = {cr, cl, cd, cu};

            for (int i = 0; i < 4; i++)
            {
                if (direction_control[i] != 0)
                {
                    filled_id.push_back(i);
                    k++;
                }
            }

            auto random = std::default_random_engine{};
            std::shuffle(std::begin(shuffle_vector), std::end(shuffle_vector), random);
            last_random = rand() % k;
            last_index = filled_id[last_random];

            if (last_index == 0)
            {
                boardd[random_row][random_col + 2] = boardd[random_row][random_col];
                boardd[random_row][random_col] = grid_type::space;
                boardd[random_row][random_col + 1] = grid_type::space;
            }

            else if (last_index == 1)
            {
                boardd[random_row][random_col - 2] = boardd[random_row][random_col];
                boardd[random_row][random_col] = grid_type::space;
                boardd[random_row][random_col - 1] = grid_type::space;
            }

            else if (last_index == 2)
            {
                boardd[random_row + 2][random_col] = boardd[random_row][random_col];
                boardd[random_row][random_col] = grid_type::space;
                boardd[random_row + 1][random_col] = grid_type::space;
            }
            else if (last_index == 3)
            {
                boardd[random_row - 2][random_col] = boardd[random_row][random_col];
                boardd[random_row][random_col] = grid_type::space;
                boardd[random_row - 1][random_col] = grid_type::space;
            }
            else
                std::cout << "Mistake happened";
            print_grid(boardd);
            temp_board= boardd;
            *board_type="board7";
            if(ask_user_to_continue()==2){
                print_grid(boardd);
                        enter14:
                        ret= parse_command(&row,&direction,&col,&filename);
                        std:: cout<< ret;
                        if(ret==1){
                            temp_board=load_file(filename,&does_file_exist,board_type);
                            if(!does_file_exist){
                            std::cerr<<"Please enter a valid file name!";
                            goto enter14;
                            }
                            computer_game(&temp_board,board_type,2,4);
                        }
                        else if(ret==2){
                                if(*board_type=="board6"){
                                    save_game_to_the_file_for_table_6(temp_board,6,1,filename);
                                }
                                else{
                                    if(*board_type=="board1"){
                                        std:: cout<< filename;
                                        save_game_to_the_file(temp_board,1,1,filename);
                                    }
                                    else if(*board_type=="board2"){
                                        save_game_to_the_file(temp_board,2,1,filename);
                                    }
                                     else if(*board_type=="board3"){
                                        save_game_to_the_file(temp_board,3,1,filename);
                                    }
                                     else if(*board_type=="board4"){
                                        save_game_to_the_file(temp_board,4,1,filename);
                                    }
                                     else if(*board_type=="board5"){
                                        save_game_to_the_file(temp_board,5,1,filename);
                                    }
                                     else if(*board_type=="board8"){
                                        save_game_to_the_file(temp_board,8,1,filename);
                                    }
                                     else if(*board_type=="board7"){
                                        save_game_to_the_file(temp_board,7,1,filename);
                                    }
                                     else if(*board_type=="board9"){                                      
                                         save_game_to_the_file(temp_board,9,1,filename);
                                    }
                                }
                        }
            }
        } while (!(check_game_is_done(boardd))); 
        std::cout << "Game is done! Score is: " << calculateScore(boardd);
        break;
    } 
            
        case 5: // if the user select for computer game for board5
    {   int user_ans;
        *board_type= "board5";
        do
        {
            capacity = boarde.capacity();
            int k = 0;
            int cd, cu, cr, cl, last_shuffle, last_random, last_index;
            std::vector<int> filled_id;
            auto shuffle_vector = filled_id;
            int flag = 0;
            random_col = rand() % capacity;
            random_row = rand() % capacity;
            do
            {
                random_col = rand() % capacity;
                random_row = rand() % capacity;
                cu = check_up(boarde, random_row, random_col);
                cd = check_down(boarde, random_row, random_col);
                cr = check_right(boarde, random_row, random_col);
                cl = check_left(boarde, random_row, random_col);
            } while (cd + cu + cr + cl == 0 || boarde[random_row][random_col] != grid_type::peg);

            std::vector<int> direction_control = {cr, cl, cd, cu};

            for (int i = 0; i < 4; i++)
            {
                if (direction_control[i] != 0)
                {
                    filled_id.push_back(i);
                    k++;
                }
            }

            auto random = std::default_random_engine{};
            std::shuffle(std::begin(shuffle_vector), std::end(shuffle_vector), random);
            last_random = rand() % k;
            last_index = filled_id[last_random];

            if (last_index == 0)
            {
                boarde[random_row][random_col + 2] = boarde[random_row][random_col];
                boarde[random_row][random_col] = grid_type::space;
                boarde[random_row][random_col + 1] = grid_type::space;
            }

            else if (last_index == 1)
            {
                boarde[random_row][random_col - 2] = boarde[random_row][random_col];
                boarde[random_row][random_col] = grid_type::space;
                boarde[random_row][random_col - 1] = grid_type::space;
            }

            else if (last_index == 2)
            {
                boarde[random_row + 2][random_col] = boarde[random_row][random_col];
                boarde[random_row][random_col] = grid_type::space;
                boarde[random_row + 1][random_col] = grid_type::space;
            }
            else if (last_index == 3)
            {
                boarde[random_row - 2][random_col] = boarde[random_row][random_col];
                boarde[random_row][random_col] = grid_type::space;
                boarde[random_row - 1][random_col] = grid_type::space;
            }
            else
                std::cout << "Mistake happened";
            print_grid(boarde);
            temp_board= boarde;
            *board_type="board5";
            if(ask_user_to_continue()==2){
                print_grid(boardf);
                        enter11:
                        ret= parse_command(&row,&direction,&col,&filename);
                        std:: cout<< ret;
                        if(ret==1){
                            temp_board=load_file(filename,&does_file_exist,board_type);
                            if(!does_file_exist){
                            std::cerr<<"Please enter a valid file name!";
                            goto enter11;
                            }
                            computer_game(&temp_board,board_type,2,5);
                        }
                        else if(ret==2){
                                if(*board_type=="board6"){
                                    save_game_to_the_file_for_table_6(temp_board,6,1,filename);
                                }
                                else{
                                    if(*board_type=="board1"){
                                        std:: cout<< filename;
                                        save_game_to_the_file(temp_board,1,1,filename);
                                    }
                                    else if(*board_type=="board2"){
                                        save_game_to_the_file(temp_board,2,1,filename);
                                    }
                                     else if(*board_type=="board3"){
                                        save_game_to_the_file(temp_board,3,1,filename);
                                    }
                                     else if(*board_type=="board4"){
                                        save_game_to_the_file(temp_board,4,1,filename);
                                    }
                                     else if(*board_type=="board5"){
                                        save_game_to_the_file(temp_board,5,1,filename);
                                    }
                                     else if(*board_type=="board8"){
                                        save_game_to_the_file(temp_board,8,1,filename);
                                    }
                                     else if(*board_type=="board7"){
                                        save_game_to_the_file(temp_board,7,1,filename);
                                    }
                                     else if(*board_type=="board9"){                                      
                                         save_game_to_the_file(temp_board,9,1,filename);
                                    }
                                }
                        }
            }
        } while (!(check_game_is_done(boarde))); 
        std::cout << "Game is done! Score is: " << calculateScore(boarde);
        break;
    } 
        
        case 6: // if the user select for computer game for board5
    {   
        int user_ans;
        *board_type= "board6";
        do
        {
            capacity = boardf.capacity();
            int k = 0;
            int cd, cu, cr, cl, last_shuffle, last_random, last_index;
            std::vector<int> filled_id;
            auto shuffle_vector = filled_id;
            int flag = 0;
            random_col = rand() % capacity;
            random_row = rand() % capacity;
            do
            {
                random_col = rand() % capacity;
                random_row = rand() % capacity;
                cu = check_up(boardf, random_row, random_col);
                cd = check_down(boardf, random_row, random_col);
                cr = check_right(boardf, random_row, random_col);
                cl = check_left(boardf, random_row, random_col);
            } while (cd + cu + cr + cl == 0 || boardf[random_row][random_col] != grid_type::peg);

            std::vector<int> direction_control = {cr, cl, cd, cu};

            for (int i = 0; i < 4; i++)
            {
                if (direction_control[i] != 0)
                {
                    filled_id.push_back(i);
                    k++;
                }
            }

            auto random = std::default_random_engine{};
            std::shuffle(std::begin(shuffle_vector), std::end(shuffle_vector), random);
            last_random = rand() % k;
            last_index = filled_id[last_random];

            if (last_index == 0)
            {
                boardf[random_row][random_col + 2] = boardf[random_row][random_col];
                boardf[random_row][random_col] = grid_type::space;
                boardf[random_row][random_col + 1] = grid_type::space;
            }

            else if (last_index == 1)
            {
                boardf[random_row][random_col - 2] = boardf[random_row][random_col];
                boardf[random_row][random_col] = grid_type::space;
                boardf[random_row][random_col - 1] = grid_type::space;
            }

            else if (last_index == 2)
            {
                boardf[random_row + 2][random_col] = boardf[random_row][random_col];
                boardf[random_row][random_col] = grid_type::space;
                boardf[random_row + 1][random_col] = grid_type::space;
            }
            else if (last_index == 3)
            {
                boardf[random_row - 2][random_col] = boardf[random_row][random_col];
                boardf[random_row][random_col] = grid_type::space;
                boardf[random_row - 1][random_col] = grid_type::space;
            }
            else
                std::cout << "Mistake happened";
            print_grid(boardf);
            temp_board= boardf;
            *board_type="board7";
            if(ask_user_to_continue()==2){
                print_grid(boardf);
                        enter10:
                        ret= parse_command(&row,&direction,&col,&filename);
                        std:: cout<< ret;
                        if(ret==1){
                            temp_board=load_file(filename,&does_file_exist,board_type);
                            if(!does_file_exist){
                            std::cerr<<"Please enter a valid file name!";
                            goto enter10;
                            }
                            computer_game(&temp_board,board_type,2,6);
                        }
                        else if(ret==2){
                                if(*board_type=="board6"){
                                    save_game_to_the_file_for_table_6(temp_board,6,1,filename);
                                }
                                else{
                                    if(*board_type=="board1"){
                                        std:: cout<< filename;
                                        save_game_to_the_file(temp_board,1,1,filename);
                                    }
                                    else if(*board_type=="board2"){
                                        save_game_to_the_file(temp_board,2,1,filename);
                                    }
                                     else if(*board_type=="board3"){
                                        save_game_to_the_file(temp_board,3,1,filename);
                                    }
                                     else if(*board_type=="board4"){
                                        save_game_to_the_file(temp_board,4,1,filename);
                                    }
                                     else if(*board_type=="board5"){
                                        save_game_to_the_file(temp_board,5,1,filename);
                                    }
                                     else if(*board_type=="board8"){
                                        save_game_to_the_file(temp_board,8,1,filename);
                                    }
                                     else if(*board_type=="board7"){
                                        save_game_to_the_file(temp_board,7,1,filename);
                                    }
                                     else if(*board_type=="board9"){                                      
                                         save_game_to_the_file(temp_board,9,1,filename);
                                    }
                                }
                        }
            }
        } while (!(check_game_is_done(boardf))); 
        std::cout << "Game is done! Score is: " << calculateScore(boardf);
        break;
    } 
    case 7: // if the user select for computer game for board5
    {   int user_ans;
        *board_type= "board7";
        do
        {
            capacity = boardk.capacity();
            int k = 0;
            int cd, cu, cr, cl, last_shuffle, last_random, last_index;
            std::vector<int> filled_id;
            auto shuffle_vector = filled_id;
            int flag = 0;
            random_col = rand() % capacity;
            random_row = rand() % capacity;
            do
            {
                random_col = rand() % capacity;
                random_row = rand() % capacity;
                cu = check_up(boardk, random_row, random_col);
                cd = check_down(boardk, random_row, random_col);
                cr = check_right(boardk, random_row, random_col);
                cl = check_left(boardk, random_row, random_col);
            } while (cd + cu + cr + cl == 0 || boardk[random_row][random_col] != grid_type::peg);

            std::vector<int> direction_control = {cr, cl, cd, cu};

            for (int i = 0; i < 4; i++)
            {
                if (direction_control[i] != 0)
                {
                    filled_id.push_back(i);
                    k++;
                }
            }

            auto random = std::default_random_engine{};
            std::shuffle(std::begin(shuffle_vector), std::end(shuffle_vector), random);
            last_random = rand() % k;
            last_index = filled_id[last_random];

            if (last_index == 0)
            {
                boardk[random_row][random_col + 2] = boardk[random_row][random_col];
                boardk[random_row][random_col] = grid_type::space;
                boardk[random_row][random_col + 1] = grid_type::space;
            }

            else if (last_index == 1)
            {
                boardk[random_row][random_col - 2] = boardk[random_row][random_col];
                boardk[random_row][random_col] = grid_type::space;
                boardk[random_row][random_col - 1] = grid_type::space;
            }

            else if (last_index == 2)
            {
                boardk[random_row + 2][random_col] = boardk[random_row][random_col];
                boardk[random_row][random_col] = grid_type::space;
                boardk[random_row + 1][random_col] = grid_type::space;
            }
            else if (last_index == 3)
            {
                boardk[random_row - 2][random_col] = boardk[random_row][random_col];
                boardk[random_row][random_col] = grid_type::space;
                boardk[random_row - 1][random_col] = grid_type::space;
            }
            else
                std::cout << "Mistake happened";
            print_grid(boardk);
            temp_board= boardk;
            *board_type="board7";
            if(ask_user_to_continue()==2){
                print_grid(boardk);
                        enter9:
                        ret= parse_command(&row,&direction,&col,&filename);
                        std:: cout<< ret;
                        if(ret==1){
                            temp_board=load_file(filename,&does_file_exist,board_type);
                            if(!does_file_exist){
                            std::cerr<<"Please enter a valid file name!";
                            goto enter9;
                            }
                            computer_game(&temp_board,board_type,2,7);
                        }
                        else if(ret==2){
                                if(*board_type=="board6"){
                                    save_game_to_the_file_for_table_6(temp_board,6,1,filename);
                                }
                                else{
                                    if(*board_type=="board1"){
                                        std:: cout<< filename;
                                        save_game_to_the_file(temp_board,1,1,filename);
                                    }
                                    else if(*board_type=="board2"){
                                        save_game_to_the_file(temp_board,2,1,filename);
                                    }
                                     else if(*board_type=="board3"){
                                        save_game_to_the_file(temp_board,3,1,filename);
                                    }
                                     else if(*board_type=="board4"){
                                        save_game_to_the_file(temp_board,4,1,filename);
                                    }
                                     else if(*board_type=="board5"){
                                        save_game_to_the_file(temp_board,5,1,filename);
                                    }
                                     else if(*board_type=="board8"){
                                        save_game_to_the_file(temp_board,8,1,filename);
                                    }
                                     else if(*board_type=="board7"){
                                        save_game_to_the_file(temp_board,7,1,filename);
                                    }
                                     else if(*board_type=="board9"){                                      
                                         save_game_to_the_file(temp_board,9,1,filename);
                                    }
                                }
                        }
            }
        } while (!(check_game_is_done(boardk))); 
        std::cout << "Game is done! Score is: " << calculateScore(boardk);
        break;
    } 
    case 8: // if the user select for computer game for board5
    {   int user_ans;
        *board_type= "board8";
        do
        {
            capacity = boardo.capacity();
            int k = 0;
            int cd, cu, cr, cl, last_shuffle, last_random, last_index;
            std::vector<int> filled_id;
            auto shuffle_vector = filled_id;
            int flag = 0;
            random_col = rand() % capacity;
            random_row = rand() % capacity;
            do
            {
                random_col = rand() % capacity;
                random_row = rand() % capacity;
                cu = check_up(boardo, random_row, random_col);
                cd = check_down(boardo, random_row, random_col);
                cr = check_right(boardo, random_row, random_col);
                cl = check_left(boardo, random_row, random_col);
            } while (cd + cu + cr + cl == 0 || boardo[random_row][random_col] != grid_type::peg);

            std::vector<int> direction_control = {cr, cl, cd, cu};

            for (int i = 0; i < 4; i++)
            {
                if (direction_control[i] != 0)
                {
                    filled_id.push_back(i);
                    k++;
                }
            }

            auto random = std::default_random_engine{};
            std::shuffle(std::begin(shuffle_vector), std::end(shuffle_vector), random);
            last_random = rand() % k;
            last_index = filled_id[last_random];

            if (last_index == 0)
            {
                boardo[random_row][random_col + 2] = boardo[random_row][random_col];
                boardo[random_row][random_col] = grid_type::space;
                boardo[random_row][random_col + 1] = grid_type::space;
            }

            else if (last_index == 1)
            {
                boardo[random_row][random_col - 2] = boardo[random_row][random_col];
                boardo[random_row][random_col] = grid_type::space;
                boardo[random_row][random_col - 1] = grid_type::space;
            }

            else if (last_index == 2)
            {
                boardo[random_row + 2][random_col] = boardo[random_row][random_col];
                boardo[random_row][random_col] = grid_type::space;
                boardo[random_row + 1][random_col] = grid_type::space;
            }
            else if (last_index == 3)
            {
                boardo[random_row - 2][random_col] = boardo[random_row][random_col];
                boardo[random_row][random_col] = grid_type::space;
                boardo[random_row - 1][random_col] = grid_type::space;
            }
            else
                std::cout << "Mistake happened";
            print_grid(boardo);
            temp_board= boardo;
            *board_type="board8";
            if(ask_user_to_continue()==2){
                print_grid(boardo);
                        enter15:
                        ret= parse_command(&row,&direction,&col,&filename);
                        std:: cout<< ret;
                        if(ret==1){
                            temp_board=load_file(filename,&does_file_exist,board_type);
                            if(!does_file_exist){
                            std::cerr<<"Please enter a valid file name!";
                            goto enter15;
                            }
                            computer_game(&temp_board,board_type,2,8);
                        }
                        else if(ret==2){
                                if(*board_type=="board6"){
                                    save_game_to_the_file_for_table_6(temp_board,6,1,filename);
                                }
                                else{
                                    if(*board_type=="board1"){
                                        std:: cout<< filename;
                                        save_game_to_the_file(temp_board,1,1,filename);
                                    }
                                    else if(*board_type=="board2"){
                                        save_game_to_the_file(temp_board,2,1,filename);
                                    }
                                     else if(*board_type=="board3"){
                                        save_game_to_the_file(temp_board,3,1,filename);
                                    }
                                     else if(*board_type=="board4"){
                                        save_game_to_the_file(temp_board,4,1,filename);
                                    }
                                     else if(*board_type=="board5"){
                                        save_game_to_the_file(temp_board,5,1,filename);
                                    }
                                     else if(*board_type=="board8"){
                                        save_game_to_the_file(temp_board,8,1,filename);
                                    }
                                     else if(*board_type=="board7"){
                                        save_game_to_the_file(temp_board,7,1,filename);
                                    }
                                     else if(*board_type=="board9"){                                      
                                         save_game_to_the_file(temp_board,9,1,filename);
                                    }
                                }
                        }
            }
        } while (!(check_game_is_done(boardo))); 
        std::cout << "Game is done! Score is: " << calculateScore(boardo);
        break;
    }
    case 9: // if the user select for computer game for board5
    {   int user_ans;
        *board_type= "board9";
        do
        {
            capacity = boardl.capacity();
            int k = 0;
            int cd, cu, cr, cl, last_shuffle, last_random, last_index;
            std::vector<int> filled_id;
            auto shuffle_vector = filled_id;
            int flag = 0;
            random_col = rand() % capacity;
            random_row = rand() % capacity;
            do
            {
                random_col = rand() % capacity;
                random_row = rand() % capacity;
                cu = check_up(boardl, random_row, random_col);
                cd = check_down(boardl, random_row, random_col);
                cr = check_right(boardl, random_row, random_col);
                cl = check_left(boardl, random_row, random_col);
            } while (cd + cu + cr + cl == 0 || boardl[random_row][random_col] != grid_type::peg);

            std::vector<int> direction_control = {cr, cl, cd, cu};

            for (int i = 0; i < 4; i++)
            {
                if (direction_control[i] != 0)
                {
                    filled_id.push_back(i);
                    k++;
                }
            }

            auto random = std::default_random_engine{};
            std::shuffle(std::begin(shuffle_vector), std::end(shuffle_vector), random);
            last_random = rand() % k;
            last_index = filled_id[last_random];

            if (last_index == 0)
            {
                boardl[random_row][random_col + 2] = boardl[random_row][random_col];
                boardl[random_row][random_col] = grid_type::space;
                boardl[random_row][random_col + 1] = grid_type::space;
            }

            else if (last_index == 1)
            {
                boardl[random_row][random_col - 2] = boardl[random_row][random_col];
                boardl[random_row][random_col] = grid_type::space;
                boardl[random_row][random_col - 1] = grid_type::space;
            }

            else if (last_index == 2)
            {
                boardl[random_row + 2][random_col] = boardl[random_row][random_col];
                boardl[random_row][random_col] = grid_type::space;
                boardl[random_row + 1][random_col] = grid_type::space;
            }
            else if (last_index == 3)
            {
                boardl[random_row - 2][random_col] = boardl[random_row][random_col];
                boardl[random_row][random_col] = grid_type::space;
                boardl[random_row - 1][random_col] = grid_type::space;
            }
            else
                std::cout << "Mistake happened";
            print_grid(boardl);
            temp_board= boardl;
            *board_type="board9";
            if(ask_user_to_continue()==2){
                print_grid(boardl);
                        enter5:
                        ret= parse_command(&row,&direction,&col,&filename);
                        std:: cout<< ret;
                        if(ret==1){
                            temp_board=load_file(filename,&does_file_exist,board_type);
                            if(!does_file_exist){
                            std::cerr<<"Please enter a valid file name!";
                            goto enter5;
                            }
                            computer_game(&temp_board,board_type,2,9);
                        }
                        else if(ret==2){
                                if(*board_type=="board6"){
                                    save_game_to_the_file_for_table_6(temp_board,6,1,filename);
                                }
                                else{
                                    if(*board_type=="board1"){
                                        std:: cout<< filename;
                                        save_game_to_the_file(temp_board,1,1,filename);
                                    }
                                    else if(*board_type=="board2"){
                                        save_game_to_the_file(temp_board,2,1,filename);
                                    }
                                     else if(*board_type=="board3"){
                                        save_game_to_the_file(temp_board,3,1,filename);
                                    }
                                     else if(*board_type=="board4"){
                                        save_game_to_the_file(temp_board,4,1,filename);
                                    }
                                     else if(*board_type=="board5"){
                                        save_game_to_the_file(temp_board,5,1,filename);
                                    }
                                     else if(*board_type=="board8"){
                                        save_game_to_the_file(temp_board,8,1,filename);
                                    }
                                     else if(*board_type=="board7"){
                                        save_game_to_the_file(temp_board,7,1,filename);
                                    }
                                     else if(*board_type=="board9"){                                      
                                         save_game_to_the_file(temp_board,9,1,filename);
                                    }
                                }
                        }
            }
        } while (!(check_game_is_done(boardl))); 
    }
        std::cout << "Game is done! Score is: " << calculateScore(boardl);
        break;
    
      default:
        std::cout << "Please choose a grid between 1-9" << std::endl;
        goto ab2;
        break;
    }
}

void manage_the_human_game_with_arbitraries(int flag = 0) //DEFAULT FLAG PARAMETER
{
    int choice, row, col, control,choice1,does_file_exist,ret;  
    string filename;
    char direction;
    int menu_choice;
    string board_type;
        std::vector<std::vector<grid_type>> load_file_return;
        std::vector<std::vector<grid_type>> board1_temp(board1);
        std::vector<std::vector<grid_type>> board2_temp(board2);
        std::vector<std::vector<grid_type>> board3_temp(board3);
        std::vector<std::vector<grid_type>> board4_temp(board4);
        std::vector<std::vector<grid_type>> board5_temp(board5);
        std::vector<std::vector<grid_type>> board6_temp(board6);
        std::vector<std::vector<grid_type>> board7_temp(board7);
        std::vector<std::vector<grid_type>> board8_temp(board8);
        std::vector<std::vector<grid_type>> board9_temp(board9);
        std::vector<std::vector<grid_type>> temp_board;
        std:: cout<< "Start a new game(1) or load a game(2)?: ";
        std:: cin >> menu_choice;
        if(menu_choice==1){ // User has selected to started a new game
            enter3:
            std:: cout<< "Please choose a board!: "; // Printing the boards
            std:: cout<< "Board 1: ";
            print_grid(board1);
            std:: cout<< "Board 2: ";
            print_grid(board2);
            std:: cout<< "Board 3: ";
            print_grid(board3);
            std:: cout<< "Board 4: ";
            print_grid(board4);
            std:: cout<< "Board 5: ";
            print_grid(board5);
            std:: cout<< "Board 6: ";
            print_last_grid(board6);
            std:: cout<< "Board 7: ";
            print_grid(board7);
            std:: cout<< "Board 8: ";
            print_grid(board8);
            std:: cout<< "Board 9: ";
            print_grid(board9);
            int choice;
            std:: cin>> choice;
            if(std::cin.fail()){
                std:: cout<< "Please enter an integer!";
            }
            else if(choice>=10 || choice <1 ){
                std:: cout<< "Please enter a valid integer!";
                goto enter3;
            }
            if(choice==1){
                temp_board=board1;
                board_type="board1";
            }
            else if(choice==2){
                temp_board=board2;
                board_type="board2";
            }
            else if(choice==3){
                temp_board=board3;
                board_type="board3";
            }
            else if(choice==4){
                temp_board=board4;
                board_type="board4";
            }
            else if(choice==5){
                temp_board=board5;
                board_type="board5";
            }
            else if(choice==6){
                temp_board=board6;
                board_type="board6";
            }
            else if(choice==7){
                temp_board=board7;
                board_type="board7";
            }
            else if(choice==8){
                temp_board=board8;
                board_type="board8";
            }
            else if(choice==9){
                temp_board=board9;
                board_type="board9";
            }
                do{     
                        print_grid(temp_board);
                        enter5:
                        ret= parse_command(&row,&direction,&col,&filename);
                        if(ret==1){
                            temp_board=load_file(filename,&does_file_exist,&board_type);
                            if(!does_file_exist){
                            std::cerr<<"Please enter a valid file name!";
                            goto enter5;
                            }
                            std:: cout<< "Loaded board is :"<< std::endl;
                        }
                        else if(ret==2){
                            std:: cout<< board_type;
                                if(board_type=="board6"){
                                    save_game_to_the_file_for_table_6(temp_board,6,1,filename);
                                }
                                else{
                                    if(board_type=="board1"){
                                        std:: cout<< filename;
                                        save_game_to_the_file(temp_board,1,1,filename);
                                    }
                                    else if(board_type=="board2"){
                                        save_game_to_the_file(temp_board,2,1,filename);
                                    }
                                     else if(board_type=="board3"){
                                        save_game_to_the_file(temp_board,3,1,filename);
                                    }
                                     else if(board_type=="board4"){
                                        save_game_to_the_file(temp_board,4,1,filename);
                                    }
                                     else if(board_type=="board5"){
                                        save_game_to_the_file(temp_board,5,1,filename);
                                    }
                                     else if(board_type=="board8"){
                                        save_game_to_the_file(temp_board,8,1,filename);
                                    }
                                     else if(board_type=="board7"){
                                        save_game_to_the_file(temp_board,7,1,filename);
                                    }
                                     else if(board_type=="board9"){
                                        save_game_to_the_file(temp_board,9,1,filename);
                                    }
                                }
                        }
                        else if(ret==0){ // manage the game
                            if(board_type=="board6"){
                                manage_game_for_board_6(&temp_board,row,direction,col);
                            }
                            else{
                                manage_game(&temp_board,row,direction,col);
                            }
                        }
                }
                while( number_of_peg_left(temp_board)!=1 && check_game_is_done(temp_board)==0 );
                if(number_of_peg_left(temp_board)==1){
                    std:: cout<<"You win the game!";
                    exit(1);
                }
                else if(check_game_is_done(temp_board)==1){
                    std:: cout<< "Game is done!";
                }

        }
        else{ // User has selected to load a loaded game
        enter1:
            ret= parse_command(&row,&direction,&col,&filename);
            if(ret!=1){
                std::cerr<<"Please enter a load command";
                goto enter1;
            }   
                enter2:
                load_file_return=load_file(filename,&does_file_exist,&board_type);
                if(!does_file_exist){
                    std::cerr<<"Please enter a valid file name!";
                    goto enter1;
                }
                std:: cout<< "Loaded board is :"<< std::endl;
                print_grid(load_file_return);
                do{     
                        print_grid(load_file_return);
                        ret= parse_command(&row,&direction,&col,&filename);
                        if(ret==1){
                                goto enter2;
                        }
                        else if(ret==2){
                                if(board_type=="board6"){
                                    save_game_to_the_file_for_table_6(load_file_return,6,1,filename);
                                }
                                else{
                                    if(board_type=="board1"){
                                        save_game_to_the_file(load_file_return,1,1,filename);
                                    }
                                    else if(board_type=="board2"){
                                        save_game_to_the_file(load_file_return,2,1,filename);
                                    }
                                     else if(board_type=="board3"){
                                        save_game_to_the_file(load_file_return,3,1,filename);
                                    }
                                     else if(board_type=="board4"){
                                        save_game_to_the_file(load_file_return,4,1,filename);
                                    }
                                     else if(board_type=="board5"){
                                        save_game_to_the_file(load_file_return,5,1,filename);
                                    }
                                     else if(board_type=="board8"){
                                        save_game_to_the_file(load_file_return,8,1,filename);
                                    }
                                     else if(board_type=="board7"){
                                        save_game_to_the_file(load_file_return,7,1,filename);
                                    }
                                     else if(board_type=="board9"){
                                        save_game_to_the_file(load_file_return,9,1,filename);
                                    }
                                }
                        }
                        else if(ret==0){ // manage the game
                            if(board_type=="board6"){
                                manage_game_for_board_6(&load_file_return,row,direction,col);
                            }
                            else{
                                manage_game(&load_file_return,row,direction,col);
                            }
                        }
                }
                while( ret!=1 && number_of_peg_left(load_file_return)!=1 && check_game_is_done(load_file_return)==0 );
                if(number_of_peg_left(load_file_return)==1){
                    std:: cout<<"You win the game!";
                    exit(1);
                }
                else if(check_game_is_done(load_file_return)==1){
                    std:: cout<< "Game is done!";
                }
        }
 }
void manage_the_computer_game_with_arbitraries(int flag = 1) //DEFAULT FLAG ARGUMENT
{ // this function manages the human games with arbitrary boards (board 7 ,8 and 9)
    int choice, row, col, control,choice1,does_file_exist,ret,ret1,parameter;  
    string filename;
    char direction;
    int menu_choice;
    string board_type;
        std::vector<std::vector<grid_type>> load_file_return; // temporary vectors that will be used
        std::vector<std::vector<grid_type>> board1_temp(board1);
        std::vector<std::vector<grid_type>> board2_temp(board2);
        std::vector<std::vector<grid_type>> board3_temp(board3);
        std::vector<std::vector<grid_type>> board4_temp(board4);
        std::vector<std::vector<grid_type>> board5_temp(board5);
        std::vector<std::vector<grid_type>> board6_temp(board6);
        std::vector<std::vector<grid_type>> board7_temp(board7);
        std::vector<std::vector<grid_type>> board8_temp(board8);
        std::vector<std::vector<grid_type>> board9_temp(board9);
        std::vector<std::vector<grid_type>> temp_board;
        std:: cout<< "Start a new game(1) or load a game(2)?: ";
        std:: cin >> menu_choice;
        if(menu_choice==1){ // User has selected to started a new game
            do{         
                    computer_game(&temp_board,&board_type,1,10);
                }
            while( number_of_peg_left(temp_board)!=1 && check_game_is_done(temp_board)==0 );
                //user command girmek isterse
                        print_grid(temp_board);
                        enter5:
                        ret= parse_command(&row,&direction,&col,&filename);
                        if(ret==1){
                            temp_board=load_file(filename,&does_file_exist,&board_type);
                            if(!does_file_exist){
                            std::cerr<<"Please enter a valid file name!";
                            goto enter5;
                            }
                            std:: cout<< "Loaded board is :"<< std::endl;
                            print_grid(temp_board);
                        }
                        else if(ret==2){
                            
                                if(board_type=="board6"){
                                    save_game_to_the_file_for_table_6(temp_board,6,1,filename);
                                }
                                else{
                                    if(board_type=="board1"){
                                        std:: cout<< filename;
                                        save_game_to_the_file(temp_board,1,1,filename);
                                    }
                                    else if(board_type=="board2"){
                                        save_game_to_the_file(temp_board,2,1,filename);
                                    }
                                     else if(board_type=="board3"){
                                        save_game_to_the_file(temp_board,3,1,filename);
                                    }
                                     else if(board_type=="board4"){
                                        save_game_to_the_file(temp_board,4,1,filename);
                                    }
                                     else if(board_type=="board5"){
                                        save_game_to_the_file(temp_board,5,1,filename);
                                    }
                                     else if(board_type=="board8"){
                                        save_game_to_the_file(temp_board,8,1,filename);
                                    }
                                     else if(board_type=="board7"){
                                        save_game_to_the_file(temp_board,7,1,filename);
                                    }
                                     else if(board_type=="board9"){
                                        save_game_to_the_file(temp_board,9,1,filename);
                                    }
                                }
                            }
                                 
                if(number_of_peg_left(temp_board)==1){
                    std:: cout<<"You win the game!";
                    exit(1);
                }
                else if(check_game_is_done(temp_board)==1){
                    std:: cout<< "Game is done!";
                } 

        }
        else{ // User has selected to load a loaded game
            adam1:
            int row2,col2,does_file_exist1;
            string filename2,board_type2;
            char direction2;
            int return_value=parse_command(&row2,&direction2,&col2,&filename2);
            
            if(return_value==1){
                std::vector<std::vector<grid_type>> temp;
                temp=load_file(filename2,&does_file_exist1,&board_type2);
                if(!does_file_exist1){
                    std:: cerr<< "There is no such file exists.Try again!" << std::endl;
                    goto adam1;
                }
                if(board_type2=="board1"){
                    computer_game(&temp,&board_type2,2,1);
                }
                else if(board_type2=="board2"){
                    computer_game(&temp,&board_type2,2,2);
                }
                else if(board_type2=="board3"){
                    computer_game(&temp,&board_type2,2,3);
                }
                else if(board_type2=="board4"){
                    computer_game(&temp,&board_type2,2,4);
                }
                else if(board_type2=="board5"){
                    computer_game(&temp,&board_type2,2,5);
                }
                else if(board_type2=="board6"){
                    computer_game(&temp,&board_type2,2,6);
                }
                else if(board_type2=="board7"){
                    computer_game(&temp,&board_type2,2,7);
                }
                else if(board_type2=="board8"){
                    computer_game(&temp,&board_type2,2,8);
                }
                else if(board_type2=="board9"){
                    computer_game(&temp,&board_type2,2,9);
                }

            }
            else{
                std:: cout<<"Please enter a load command";
                goto adam1;
            }
        }
    
}
int main()
{
        int choice;
        std::cout << std::endl
                  << "Choose a game type!: " << std::endl<< "1- Human Game: " << std::endl
                  << "2-Computer Game:";
        std::cin >> choice;
        if (choice == 1)
        {   
            manage_the_human_game_with_arbitraries(0);
        }
        else
        {
            manage_the_computer_game_with_arbitraries(1);
        }
    return 0;
}