#include "Livro.h"

#include <fstream>

Livro::Livro(string bookPathName)
{
    bookPath = bookPathName;
}

Livro::~Livro()
{
    //dtor
}


void Livro::readBook(string file){
    ifstream myfile;
    char atual;
    myfile.open (fileName);
    if (myfile.is_open()){
        while (myfile.get(atual)){
            printf(%c,atual);
        }
        myfile.close();
    }
    else cout << "Unable to open file";
}