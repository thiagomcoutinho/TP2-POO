#ifndef INTERFACE
#define INTERFACE

#include<ncurses.h>
#include<string>

using namespace std;

class Interface{

    private:
        int x;
        int y;

    public:
        Interface();
        ~Interface();
        void menuInicial();
        void menuCadastroCliente();
        void menuCadastroPlano();
        void menuCadastroCelular();
        void menuAdicionaCreditos();
        void menuRegistraLigacaoS();
        void menuRegistraLigacaoD();
        void listaDadosPacote();
        void listaValorConta();
        void listaCreditos();
        void listaExtratoS();
        void listaExtratoD();
        void listaClientes();
        void informaVencimentos();
        void informaLimiteFranquia();

        string getString();

};
#endif