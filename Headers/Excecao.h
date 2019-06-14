#ifndef EXCECAO
#define EXCECAO

#include<string>

using namespace std;

class Excecao{

    private:
        const string mensagem;

    public:
        Excecao();
        Excecao(const string& _mensagem) : mensagem(_mensagem) {};
        ~Excecao();

        // FUNCAO GET
        inline string getExcecao() const {return(mensagem);};
};
#endif