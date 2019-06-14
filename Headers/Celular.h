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

        // FUNCOES DE LIGAÇÃO
        void ligar(const Date& timestamp, const double& duracao, const double& numTel);
        bool ligar(const Date& timestamp, const double& duracao, const tipoDados& td);

        // FUNÇÕES GET
        inline static double getProxNumCelular()       {return(proxNumCelular);}; // STATIC FUNCTION
        inline vector<Ligacao*> getLigacoes()    const {return(ligacoes);};
        inline double getNumero()                const {return(numero);};
        inline Plano* getPlano()                 const {return(plano);};
        inline Cliente* getCliente()             const {return(cliente);};

        // FUNÇÕES SET
        inline static void incrementProxNumCelular() {proxNumCelular++;};
};

#endif