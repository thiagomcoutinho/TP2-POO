#include<Headers/Celular.h>
#include<Headers/Date.h>

Celular::Celular(Cliente c, Plano& p){
    plano = &p;
    numero = proxNumCelular;
    proxNumCelular++;
    c.addCelular(*this);

    /* TODO: Verificar se o plano é da classe 
        PosPago. Caso verdadeiro throw exception.

        TYPE* dynamic_cast<TYPE*> (object); --> Retorna NULL. (TESTAR)
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

void Celular::addLigacaoSimples(Date timestamp, double duracao){

    double custo = duracao*plano->getValorMinuto();

    /*
        TODO: Verificar o plano atual e se a ligacao pode
        ser feita. Caso possivel, execute abaixo. Caso contrario,
        throw exception.
    */
    Ligacao l(timestamp, duracao, custo);
    ligacoes.push_back(l);
}