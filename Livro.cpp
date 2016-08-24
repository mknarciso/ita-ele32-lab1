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
    if(quantityChar.find(atual)!=quantityChar.end()){
        quantityChar[atual]++;
    }else quantityChar[atual]=1;
    return 0;
}

void Livro::computeEficiency() {
    
}

void Livro::computePrevisibility() {
    
}

void Livro::computeInfoNextChar() {
    
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
    else cout << "Unable to open file";
    
    printMatrix1();
}

int main() {
    Livro livro1 = Livro("darwin-french.txt");
    livro1.readBook();
}
