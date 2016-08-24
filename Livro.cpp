#include "Livro.h"
#include <fstream>
#include <iostream>
#include <tgmath.h> 

using namespace std;

Livro::Livro(string bookPathName)
{
    bookPath = bookPathName;
    entropy = 0;
    totalChars = 0;
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

void Livro::computeProbabilities() {
    map<char,int>:: iterator it;
    for (it = quantityChar.begin(); it != quantityChar.end(); it++) {
        char actual = it->first;
        probabilities[actual] = quantityChar[actual]/(1.0*totalChars);
    }
}

void Livro::computeEntropy() {
   
    map<char, int>::iterator it;
    computeProbabilities();
    for (it = quantityChar.begin(); it != quantityChar.end(); it ++) {
        char actual = it->first;
        entropy -= probabilities[actual]*log2(probabilities[actual]);

    }
    
    
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
            totalChars++;
        }
        cout<<endl;
        myfile.close();
    }
    else cout << "Unable to open file";
    cout<<"======[ "<<bookPath<<" ]======"<<endl;
    cout<<"Caracteres: "<<quantityChar.size()<<" / ";
    cout<<"Combinações: "<<charMap.size()<<endl;
    computeEntropy();
    cout <<"Entropia: "<< entropy << endl;
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
    //livro1.computeEntropy();
    //cout << livro1.entropy << endl;

}
