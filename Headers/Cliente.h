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
        vector<Celular*> celulares;

    public:
        Cliente();
        Cliente(const string& _cpf, const string& _nome, const string& _endereco) : CPF(_cpf), nome(_nome), endereco(_endereco) {};
        ~Cliente();

        // FUNCOES DE ADICIONAR CELULAR
        void addCelular(const string& nomePlano, const double& vlrMinuto, const double& _franquia, const double& _velAlem, \
        const double& _veloc, const Date& vencimento);
        void addCelular(const string& nomePlano, const double& vlrMinuto, const double& _franquia, const double& _velAlem, \
        const double& _veloc, Date& curr_date, const double& credito);
        
        // FUNCOES DE EFETUAR LIGACAO
        void efetuarLigacao(const int& celularIndex, const Date& timestamp, const double& duracao, const double& numTel);
        void efetuarLigacao(const int& celularIndex, const Date& timestamp, const double& duracao, const tipoDados& data_type);

        // FUNCOES GET
        inline string getNome()                const {return(nome);};
        inline string getCPF()                 const {return(CPF);};
        inline string getEndereco()            const {return(endereco);};
        inline vector<Celular*> getCelulares() const {return(celulares);};
};
#endif