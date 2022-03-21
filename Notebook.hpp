#include "Direction.hpp"
#include <string>
#include <iostream>
#include <map>

using namespace std;
namespace ariel {
    // Defines a direction of a message on the board
     class Notebook {
     public:
         static constexpr int  ROW_LENGHT = 100;
         map<unsigned int ,map<unsigned int,char*>> MyNotebook;
         Notebook();
         void write(unsigned int page,unsigned int row,unsigned int columns,Direction direction,string  const & str);
         string read(unsigned int page,unsigned int row,unsigned int columns,Direction direction,unsigned int len);
         void erase(unsigned int page,unsigned int row,unsigned int columns,Direction direction,unsigned int len);
         string show(unsigned int p);
         bool  check_if_already_written(unsigned int page, unsigned int row, unsigned int columns, ariel::Direction direction, unsigned int lenth);
         void  init_row(unsigned int page, unsigned int row);
     private:

    };

};