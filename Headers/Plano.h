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
        Plano();
        ~Plano();
        inline const double getValorMinuto(){return(valorMinuto);};
};
#endif