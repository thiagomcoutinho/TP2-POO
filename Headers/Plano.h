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
        inline const double getValorMinuto(){return(valorMinuto);};
        inline const double getVelocidade(){return(velocidade);};
        inline const double getFranquia(){return(franquia);};
        inline const double getVelocAlem(){return(velocAlem);};

};
#endif