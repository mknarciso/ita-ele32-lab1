#ifndef LIVRO_H
#define LIVRO_H

#include <map>
#include <algorithm>

using namespace std;

class Livro
{
    public:
        Livro(string bookPath);
        virtual ~Livro();
        map<pair<char, char>, int> charMap;
        map <char, int> quantityChar;
        map<char, double> probabilities;
        double entropy;
        int totalChars;
        string bookPath;
        void readBook();
        void computeEntropy();
        void printMatrix1();
        void printMatrix2();
        int loadMatrix(char atual);
        int loadMatrix2(char anterior, char atual);
        void computeEficiency();
        void computePrevisibility();
        void computeInfoNextChar();
        void computeProbabilities();

        



    protected:
    private:

};

#endif // LIVRO_H
