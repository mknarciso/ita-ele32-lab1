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
        map<pair<char, char>, int> previousChar;
        map <char, int> quantityChar;
        string bookPath;
        void readBook ();



    protected:
    private:

};

#endif // LIVRO_H
