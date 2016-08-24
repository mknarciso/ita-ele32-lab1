#include "Livro.h"
#include <fstream>
#include <iostream>
#include <tgmath.h> 

using namespace std;

Livro::Livro(string bookPathName)
{
    bookPath = bookPathName;
    entropy = 0;
    conditionalEntropy = 0;
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

void Livro::computeConditionalProbabilities() {
    map<char, int>::iterator it;
    map<char, int>::iterator it2;
    for (it = quantityChar.begin(); it != quantityChar.end(); it++) {
        char anterior = it->first;
        for (it2 = quantityChar.begin(); it2 != quantityChar.end(); it2++) {
            char atual = it2->first;
            if (charMap.find(make_pair(atual, anterior)) != charMap.end())
                conditionalProbabilities[make_pair(atual, anterior)] = charMap[make_pair(atual, anterior)]/(1.0*quantityChar[anterior]);
                cout << charMap[make_pair(atual,anterior)] << endl;
        }
    }
}

void Livro::computeConditionalEntropy() {
    map<char, int>::iterator it;
    map<char, int>::iterator it2;
    computeConditionalProbabilities();
    int sum = 0;
    for (it = quantityChar.begin(); it != quantityChar.end(); it++) {
        char anterior = it->first;
        for (it2 = quantityChar.begin(); it2 != quantityChar.end(); it2++) {
            char atual = it2->first;
            if (conditionalProbabilities.find(make_pair(atual, anterior)) != conditionalProbabilities.end() ){
                sum += conditionalProbabilities[make_pair(atual, anterior)]*log2(conditionalProbabilities[make_pair(atual,anterior)]);
            }
        }
        conditionalEntropy -= sum*probabilities[anterior];
        sum = 0;
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
    livro1.computeConditionalEntropy();
    cout << livro1.entropy << endl;
    cout << livro1.conditionalEntropy << endl;
    cout << "Hello World!" << std::endl;

}
