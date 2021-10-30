#ifndef GRIDS_H
#define GRIDS_H
#include <array>
#include <vector>
using namespace std;
 enum class grid_type // grid type for boards
{
    space = 0,
    peg = 1,
    wall = 2
};
std::vector<std::vector<grid_type> > board1 = { // 7x7 board
    {grid_type::wall, grid_type::wall, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::wall, grid_type::wall},
    {grid_type::wall, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::wall},
    {grid_type::peg, grid_type::peg, grid_type::peg, grid_type::space, grid_type::peg, grid_type::peg, grid_type::peg},
    {grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg},
    {grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg},
    {grid_type::wall, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::wall},
    {grid_type::wall, grid_type::wall, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::wall, grid_type::wall}};
std::vector<std::vector<grid_type> > board2 = { // 9x9 board
    {grid_type::wall, grid_type::wall, grid_type::wall, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::wall, grid_type::wall, grid_type::wall},
    {grid_type::wall, grid_type::wall,grid_type:: wall, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::wall,grid_type:: wall,grid_type:: wall},
    {grid_type::wall,grid_type:: wall,grid_type:: wall, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::wall,grid_type:: wall,grid_type:: wall},
    {grid_type::peg, grid_type::peg,  grid_type::peg,   grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg,  grid_type::peg},
    {grid_type::peg, grid_type::peg,  grid_type::peg,   grid_type::peg,grid_type::space,grid_type::peg, grid_type::peg, grid_type::peg,  grid_type::peg},
    {grid_type::peg, grid_type::peg,  grid_type::peg,   grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg,  grid_type::peg},
    {grid_type::wall,grid_type:: wall,grid_type:: wall, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::wall,grid_type:: wall,grid_type:: wall},
    {grid_type::wall,grid_type:: wall,grid_type:: wall, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::wall,grid_type:: wall,grid_type:: wall},
    {grid_type::wall,grid_type:: wall,grid_type:: wall, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::wall,grid_type:: wall,grid_type:: wall}};
std::vector<std::vector<grid_type> > board3 = {
    //8x8 board
    {grid_type::wall,grid_type:: wall, grid_type::peg, grid_type::peg,  grid_type:: peg, grid_type::wall, grid_type::wall, grid_type::wall},
    {grid_type::wall,grid_type:: wall, grid_type::peg, grid_type::peg,  grid_type:: peg, grid_type::wall, grid_type::wall, grid_type::wall},
    {grid_type::wall,grid_type:: wall, grid_type::peg, grid_type::peg,  grid_type:: peg, grid_type::wall, grid_type::wall, grid_type::wall},
    {grid_type::peg, grid_type::peg,   grid_type::peg, grid_type::peg,  grid_type:: peg, grid_type::peg,  grid_type::peg,  grid_type::peg},
    {grid_type::peg, grid_type::peg,   grid_type::peg, grid_type::space,grid_type:: peg, grid_type::peg,  grid_type::peg,  grid_type::peg},
    {grid_type::peg, grid_type::peg,   grid_type::peg, grid_type::peg,  grid_type:: peg, grid_type::peg,  grid_type::peg,  grid_type::peg},
    {grid_type::wall,grid_type:: wall, grid_type::peg, grid_type::peg,  grid_type:: peg, grid_type::wall, grid_type::wall, grid_type::wall},
    {grid_type::wall,grid_type:: wall, grid_type::peg, grid_type::peg,  grid_type:: peg, grid_type::wall, grid_type::wall, grid_type::wall},
};
std::vector<std::vector<grid_type> > board4 = {
    // 7x7 board
    {grid_type::wall, grid_type::wall, grid_type::peg,grid_type:: peg,  grid_type::peg, grid_type::wall, grid_type::wall},
    {grid_type::wall, grid_type::wall, grid_type::peg,grid_type:: peg,  grid_type::peg, grid_type::wall, grid_type::wall},
    {grid_type::peg,  grid_type:: peg, grid_type::peg,grid_type:: peg,  grid_type:: peg,grid_type:: peg, grid_type::peg},
    {grid_type::peg,  grid_type:: peg, grid_type::peg,grid_type:: space,grid_type:: peg,grid_type:: peg,grid_type:: peg},
    {grid_type::peg,  grid_type:: peg, grid_type::peg,grid_type:: peg,  grid_type:: peg,grid_type:: peg, grid_type::peg},
    {grid_type::wall, grid_type::wall, grid_type::peg,grid_type:: peg,  grid_type::peg, grid_type::wall, grid_type::wall},
    {grid_type::wall, grid_type::wall, grid_type::peg,grid_type:: peg,  grid_type::peg, grid_type::wall, grid_type::wall},
};
std::vector<std::vector<grid_type> > board5 = { // 9x9 board
    {grid_type::wall, grid_type::wall, grid_type::wall, grid_type::wall, grid_type::peg, grid_type::wall, grid_type::wall, grid_type::wall, grid_type::wall},
    {grid_type::wall, grid_type::wall, grid_type::wall, grid_type::peg,  grid_type::peg, grid_type::peg, grid_type::wall, grid_type::wall, grid_type::wall},
    {grid_type::wall, grid_type::wall, grid_type::peg,  grid_type::peg,  grid_type::peg, grid_type::peg, grid_type::peg, grid_type::wall, grid_type::wall},
    {grid_type::wall, grid_type::peg,  grid_type::peg,  grid_type::peg,  grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::wall},
    {grid_type::peg,  grid_type::peg,  grid_type::peg,  grid_type::peg,  grid_type::space, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg},
    {grid_type::wall, grid_type::peg,  grid_type::peg,  grid_type::peg,  grid_type::peg, grid_type::peg, grid_type::peg, grid_type::peg, grid_type::wall},
    {grid_type::wall, grid_type::wall, grid_type::peg,  grid_type::peg,  grid_type::peg, grid_type::peg, grid_type::peg, grid_type::wall, grid_type::wall},
    {grid_type::wall, grid_type::wall, grid_type::wall, grid_type::peg,  grid_type::peg, grid_type::peg, grid_type::wall, grid_type::wall, grid_type::wall},
    {grid_type::wall, grid_type::wall, grid_type::wall, grid_type::wall, grid_type::peg, grid_type::wall, grid_type::wall, grid_type::wall, grid_type::wall}};

std::vector<std::vector<grid_type> > board6 = { // 5x9 board
    {grid_type::wall, grid_type::wall,grid_type:: wall,grid_type:: wall, grid_type::space, grid_type::wall, grid_type::wall, grid_type::wall, grid_type::wall},
    {grid_type::wall, grid_type::wall,grid_type:: wall,grid_type:: peg,  grid_type::wall, grid_type::peg, grid_type::wall, grid_type::wall, grid_type::wall},
    {grid_type::wall, grid_type::wall,grid_type:: peg, grid_type:: wall, grid_type::peg, grid_type::wall, grid_type::peg, grid_type::wall, grid_type::wall},
    {grid_type::wall, grid_type::peg, grid_type::wall, grid_type:: peg,  grid_type::wall, grid_type::peg, grid_type::wall, grid_type::peg, grid_type::wall},
    {grid_type::peg,  grid_type::wall,grid_type:: peg, grid_type:: wall, grid_type::peg, grid_type::wall, grid_type::peg, grid_type::wall,grid_type:: peg}};
#endif //GRIDS_H