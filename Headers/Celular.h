#ifndef CELULAR
#define CELULAR

#include "./Plano.h"
#include "./PosPago.h"
#include "./Excecao.h"
#include "./Ligacao.h"
#include "./LigacaoDados.h"
#include "./LigacaoSimples.h"
#include "./Date.h"

#include<vector>

using namespace std;

class Cliente; // Instanciando classe sem declaração completa (FORWARD DECLARATION)

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

        // FUNCOES DE LIGAR
        void ligar(Date timestamp, double duracao, double numTel);
        void ligar(Date timestamp, double duracao, tipoDados td);

        // FUNCAO INLINE GET STATIC
        inline static double getProxNumCelular() {return(proxNumCelular);};
        // FUNCAO INLINE SET STATIC
        inline static void incrementProxNumCelular() {proxNumCelular++;};
};

#endif