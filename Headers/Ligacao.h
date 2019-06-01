#ifndef LIGACAO
#define LIGACAO

#include "./Date.h"

class Ligacao{

    private:
        const Date dataHora;
        const double duracao;
        const double custo;

    public:
        // IMPORTANTE: USAR PROTECTED NAS CLASSES.

        Ligacao() : duracao(0), custo(0) {};
        Ligacao(Date _dataHora, double _duracao, double _custo) : dataHora(_dataHora), duracao(_duracao), custo(_custo) {};
        virtual ~Ligacao();

        inline const double getDuracao(){return(duracao);};
        inline const double getCusto(){return(custo);};
        inline const Date getDate(){return(dataHora);};
};
#endif