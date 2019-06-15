#include "./../Headers/Date.h"

Date::Date(){
    ano = 0;
    mes = dia = 1;
}

Date::Date(const int& _ano, const int& _mes, const int& _dia){
    if(_mes <= 0 || _mes > 12){
        throw Excecao("Mes invalido!");
    }
    if(_ano < 1950 || _ano > 2100){
        throw Excecao("Ano invalido(T)!");
    }
    ano = _ano;
    mes = _mes;

    vector<int> limitesMes = getLimitesMes();
    if(_dia > limitesMes[1] || _dia < limitesMes [0]){
        throw Excecao("Dia do mes invalido!");
    }

    dia = _dia;
}

Date::~Date(){}

void Date::acrescentaTempo(){
    int diasRestantes = 180;
    int diferenca;
    int mesInicial = mes;
    int ultimoDiaMes;

    while(diasRestantes != 0){

        if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){ // 31 DIAS
            ultimoDiaMes = 31;
        }else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){ // 30 DIAS
            ultimoDiaMes = 30;
        }else{ // FEVEREIRO
            ultimoDiaMes = 28;
        }
        diferenca = ultimoDiaMes - dia;

        if(diferenca == 0){ // ATUALIZA MES
            mes++;
            dia = 1;
            diasRestantes--;
            continue;
        }

        if(diasRestantes > diferenca){ // ATUALIZA DIA ATE ULTIMO DIA DO MES
            dia += diferenca;
            diasRestantes -= diferenca;
        }else{                        // ATUALIZA DIA ATE O NUMERO DE DIAS RESTANTES
            dia += diasRestantes;
            diasRestantes = 0;
        }

        if(mes % 12 == 1 && mesInicial != 1){ // ATUALIZA ANO
            ano++;
            mes = 1;
        };
    }
}

bool Date::operator > (const Date& b) const{
    if(ano > b.getAno()){ // ANO MAIOR
        return(true);
    }else if(ano == b.getAno()){
        if(mes > b.mes){ // MES MAIOR
            return(true);
        }else if(mes == b.getMes()){
            if(dia > b.dia){ // DIA MAIOR
                return(true);
            }else{ // DIA MENOR OU IGUAL
                return(false);
            }
        }else{ // MES MENOR
            return(false);
        }
    }else{ // ANO MENOR
        return(false);
    }
}

bool Date::operator >= (const Date& b) const{
    if(ano > b.getAno()){ // ANO MAIOR
        return(true);
    }else if(ano == b.getAno()){
        if(mes > b.mes){ // MES MAIOR
            return(true);
        }else if(mes == b.getMes()){
            if(dia >= b.dia){ // DIA MAIOR OU IGUAL
                return(true);
            }else{ // DIA MENOR
                return(false);
            }
        }else{ // MES MENOR
            return(false);
        }
    }else{ // ANO MENOR
        return(false);
    }
}

bool Date:: operator <= (const Date& b) const{
    if(ano < b.getAno()){ // ANO MENOR
        return(true);
    }else if(ano == b.getAno()){
        if(mes < b.mes){ // MES MENOR
            return(true);
        }else if(mes == b.getMes()){
            if(dia <= b.dia){ // DIA MENOR OU IGUAL
                return(true);
            }else{ // DIA MENOR
                return(false);
            }
        }else{ // MES MENOR
            return(false);
        }
    }else{ // ANO MENOR
        return(false);
    }
}

Date & Date::operator = (const string& str_date){
    vector<string> date_split;
    string aux;

    for(int i=0; i<str_date.size(); i++){ // PARTICIONA STRING A PARTIR DO TOKEN '-'
        if(str_date[i] == '-'){
            date_split.push_back(aux);
            aux.clear();
        }else{
            aux.push_back(str_date[i]);
        }
    }
    date_split.push_back(aux);

    // CONFERE FORMATO DE DATA
    if(date_split.size() != 3 || date_split[0].size() != 2 || date_split[1].size() != 2 || date_split[2].size() != 4){
        throw Excecao("Formato de data invalido!");
    }

    // CONFERE INTERVALOS DAS DATAS
    if(stoi(date_split[1]) <= 0 || stoi(date_split[1]) > 12){
        throw Excecao("Mes invalido!");
    }

    if(stoi(date_split[2]) < 1950 || stoi(date_split[2]) > 2100){
        throw Excecao("Ano invalido!");
    }
    mes = stoi(date_split[1]);
    ano = stoi(date_split[2]);

    vector<int> limitesMes = getLimitesMes();
    if(stoi(date_split[0]) > limitesMes[1] || stoi(date_split[0]) < limitesMes[0]){
        throw Excecao("Dia do mes invalido!");
    }
    dia = stoi(date_split[0]);
    
    return(*this);
}

Date & Date::operator = (const Date& data){
    // CONFERE SE A DATA É VALIDA E ATRIBUI AO NOVO OBJETO
    if(data.getMes() <= 0 || data.getMes() > 12){
        throw Excecao("Mes invalido!");
    }

    if(data.getAno() < 1950 || data.getAno() > 2100){
        throw Excecao("Ano invalido!");
    }

    ano = data.getAno();
    mes = data.getMes();

    vector<int> limitesMes = getLimitesMes();
    if(data.getDia() > limitesMes[1] || data.getDia() < limitesMes[0]){
        throw Excecao("Dia do mes invalido!");
    }
    dia = data.getDia();

    return(*this);
}

string Date::convertDateToString() const{
    // CONVERTE DATA PARA FORMATO STRING DD/MM/YYYY
    string sDate;
    sDate = to_string(dia) + "/" + to_string(mes) + "/" + to_string(ano);
    return(sDate);
}

vector<int> Date::getLimitesMes() const{
    int ultimoDiaMes;

    if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){ // 31 DIAS
        ultimoDiaMes = 31;
    }else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){ // 30 DIAS
        ultimoDiaMes = 30;
    }else{ // FEVEREIRO
        ultimoDiaMes = 28;
    }

    vector<int> limitesMes;
    limitesMes.push_back(1);
    limitesMes.push_back(ultimoDiaMes);

    return(limitesMes);
}