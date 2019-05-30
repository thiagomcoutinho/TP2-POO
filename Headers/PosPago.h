#ifndef POSPAGO
#define POSPAGO

#include<Headers/Date.h>
#include<Headers/Plano.h>

class PosPago : public Plano{

    private:
        Date vencimento;

    public:
        PosPago();
        PosPago(string _nome, double _vlrMinuto, double _franquia, double _velocAlem, Date _vencimento) : \
        Plano(_nome, _vlrMinuto, _franquia, _velocAlem), vencimento(_vencimento) {};
        ~PosPago();
        const void verificaVencimento(const Date& dataLigacao);
};
#endif
