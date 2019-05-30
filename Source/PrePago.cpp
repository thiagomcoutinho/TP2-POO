#include<Headers/PrePago.h>

PrePago::PrePago(){}

void PrePago::adicionaCreditos(int creditos, Date dataAtual){
    credito += creditos;
    //validade.acrescentaTempo(180*60*60);
}

const void PrePago::verificaCredito(const double& custo){
    if(credito - custo < 0){
        throw exception::exception();
    }
}

const void PrePago::verificaValidade(const Date& dataLigacao){
    if(dataLigacao > validade){
        throw exception::exception();
    }
}
