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
        PrePago(const string& _nome, const double& _vlrMinuto, const double& _franquia, const double& _velocAlem, const double& _veloc, const double& _credito, const Date& _validade) : \
        Plano(_nome, _vlrMinuto, _franquia, _velocAlem, _veloc), credito(_credito), validade(_validade) {};
        virtual ~PrePago();

        // FUNCOES SET
        void adicionaCreditos(const int& creditos, const Date& dataAtual);
        inline void cobraCusto(const double& custo) {credito -= custo;};

        // FUNCOES GET
        inline Date getValidade() const {return(validade);};
        inline double getCredito() const {return(credito);};

        // FUNCOES DE VERIFICACAO
        void verificaData(const Date& dataLigacao) const;
        void verificaCredito(const double& custo) const;
};
#endif