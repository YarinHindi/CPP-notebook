#include "Direction.hpp"
#include <string>
#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;
namespace ariel {
    // Defines a direction of a message on the board
     class Notebook {
     public:
         static constexpr int  ROW_LENGHT = 100;
         unordered_map<int ,unordered_map<int,char*>> MyNotebook;
         Notebook();
         void write( int page, int row, int columns,Direction direction,string  const & str) const;
         string read( int page, int row, int columns,Direction direction, int len) const;
         void erase( int page, int row, int columns,Direction direction, int len) const;
         string show( int p) const;
         bool check_if_already_written( int page,  int row,  int columns, ariel::Direction direction,  int lenth) const;
         void init_row( int page,  int row) const;
     private:

    };

};