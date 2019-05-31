#ifndef PLANO
#define PLANO

#include<string>

using namespace std;

class Plano{

    private:
        string nome;
        double valorMinuto;
        double velocidade;
        double franquia;
        double velocAlem;

    public:
        Plano(string _nome, double _vlrMinuto, double _franquia, double _velocAlem);
        Plano();
        virtual ~Plano();
        // FUNCOES GET
        inline double getValorMinuto() const {return(valorMinuto);};
        inline double getVelocidade()  const {return(velocidade);};
        inline double getFranquia()    const {return(franquia);};
        inline double getVelocAlem()   const {return(velocAlem);};

        // VIRTUAIS PURAS
        virtual void verificaCredito(const double& custo) const = 0;
        virtual void verificaData(const Date& dataLigacao) const = 0;
        virtual void cobraCusto(const double& custo) = 0;
};
#endif