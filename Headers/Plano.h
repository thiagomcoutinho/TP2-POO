#ifndef PLANO
#define PLANO

#include<string>
#include "./Date.h"

using namespace std;

class Plano{

    private:
        const string nome;
        double valorMinuto;
        double velocidade;
        double franquia;
        double velocAlem;
        double franquiaGasta;

    public:
        Plano(string _nome, double _vlrMinuto, double _franquia, double _velocAlem, double _veloc) : \
        nome(_nome), valorMinuto(_vlrMinuto), franquia(_franquia), velocAlem(_velocAlem), \
        velocidade(_veloc), franquiaGasta(0) {};

        Plano();
        virtual ~Plano();
        // FUNCOES GET
        inline double getValorMinuto()   const {return(valorMinuto);};
        inline double getVelocidade()    const {return(velocidade);};
        inline double getFranquia()      const {return(franquia);};
        inline double getVelocAlem()     const {return(velocAlem);};
        inline double getFranquiaGasta() const {return(franquiaGasta);};
        inline string getNomePlano()     const {return(nome);};

        // FUNCOES SET
        inline void setFranquiaGasta(const double& gasto) {franquiaGasta += gasto;};

        // VIRTUAIS PURAS
        virtual void verificaCredito(const double& custo) const = 0;
        virtual void verificaData(const Date& dataLigacao) const = 0;
        virtual void cobraCusto(const double& custo) = 0;
};
#endif