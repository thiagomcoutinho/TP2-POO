#ifndef DATE
#define DATE

#include "./Excecao.h"

#include<string>
#include<vector>

using namespace std;

class Date{

    private:
        int seg;
        int min;
        int hora;
        int dia;
        int mes;
        int ano;

    public:
        Date();
        Date(int _ano, int _mes, int _dia);
        Date(int _hora, int _min, int _seg, int aux);
        ~Date();

        // OPERADORES
        bool operator > (Date b) const;
        bool operator >= (Date b) const;
        Date & operator = (string str_date);
        Date & operator = (Date data);

        // FUNCOES SET
        void acrescentaTempo();

        // FUNCAO SET DE CONVERSAO DE STRING PARA DATA

        // FUNCOES GET
        string convertDateToString(bool ligacao) const;
        inline int getSeg()  {return(seg);};
        inline int getMin()  {return(min);};
        inline int getHora() {return(hora);};
        inline int getDia()  {return(dia);};
        inline int getMes()  {return(mes);};
        inline int getAno()  {return(ano);};


};
#endif