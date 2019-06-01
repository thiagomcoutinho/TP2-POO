#ifndef EXCECAO
#define EXCECAO

#include<string>

using namespace std;

class Excecao{

    private:
        const string mensagem;

    public:
        Excecao(string _mensagem) : mensagem(_mensagem) {};
        ~Excecao();
        const string getExcesao() const {return(mensagem);};
};
#endif