#include "./../Headers/PosPago.h"
#include "./../Headers/Excecao.h"

PosPago::PosPago(){}

PosPago::~PosPago(){}

void PosPago::verificaData(const Date& dataLigacao) const{
    if(dataLigacao > vencimento){
        throw Excecao();
    }
}

void PosPago::verificaCredito(const double& custo) const{
    throw Excecao(); // FUNCAO DO PLANO PRE-PAGO.
}