#include<Headers/PosPago.h>

PosPago::PosPago(){}

PosPago::~PosPago(){}

const void PosPago::verificaVencimento(const Date& dataLigacao){
    if(dataLigacao > vencimento){
        throw exception::exception();
    }
}