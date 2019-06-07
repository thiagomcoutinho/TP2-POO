#ifndef EXCECAO
#define EXCECAO

#include<string>

using namespace std;

class Excecao{

    private:
        const string mensagem;

    public:
        Excecao();
        Excecao(char* _mensagem) : mensagem(_mensagem) {};
        ~Excecao();

        // FUNCAO GET
        const inline string getExcecao() const {return(mensagem);};
};
#endif