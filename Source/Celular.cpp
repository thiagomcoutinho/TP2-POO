#include<Headers/Celular.h>
#include<Headers/Date.h>
#include<Headers/LigacaoSimples.h>
#include<Headers/LigacaoDados.h>

Celular::Celular(){
}

Celular::Celular(Cliente client, Plano& p){

    plano = &p;
    numero = proxNumCelular;
    proxNumCelular++;

}

// Celular pré-pago
void Celular::ligar(Date timestamp, double duracao, double numTel){
    /*
        TODO: Verificar o plano atual e se a ligacao pode
        ser feita. Caso possivel, execute abaixo. Caso contrario,
        throw exception.
    */

    if(dynamic_cast<PrePago*>(plano) == nullptr){
        throw exception::exception();
    }else{

        double custo = duracao*plano->getValorMinuto();
        LigacaoSimples l(timestamp, duracao, custo, numTel);
        ligacoes.push_back(l);

    }
}

// Celular pós-pago
void Celular::ligar(Date timestamp, double duracao, tipoDados td){
    /* TODO: Verificar se o plano é da classe 
        PosPago e entao utilizar a data de vencimento.
    */
    if(dynamic_cast<PosPago*>(plano) == nullptr){
        throw exception::exception();
    }else{
        
    }

    double franquia = plano->getFranquia();
}