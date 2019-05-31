#ifndef INTERFACE
#define INTERFACE

//#include "./../Headers/Cliente.h"
#include<ncurses.h>
#include<vector>
#include<string>

using namespace std;

class Interface{

    private:
        int x;
        int y;
        //vector<Cliente> clientes;

    public:
        Interface();
        ~Interface();
        // FUNCOES DE MENU
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
        // FUNCOES AUXILIARES
        void print(const char* text) const;
        void switchMenu(const char option);
        
        string getString();

};
#endif