#ifndef PREPAGO
#define PREPAGO

#include<Headers/Date.h>
#include<Headers/Plano.h>

class PrePago : public Plano{

    private:    
        double credito;
        Date validade;

    public:
        PrePago();
        PrePago(string _nome, double _vlrMinuto, double _franquia, double _velocAlem, double _credito, Date _validade) : \
        Plano(_nome, _vlrMinuto, _franquia, _velocAlem), credito(_credito), validade(_validade) {};
        ~PrePago();
        void adicionaCreditos(int creditos, Date dataAtual);
        void verificaData(const Date& dataLigacao) const;
        void verificaCredito(const double& custo) const;
        void cobraCusto(const double& custo);
};
#endif