#include <vector>
#include <iostream>

class Grid{
    
    public:
        Grid(int col, int row) : grid(col, std::vector<int>(row)) {}
        std::vector<std::vector<int>> get();
        int getValue(int row, int col);
        void set(int row, int col, int data);

    private:
        std::vector<std::vector<int>> grid;

};