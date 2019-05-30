#ifndef LIGACAODADOS
#define LIGACAODADOS

#include<Headers/Ligacao.h>

using namespace std;

enum tipoDados{download, upload};

class LigacaoDados : public Ligacao{

    private:
        tipoDados dtype;

    public:
    LigacaoDados();
    LigacaoDados(const Date _dataHora, const double _duracao, const double _custo, const tipoDados _dtype): \
         Ligacao(_dataHora, _duracao, _custo), dtype(_dtype) {};
    ~LigacaoDados();
};
#endif