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
        vector<Ligacao*> ligacoes;
        static double proxNumCelular;

    public:
        Celular();
        Celular(Cliente* c, Plano* p);
        ~Celular();

        // TO-DO: FALTA O NUMERO DO CELULAR.

        // FUNCOES DE LIGAR
        void ligar(Date timestamp, double duracao, double numTel);
        void ligar(double duracao, tipoDados td, Date timestamp);

        // FUNCAO INLINE GET STATIC
        inline static double getProxNumCelular() {return(proxNumCelular);};
        // FUNCAO INLINE SET STATIC
        inline static void incrementProxNumCelular() {proxNumCelular++;};
        
        inline vector<Ligacao*> getLigacoes() {return(ligacoes);};

        inline double getNumero() {return(numero);};

        inline Plano* getPlano() {return(plano);};

        inline Cliente* getCliente() {return(cliente);};
};

#endif