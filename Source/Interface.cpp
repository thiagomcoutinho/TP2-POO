#include "./../Headers/Interface.h"

Interface::Interface(){
    // Inicializa tela
    initscr();
    // Posicoes do cursor
    x = y = 5;
    
    int c = 0;
    int b;

    // Cria menu inicial
    menuInicial();
    // Loop infinito ate que o cliente saia da aplicacao
    while(c != 113){ // 'q' quit
        c = getch();
        if(c == 113){break;}

        b = getch(); // VARIAVEL AUXILIAR PARA ENTRADA
        if(c != 113){
            try{
                switchMenu(c);
            }
            catch (Excecao& e){
                /* string excecao = e.getExcecao();
                char* ptr_char_excecao = excecao.c_str();
                print(ptr_char_excecao); */
            }
        }
    }
}

Interface::~Interface(){
    endwin();
}

void Interface::print(const char* text, bool breakLine = true){
    mvprintw(y, x, text);
    if(breakLine){
        y++;
    }
}

void Interface::setMenu(){
    y = x = 5;
    clear();
}

void Interface::getString()
{
    nocbreak();
    echo();

    input.clear();

    int ch = getch();

    while ( ch != '\n' )
    {
        input.push_back( ch );
        ch = getch();
    }
}

Celular* Interface::getCelular(int numeroCelular){

    Celular* c;

    if(numeroCelular <= ptr_celulares.size() && numeroCelular >= 0){
        c = ptr_celulares[numeroCelular];
    }else{
        throw Excecao("Numero de celular inexistente!");
    }

    return(c);
}

void Interface::switchMenu(int option){

    switch (option)
    {
        case 97:
            menuCadastroCliente();
            break;
        case 98:
            menuCadastroPlano();
            break;
        case 99:
            menuCadastroCelular();
            break;
        case 100:
            menuAdicionaCreditos();
            break;
        case 101:
            menuRegistraLigacaoS();
            break;
        case 102:
            menuRegistraLigacaoD();
            break;
        case 103:
            listaDadosPacote();
            break;
        case 104:
            listaValorConta();
            break;
        case 105:
            listaCreditos();
            break;
        case 106:
            listaExtratoS();
            break;
        case 107:
            listaExtratoD();
            break;
        case 108:
            listaClientes();
            break;
        case 109:
            listaPlanos();
            break;
        case 110:
            listaCelulares();
            break;
        case 111:
            informaVencimentos();
            break;
        case 112:
            informaLimiteFranquia();
            break;
        default:
            break;
    }
}

void Interface::menuInicial(){

    setMenu();

    print("///// OPERADORA TELEFONICA CONAUT /////");
    print("a. Cadastro de Clientes");
    print("b. Cadastro de Planos");
    print("c. Cadastro de Celulares");
    print("d. Adicionar Creditos");
    print("e. Registro de Ligacao Simples");
    print("f. Registro de Ligacao de Dados");
    print("g. Informacao de Pacote de Dados");
    print("h. Valor de Contas");
    print("i. Saldo de Creditos");
    print("j. Extrato de Ligacoes Simples");
    print("k. Extrato de Ligacoes de Dados");
    print("l. Lista de Clientes");
    print("m. Lista de Planos");
    print("n. Lista de Celulares");
    print("o. Informe de Vencimentos");
    print("p. Limite de Franquia");
    print("Pressione q para sair");
    print("Escolha uma opcao: ");

    refresh();
}

void Interface::menuCadastroCliente(){

    string nome, CPF, endereco;

    setMenu();

    print("///// MENU DE CADASTRO DE CLIENTES /////");
    
    print("ENTRE COM OS DADOS DO CLIENTE: ");
    print("NOME DO CLIENTE: ");
    getString();
    nome = input;
    print("ENDERECO: ");
    getString();
    CPF = input;
    print("CPF/CNPJ: ");
    getString();
    endereco = input;
    
    refresh();

    // CRIA CLIENTE
    Cliente c(CPF, nome, endereco);
    clientes.push_back(c);

    menuInicial();
}

