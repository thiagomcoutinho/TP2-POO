#ifndef CLIENTE
#define CLIENTE

#include "./Celular.h"
#include "./PrePago.h"
#include "./PosPago.h"
#include "./Date.h"
#include<vector>
#include<string>

using namespace std;

class Cliente{

    private:
        const string CPF;
        const string nome;
        string endereco;
        vector<Celular> celulares;

    public:
        Cliente();
        Cliente(string _cpf, string _nome, string _endereco) : CPF(_cpf), nome(_nome), endereco(_endereco) {};
        ~Cliente();

        // FUNCOES DE ADICIONAR CELULAR
        void addCelular(string nomePlano, double vlrMinuto, double _franquia, double _velAlem, Date vencimento);
        void addCelular(string nomePlano, double vlrMinuto, double _franquia, double _velAlem, Date curr_date, double credito);
        
        // FUNCOES DE EFETUAR LIGACAO
        void efetuarLigacao(int celularIndex, Date timestamp, double duracao, double numTel);
        void efetuarLigacao(int celularIndex, Date timestamp, double duracao, tipoDados data_type);
};
#endif