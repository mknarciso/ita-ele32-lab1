#include "Livro.h"
#include <fstream>
#include <iostream>

using namespace std;

Livro::Livro(string bookPathName)
{
    bookPath = bookPathName;
}

Livro::~Livro()
{
    //dtor
}

int Livro::loadMatrix(char atual){
    if(quantityChar.find(atual)!=quantityChar.end())
        quantityChar[atual]++;
    else quantityChar[atual]=1;
    return 0;
}

void Livro::printMatrix1(){
    map<char,int>::iterator It;
    for(It=quantityChar.begin();It!=quantityChar.end();It++){
        cout<<It->first<<": "<<It->second<<endl;
    }
}


void Livro::readBook(){
    ifstream myfile;
    char atual;
    myfile.open (bookPath);
    if (myfile.is_open()){
        while (myfile.get(atual)){
            //cout<<atual;
            loadMatrix(atual);
        }
        cout<<endl;
        myfile.close();
    }
    printMatrix1();
    else cout << "Unable to open file";
}

int main() {
    Livro livro1 = Livro("teste.txt");
    livro1.readBook();
    cout << "Hello World!" << std::endl;
}
