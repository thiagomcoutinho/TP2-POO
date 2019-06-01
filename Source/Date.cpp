#include "./../Headers/Date.h"

Date::Date(){
    ano = mes = dia = hora = min = seg = 0;
}

Date::Date(int _ano, int _mes, int _dia){
    ano = _ano;
    mes = _mes;
    dia = _dia;
    hora = min = seg = 0;
}

Date::Date(int _hora, int _min, int _seg, int _aux){
    hora = _hora;
    min = _min;
    seg = _seg;
    ano = mes = dia = 0;
}

Date::~Date(){

}

void Date::acrescentaTempo(){
    int diasRestantes = 180;
    int diferenca;
    int mesInicial = mes;

    while(diasRestantes != 0){

        if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){ // 31 DIAS
            diferenca = dia - 31;
        }else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){ // 30 DIAS
            diferenca = dia - 30;
        }else{ // FEVEREIRO
            diferenca = dia - 28;
        }

        if(diferenca == 0){ // ULTIMO DIA DO MES.
            mes++;
            dia = 1;
            diasRestantes--;
        }else{
            if(diferenca > diasRestantes){ // DIFERENCA PARA FINAL DO MES É MENOR QUE DIAS RESTANTES
                dia += diasRestantes;
                diasRestantes = 0;
            }else{ // COMPLETA MES
                diasRestantes -= diferenca;
                dia = 1;
                mes++;
            }
        }

        if(mes % 12 == 1 && mesInicial != 1){ // ATUALIZA ANO
            ano++;
            mes = 1;
        };
    }
}

bool Date::operator > (const Date& b){
    if(b.ano > ano){ // Compara ano
        return(true);
    }else if(b.mes > mes){ // Compara mes
        return(true);
    }else if(b.dia > dia){ // Compara dia
        return(true);
    }else if(b.hora > hora){ // Compara hora
        return(true);
    }else if(b.min > min){ // Compara minuto
        return(true);
    }else if(b.seg > seg){ // Compara segundo
        return(true);
    }else{
        return(false);
    }
}

string Date::convertDateToString(bool ligacao) const{
    string sDate;
    if(ligacao){
        sDate = to_string(hora) + ":" + to_string(min) + ":" + to_string(seg); 
    }else{
        sDate = to_string(dia) + "/" + to_string(mes) + "/" + to_string(ano);
    }
    return(sDate);
}