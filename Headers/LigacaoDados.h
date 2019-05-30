#ifndef LIGACAODADOS
#define LIGACAODADOS

#include<Headers/Ligacao.h>

using namespace std;

class LigacaoDados : public Ligacao{

    public:
        enum tipoDados {download, upload};
};
#endif