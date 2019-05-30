#include<Headers/Celular.h>
#include<Headers/Date.h>

Celular::Celular(Cliente c, Plano& p){
    plano = &p;
    numero = proxNumCelular;
    proxNumCelular++;
    c.addCelular(*this);

    /* TODO: Verificar se o plano é da classe 
        PosPago. Caso verdadeiro throw exception.
    */
}

Celular::Celular(Cliente c, Plano& p, Date vencimento){

    plano = &p;
    numero = proxNumCelular;
    proxNumCelular++;
    c.addCelular(*this);

    /* TODO: Verificar se o plano é da classe 
        PosPago e entao utilizar a data de vencimento.
    */
}

