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

void Livro::computeConditionalProbabilities() {
    map<char, int>::iterator it;
    map<char, int>::iterator it2;
    for (it = quantityChar.begin(); it != quantityChar.end(); it++) {
        char anterior = it->first;
        for (it2 = quantityChar.begin(); it2 != quantityChar.end(); it2++) {
            char atual = it2->first;
            if (charMap.find(make_pair(atual, anterior)) != charMap.end())
                conditionalProbabilities[make_pair(atual, anterior)] = charMap[make_pair(atual, anterior)]/(1.0*quantityChar[anterior]);
        }
    }
}

void Livro::computeConditionalEntropy() {
    map<char, int>::iterator it;
    map<char, int>::iterator it2;
    computeConditionalProbabilities();
    double sum = 0;
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
    computeConditionalEntropy();
    cout << "Entropia Condicional: " << conditionalEntropy << endl;
    cout << "Char Count: " << totalChars << endl;
    printMatrix2();
 
}

double Livro::computeMutualInfo() {
    return entropy - conditionalEntropy;
}

int main() {
    Livro livro1 = Livro("hamlet-english.txt");
    Livro livro2 = Livro("hamlet-french.txt");
    Livro livro3 = Livro("hamlet-finnish.txt");
    Livro livro4 = Livro("hamlet-greek.txt");
    Livro livro5 = Livro("hamlet-portugues.txt");
    Livro livro6 = Livro("iliad-english.txt");
    Livro livro7 = Livro("iliad-french.txt");
    Livro livro8 = Livro("iliad-finnish.txt");
    Livro livro9 = Livro("iliad-greek.txt");
    Livro livro10 = Livro("iliad-portugues.txt");   
    Livro livro11 = Livro("annakarenina-english.txt");
    Livro livro12 = Livro("annakarenina-french.txt");
    Livro livro13 = Livro("annakarenina-finnish.txt");
    Livro livro14 = Livro("annakarenina-greek.txt");
    Livro livro15 = Livro("annakarenina-portugues.txt");   
    livro15.readBook();
    /*livro1.readBook();
    livro2.readBook();
    livro3.readBook();
    livro4.readBook();
    livro5.readBook();
    livro6.readBook();
    livro7.readBook();
    livro8.readBook();
    livro9.readBook();
    livro10.readBook();
    livro11.readBook();
    livro12.readBook();
    livro13.readBook();
    livro14.readBook();
    livro15.readBook();*/
    //livro1.computeEntropy();
    //cout << livro1.entropy << endl;


}
