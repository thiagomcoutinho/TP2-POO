#ifndef POSPAGO
#define POSPAGO

#include "./Date.h"
#include "./Plano.h"
#include "./Excecao.h"

class PosPago : public Plano{

    private:
        Date vencimento;
        double valor;

    public:
        PosPago();
        PosPago(string _nome, double _vlrMinuto, double _franquia, double _velocAlem, double _veloc, Date _vencimento) : \
        Plano(_nome, _vlrMinuto, _franquia, _velocAlem, _veloc), vencimento(_vencimento) {};
        virtual ~PosPago();

        // FUNCOES DE VERIFICACAO
        void verificaData(const Date& dataLigacao) const;
        void verificaCredito(const double& custo) const;

        // FUNCOES SET
        inline void cobraCusto(const double& custo) {valor += custo;};
        
        // FUNCOES GET
        inline Date getVencimento() const {return(vencimento);};
        inline double getValor() const {return(valor);};
};
#endif
