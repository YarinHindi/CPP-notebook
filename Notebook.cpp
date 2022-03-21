#include "Notebook.hpp"
#include <stdexcept>
#include <iostream>
#include "Direction.hpp"
#include <vector>
#include <map>
#include <stdexcept>
#include <string>
using ariel::Notebook;
using namespace std;

    Notebook::Notebook() {

    }
    void  Notebook::init_row(unsigned int page, unsigned int row){
        try {
            this->MyNotebook.at(page).at(row);

        }
        catch (exception& ex) {
            char *arr = new char[ROW_LENGHT];
            for (unsigned int i = 0; i < ROW_LENGHT; ++i) {
                arr[i] ='-';
            }

            this->MyNotebook[page][row] = arr;
        }
    }
    bool Notebook::check_if_already_written(unsigned int page, unsigned int row, unsigned int columns, ariel::Direction direction, unsigned int lenth){
        if(direction==Direction::Horizontal){
            for (unsigned int i = columns; i < columns+lenth; ++i) {
                if(this->MyNotebook.at(page).at(row)[i]=='~'||this->MyNotebook.at(page).at(row)[i]!='-'){
                    return true;
                }
            }
        }else{
            for (unsigned int i = row; i < row+lenth; ++i) {
                if(this->MyNotebook.at(page).at(i)[columns]=='~'||this->MyNotebook.at(page).at(i)[columns]!='-'){
                    return true;
                }
            }
        }
        return false;
    }
    void Notebook::write(unsigned int page, unsigned int row, unsigned int columns, ariel::Direction direction, string const & str) {
        if(direction==Direction::Horizontal){
            init_row(page,row);
        }else{
            for (unsigned int i = row; i < row+str.size() ; ++i) {
                init_row(page,i);
            }
        }
        if(check_if_already_written(page,row,columns,direction,str.size())){
           throw std::invalid_argument("you cant write in place that already been written");
        }if(direction==Direction::Horizontal){
                for (unsigned int i = columns; i <columns +str.size() ; ++i) {
                    this->MyNotebook.at(page).at(row)[i] = str.at(i-columns);

                }
            }else{
                for (unsigned int i = row; i <row +str.size() ; ++i) {
                    this->MyNotebook.at(page).at(i)[columns] = str.at(i-row);
                }
            }
        }



    string Notebook::read(unsigned int page, unsigned int row, unsigned int columns, ariel::Direction direction, unsigned int len) {
        if(direction==Direction::Horizontal){
            init_row(page,row);
        }else{
            for (unsigned int i = row; i < row+len ; ++i) {
                init_row(page,i);
            }
        }
        string ans;
        if(direction==Direction::Horizontal){
            for (unsigned int i = columns; i <columns +len ; ++i) {
               ans += this->MyNotebook.at(page).at(row)[i] ;
            }
        }else{
            for (unsigned int i = row; i <row +len ; ++i) {
                ans += this->MyNotebook.at(page).at(i)[columns] ;
            }
        }
        return ans;
    }




    void Notebook::erase(unsigned int page, unsigned int row, unsigned int columns, ariel::Direction direction, unsigned int len) {
        if(direction==Direction::Horizontal){
            init_row(page,row);
        }else{
            for (unsigned int i = row; i < row+len ; ++i) {
                init_row(page,i);
            }
        }
        if(direction==Direction::Horizontal){
            for (unsigned int i = columns; i <columns +len ; ++i) {
                this->MyNotebook.at(page).at(row)[i] = '~' ;
            }
        }else{
            for (unsigned int i = row; i <row +len ; ++i) {
                this->MyNotebook.at(page).at(i)[columns] = '~' ;
            }
        }
    }

    string Notebook::show(unsigned int p) {
    int size = this->MyNotebook.size();
    cout<<+"this is the size"+size;
        return +""+size;

}
