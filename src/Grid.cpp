#include "Grid.hpp"

std::vector<std::vector<int>> Grid::get(){
    return grid;
}

int Grid::getValue(int row, int col){
    return grid[row][col];
}

void Grid::set(int row, int col, int data){
    grid[row][col] = data;
}
