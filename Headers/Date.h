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

        void acrescentaTempo();
        bool operator > (Date b) const;
        string convertDateToString(bool ligacao) const;
};
#endif