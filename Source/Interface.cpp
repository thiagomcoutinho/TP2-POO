#include "./../Headers/Interface.h"

void Interface::print(const char* text, bool breakLine = true){
    mvprintw(y, x, text);
    if(breakLine){
        y++;
        x = 5;
    }else{
        string s_text(text);
        x += s_text.size();
    }
}

Interface::Interface(){
    // Inicializa tela
    initscr();
    // Posicoes do cursor
    x = y = 5;
    
    int c = 0;
    int b, erro;

    /*
        print("DATA ATUAL(dd-mm-yyyy): ", false);
        getString();
        data_atual = input;
        informaVencimentos();
        informaLimiteFranquia();
        print("Pressione Enter para continuar.");
     */

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
            catch (Excecao e){
                string excecao = e.getExcecao();
                setMenu();
                print("ERRO: ", false);
                print(excecao.c_str());
                print("OPERACAO CANCELADA!");
                print("Aperte qualquer tecla para retornar ao menu principal");
                erro = getch();

                refresh();
                menuInicial();
            }
        }
    }
}

Interface::~Interface(){
    endwin();
}

void Interface::setMenu(){
    y = x = 5;
    clear();
    refresh();
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
    print("VALOR DO MINUTO(REAIS): ");
    getString();
    vlrMinuto = stod(input);
    print("VELOCIDADE DO PACOTE DE DADOS(Mbps): ");
    getString();
    veloc = stod(input);
    print("FRANQUIA(Mb): ");
    getString();
    franquia = stod(input);
    print("VELOCIDADE ALEM DA FRANQUIA(Mbps): ");
    getString();
    velocAlem = stod(input);
    print("TIPO DO PLANO(PosPago ou PrePago): ");
    getString();
    if(input == "PosPago"){ // Pós-Pago
        print("DATA DE VENCIMENTO(dd-mm-yyyy): ");
        getString();
        vencimento_ou_validade = input; //TO-DO: BUG NA FUNCAO DE ATRIBUICAO.
        
        //Date aux(1990, 10, 11);
        // TO-DO: tratar meses e dias maiores que o possivel em Date.

        p = new PosPago(nome_plano, vlrMinuto, franquia, velocAlem, veloc, vencimento_ou_validade);
    }else if(input == "PrePago"){ // Pŕe-Pago
        print("VALOR CREDITO: ");
        getString();
        credito = stod(input);
        vencimento_ou_validade = data_atual;
        vencimento_ou_validade.acrescentaTempo();

        p = new PrePago(nome_plano, vlrMinuto, franquia, velocAlem, veloc, credito, vencimento_ou_validade);
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
    Celular* ptr_celular = new Celular();
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
    ptr_celular = &celulares_cliente[celulares_cliente.size()-1];
    ptr_celulares.push_back(ptr_celular);

    refresh();
    menuInicial();
}

void Interface::menuAdicionaCreditos(){

    double creditos;
    int numeroCelular;
    Date validade;

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

void Interface::listaValorConta(){ // TO-DO

    int numeroCelular;

    setMenu();

    print("///// CONSULTA DE CONTAS /////");
    print("CELULAR : ");
    getString();
    numeroCelular = stoi(input);

    Celular* c = getCelular(numeroCelular);

    Plano* p = c->getPlano();
    PosPago* sub_p = dynamic_cast<PosPago*> (p);

    if(sub_p != nullptr){ // Plano Pos-Pago
        // IMPRIME O VALOR ACUMULADO APOS O DIA DE VENCIMENTO DO MES ANTERIOR
        // IMPRIME O VALOR ACUMULADO APOS O DIA DE VENCIMENTO ATUAL
    }else{
        throw Excecao("O celular escolhido nao possui plano pos pago!");
    }

    refresh();
    menuInicial();
}

void Interface::listaCreditos(){

    int numeroCelular;
    string str_validade;
    Date validade;

    setMenu();

    print("///// CONSULTA DE CREDITOS /////");
    print("CELULAR : ");
    getString();
    numeroCelular = stoi(input);

    Celular* c = getCelular(numeroCelular);

    Plano* p = c->getPlano();

    PrePago* sub_p = dynamic_cast<PrePago*> (p);

    if(sub_p != nullptr){ // Celular com plano PrePago
        validade = sub_p->getValidade();
        str_validade = validade.convertDateToString(false);
        print("CREDITOS DISPONIVEIS: ", false);
        print(str_validade.c_str());
    }else{
        throw Excecao("O celular escolhido nao possui plano pre pago!");
    }

    refresh();
    menuInicial();
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

    setMenu();

    vector<Celular> aux;

    for(int i=0; i<clientes.size(); i++){
        print("///// Cliente #", false);
        print(to_string(i).c_str(), false);
        print(" /////");
        print("CPF: ", false);
        print(clientes[i].getCPF().c_str());
        print("NOME: ", false);
        print(clientes[i].getEndereco().c_str());
        print("ENDERECO: ", false);
        print(clientes[i].getEndereco().c_str());
        print("Numero de celulares: ", false);
        aux = clientes[i].getCelulares();
        print(to_string(aux.size()).c_str());
    }

    print("Pressione qualquer tecla para sair");
    int c = getch();

    refresh();
    menuInicial();
}

void Interface::listaPlanos(){

    setMenu();

    map<string, Plano*>::iterator it;
    Plano* p;
    PosPago* pos;

    for(it = planos.begin(); it != planos.end(); it++){
        print("Nome do Plano: ", false);
        print(it->first.c_str());
        
        p = it->second;

        print("Valor do minuto: ", false);
        print(to_string(p->getValorMinuto()).c_str());
        print("Velocidade: ", false);
        print(to_string(p->getVelocidade()).c_str());
        print("FRANQUIA: ", false);
        print(to_string(p->getFranquia()).c_str());
        print("Velocidade alem do limite: ", false);
        print(to_string(p->getVelocAlem()).c_str());
        
        PosPago* pos = dynamic_cast<PosPago*> (p);
        if(pos != nullptr){ // Pos-Pago
            print("TIPO: POS PAGO");
        }else{ // PrePago
            print("TIPO: PRE PAGO");
        }
    }

    print("Pressione qualquer tecla para sair");
    int c = getch();

    refresh();
    menuInicial();
}

void Interface::listaCelulares(){

    setMenu();

    vector<Ligacao> aux;
    Plano* p;
    string nome_plano;

    for(int i=0; i<ptr_celulares.size(); i++){
        print("NUMERO DO CELULAR: ", false);
        print(to_string(ptr_celulares[i]->getNumero()).c_str());

        aux = ptr_celulares[i]->getLigacoes();
        print("NUMERO DE LIGACOES: ", false);
        print(to_string(aux.size()).c_str()); 
        
        p = ptr_celulares[i]->getPlano();
        print("PLANO: ", false);
        print(p->getNomePlano().c_str());
    }

    print("Pressione qualquer tecla para sair");
    int c = getch();

    refresh();
    menuInicial();
}

void Interface::informaVencimentos(){

    /* 
        DEPOIS QUE A INTERFACE INICIALIZAR,
        pegar a data atual. Rodar as funcoes de informe e caso tiver algum plano
        vencido ou franquia vencida, imprimir na tela do usuario.
        Esperar tecla enter para Imprimir menuInicial();
    */

   setMenu();

    print("///// FATURAS VENCIDAS /////");

    Plano* p;
    PosPago* sub_p;
    Date vencimento;
    Cliente* c;
    Celular* curr_cel;
    string nome_cliente;

    for(int i = 0; i<ptr_celulares.size(); i++){

        curr_cel = ptr_celulares[i];

        p = curr_cel->getPlano();
        sub_p = dynamic_cast<PosPago*> (p);
        if(sub_p != nullptr){ // Plano Pos Pago
            vencimento = sub_p->getVencimento();
            if(vencimento > data_atual){
                
                c = curr_cel->getCliente();
                nome_cliente = c->getNome();
                print("Cliente: ", false);
                print(nome_cliente.c_str());
                print("Numero de celular: ", false);
                print(to_string(curr_cel->getNumero()).c_str());
                print("VALOR DO PLANO: ", false);
                print(to_string(sub_p->getValor()).c_str());
                print("DATA DE VENCIMENTO: ", false);
                print(vencimento.convertDateToString(false).c_str());
            }
        }
    }
}

void Interface::informaLimiteFranquia(){
    // QUANDO O CONSUMO DE DADOS ALCANCAR O VALOR
    // DA FRANQUIA, INFORMAR OS DADOS DO CLIENTE E CELULAR
}

// TO-DO: Exceções: Plano nao existente. Celular não existente. Cliente não existente.
// TO-DO: Criar diagrama UML para colocar no trabalho.