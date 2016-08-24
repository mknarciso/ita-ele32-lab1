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

int Livro::loadMatrix2(char anterior,char atual){
    if(charMap.find(make_pair(atual,anterior))!=charMap.end()){
        charMap[make_pair(atual,anterior)]++;
    }else charMap[make_pair(atual,anterior)]=1;
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
void Livro::printMatrix2(){
    map<pair<char, char>, int>::iterator It;
    for(It=charMap.begin();It!=charMap.end();It++){
        cout<<It->first.first<<","<<It->first.second<<": "<<It->second<<endl;
    }
}


void Livro::readBook(){
    ifstream myfile;
    char atual;
    char anterior=' ';
    myfile.open (bookPath);
    if (myfile.is_open()){
        while (myfile.get(atual)){
            //cout<<atual;
            loadMatrix(atual);
            loadMatrix2(anterior,atual);
            anterior=atual;
        }
        cout<<endl;
        myfile.close();
    }
    else cout << "Unable to open file";
    cout<<"======[ "<<bookPath<<" ]======"<<endl;
    cout<<"Caracteres:"<<quantityChar.size()<<" / ";
    cout<<"Combinações:"<<charMap.size();
}

int main() {
    Livro livro1 = Livro("hamlet-english.txt");
    Livro livro2 = Livro("hamlet-french.txt");
    Livro livro3 = Livro("hamlet-esperanto.txt");
    Livro livro4 = Livro("hamlet-finish.txt");
    Livro livro5 = Livro("hamlet-german.txt");
    Livro livro6 = Livro("hamlet-greek.txt");
    Livro livro7 = Livro("hamlet-portugues-arcaico.txt");
    livro1.readBook();
    livro2.readBook();
    livro3.readBook();
    livro4.readBook();
    livro5.readBook();
    livro6.readBook();
    livro7.readBook();
}
