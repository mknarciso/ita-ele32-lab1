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
        int entropies;
        string bookPath;
        void readBook();
        void computeEntropy();
        void printMatrix1();
        int loadMatrix(char atual);
        void readBook ();
        void computeEficiency();
        void computePrevisibility();
        void computeInfoNextChar();



    protected:
    private:

};

#endif // LIVRO_H
