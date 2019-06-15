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
        vector<Cliente*> clientes;
        map<string, Plano*> planos;
        vector<Celular*> ptr_celulares;
        Date data_atual;
        
    public:
        Interface();
        ~Interface();
        // FUNCOES DE IMPRESSAO
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
        void listaPlanos();
        void listaCelulares();
        void informaVencimentos();
        void informaLimiteFranquia(Celular* c);
        void atualizaDataAtual();
        // FUNCOES AUXILIARES
        void print(const char* text, const bool& breakLine);
        void switchMenu(const int& option);
        void setMenu();
        Celular* getCelular(const int& numeroCelular);
        
        // FUNCOES DE ENTRADA
        void getString();
};
#endif