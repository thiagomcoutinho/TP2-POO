#include "./../Headers/PosPago.h"

PosPago::PosPago(){}

PosPago::~PosPago(){}

void PosPago::verificaData(const Date& dataLigacao) const{
    if(dataLigacao > vencimento){
        throw exception::exception();
    }
}

void PosPago::verificaCredito(const double& custo) const{
    throw exception::exception(); // FUNCAO DO PLANO PRE-PAGO.
}