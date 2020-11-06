#ifndef HOCS1_LETTER_H
#define HOCS1_LETTER_H

#include <iostream>

using namespace std;

class Letter {
public:
    string getLetter() {
        return letter;
    }

    int getCode(){
        return code;
    }

    Letter(string letter,int code){
        this->letter = letter;
        this->code = code;
    }

private:
    string letter;
    int code;
};


#endif //HOCS1_LETTER_H
