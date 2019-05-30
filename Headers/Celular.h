#ifndef CELULAR
#define CELULAR
#include<Headers/Cliente.h>
#include<Headers/Plano.h>
#include<Headers/Ligacao.h>
#include<Headers/Date.h>
#include<vector>

using namespace std;

class Celular{

    private:
        double numero;
        Cliente cliente;
        Plano* plano;
        vector<Ligacao> ligacoes;
        static double proxNumCelular;

    public:
        Celular(Cliente c, Plano& p);
        Celular(Cliente c, Plano& p, Date vencimento);
        ~Celular();
        void addLigacaoSimples(Date timestamp, double duracao);
        void addLigacaoDados(Date timestamp, double duracao);
        
};
static double proxNumCelular = 0;

#endif