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
    client.pushCelular(*this);

}