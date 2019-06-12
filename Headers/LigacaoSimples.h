#ifndef LIGACAOSIMPLES
#define LIGACAOSIMPLES

#include "./Ligacao.h"

class LigacaoSimples : public Ligacao{

    private:   
        const double numTelefone;

    public:
        LigacaoSimples();
        LigacaoSimples(const Date _dataHora, const double _duracao, const double _custo, const double _numTel): \
         Ligacao(_dataHora, _duracao, _custo), numTelefone(_numTel) {};
        virtual ~LigacaoSimples();
        
        // FUNCOES GET
        inline double getNumTelefone() const {return(numTelefone);};
};
#endif