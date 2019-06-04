#ifndef LIGACAODADOS
#define LIGACAODADOS

#include "./Ligacao.h"

using namespace std;

enum tipoDados{download, upload};

class LigacaoDados : public Ligacao{

    private:
        const tipoDados dtype;

    public:
        LigacaoDados();
        LigacaoDados(const Date _dataHora, const double _duracao, const double _custo, const tipoDados _dtype): \
            Ligacao(_dataHora, _duracao, _custo), dtype(_dtype) {};
        ~LigacaoDados();

        // FUNCOES GET
        inline tipoDados getTipoDados() const {return(dtype);};
};
#endif