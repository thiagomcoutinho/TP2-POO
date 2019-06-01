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

        inline double getDuracao() const {return(duracao);};
        inline double getCusto()   const {return(custo);};
        inline Date getDate()      const {return(dataHora);};
};
#endif