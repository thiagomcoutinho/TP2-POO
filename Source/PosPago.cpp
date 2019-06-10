#include "./../Headers/PosPago.h"

PosPago::PosPago(){}

PosPago::~PosPago(){}

void PosPago::verificaData(const Date& dataLigacao) const{
    if(dataLigacao > vencimento){
        throw Excecao("Plano vencido");
    }
}

void PosPago::verificaCredito(const double& custo) const{
    throw Excecao("Esse plano e do tipo pos pago!"); // FUNCAO DO PLANO PRE-PAGO.
}