void Interface::menuCadastroPlano(){

    setMenu();

    Date vencimento_ou_validade;

    string nome_plano;
    double vlrMinuto, franquia, veloc, velocAlem, credito;
    Plano* p;

    print("///// MENU DE CADASTRO DE PLANOS /////");
    print("NOME DO PLANO: ");
    getString();
    nome_plano = input;
    print("VALOR DO MINUTO: ");
    getString();
    vlrMinuto = stod(input);
    print("VELOCIDADE DO PACOTE DE DADOS: ");
    getString();
    veloc = stod(input);
    print("FRANQUIA: ");
    getString();
    franquia = stod(input);
    print("VELOCIDADE ALEM DA FRANQUIA: ");
    getString();
    velocAlem = stod(input);
    print("TIPO DO PLANO: ");
    getString();
    if(input == "PosPago"){ // Pós-Pago
        print("DATA DE VENCIMENTO: ");
        getString();
        vencimento_ou_validade = input;
        PosPago sub_p(nome_plano, vlrMinuto, franquia, velocAlem, veloc, vencimento_ou_validade);
        p = &sub_p;
    }else if(input == "PrePago"){ // Pŕe-Pago
        print("VALOR CREDITO: ");
        getString();
        credito = stod(input);
        vencimento_ou_validade = data_atual;
        vencimento_ou_validade.acrescentaTempo();

        PrePago sub_p(nome_plano, vlrMinuto, franquia, velocAlem, veloc, credito, vencimento_ou_validade);
        p = &sub_p;
    }else{
        throw Excecao("Tipo de plano nao existente!");
    }
    planos.insert(make_pair(nome_plano, p));

    refresh();
    menuInicial();
}

void Interface::menuCadastroCelular(){

    Date vencimento_ou_validade;
    Cliente* ptr_cliente;
    string nome_plano;
    double n_cliente, vlr_minuto, franquia, velocAlem, veloc, credito;

    setMenu();

    print("///// MENU DE CADASTRO DE CELULARES /////");
    print("NUMERO DO CLIENTE(A PARTIR DE 1): ");
    getString();
    n_cliente = stoi(input);
    if(n_cliente <= clientes.size() && n_cliente >= 0){
        n_cliente--;
        ptr_cliente = &clientes[n_cliente];
    }else{
        throw Excecao("Numero de cliente nao existente!");
    }

    print("NOME DO PLANO: ");
    getString();
    nome_plano = input;
    if(planos.find(nome_plano) == planos.end()){
        throw Excecao();
    }else{
        Plano* p = planos.find(nome_plano)->second;
        PosPago* ptr_posPago = dynamic_cast<PosPago*>(p);

        vlr_minuto = p->getValorMinuto();
        franquia = p->getFranquia();
        velocAlem = p->getVelocAlem();
        veloc = p->getVelocidade();
        if(ptr_posPago != nullptr){ // Pós-Pago
            print("DATA DE VENCIMENTO: ");
            getString();
            vencimento_ou_validade = input;
            ptr_cliente->addCelular(nome_plano, vlr_minuto, franquia, velocAlem, veloc, vencimento_ou_validade);
        }else{ // Pre-Pago
            print("CREDITO INICIAL: ");
            getString();
            credito = stod(input);
            vencimento_ou_validade = data_atual;
            vencimento_ou_validade.acrescentaTempo();
            ptr_cliente->addCelular(nome_plano, vlr_minuto, franquia, velocAlem, veloc, vencimento_ou_validade, credito);
        }
    }
    vector<Celular> celulares_cliente = ptr_cliente->getCelulares();
    Celular* ptr_celular = &celulares_cliente[celulares_cliente.size()-1];
    ptr_celulares.push_back(ptr_celular);

    refresh();
    menuInicial();
}

void Interface::menuAdicionaCreditos(){

    double creditos;
    int numeroCelular;
    Date validade;
    Celular* c;

    setMenu();

    print("///// MENU DE CREDITOS /////");
    print("NUMERO DO CELULAR: ");
    getString();
    numeroCelular = stoi(input);
    Celular* c = getCelular(numeroCelular);

    print("VALOR DE CREDITOS: ");
    getString();
    creditos = stod(input);

    validade = data_atual;

    Plano* p = c->getPlano();
    PrePago* sub_p = dynamic_cast<PrePago*> (p);

    if(sub_p != nullptr){
        sub_p->adicionaCreditos(creditos, data_atual);
    }else{
        throw Excecao("O celular escolhido nao possui plano Pre Pago!");
    }
    
    refresh();
    menuInicial();
}

void Interface::menuRegistraLigacaoS(){

    int numeroCelular;
    Date data_ligacao;
    double duracao, telefone;

    setMenu();

    print("///// MENU DE REGISTRO DE LIGACOES SIMPLES /////");
    print("CELULAR: ");
    getString();
    numeroCelular = stoi(input);
    Celular* c = getCelular(numeroCelular);

    print("DATA: ");
    getString();
    data_ligacao = input;
    print("DURACAO(MIN): ");
    getString();
    duracao = stod(input);
    print("# TELEFONE: ");
    getString();
    telefone = stod(input);

    c->ligar(data_ligacao, duracao, telefone);

    refresh();
    menuInicial();
}

