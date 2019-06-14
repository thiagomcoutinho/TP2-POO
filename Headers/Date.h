#ifndef DATE
#define DATE

#include "./Excecao.h"

#include<string>
#include<vector>

using namespace std;

class Date{

    private:
        int dia;
        int mes;
        int ano;

    public:
        Date();
        Date(const int& _ano, const int& _mes, const int& _dia);
        ~Date();

        // OPERADORES
        bool operator >  (const Date& b) const;
        bool operator >= (const Date& b) const;
        bool operator <= (const Date& b) const;
        Date & operator = (const string& str_date);
        Date & operator = (const Date& data);

        // FUNCOES SET
        void acrescentaTempo();

        // FUNCOES GET
        string convertDateToString() const;
        vector<int> getLimitesMes() const;
        inline int getDia()  const {return(dia);};
        inline int getMes()  const {return(mes);};
        inline int getAno()  const {return(ano);};
};
#endif