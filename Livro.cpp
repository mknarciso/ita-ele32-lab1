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


void Livro::readBook(){
    ifstream myfile;
    char atual;
    myfile.open (bookPath);
    if (myfile.is_open()){
        while (myfile.get(atual)){
            //cout<<atual;
            loadMatrix(atual);
            totalChars++;
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
    livro1.computeEntropy();
    cout << livro1.entropy << endl;
    cout << "Hello World!" << std::endl;

}
