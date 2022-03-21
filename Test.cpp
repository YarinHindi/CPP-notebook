#include "doctest.h"
#include "Notebook.hpp"
#include <string>
using namespace ariel;
using namespace std;


TEST_CASE("TEST read/write function : valid write meaning we didnt write in that place yet and on the way we check read also"){
    Notebook note2;
    note2.write(0,0,0,Direction::Horizontal,"that the start of the notebook");
    CHECK(note2.read(0,0,0,Direction::Horizontal,30)=="that the start of the notebook");
    note2.write(0,1,0,Direction::Vertical,"second time writing");
    CHECK(note2.read(0,1,0,Direction::Vertical,19)=="second time writing");
    char msg[100];
    for (int i = 0; i <100 ; ++i) {
        msg[i]='-';
    }
    for (unsigned int i = 0; i < 100; ++i) {
        note2.write(1,0,i,Direction::Horizontal,"a");
        msg[i]='a';
        CHECK(note2.read(1,0,0,Direction::Horizontal,100)==msg);

    }

}
TEST_CASE("TEST write function:: invalid writing meaning we already write to that place"){
    Notebook note3;
    note3.write(0,0,0,Direction::Horizontal,"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    for (unsigned int i = 0; i < 45 ; ++i) {
        CHECK_THROWS(note3.write(0,0,i,Direction::Horizontal,"t"));
        CHECK_THROWS(note3.write(0,0,i,Direction::Vertical,"y"));
    }

}
TEST_CASE("erase function"){
    Notebook note4;
    note4.erase(0,0,0,Direction::Horizontal,100);
    for (unsigned int i = 0; i < 100; ++i) {
        CHECK(note4.read(0,0,i,Direction::Horizontal,1)=="~");
    }

}