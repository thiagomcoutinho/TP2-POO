#ifndef CELULAR
#define CELULAR

#include<Headers/Cliente.h>
#include<Headers/Plano.h>
#include<Headers/Ligacao.h>
#include<Headers/LigacaoDados.h>
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
        Celular();
        Celular(Cliente c, Plano& p);
        ~Celular();
};
static double proxNumCelular = 0;

#endif