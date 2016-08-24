#ifndef LIVRO_H
#define LIVRO_H


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
