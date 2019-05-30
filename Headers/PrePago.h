#include<Headers/Date.h>
#include<Headers/Plano.h>

class PrePago : public Plano{

    private:    
        double credito;
        Date validade;

    public:
        PrePago();

        void adicionaCreditos(int creditos, Date dataAtual);

};