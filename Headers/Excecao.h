#ifndef EXCECAO
#define EXCECAO

#include<string>

using namespace std;

class Excecao{

    private:
        string mensagem;

    public:
        Excecao();
        Excecao(string _mensagem) : mensagem(_mensagem) {};
        ~Excecao();

        // FUNCAO GET
        inline string getExcecao() {return(mensagem);};
};
#endif