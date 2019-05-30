#include<Headers/PrePago.h>

void PrePago::adicionaCreditos(int creditos, Date dataAtual){
    credito += creditos;
    validade.acrescentaTempo(180*60*60);
}