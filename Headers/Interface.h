#ifndef INTERFACE
#define INTERFACE

#include "./Cliente.h"
#include "./Plano.h"
#include<ncurses.h>
#include<vector>
#include<string>
#include<cstring>
#include<map>

using namespace std;

class Interface{

    private:
        int x;
        int y;
        string input;
        vector<Cliente> clientes;
        map<string, Plano*> planos;
        Date data_atual;

    public:
        Interface();
        ~Interface();
        // FUNCOES DE IMPRESSAO
        void menuInicial();
        void menuCadastroCliente();
        void menuCadastroPlano();
        void menuCadastroCelular();   // TO-DO: VERIFICAR QUAIS FUNCOES AQUI PODEM SER CONST
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