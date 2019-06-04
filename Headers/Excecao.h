#ifndef EXCECAO
#define EXCECAO

#include<string>

using namespace std;

class Excecao{

    private:
        const string mensagem;

    public:
        Excecao();
        Excecao(string _mensagem) : mensagem(_mensagem) {};
        ~Excecao();
        inline const string getExcesao() const {return(mensagem);};
};
#endif