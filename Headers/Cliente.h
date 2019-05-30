#ifndef CLIENTE
#define CLIENTE

#include<Headers/Celular.h>
#include<Headers/PrePago.h>
#include<Headers/PosPago.h>
#include<vector>
#include<string>

using namespace std;

class Cliente{

    private:
        string CPF;
        string nome;
        string endereco;
        vector<Celular> celulares;

    public:
        Cliente();
        Cliente(int _cpf, string _nome, string _endereco);
        ~Cliente();
        void pushCelular(Celular cel);
        void addCelular(string nomePlano, double vlrMinuto, double _franquia, double _velAlem, Date vencimento);
        void addCelular(string nomePlano, double vlrMinuto, double _franquia, double _velAlem, Date curr_date, double credito);
        void efetuarLigacao(int celularIndex, Date timestamp, double duracao, double numTel);
        void efetuarLigacao(int celularIndex, Date timestamp, double duracao, TipoDados data_type);
};
#endif