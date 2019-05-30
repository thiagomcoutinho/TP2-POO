#include<Headers/Date.h>

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

void Date::acrescentaTempo(const Date& tempoExtra){

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