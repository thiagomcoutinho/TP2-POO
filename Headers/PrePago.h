#ifndef PREPAGO
#define PREPAGO

#include "./Date.h"
#include "./Plano.h"
#include "./Excecao.h"

class PrePago : public Plano{

    private:    
        double credito;
        Date validade;

    public:
        PrePago();
        PrePago(string _nome, double _vlrMinuto, double _franquia, double _velocAlem, double _veloc, double _credito, Date _validade) : \
        Plano(_nome, _vlrMinuto, _franquia, _velocAlem, _veloc), credito(_credito), validade(_validade) {};
        ~PrePago();

        // FUNCOES SET
        void adicionaCreditos(int creditos, Date dataAtual);
        inline void cobraCusto(const double& custo) {credito -= custo;};

        // FUNCOES GET
        inline Date getValidade() const {return(validade);};
        inline double getCredito() const {return(credito);};

        // FUNCOES DE VERIFICACAO
        void verificaData(const Date& dataLigacao) const;
        void verificaCredito(const double& custo) const;
};
#endif