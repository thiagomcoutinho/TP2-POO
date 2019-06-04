#ifndef CELULAR
#define CELULAR

#include "./Plano.h"
#include "./Ligacao.h"
#include "./LigacaoDados.h"
#include "./LigacaoSimples.h"
#include "./Date.h"
#include<vector>

using namespace std;

class Cliente; // Instanciando classe sem declaração completa

class Celular{

    private:
        double numero;
        Cliente* cliente;
        Plano* plano;
        vector<Ligacao> ligacoes;
        static double proxNumCelular;

    public:
        Celular();
        Celular(Cliente& c, Plano& p);
        ~Celular();
        void ligar(Date timestamp, double duracao, double numTel);
        void ligar(Date timestamp, double duracao, tipoDados td);

        static double getProxNumCelular();
        static void incrementProxNumCelular();
};

#endif