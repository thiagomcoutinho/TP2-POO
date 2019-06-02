#ifndef INTERFACE
#define INTERFACE

#include "./Cliente.h"
//#include "./Plano.h"
#include<ncurses.h>
#include<vector>
#include<string>

using namespace std;

class Interface{

    private:
        int x;
        int y;
        string input;
        //vector<Cliente> clientes;
        //vector<Plano> planos;

    public:
        Interface();
        ~Interface();
        // FUNCOES DE IMPRESSAO
        void menuInicial();
        void menuCadastroCliente(int option);
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
        void listaPlanos();
        void listaCelulares();
        void informaVencimentos();
        void informaLimiteFranquia();
        // FUNCOES AUXILIARES
        void print(const char* text, bool breakLine);
        void switchMenu(int option);
        void setMenu();
        
        // FUNCOES DE ENTRADA
        void getString();
};
#endif