#ifndef DATE
#define DATE

#include<string>

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

        // FUNCAO DE ADICIONAR TEMPO
        void acrescentaTempo();
        
        // OPERADOR DE COMPARACAO
        bool operator > (Date b) const;

        // FUNCAO AUXILIAR DE CONVERSAO DE STRING
        string convertDateToString(bool ligacao) const;
};
#endif