void Interface::menuRegistraLigacaoD(){

    tipoDados td;
    int numeroCelular;
    Date data_ligacao;
    double duracao;

    setMenu();

    print("///// MENU DE REGISTRO DE LIGACOES DE DADOS /////");
    print("CELULAR: ");
    getString();
    numeroCelular = stoi(input);
    Celular* c = getCelular(numeroCelular);

    print("DATA: ");
    getString();
    data_ligacao = input;
    print("DURACAO(MIN): ");
    getString();
    duracao = stod(input);
    print("TIPO(download ou upload): ");
    getString();
    if(input == "download"){
        td = download;
    }else if(input == "upload"){
        td = upload;
    }else{
        throw Excecao("Tipo de dados incorreto!");
    }

    c->ligar(duracao, td, data_ligacao);

    refresh();
    menuInicial();
}

void Interface::listaDadosPacote(){

    int numeroCelular;
    string aux;

    setMenu();
    
    print("///// CONSULTA DE DADOS DO PACOTE /////");
    print("CELULAR: ");
    getString();
    numeroCelular = stoi(input);
    Celular* c = getCelular(numeroCelular);

    Plano* p = c->getPlano();

    print("FRANQUIA: ", false);
    aux = to_string(p->getFranquia());
    print(aux.c_str());
    print("FRANQUIA GASTA: ", false);
    aux = to_string(p->getFranquiaGasta());
    print(aux.c_str());
    print("VELOCIDADE ATUAL: ");

    print("DOWNLOAD: ", false);

    if(p->getFranquiaGasta() > p->getFranquia()){ // FRANQUIA TOTALMENTE GASTA, VELOCIDADE REDUZIDA
        aux = to_string(p->getVelocAlem());
        print(aux.c_str());

        aux = to_string(p->getVelocAlem()*0.1);
        print("UPLOAD: ", false);
        print(aux.c_str());
    }else{ // FRANQUIA DISPONIVEL, VELOCIDADE CONTRATADA
        aux = to_string(p->getVelocidade());
        print(aux.c_str());

        aux = to_string(p->getVelocidade()*0.1);
        print("UPLOAD: ", false);
        print(aux.c_str());
    }

    refresh();
    menuInicial();
}

void Interface::listaValorConta(){

    setMenu();
    print("///// CONSULTA DE CONTAS /////");
    print("CELULAR : ");
    getString();

    refresh();
    menuInicial();

    // RECEBE CELULAR
    // VALOR TOTAL DAS LIGACOES APOS O DIA DE VENCIMENTO MES ANTERIOR
    // DIA DE VENCIMENTO 
}

void Interface::listaCreditos(){

    setMenu();
    print("///// CONSULTA DE CREDITOS /////");
    print("CELULAR : ");
    getString();

    refresh();
    menuInicial();

    // RECEBE CELULAR
    // LISTA OS CREDITOS 
    // DATA DE VALIDADE DOS CREDITOS
}

void Interface::listaExtratoS(){

    setMenu();
    print("///// CONSULTA DE EXTRATO SIMPLES /////");
    print("CELULAR: ");
    getString();
    print("DATA INICIAL: ");
    getString();

    refresh();
    menuInicial();
    // RECEBE CELULAR
    // RECEBE DATA
    // IMPRIME TODAS AS LIGACOES A PARTIR DA DATA
    // DURACAO
    // VALOR
    // DATA
}

void Interface::listaExtratoD(){

    setMenu();
    print("///// CONSULTA DE EXTRADO DE DADOS /////");
    print("CELULAR: ");
    getString();
    print("DATA INICIAL: ");
    getString();

    refresh();
    menuInicial();
    // RECEBE CELULAR E DATA
    // CONSUMO DE DADOS A PARTIR DA DATA
    // IMPRIMIR DATA, DURACAO, TIPO, E QUANTIDADE CONSUMIDA.
}

void Interface::listaClientes(){
    // LISTA CLIENTES E INFORMACOES --> TODOS OS DADOS
}

void Interface::listaPlanos(){
    // LISTA PLANOS E INFORMACOEs
}

void Interface::listaCelulares(){
    // LISTA CELULARES E INFORMACOES
}

void Interface::informaVencimentos(){
    // SEMPRE QUE UMA FATURA OU CREDITO VENCER
    // INFORMAR AO USUARIO OS DADOS DO CLIENTE E CELULAR
}

void Interface::informaLimiteFranquia(){
    // QUANDO O CONSUMO DE DADOS ALCANCAR O VALOR
    // DA FRANQUIA, INFORMAR OS DADOS DO CLIENTE E CELULAR
}

// TO-DO: Exceções: Plano nao existente. Celular não existente. Cliente não existente.
// TO-DO: Criar diagrama UML para colocar no trabalho.