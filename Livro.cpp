#include "Livro.h"

Livro::Livro(string bookPathName)
{
    bookPath = bookPathName;
}

Livro::~Livro()
{
    //dtor
}


string Livro::readBook(string file){
    ofstream myfile;
    myfile.open (fileName);
    myfile << "Writing this to a file.\n";
    myfile.close();
    return 0;
}