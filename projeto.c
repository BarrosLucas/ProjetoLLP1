#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define ALUGUEL 1
#define VENDA   0

struct Informacoes{
	int aluguelOuVenda;
	double valor;
};

struct Endereco{
	char rua[100];
	int numero;
	char bairro[100];
	char CEP[10];
	char cidade[100];
};
	
struct Casa{
	char tituloDoAnuncio[30];
	int numeroDePavimentos;
	int numeroDeQuartos;
	double areaDoTerreno;
	double areaConstruida;
	struct Endereco endereco;
	struct Informacoes informacoes;
};

struct Apartamento{
	char tituloDoAnuncio[30];
	double area;
	int numeroDeQuartos;
	char posicao[50];
	int andar;
	double valorDoCondominio;
	int numeroDeVagasDeGaragem;
	struct Endereco endereco;
	struct Informacoes informacoes;
};

struct Terreno{
	char tituloDoAnuncio[30];
	double area;
	struct Endereco endereco;
	struct Informacoes informacoes;
};


void menu();
void cadastrar();
int menuCadastro();
int inserirInformacoesGerais(struct Informacoes *informacoes, struct Endereco *endereco);
void inserirInformacoesCasa(struct Casa *casa);
int menuAluguelVenda();
void mostrarInformacoes(struct Informacoes *informacoes);
void mostrarEndereco(struct Endereco *endereco);
void mostrarCasa(struct Casa *casa);

char * codificarEndereco(struct Endereco *endereco);
char * codificarInformacoes(struct Informacoes *informacoes);
char * codificarCasa(struct Casa *casa);
char * codificarApartamento(struct Apartamento *apartamento);
char * codificarTerreno(struct Terreno *terreno);

struct Casa casas[999];
struct Apartamento apartamentos[999];
struct Terreno terrenos[999];
int ultimoIndiceCasas = 0, ultimoIndiceApartamentos = 0, ultimoIndiceTerrenos = 0;


int main(void){
	int i;
	

	lerArquivoCasa();
	menu();
	
/*
	/*struct Casa novaCasa;
	novaCasa.areaConstruida = 11;
	novaCasa.areaDoTerreno = 12;
	novaCasa.numeroDePavimentos = 3;
	novaCasa.numeroDeQuartos = 5;
	strcpy(novaCasa.tituloDoAnuncio,"Titulo Teste");
	strcpy(novaCasa.endereco.bairro,"Bairro Teste");
	strcpy(novaCasa.endereco.CEP,"11111-111");
	strcpy(novaCasa.endereco.cidade,"Cidade Teste");
	strcpy(novaCasa.endereco.rua,"Rua Teste");
	novaCasa.endereco.numero = 100;
	novaCasa.informacoes.aluguelOuVenda = 1;
	novaCasa.informacoes.valor = 12;*/
	
	/*struct Apartamento novoApartamento;
	novoApartamento.andar = 3;
	novoApartamento.area = 2.5;
	novoApartamento.numeroDeQuartos = 4;
	novoApartamento.numeroDeVagasDeGaragem = 20;
	novoApartamento.valorDoCondominio = 4.53;
	strcpy(novoApartamento.tituloDoAnuncio,"Titulo Teste");
	strcpy(novoApartamento.posicao,"Ali");
	strcpy(novoApartamento.endereco.bairro,"Bairro Teste");
	strcpy(novoApartamento.endereco.CEP,"33333-333");
	strcpy(novoApartamento.endereco.cidade,"Cidade Teste");
	strcpy(novoApartamento.endereco.rua,"Rua Teste");
	novoApartamento.endereco.numero=3;
	novoApartamento.informacoes.aluguelOuVenda = 1;
	novoApartamento.informacoes.valor = 3.65;
	
	struct Terreno novoTerreno;
	novoTerreno.area = 3.45;
	strcpy(novoTerreno.tituloDoAnuncio,"Titulo Teste");
	strcpy(novoTerreno.endereco.bairro,"Bairro Teste");
	strcpy(novoTerreno.endereco.CEP,"33333-333");
	strcpy(novoTerreno.endereco.cidade,"Cidade Teste");
	strcpy(novoTerreno.endereco.rua,"Rua Teste");
	novoTerreno.endereco.numero=3;
	novoTerreno.informacoes.aluguelOuVenda = 0;
	novoTerreno.informacoes.valor = 3.65;
	
	
	char info[800];
	strcpy(info,codificarTerreno(&novoTerreno));
	printf("CODIFICADO:\n%s\n",info);
	
	struct Terreno terrenoCC;
	
	char newInfo[800];
	printf("DECODIFICADO:\n");
	decodificadorTerreno(info,&terrenoCC,800);
	
	char info[800];
	strcpy(info,codificarCasa(&novaCasa));
	printf("CODIFICADO:\n%s\n",info);
	
	printf("DECODIFICADO:\n");
	
	char newInfo[800];
	decodificadorInformacoes(newInfo,&novaCasa,800);
*/
	
	return 0;
}

void menu(){
	int escolha;
	
	
	printf("Escolha uma opcao: \n");
	printf("1 - Cadastrar Imovel\n");
	printf("2 - Consultar Imovel\n");
	printf("3 - Remover Imovel\n");
	printf("4 - Editar Imovel\n");
	printf("Escolha: ");
	
	
	scanf("%d",&escolha);
	system("cls");
	fflush(stdin);
	switch(escolha){
		case 1:
			cadastrar();
			break;
		case 2:
			consultar();
			break;
		case 3:
			remover();
			break;
		case 4:
			atualizar();
			break;
		default:
			printf("Opcao invalida...\n");
			menu();
	}
}

void cadastrar(){
	int opcao = menuCadastro();
	int continua=0;
	
	switch(opcao){
		case 1:
		
			printf("=====CADASTRO DE CASA=====\n");
			struct Casa novaCasa;
			continua = inserirInformacoesGerais(&novaCasa.informacoes,&novaCasa.endereco);
			if(!continua){
				inserirInformacoesCasa(&novaCasa);	
				if(salvarCasa(&novaCasa)){
					casas[ultimoIndiceCasas] = novaCasa;
					memset(novaCasa.endereco.bairro,0,sizeof(novaCasa.endereco.bairro));
					memset(novaCasa.endereco.CEP,0,sizeof(novaCasa.endereco.CEP));
					memset(novaCasa.endereco.cidade,0,sizeof(novaCasa.endereco.cidade));
					memset(novaCasa.endereco.rua,0,sizeof(novaCasa.endereco.rua));
					ultimoIndiceCasas ++;
					printf("CADASTRO REALIZADO COM SUCESSO!");	
				}else{
					printf("Falha no cadastro...\n");
				}
				//char strCasa[800];
				//strcpy(strCasa,codificarCasa(&novaCasa));
				//printf("%s",strCasa);
				
				
			}else{
				printf("Ja existe um imovel cadastrado nesse endereco...\n");
				
			}
			sleep(3);	
			
			system("cls");
			
			menu();
			//mostrarCasa(&casas[ultimoIndiceCasas-1]);
			break;
		case 2:
			printf("=====CADASTRO DE APARTAMENTO=====\n");
			struct Apartamento novoApartamento;
			continua = inserirInformacoesGerais(&novoApartamento.informacoes,&novoApartamento.endereco);
			
			if(!continua){
				inserirInformacoesApartamento(&novoApartamento);
				
				if(salvarApartamento(&novoApartamento)){
					apartamentos[ultimoIndiceApartamentos] = novoApartamento;
					ultimoIndiceApartamentos ++;
					printf("CADASTRO REALIZADO COM SUCESSO!");		
				}else{
					printf("Falha no cadastro...\n");
				}
				//char strAp[800];
				//strcpy(strAp,codificarApartamento(&novoApartamento));
				//printf("%s",strAp);
				
				
			}else{
				printf("Ja existe um imovel cadastrado nesse endereco...\n");
			}
			
			
			sleep(3);
			
			system("cls");
			
			menu();
			//mostrarApartamento(&apartamentos[ultimoIndiceApartamentos-1]);
			break;
		case 3:
			printf("=====CADASTRO DE TERRENO=====\n");
			struct Terreno novoTerreno;
			continua = inserirInformacoesGerais(&novoTerreno.informacoes,&novoTerreno.endereco);
			if(!continua){
				inserirInformacoesTerreno(&novoTerreno);
				
				if(salvarTerreno(&novoTerreno)){
					terrenos[ultimoIndiceTerrenos] = novoTerreno;
					ultimoIndiceTerrenos ++;
					printf("CADASTRO REALIZADO COM SUCESSO!");		
				}else{
					printf("Falha no cadastro...\n");
				}
				//char strTer[800];
				//strcpy(strTer,codificarTerreno(&novoTerreno));
				//printf("%s",strTer);

				
				
			}else{
				printf("Ja existe um imovel cadastrado nesse endereco...\n");
			}
			
			
			sleep(3);
			
			system("cls");
			
			menu();
			//mostrarTerreno(&terrenos[ultimoIndiceTerrenos-1]);
			break;
		case 4:
			system("cls");
			menu();
			
			
	}
	
}

int menuCadastro(){
	int escolha;
	
	printf("O que voce deseja cadastrar?\n");
	printf("1 - Casa\n");
	printf("2 - Apartamento\n");
	printf("3 - Terreno\n");
	printf("4 - Voltar\n");
	printf("Escolha: ");
	
	scanf("%d",&escolha);
	system("cls");
	if (escolha < 1 || escolha > 4){
		printf("Opcao invalida...\n");
		escolha = menuCadastro();
	}
	return escolha;
}

void inserirInformacoesCasa(struct Casa *casa){
	fflush(stdin);
	memset((*casa).tituloDoAnuncio, 0, sizeof((*casa).tituloDoAnuncio));
	
	int numeroDePavimentos, numeroDeQuartos;
	double areaDoTerreno, areaConstruida;

	printf("Titulo do Anuncio: ");
	fgets((*casa).tituloDoAnuncio,30,stdin);
	(*casa).tituloDoAnuncio[strcspn((*casa).tituloDoAnuncio, "\n")] = '\0';
	fflush(stdin);
	
	printf("Numero de Pavimentos: ");
	scanf("%d",&numeroDePavimentos);
	fflush(stdin);
	
	printf("Numero de Quartos: ");
	scanf("%d",&numeroDeQuartos);
	fflush(stdin);
	
	printf("Area do Terreno: ");
	scanf("%lf",&areaDoTerreno);
	fflush(stdin);
	
	printf("Area Construida: ");
	scanf("%lf",&areaConstruida);
	fflush(stdin);
	
	(*casa).numeroDePavimentos = numeroDePavimentos;
	(*casa).numeroDeQuartos = numeroDeQuartos;
	(*casa).areaDoTerreno = areaDoTerreno;
	(*casa).areaConstruida = areaConstruida;	
}

void inserirInformacoesApartamento(struct Apartamento *apartamento){
	fflush(stdin);
	memset((*apartamento).tituloDoAnuncio, 0, sizeof((*apartamento).tituloDoAnuncio));
	memset((*apartamento).posicao, 0, sizeof((*apartamento).posicao));
	
	double area, valorDoCondominio;
	int numeroDeQuartos,andar,numeroDeVagasDeGaragem;

	printf("Titulo do Anuncio: ");
	fgets((*apartamento).tituloDoAnuncio,30,stdin);
	(*apartamento).tituloDoAnuncio[strcspn((*apartamento).tituloDoAnuncio, "\n")] = '\0';
	fflush(stdin);
	
	printf("Area: ");
	scanf("%lf",&area);
	fflush(stdin);
	
	printf("Numero de Quartos: ");
	scanf("%d",&numeroDeQuartos);
	fflush(stdin);
	
	printf("Posicao: ");
	fgets((*apartamento).posicao,50,stdin);
	(*apartamento).posicao[strcspn((*apartamento).posicao, "\n")] = '\0';
	fflush(stdin);
	
	printf("Andar: ");
	scanf("%d",&andar);
	fflush(stdin);
	
	printf("Valor do Condominio: R$ ");
	scanf("%lf",&valorDoCondominio);
	fflush(stdin);
	
	
	printf("Numero de Vagas de Garagem: ");
	scanf("%d",&numeroDeVagasDeGaragem);
	fflush(stdin);
	
	
	(*apartamento).area = area;
	(*apartamento).numeroDeQuartos = numeroDeQuartos;
	(*apartamento).andar = andar;
	(*apartamento).valorDoCondominio = valorDoCondominio;
	(*apartamento).numeroDeVagasDeGaragem = numeroDeVagasDeGaragem;
}

void inserirInformacoesTerreno(struct Terreno *terreno){
	fflush(stdin);
	memset((*terreno).tituloDoAnuncio, 0, sizeof((*terreno).tituloDoAnuncio));
	
	double area;
	printf("Titulo do Anuncio: ");
	fgets((*terreno).tituloDoAnuncio,30,stdin);
	(*terreno).tituloDoAnuncio[strcspn((*terreno).tituloDoAnuncio, "\n")] = '\0';
	fflush(stdin);
	
	printf("Area: ");
	scanf("%lf",&area);
	fflush(stdin);
	
	(*terreno).area = area;	
}

int inserirInformacoesGerais(struct Informacoes *informacoes, struct Endereco *endereco){
	fflush(stdin);
	int retorno = 1; //0 = SUCESSO | 1 = INSUCESSO
	int aluguelOuVenda = menuAluguelVenda();
	double valor;
	int numero;
	aluguelOuVenda = (aluguelOuVenda==1)? ALUGUEL : ((aluguelOuVenda==2)? VENDA : 3);
	if(aluguelOuVenda == 3){
		system("cls");
		fflush(stdin);
		menu();
		return retorno;
	}else{
		/*memset((*endereco).rua, 0, sizeof((*endereco).rua));
		memset((*endereco).bairro, 0, sizeof((*endereco).bairro));
		memset((*endereco).CEP, 0, sizeof((*endereco).CEP));
		memset((*endereco).cidade, 0, sizeof((*endereco).cidade));*/
		
		
		printf("Valor: R$ ");
		scanf("%lf",&valor);
		fflush(stdin);
		
		printf("Rua: ");
		fgets((*endereco).rua,100,stdin);
		(*endereco).rua[strcspn((*endereco).rua, "\n")] = '\0';
		fflush(stdin);
		
		printf("Numero: ");
		scanf("%d",&numero);
		fflush(stdin);
		
		printf("Bairro: ");
		fgets((*endereco).bairro,100,stdin);
		(*endereco).bairro[strcspn((*endereco).bairro, "\n")] = '\0';
		fflush(stdin);
		
		printf("CEP: ");
		fgets((*endereco).CEP,10,stdin);
		(*endereco).CEP[strcspn((*endereco).CEP, "\n")] = '\0';
		fflush(stdin);
		
		printf("Cidade: ");
		fgets((*endereco).cidade,100,stdin);
		(*endereco).cidade[strcspn((*endereco).cidade, "\n")] = '\0';
		fflush(stdin);
		
		
		(*informacoes).aluguelOuVenda = aluguelOuVenda;
		(*informacoes).valor = valor;
		
		(*endereco).numero = numero;
		
		//char ender[100];
		
		//strcpy(ender,codificarInformacoes(&(*informacoes)));
		//printf("%s\n",ender);
		
		return jaExisteEndereco(&(*endereco));
	}
	return 1;
	
		
}

int menuAluguelVenda(){
	int escolha;
	printf("Voce quer: \n");
	printf("1 - Alugar\n");
	printf("2 - Vender\n");
	printf("3 - Cancelar\n");
	printf("Escolha: ");
	scanf("%d",&escolha);
	if(escolha < 1 || escolha > 3){
		escolha = menuAluguelVenda();
	}
	return escolha;
}


void consultar(){
	int consulta = menuConsulta();
	int i;
	char letra;
	fflush(stdin);
	switch(consulta){
		case 1:
			mostrarTudo();
			printf("Digite enter para voltar...");
			scanf("%c",&letra);
			system("cls");
			menu();
			break;
		case 2:
			fflush(stdin);
			buscarPorTitulo();
			printf("Digite enter para voltar...");
			scanf("%c",&letra);
			system("cls");
			menu();
			break;	
		case 3:
			fflush(stdin);
			buscarPorBairro();
			printf("Digite enter para voltar...");
			scanf("%c",&letra);
			system("cls");
			menu();
			break;
		case 4:
			fflush(stdin);
			buscarPorValor();
			printf("Digite enter para voltar...");
			scanf("%c",&letra);
			system("cls");
			menu();
			break;
		case 5:
			fflush(stdin);
			buscarVendaPorTipo();
			printf("Digite enter para voltar...");
			scanf("%c",&letra);
			system("cls");
			menu();
			break;
		case 6:
			fflush(stdin);
			buscarAluguelPorTipo();
			printf("Digite enter para voltar...");
			scanf("%c",&letra);
			system("cls");
			menu();
		case 7:
			fflush(stdin);
			system("cls");
			menu();
	}
}
int menuConsulta(){
	fflush(stdin);
	int escolha;
	printf("Que tipo de consulta deseja fazer?\n");
	printf("1 - Mostrar todos os imoveis\n");
	printf("2 - Buscar imovel por titulo\n");
	printf("3 - Buscar imovel por bairro\n");
	printf("4 - Buscar imovel acima de um valor\n");
	printf("5 - Buscar os imoveis a venda por tipo de imovel\n");
	printf("6 - Buscar os imoveis a aluguel por tipo de imovel\n");
	printf("7 - Voltar\n");
	printf("Sua escolha: ");
	scanf("%d",&escolha);
	fflush(stdin);
	system("cls");
	if(escolha < 1 || escolha > 7){
		printf("Opcao invalida...\n");
		escolha = menuConsulta();
	}
	return escolha;
}

void mostrarTudo(){
	printf("=====CASAS=====\n");
	int i;
	for(i = 0;i<ultimoIndiceCasas;i++){
		printf("\n");
		mostrarCasa(&casas[i]);
		printf("\n");
	}
	printf("=====APARTAMENTOS=====\n");
	for(i = 0;i<ultimoIndiceApartamentos;i++){
		printf("\n");
		mostrarApartamento(&apartamentos[i]);
		printf("\n");
	}
	printf("=====TERRENOS=====\n");
	for(i = 0;i<ultimoIndiceTerrenos;i++){
		printf("\n");
		mostrarTerreno(&terrenos[i]);
		printf("\n");
	}
}

void buscarPorTitulo(){
	fflush(stdin);
	char titulo[30];
	int i,qnt=0;
	printf("=====BUSCA POR TITULO=====\n");
	printf("Titulo: ");
	fgets(titulo,30,stdin);
	titulo[strcspn(titulo, "\n")] = '\0';
	fflush(stdin);
	
	
	
	for(i=0;i<ultimoIndiceCasas;i++){
		if(stricmp(titulo,casas[i].tituloDoAnuncio)==0){
			mostrarCasa(&casas[i]);
			qnt=1;
		}
	}
	
	for(i=0;i<ultimoIndiceApartamentos;i++){
		if(stricmp(titulo,apartamentos[i].tituloDoAnuncio)==0){
			mostrarApartamento(&apartamentos[i]);
			qnt = 1;
		}
	}
	
	for(i=0;i<ultimoIndiceTerrenos;i++){
		if(stricmp(titulo,terrenos[i].tituloDoAnuncio)==0){
			mostrarTerreno(&terrenos[i]);
			qnt = 1;
		}
	}	
	
	if(qnt == 0){
		fflush(stdin);
		char escolha;
		system("cls");
		printf("Nenhum item identificado...\n");
		printf("Deseja realizar novamente a busca?\n");
		printf("1 - Sim\n");
		printf("Enter - Nao\n");
		printf("Sua escolha: ");
		scanf("%c",&escolha);
		if(escolha == '1'){
			system("cls");
			buscarPorTitulo();
		}else{
			system("cls");
			menu();
		}
	}
}

void buscarPorBairro(){
	fflush(stdin);
	char bairro[100];
	int i,qnt=0;
	printf("=====BUSCA POR BAIRRO=====\n");
	printf("Bairro: ");
	fgets(bairro,100,stdin);
	bairro[strcspn(bairro, "\n")] = '\0';
	fflush(stdin);
	
	for(i=0;i<ultimoIndiceCasas;i++){
		if(stricmp(bairro,casas[i].endereco.bairro)==0){
			mostrarCasa(&casas[i]);
			qnt=1;
		}
	}
	
	for(i=0;i<ultimoIndiceApartamentos;i++){
		if(stricmp(bairro,apartamentos[i].endereco.bairro)==0){
			mostrarApartamento(&apartamentos[i]);
			qnt = 1;
		}
	}
	
	for(i=0;i<ultimoIndiceTerrenos;i++){
		if(stricmp(bairro,terrenos[i].endereco.bairro)==0){
			mostrarTerreno(&terrenos[i]);
			qnt = 1;
		}
	}	
	
	if(qnt == 0){
		fflush(stdin);
		char escolha;
		system("cls");
		printf("Nenhum item identificado...\n");
		printf("Deseja realizar novamente a busca?\n");
		printf("1 - Sim\n");
		printf("Qualquer outra tecla - Nao\n");
		printf("Sua escolha: ");
		scanf("%c",&escolha);
		if(escolha == '1'){
			system("cls");
			buscarPorBairro();
		}else{
			system("cls");
			menu();
		}
	}
}

void buscarPorValor(){
	fflush(stdin);
	double valorMinimo;
	int i,qnt=0;
	printf("=====BUSCA POR VALOR MINIMO=====\n");
	printf("Imoveis a partir de R$ ");
	scanf("%lf",&valorMinimo);
	fflush(stdin);
	
	for(i=0;i<ultimoIndiceCasas;i++){
		if(casas[i].informacoes.valor >= valorMinimo){
			mostrarCasa(&casas[i]);
			qnt=1;
		}
	}
	for(i=0;i<ultimoIndiceApartamentos;i++){
		if(apartamentos[i].informacoes.valor >= valorMinimo){
			mostrarApartamento(&apartamentos[i]);
			qnt = 1;
		}
	}
	for(i=0;i<ultimoIndiceTerrenos;i++){
		if(terrenos[i].informacoes.valor >= valorMinimo){
			mostrarTerreno(&terrenos[i]);
			qnt = 1;
		}
	}	
		
	if(qnt == 0){
		fflush(stdin);
		char escolha;
		system("cls");
		printf("Nenhum item identificado...\n");
		printf("Deseja realizar novamente a busca?\n");
		printf("1 - Sim\n");
		printf("Qualquer outra tecla - Nao\n");
		printf("Sua escolha: ");
		scanf("%c",&escolha);
		if(escolha == '1'){
			system("cls");
			buscarPorBairro();
		}else{
			system("cls");
			menu();
		}
	}
}
void buscarAluguelPorTipo(){
	int tipo = menuBuscaAluguelTipo();
	fflush(stdin);
	switch(tipo){
		case 1:
			mostrarCasasPorTipo(ALUGUEL);
			break;
		case 2:
			mostrarApartamentosPorTipo(ALUGUEL);
			break;
		case 3:
			mostrarTerrenosPorTipo(ALUGUEL);
			break;
		case 4:
			menu();
	}
}

void buscarVendaPorTipo(){
	int tipo = menuBuscaVendaTipo();
	fflush(stdin);
	switch(tipo){
		case 1:
			mostrarCasasPorTipo(VENDA);
			break;
		case 2:
			mostrarApartamentosPorTipo(VENDA);
			break;
		case 3:
			mostrarTerrenosPorTipo(VENDA);
			break;
		case 4:
			menu();
	}
}
int menuBuscaAluguelTipo(){
	int escolha;
	fflush(stdin);
	system("cls");
	printf("Buscar por que tipo de imovel a aluguel?\n");
	printf("1 - Casa\n");
	printf("2 - Apartamento\n");
	printf("3 - Terreno\n");
	printf("4 - Cancelar\n");
	printf("Escolha: ");
	scanf("%d",&escolha);
	fflush(stdin);
	system("cls");
	if(escolha < 1 || escolha > 4){
		printf("Opcao invalida...\n");
		escolha = menuBuscaAluguelTipo();
	}
	return escolha;
}
int menuBuscaVendaTipo(){
	int escolha;
	fflush(stdin);
	system("cls");
	printf("Buscar por que tipo de imovel a venda?\n");
	printf("1 - Casa\n");
	printf("2 - Apartamento\n");
	printf("3 - Terreno\n");
	printf("4 - Cancelar\n");
	printf("Escolha: ");
	scanf("%d",&escolha);
	fflush(stdin);
	system("cls");
	if(escolha < 1 || escolha > 4){
		printf("Opcao invalida...\n");
		escolha = menuBuscaVendaTipo();
	}
	return escolha;
}

void atualizar(){
	int num;
	struct Endereco endereco;
	printf("=====ATUALIZAR=====\n");
	printf("Informe o endereco do imovel...\n");
	
	printf("Rua: ");
	fgets(endereco.rua,100,stdin);
	endereco.rua[strcspn(endereco.rua, "\n")] = '\0';
	fflush(stdin);
	
	printf("Numero: ");
	scanf("%d",&num);
	endereco.numero = num;
	fflush(stdin);
	
	printf("Bairro: ");
	fgets(endereco.bairro,100,stdin);
	endereco.bairro[strcspn(endereco.bairro, "\n")] = '\0';
	fflush(stdin);
	
	printf("CEP: ");
	fgets(endereco.CEP,10,stdin);
	endereco.CEP[strcspn(endereco.CEP, "\n")] = '\0';
	fflush(stdin);
	
	printf("Cidade: ");
	fgets(endereco.cidade,100,stdin);
	endereco.cidade[strcspn(endereco.cidade, "\n")] = '\0';
	fflush(stdin);
	
	int vaiEditar = jaExisteEndereco(&endereco);
	if(vaiEditar != 0){
		int index,escolha;
		switch(vaiEditar){
			case 1:
				index = buscarCasaPorEndereco(&endereco);
				printf("Deseja mesmo editar esse imovel?\n1 - Sim\n2 - Nao\nEscolha: ");
				scanf("%d",&escolha);
				if(escolha==1){
					memset(casas[index].tituloDoAnuncio, 0, sizeof(casas[index].tituloDoAnuncio));
			 		//memset(casas[index].endereco.bairro, 0, sizeof(casas[index].endereco.bairro));
			 		//memset(casas[index].endereco.CEP, 0, sizeof(casas[index].endereco.CEP));
			 		//memset(casas[index].endereco.cidade, 0, sizeof(casas[index].endereco.cidade));
			 		//memset(casas[index].endereco.rua, 0, sizeof(casas[index].endereco.rua));
					
					
					inserirInformacoesCasa(&(casas[index]));
					
					//casas[index] = casas[ultimoIndiceCasas-1];
					//ultimoIndiceCasas--;
					if(salvarArrayDeCasasNoArquivo()){
						printf("Casa atualizada com sucesso!\n");
					}else{
						printf("Houve alguma falha na atualizacao.\n");
					}
					//Deletar do array e do arquivo
				}
				//Mostrar casa
				break;
			case 2:
				index = buscarApartamentoPorEndereco(&endereco);
				printf("Deseja mesmo editar esse imovel?\n1 - Sim\n2 - Nao\nEscolha: ");
				scanf("%d",&escolha);
				if(escolha==1){
					memset(apartamentos[index].tituloDoAnuncio, 0, sizeof(apartamentos[index].tituloDoAnuncio));
					memset(apartamentos[index].posicao, 0, sizeof(apartamentos[index].posicao));
					//apartamentos[index] = apartamentos[ultimoIndiceApartamentos-1];
					//ultimoIndiceApartamentos--;
					
					inserirInformacoesApartamento(&(apartamentos[index]));
					
					//casas[index] = casas[ultimoIndiceCasas-1];
					//ultimoIndiceCasas--;
					if(salvarArrayDeApartamentosNoArquivo()){
						printf("Apartamento atualizado com sucesso!\n");
					}else{
						printf("Houve alguma falha na atualizacao.\n");
					}
				}
				//Mostrar apartamento
				break;
			case 3:
				index = buscarTerrenoPorEndereco(&endereco);
				printf("Deseja mesmo atualizar esse imovel?\n1 - Sim\n2 - Nao\nEscolha: ");
				scanf("%d",&escolha);
				if(escolha==1){
					memset(terrenos[index].tituloDoAnuncio, 0, sizeof(terrenos[index].tituloDoAnuncio));
					//apartamentos[index] = apartamentos[ultimoIndiceApartamentos-1];
					//ultimoIndiceApartamentos--;
					
					inserirInformacoesTerreno(&(terrenos[index]));
					
					//casas[index] = casas[ultimoIndiceCasas-1];
					//ultimoIndiceCasas--;
					if(salvarArrayDeTerrenosNoArquivo()){
						printf("Terreno atualizado com sucesso!\n");
					}else{
						printf("Houve alguma falha na atualizacao.\n");
					}
				}
				//Mostrar terreno
				break;
		}
	}else{ //vai deletar == 0
		printf("Nao foi localizado nenhum imovel no endereco informado.\n");
	}
	sleep(3);
	system("cls");
	menu();
}


void remover(){
	
	/*
	
	char rua[100];
	int numero;
	char bairro[100];
	char CEP[10];
	char cidade[100];
	*/
	int num;
	struct Endereco endereco;
	printf("=====REMOVER=====\n");
	printf("Informe o endereco do imovel...\n");
	
	printf("Rua: ");
	fgets(endereco.rua,100,stdin);
	endereco.rua[strcspn(endereco.rua, "\n")] = '\0';
	fflush(stdin);
	
	printf("Numero: ");
	scanf("%d",&num);
	endereco.numero = num;
	fflush(stdin);
	
	printf("Bairro: ");
	fgets(endereco.bairro,100,stdin);
	endereco.bairro[strcspn(endereco.bairro, "\n")] = '\0';
	fflush(stdin);
	
	printf("CEP: ");
	fgets(endereco.CEP,10,stdin);
	endereco.CEP[strcspn(endereco.CEP, "\n")] = '\0';
	fflush(stdin);
	
	printf("Cidade: ");
	fgets(endereco.cidade,100,stdin);
	endereco.cidade[strcspn(endereco.cidade, "\n")] = '\0';
	fflush(stdin);
	
	int vaiDeletar = jaExisteEndereco(&endereco);
	if(vaiDeletar != 0){
		int index,escolha;
		switch(vaiDeletar){
			case 1:
				index = buscarCasaPorEndereco(&endereco);
				printf("Deseja mesmo excluir esse imovel?\n1 - Sim\n2 - Nao\nEscolha: ");
				scanf("%d",&escolha);
				if(escolha==1){
					casas[index] = casas[ultimoIndiceCasas-1];
					ultimoIndiceCasas--;
					if(salvarArrayDeCasasNoArquivo()){
						printf("Casa removida com sucesso!\n");
					}else{
						printf("Houve alguma falha na remocao.\n");
					}
					//Deletar do array e do arquivo
				}
				//Mostrar casa
				break;
			case 2:
				index = buscarApartamentoPorEndereco(&endereco);
				printf("Deseja mesmo excluir esse imovel?\n1 - Sim\n2 - Nao\nEscolha: ");
				scanf("%d",&escolha);
				if(escolha==1){
					apartamentos[index] = apartamentos[ultimoIndiceApartamentos-1];
					ultimoIndiceApartamentos--;
					if(salvarArrayDeApartamentosNoArquivo()){
						printf("Apartamento removido com sucesso!\n");
					}else{
						printf("Houve alguma falha na remocao.\n");
					}
					//Deletar do array e do arquivo
				}
				//Mostrar apartamento
				break;
			case 3:
				index = buscarTerrenoPorEndereco(&endereco);
				printf("Deseja mesmo excluir esse imovel?\n1 - Sim\n2 - Nao\nEscolha: ");
				scanf("%d",&escolha);
				if(escolha==1){
					terrenos[index] = terrenos[ultimoIndiceTerrenos-1];
					ultimoIndiceTerrenos--;
					if(salvarArrayDeTerrenosNoArquivo()){
						printf("Terreno removido com sucesso!\n");
					}else{
						printf("Houve alguma falha na remocao.\n");
					}
					//Deletar do array e do arquivo
				}
				//Mostrar terreno
				break;
		}
	}else{ //vai deletar == 0
		printf("Nao foi localizado nenhum imovel no endereco informado.\n");
	}
	sleep(3);
	system("cls");
	menu();
}
int salvarArrayDeCasasNoArquivo(){
	int retorno = 0,i;
	
	//Limpa o arquivo
	FILE *fp;
	
	fp=fopen("persistencia/casas.txt","w");
	fprintf(fp,"");
	
	fclose(fp);
	
	for(i=0;i<ultimoIndiceCasas;i++){
		retorno = salvarCasa(&casas[i]);
		if(!retorno){
			return retorno;
		}
	}
	return retorno;
}

int salvarArrayDeApartamentosNoArquivo(){
	int retorno = 0,i;
	
	//Limpa o arquivo
	FILE *fp;
	
	fp=fopen("persistencia/apartamentos.txt","w");
	fprintf(fp,"");
	
	fclose(fp);
	
	for(i=0;i<ultimoIndiceApartamentos;i++){
		retorno = salvarApartamento(&apartamentos[i]);
		if(!retorno){
			return retorno;
		}
	}
	
	return retorno;
}

int salvarArrayDeTerrenosNoArquivo(){
	int retorno = 0,i;
	
	//Limpa o arquivo
	FILE *fp;
	
	fp=fopen("persistencia/terrenos.txt","w");
	fprintf(fp,"");
	
	fclose(fp);
	
	for(i=0;i<ultimoIndiceTerrenos;i++){
		retorno = salvarTerreno(&terrenos[i]);
		if(!retorno){
			return retorno;
		}
	}
	return retorno;
}
int buscarCasaPorEndereco(struct Endereco *endereco){
	int i = 0;
	for(i=0;i<ultimoIndiceCasas;i++){
		if(!stricmp((*endereco).bairro,casas[i].endereco.bairro) && !stricmp((*endereco).CEP,casas[i].endereco.CEP) && !stricmp((*endereco).cidade,casas[i].endereco.cidade) && !stricmp((*endereco).rua,casas[i].endereco.rua) && (*endereco).numero == casas[i].endereco.numero){
			mostrarCasa(&(casas[i]));
			return i;
		}
	}
}
int buscarTerrenoPorEndereco(struct Endereco *endereco){
	int i;
	for(i=0;i<ultimoIndiceTerrenos;i++){
		if(!stricmp((*endereco).bairro,terrenos[i].endereco.bairro) && !stricmp((*endereco).CEP,terrenos[i].endereco.CEP) && !stricmp((*endereco).cidade,terrenos[i].endereco.cidade) && !stricmp((*endereco).rua,terrenos[i].endereco.rua) && (*endereco).numero == terrenos[i].endereco.numero){
			mostrarTerreno(&(terrenos[i]));
			return i;
		}
	}
}
int buscarApartamentoPorEndereco(struct Endereco *endereco){
	int i;
	for(i=0;i<ultimoIndiceApartamentos;i++){
		if(!stricmp((*endereco).bairro,apartamentos[i].endereco.bairro) && !stricmp((*endereco).CEP,apartamentos[i].endereco.CEP) && !stricmp((*endereco).cidade,apartamentos[i].endereco.cidade) && !stricmp((*endereco).rua,apartamentos[i].endereco.rua) && (*endereco).numero == apartamentos[i].endereco.numero){
			mostrarApartamento(&(apartamentos[i]));
			return i;
		}
	}
}
int jaExisteTitulo(char titulo[]){
	int i;
	for(i=0;i<ultimoIndiceCasas;i++){
		if(stricmp(titulo,casas[i].tituloDoAnuncio)==0){
			return 1;
		}
	}
	for(i=0;i<ultimoIndiceApartamentos;i++){
		if(stricmp(titulo,apartamentos[i].tituloDoAnuncio)==0){
			return 1;
		}
	}
	for(i=0;i<ultimoIndiceTerrenos;i++){
		if(stricmp(titulo,terrenos[i].tituloDoAnuncio)==0){
			return 1;
		}
	}
	return 0;
}

int jaExisteEndereco(struct Endereco *endereco){
	/*
		RETORNA 1 SE FOR UMA CASA
		RETORNA 2 SE FOR UM APARTAMENTO
		RETORNA 3 SE FOR UM TERRENO
		RETORNA 0 SE N FOR NADA
	*/
	int i = 0;
	for(i=0;i<ultimoIndiceCasas;i++){
		if(!stricmp((*endereco).bairro,casas[i].endereco.bairro) && !stricmp((*endereco).CEP,casas[i].endereco.CEP) && !stricmp((*endereco).cidade,casas[i].endereco.cidade) && !stricmp((*endereco).rua,casas[i].endereco.rua) && (*endereco).numero == casas[i].endereco.numero){
			return 1;
		}
	}
	for(i=0;i<ultimoIndiceApartamentos;i++){
		if(!stricmp((*endereco).bairro,apartamentos[i].endereco.bairro) && !stricmp((*endereco).CEP,apartamentos[i].endereco.CEP) && !stricmp((*endereco).cidade,apartamentos[i].endereco.cidade) && !stricmp((*endereco).rua,apartamentos[i].endereco.rua) && (*endereco).numero == apartamentos[i].endereco.numero){
			return 2;
		}
	}
	for(i=0;i<ultimoIndiceTerrenos;i++){
		if(!stricmp((*endereco).bairro,terrenos[i].endereco.bairro) && !stricmp((*endereco).CEP,terrenos[i].endereco.CEP) && !stricmp((*endereco).cidade,terrenos[i].endereco.cidade) && !stricmp((*endereco).rua,terrenos[i].endereco.rua) && (*endereco).numero == terrenos[i].endereco.numero){
			return 3;
		}
	}
	return 0;
}

char * codificarTerreno(struct Terreno *terreno){
	char area[7],endereco[500],informacoes[100];
	/*
	struct Terreno{
		char tituloDoAnuncio[30];
		double area;
		struct Endereco endereco;
		struct Informacoes informacoes;
	};
	*/	
	sprintf(area,"%.1lf",(*terreno).area);
	strcpy(endereco,codificarEndereco(&((*terreno).endereco)));
	strcpy(informacoes,codificarInformacoes(&((*terreno).informacoes)));
	
	const char ter[800] = "{\n";
	memset(ter, 0, sizeof(ter));
	
	strcpy(ter,"{\n");
	strcat(ter,"\"tituloDoAnuncio\":\"");
	strcat(ter,(*terreno).tituloDoAnuncio);
	strcat(ter,"\",\n\"area\":\"");
	strcat(ter,area);
	strcat(ter,"\",\n\"endereco\":\n");
	strcat(ter,endereco);
	strcat(ter,",\n\"informacoes\":\n");
	strcat(ter,informacoes);
	strcat(ter,"\n}");
	
	return ter;
}

char * codificarApartamento(struct Apartamento *apartamento){
	char area[7],quartos[3],andar[3],condominio[12],vagas[4],endereco[500],informacoes[100];
	sprintf(area,"%.1lf",(*apartamento).area);
	sprintf(quartos,"%d",(*apartamento).numeroDeQuartos);
	sprintf(andar,"%d",(*apartamento).andar);
	sprintf(condominio,"%.2lf",(*apartamento).valorDoCondominio);
	sprintf(vagas,"%d",(*apartamento).numeroDeVagasDeGaragem);
	strcpy(endereco,codificarEndereco(&((*apartamento).endereco)));
	strcpy(informacoes,codificarInformacoes(&((*apartamento).informacoes)));
	/*
	struct Apartamento{
		char tituloDoAnuncio[30];
		double area; -> 7
		int numeroDeQuartos; -> 3
		char posicao[50];
		int andar; -> 3 
		double valorDoCondominio; -> 12
		int numeroDeVagasDeGaragem; -> 4
		struct Endereco endereco; -> 500
		struct Informacoes informacoes; -> 100
	};
	*/
	const char ap[800] = "{\n";
	memset(ap, 0, sizeof(ap));
	
	strcpy(ap,"{\n");
	strcat(ap,"\"tituloDoAnuncio\":\"");
	strcat(ap,(*apartamento).tituloDoAnuncio);
	strcat(ap,"\",\n\"area\":\"");
	strcat(ap,area);
	strcat(ap,"\",\n\"numeroDeQuartos\":\"");
	strcat(ap,quartos);
	strcat(ap,"\",\n\"posicao\":\"");
	strcat(ap,(*apartamento).posicao);
	strcat(ap,"\",\n\"andar\":\"");
	strcat(ap,andar);
	strcat(ap,"\",\n\"valorDoCondominio\":\"");
	strcat(ap,condominio);
	strcat(ap,"\",\n\"vagas\":\"");
	strcat(ap,vagas);
	strcat(ap,"\",\n\"endereco\":\n");
	strcat(ap,endereco);
	strcat(ap,",\n\"informacoes\":\n");
	strcat(ap,informacoes);
	strcat(ap,"\n}");
	
	return ap;
}


char * codificarCasa(struct Casa *casa){
	char pavimentos[3],quartos[3],terreno[7],construcao[7],endereco[500],info[100];
	/*
	struct Casa{
		char tituloDoAnuncio[30];
		int numeroDePavimentos; -> 3
		int numeroDeQuartos; -> 3
		double areaDoTerreno; -> 7
		double areaConstruida; -> 7
		struct Endereco endereco; -> 500
		struct Informacoes informacoes; -> 100
	};
	*/
	
	
	//struct Casa casa;
	//casa.endereco.
	memset(endereco, 0, sizeof(endereco));
	memset(info, 0, sizeof(info));
	//printf("ENDERECO ANTES: \nBairro -> %s\nRua -> %s\nCidade -> %s\nCEP -> %s\n",(*casa).endereco.bairro,(*casa).endereco.rua,(*casa).endereco.cidade,(*casa).endereco.CEP);
	//memset((*casa).endereco,sizeof((*casa).endereco));
	//memset((*casa).informacoes,sizeof((*casa).informacoes));
	
	sprintf(pavimentos,"%d",(*casa).numeroDePavimentos);
	sprintf(quartos,"%d",(*casa).numeroDeQuartos);
	sprintf(terreno,"%.1lf",(*casa).areaDoTerreno);
	sprintf(construcao,"%.1lf",(*casa).areaConstruida);
	strcpy(endereco,codificarEndereco(&((*casa).endereco)));
	strcpy(info,codificarInformacoes(&((*casa).informacoes)));
	
	//printf("ENDERECO: \n%s\n",endereco);
	
	
	const char cas[800];
	memset(cas, 0, sizeof(cas));
	
	strcpy(cas,"{\n");
	strcat(cas,"\"tituloDoAnuncio\":\"");
	strcat(cas,(*casa).tituloDoAnuncio);
	strcat(cas,"\",\n\"numeroDePavimentos\":\"");
	strcat(cas,pavimentos);
	strcat(cas,"\",\n\"numeroDeQuartos\":\"");
	strcat(cas,quartos);
	strcat(cas,"\",\n\"areaDoTerreno\":\"");
	strcat(cas,terreno);
	strcat(cas,"\",\n\"areaConstruida\":\"");
	strcat(cas,construcao);
	strcat(cas,"\",\n\"endereco\":\n");
	strcat(cas,endereco);
	strcat(cas,",\n\"informacoes\":\n");
	strcat(cas,info);
	strcat(cas,"\n}");
	
	return cas;
}


char * codificarInformacoes(struct Informacoes * informacoes){
	char info[1],valor[12];
	sprintf(info,"%d",(*informacoes).aluguelOuVenda);
	sprintf(valor,"%.2lf",(*informacoes).valor);
	
	const char inform[100];
	memset(inform, 0, sizeof(inform));
	
	strcpy(inform,"{\n");
	strcat(inform,"\"aluguelOuVenda\":\"");
	strcat(inform,info);
	strcat(inform,"\",\n\"valor\":\"");
	strcat(inform,valor);
	strcat(inform,"\"\n}");
	
	return inform;
}

char * codificarEndereco(struct Endereco *endereco){
	
	char numero[5];
	sprintf(numero,"%d",(*endereco).numero);
	
	static char ender[500];
	memset(ender, 0, sizeof(ender));
	strcpy(ender,"{\n");
	
	
	strcat(ender,"\"rua\":\"");
	strcat(ender,(*endereco).rua);
	strcat(ender,"\",\n\"numero\":\"");
	strcat(ender,numero);
	strcat(ender,"\",\n\"bairro\":\"");
	strcat(ender,(*endereco).bairro);
	strcat(ender,"\",\n\"CEP\":\"");
	strcat(ender,(*endereco).CEP);
	strcat(ender,"\",\n\"cidade\":\"");
	strcat(ender,(*endereco).cidade);
	strcat(ender,"\"\n}");
	
	//printf("ENDERECO:\n%s\n",ender);
	
	return ender;
}


void decodificadorTerreno(char terreno[], struct Terreno *novoTerreno, int tamanho){
	/*
	int aluguelOuVenda;
	double valor;
	*/
	int ehComando = 0; //0 para não é comando | 1 para é comando
	int i;
	int aspas = 1; //0 aspas abertas | 1 aspas fechadas
	char comando[30];
	char valor[100];
	int index;
	int normal = 1;
	int chave = 0;
	int contChaves = 0;
	char end[500];
	char inf[100];
	/*

	char tituloDoAnuncio[30];
	double area;
	struct Endereco endereco;
	struct Informacoes informacoes;


	*/
	for(i=0;(i<tamanho && terreno[i]!='\0');i++){
		if(normal == 1){
			if(terreno[i]=='"'){
				if(aspas==0 && ehComando == 0){//as aspas estavam abertas, mas agora fechou e esta no valor do comando   "CEP":"11111-111"
					if(strcmp(comando,"tituloDoAnuncio")==0){
						strcpy(&(*novoTerreno).tituloDoAnuncio,valor);
					}else if(strcmp(comando,"area")==0){
						double numero = atof(valor);
						(*novoTerreno).area = numero;
					}
					memset(comando, 0, sizeof(comando));
					memset(valor,0,sizeof(valor));
					index = 0;
					aspas = 1;
					//ehComando = 1;
				}else if(aspas==0 && ehComando == 1){ //as aspas estavam abertas, mas agora fechou e está no comando    "CEP"
					aspas = 1;
					//ehComando = 0;
					index = 0;
				}else if(aspas==1 && ehComando == 0){ //as aspas estavam fechadas, mas agora abriu e está no valor do comando     "
					aspas = 0;
					ehComando = 1;
					memset(comando, 0, sizeof(comando));
					memset(valor,0,sizeof(valor));
					index=0;
				}else if(aspas==1 && ehComando == 1){ //as aspas estavam fechadas, mas agora abriu e está no comando    "CEP":"
					aspas = 0;
					ehComando = 0;
				}
			}else if(terreno[i]=='{'){
				chave ++;
				if(chave > 1){
					if(contChaves==0){
						end[0] = '{';	
					}else{
						inf[0] = '{';
					}
					index = 1;
					normal = 0;
					contChaves ++;
				}
			}else if(terreno[i]=='}'){
				chave --;
				if(chave == 0){
					//mostrarTerreno(&(*novoTerreno));
				}
			}else if(terreno[i] != '\n' && terreno[i] != ':' && terreno[i] != ','){
				if(ehComando){
					comando[index]=terreno[i];
				}else{
					valor[index]=terreno[i];
				}
				index ++;
			}
		}else{
			
			if(terreno[i] != '{' && terreno[i] != '}' && terreno != ','){
				if(contChaves == 1){
					end[index] = terreno[i];
				}else if(contChaves == 2){
					inf[index] = terreno[i];
				}
				index ++;
			}else if(terreno[i] == '}'){
				chave --;
				if(contChaves == 1){
					end[index] = '}';
					decodificadorEndereco(end,&(*novoTerreno).endereco,500);
					memset(end, 0, sizeof(end));
					memset(inf, 0, sizeof(inf));
					normal = 1;
				}else if(contChaves == 2){
					inf[index] = '}';
					decodificadorInformacoes(inf,&(*novoTerreno).informacoes,100);
				}
				index = 0;
				if(contChaves == 2){
					normal = 1;
				}
			}else if(terreno[i] == '{'){
				chave ++;
				inf[index] = '{';
			}
		}
	}
}

void decodificadorApartamento(char apartamento[], struct Apartamento *novoApartamento, int tamanho){
	/*
	int aluguelOuVenda;
	double valor;
	*/
	int ehComando = 0; //0 para não é comando | 1 para é comando
	int i;
	int aspas = 1; //0 aspas abertas | 1 aspas fechadas
	char comando[30];
	char valor[100];
	int index;
	int normal = 1;
	int chave = 0;
	int contChaves = 0;
	char end[500];
	char inf[100];
	/*

	char tituloDoAnuncio[30];
	double area;
	int numeroDeQuartos;
	char posicao[50];
	int andar;
	double valorDoCondominio;
	int numeroDeVagasDeGaragem;
	struct Endereco endereco;
	struct Informacoes informacoes;


	*/
	for(i=0;(i<tamanho && apartamento[i]!='\0');i++){
		if(normal == 1){
			if(apartamento[i]=='"'){
				if(aspas==0 && ehComando == 0){//as aspas estavam abertas, mas agora fechou e esta no valor do comando   "CEP":"11111-111"
					if(strcmp(comando,"tituloDoAnuncio")==0){
						strcpy(&(*novoApartamento).tituloDoAnuncio,valor);
					}else if(strcmp(comando,"area")==0){
						double numero = atof(valor);
						(*novoApartamento).area = numero;
					}else if(strcmp(comando,"numeroDeQuartos")==0){
						int numero = atoi(valor);
						(*novoApartamento).numeroDeQuartos = numero;
					}else if(strcmp(comando,"posicao")==0){
						strcpy(&(*novoApartamento).posicao,valor);
					}else if(strcmp(comando,"andar")==0){
						int numero = atoi(valor);
						(*novoApartamento).andar = numero;
					}else if(strcmp(comando,"valorDoCondominio")==0){
						double numero = atof(valor);
						(*novoApartamento).valorDoCondominio = numero;
					}else if(strcmp(comando,"vagas")==0){
						int numero = atoi(valor);
						(*novoApartamento).numeroDeVagasDeGaragem = numero;
					}
					memset(comando, 0, sizeof(comando));
					memset(valor,0,sizeof(valor));
					index = 0;
					aspas = 1;
					//ehComando = 1;
				}else if(aspas==0 && ehComando == 1){ //as aspas estavam abertas, mas agora fechou e está no comando    "CEP"
					aspas = 1;
					//ehComando = 0;
					index = 0;
				}else if(aspas==1 && ehComando == 0){ //as aspas estavam fechadas, mas agora abriu e está no valor do comando     "
					aspas = 0;
					ehComando = 1;
					memset(comando, 0, sizeof(comando));
					memset(valor,0,sizeof(valor));
					index=0;
				}else if(aspas==1 && ehComando == 1){ //as aspas estavam fechadas, mas agora abriu e está no comando    "CEP":"
					aspas = 0;
					ehComando = 0;
				}
			}else if(apartamento[i]=='{'){
				chave ++;
				if(chave > 1){
					if(contChaves==0){
						end[0] = '{';	
					}else{
						inf[0] = '{';
					}
					index = 1;
					normal = 0;
					contChaves ++;
				}
			}else if(apartamento[i]=='}'){
				chave --;
				if(chave == 0){
					//mostrarApartamento(&(*novoApartamento));
				}
			}else if(apartamento[i] != '\n' && apartamento[i] != ':' && apartamento[i] != ','){
				if(ehComando){
					comando[index]=apartamento[i];
				}else{
					valor[index]=apartamento[i];
				}
				index ++;
			}
		}else{
			
			if(apartamento[i] != '{' && apartamento[i] != '}' && apartamento != ','){
				if(contChaves == 1){
					end[index] = apartamento[i];
				}else if(contChaves == 2){
					inf[index] = apartamento[i];
				}
				index ++;
			}else if(apartamento[i] == '}'){
				chave --;
				if(contChaves == 1){
					end[index] = '}';
					decodificadorEndereco(end,&(*novoApartamento).endereco,500);
					memset(end, 0, sizeof(end));
					memset(inf, 0, sizeof(inf));
					normal = 1;
				}else if(contChaves == 2){
					inf[index] = '}';
					decodificadorInformacoes(inf,&(*novoApartamento).informacoes,100);
				}
				index = 0;
				if(contChaves == 2){
					normal = 1;
				}
			}else if(apartamento[i] == '{'){
				chave ++;
				inf[index] = '{';
			}
		}
	}
}


void decodificadorCasa(char casa[], struct Casa *novaCasa, int tamanho){
	/*
	int aluguelOuVenda;
	double valor;
	*/
	int ehComando = 0; //0 para não é comando | 1 para é comando
	int i;
	int aspas = 1; //0 aspas abertas | 1 aspas fechadas
	char comando[30];
	char valor[100];
	int index;
	int normal = 1;
	int chave = 0;
	int contChaves = 0;
	char end[500];
	char inf[100];
	/*
	char tituloDoAnuncio[30];
	int numeroDePavimentos;
	int numeroDeQuartos;
	double areaDoTerreno;
	double areaConstruida;

	*/
	for(i=0;(i<tamanho && casa[i]!='\0');i++){
		if(normal == 1){
			if(casa[i]=='"'){
				if(aspas==0 && ehComando == 0){//as aspas estavam abertas, mas agora fechou e esta no valor do comando   "CEP":"11111-111"
					if(strcmp(comando,"tituloDoAnuncio")==0){
						strcpy(&(*novaCasa).tituloDoAnuncio,valor);
					}else if(strcmp(comando,"numeroDePavimentos")==0){
						int numero = atoi(valor);
						(*novaCasa).numeroDePavimentos = numero;
					}else if(strcmp(comando,"numeroDeQuartos")==0){
						int numero = atoi(valor);
						(*novaCasa).numeroDeQuartos = numero;
					}else if(strcmp(comando,"areaDoTerreno")==0){
						double numero = atof(valor);
						(*novaCasa).areaDoTerreno = numero;
					}else if(strcmp(comando,"areaConstruida")==0){
						double numero = atof(valor);
						(*novaCasa).areaConstruida = numero;
					}
					memset(comando, 0, sizeof(comando));
					memset(valor,0,sizeof(valor));
					index = 0;
					aspas = 1;
					//ehComando = 1;
				}else if(aspas==0 && ehComando == 1){ //as aspas estavam abertas, mas agora fechou e está no comando    "CEP"
					aspas = 1;
					//ehComando = 0;
					index = 0;
				}else if(aspas==1 && ehComando == 0){ //as aspas estavam fechadas, mas agora abriu e está no valor do comando     "
					aspas = 0;
					ehComando = 1;
					memset(comando, 0, sizeof(comando));
					memset(valor,0,sizeof(valor));
					index=0;
				}else if(aspas==1 && ehComando == 1){ //as aspas estavam fechadas, mas agora abriu e está no comando    "CEP":"
					aspas = 0;
					ehComando = 0;
				}
			}else if(casa[i]=='{'){
				chave ++;
				if(chave > 1){
					if(contChaves==0){
						end[0] = '{';	
					}else{
						inf[0] = '{';
					}
					index = 1;
					normal = 0;
					contChaves ++;
				}
			}else if(casa[i]=='}'){
				chave --;
				if(chave == 0){
					//mostrarCasa(&(*novaCasa));
				}
			}else if(casa[i] != '\n' && casa[i] != ':' && casa[i] != ','){
				if(ehComando){
					comando[index]=casa[i];
				}else{
					valor[index]=casa[i];
				}
				index ++;
			}
		}else{
			
			if(casa[i] != '{' && casa[i] != '}' && casa != ','){
				if(contChaves == 1){
					end[index] = casa[i];
				}else if(contChaves == 2){
					inf[index] = casa[i];
				}
				index ++;
			}else if(casa[i] == '}'){
				chave --;
				if(contChaves == 1){
					end[index] = '}';
					decodificadorEndereco(end,&(*novaCasa).endereco,500);
					memset(end, 0, sizeof(end));
					memset(inf, 0, sizeof(inf));
					normal = 1;
				}else if(contChaves == 2){
					inf[index] = '}';
					decodificadorInformacoes(inf,&(*novaCasa).informacoes,100);
				}
				index = 0;
				if(contChaves == 2){
					normal = 1;
				}
			}else if(casa[i] == '{'){
				chave ++;
				inf[index] = '{';
			}
		}
	}
}

void decodificadorInformacoes(char endereco[],struct Informacoes *informacoes, int tamanho){
	/*
	int aluguelOuVenda;
	double valor;
	*/
	int ehComando = 0; //0 para não é comando | 1 para é comando
	int i;
	int aspas = 1; //0 aspas abertas | 1 aspas fechadas
	char comando[30];
	char valor[100];
	int index;
	int chave = 0;
	for(i=0;(i<tamanho && endereco[i]!='\0');i++){
		if(endereco[i]=='"'){
			if(aspas==0 && ehComando == 0){//as aspas estavam abertas, mas agora fechou e esta no valor do comando   "CEP":"11111-111"
				if(strcmp(comando,"aluguelOuVenda")==0){
					int numero = atoi(valor);
					(*informacoes).aluguelOuVenda = numero;
				}else if(strcmp(comando,"valor")==0){
					double numero = atof(valor);
					(*informacoes).valor = numero;
				}
				memset(comando, 0, sizeof(comando));
				memset(valor,0,sizeof(valor));
				index = 0;
				aspas = 1;
				//ehComando = 1;
			}else if(aspas==0 && ehComando == 1){ //as aspas estavam abertas, mas agora fechou e está no comando    "CEP"
				aspas = 1;
				//ehComando = 0;
				index = 0;
			}else if(aspas==1 && ehComando == 0){ //as aspas estavam fechadas, mas agora abriu e está no valor do comando     "
				aspas = 0;
				ehComando = 1;
				memset(comando, 0, sizeof(comando));
				memset(valor,0,sizeof(valor));
				index=0;
			}else if(aspas==1 && ehComando == 1){ //as aspas estavam fechadas, mas agora abriu e está no comando    "CEP":"
				aspas = 0;
				ehComando = 0;
			}
		}else if(endereco[i]=='{'){
			chave ++;
		}else if(endereco[i]=='}'){
			chave --;
			if(chave == 0){
				//mostrarInformacoes(&(*informacoes));
			}
		}else if(endereco[i] != '\n' && endereco[i] != ':' && endereco[i] != ','){
			if(ehComando){
				comando[index]=endereco[i];
			}else{
				valor[index]=endereco[i];
			}
			index ++;
		}
	}
}

void decodificadorEndereco(char endereco[],struct Endereco *novoEndereco, int tamanho){
	int ehComando = 0; //0 para não é comando | 1 para é comando
	int i;
	int aspas = 1; //0 aspas abertas | 1 aspas fechadas
	char comando[30];
	char valor[100];
	int index;
	int chave = 0;
	for(i=0;(i<tamanho && endereco[i]!='\0');i++){
		if(endereco[i]=='"'){
			if(aspas==0 && ehComando == 0){//as aspas estavam abertas, mas agora fechou e esta no valor do comando   "CEP":"11111-111"
				if(strcmp(comando,"rua")==0){
					strcpy((*novoEndereco).rua,valor);
				}else if(strcmp(comando,"numero")==0){
					int numero = atoi(valor);
					(*novoEndereco).numero = numero;
				}else if(strcmp(comando,"bairro")==0){
					strcpy((*novoEndereco).bairro,valor);
				}else if(strcmp(comando,"CEP")==0){
					strcpy((*novoEndereco).CEP,valor);
				}else if(strcmp(comando,"cidade")==0){
					strcpy((*novoEndereco).cidade,valor);
				}
				memset(comando, 0, sizeof(comando));
				memset(valor,0,sizeof(valor));
				index = 0;
				aspas = 1;
				//ehComando = 1;
			}else if(aspas==0 && ehComando == 1){ //as aspas estavam abertas, mas agora fechou e está no comando    "CEP"
				aspas = 1;
				//ehComando = 0;
				index = 0;
			}else if(aspas==1 && ehComando == 0){ //as aspas estavam fechadas, mas agora abriu e está no valor do comando     "
				aspas = 0;
				ehComando = 1;
				memset(comando, 0, sizeof(comando));
				memset(valor,0,sizeof(valor));
				index=0;
			}else if(aspas==1 && ehComando == 1){ //as aspas estavam fechadas, mas agora abriu e está no comando    "CEP":"
				aspas = 0;
				ehComando = 0;
			}
		}else if(endereco[i]=='{'){
			chave ++;
		}else if(endereco[i]=='}'){
			chave --;
			if(chave == 0){
				//mostrarEndereco(&(*novoEndereco));
			}
		}else if(endereco[i] != '\n' && endereco[i] != ':' && endereco[i] != ','){
			if(ehComando){
				comando[index]=endereco[i];
			}else{
				valor[index]=endereco[i];
			}
			index ++;
		}
	}	
}

int salvarCasa(struct Casa *casa){
	int retorno = 0;
	FILE *fp;
	char cas[800];
	strcpy(cas,codificarCasa(&(*casa)));
	if ((fp=fopen ("persistencia/casas.txt","a")) != NULL) {
		retorno = (fprintf(fp,cas)==EOF)?0:1;
 	}
 	fclose(fp);
 	
 	return retorno;

}

int salvarApartamento(struct Apartamento *apartamento){
	int retorno = 0;
	FILE *fp;
	char ap[800];
	strcpy(ap,codificarApartamento(&(*apartamento)));
	if ((fp=fopen ("persistencia/apartamentos.txt","a")) != NULL) {
		retorno = (fprintf(fp,ap)==EOF)?0:1;
 	}
 	fclose(fp);
 	
 	return retorno;
}

int salvarTerreno(struct Terreno *terreno){
	int retorno = 0;
	FILE *fp;
	char ter[800];
	strcpy(ter,codificarTerreno(&(*terreno)));
	if ((fp=fopen ("persistencia/terrenos.txt","a")) != NULL) {
		retorno = (fprintf(fp,ter)==EOF)?0:1;
 	}
 	fclose(fp);
 	
 	return retorno;
}

void mostrarCasasPorTipo(int tipo){
	int i;
	for(i=0;i<ultimoIndiceCasas;i++){
		if(casas[i].informacoes.aluguelOuVenda==tipo){
			mostrarCasa(&casas[i]);
		}
	}
}
void mostrarApartamentosPorTipo(int tipo){
	int i;
	for(i=0;i<ultimoIndiceApartamentos;i++){
		if(apartamentos[i].informacoes.aluguelOuVenda==tipo){
			mostrarApartamento(&apartamentos[i]);
		}
	}	
}
void mostrarTerrenosPorTipo(int tipo){
	int i;
	for(i=0;i<ultimoIndiceTerrenos;i++){
		if(terrenos[i].informacoes.aluguelOuVenda==tipo){
			mostrarTerreno(&terrenos[i]);
		}
	}
}
void mostrarInformacoes(struct Informacoes *informacoes){
	if((*informacoes).aluguelOuVenda == ALUGUEL){
		printf("Aluga-se\n");	
	}else{
		printf("Vende-se\n");
	}
	printf("Valor: R$ %.2lf\n",(*informacoes).valor);
}
void mostrarEndereco(struct Endereco *endereco){
	printf("Rua: %s\n",(*endereco).rua);
	printf("Numero: %d\n",(*endereco).numero);
	printf("Bairro: %s\n",(*endereco).bairro);
	printf("CEP: %s\n",(*endereco).CEP);
	printf("Cidade: %s\n",(*endereco).cidade);
}
void mostrarCasa(struct Casa *casa){
	printf("=====CASA=====\n");
	
	
	printf("%s\n",(*casa).tituloDoAnuncio);
	printf("Numero de Pavimentos: %d\n",(*casa).numeroDePavimentos);
	printf("Numero de Quartos: %d\n",(*casa).numeroDeQuartos);
	printf("Area do Terreno: %.1lf metros quadrados\n",(*casa).areaDoTerreno);
	printf("Area Construida: %.1lf metros quadrados\n",(*casa).areaConstruida);
	mostrarEndereco(&((*casa).endereco));
	mostrarInformacoes(&((*casa).informacoes));
}
void mostrarApartamento(struct Apartamento *apartamento){
	printf("=====APARTAMENTO=====\n");
	
	
	printf("%s\n",(*apartamento).tituloDoAnuncio);
	printf("Area: %.1lf metros quadrados\n",(*apartamento).area);
	printf("Numero de quartos: %d\n",(*apartamento).numeroDeQuartos);
	printf("Posicao: %s\n",(*apartamento).posicao);
	printf("Andar: %d\n",(*apartamento).andar);
	printf("Valor do condominio: R$ %.2lf\n",(*apartamento).valorDoCondominio);
	printf("Numero de vagas de garagem: %d\n",(*apartamento).numeroDeVagasDeGaragem);
	mostrarEndereco(&((*apartamento).endereco));
	mostrarInformacoes(&((*apartamento).informacoes));
}
void mostrarTerreno(struct Terreno *terreno){
	printf("=====TERRENO=====\n");
	
	
	printf("%s\n",(*terreno).tituloDoAnuncio);
	printf("Area: %.1lf metros quadrados\n",(*terreno).area);
	mostrarEndereco(&((*terreno).endereco));
	mostrarInformacoes(&((*terreno).informacoes));
}

void lerArquivoTerreno(){
	FILE *fp;
 	char c;
 	int n = 0;
	char terreno[800];
	
	int chaves = 0;
	
	/*
	char tituloDoAnuncio[30];
	double area;
	struct Endereco endereco;
	struct Informacoes informacoes;

	*/
	
	struct Terreno novosTerrenos;
	
	if ((fp=fopen ("persistencia/terrenos.txt","r")) != NULL) {
 		while( (c=fgetc(fp)) !=EOF) {
 			terreno[n] = c;
 			//printf("casa[%d] -> %c\n",n,c);
 			if(c == '{'){
 				chaves++;
 				n++;
			 }else if(c == '}'){
			 	chaves --;
			 	if(chaves == 0){
			 		//printf("Casa:\n%s",casa);
			 		decodificadorTerreno(terreno,&(novosTerrenos),800);
			 		terrenos[ultimoIndiceTerrenos] = novosTerrenos;
			 		
			 		memset(terreno, 0, sizeof(terreno));
			 		memset(novosTerrenos.tituloDoAnuncio, 0, sizeof(novosTerrenos.tituloDoAnuncio));
			 		
			 		memset(novosTerrenos.endereco.bairro, 0, sizeof(novosTerrenos.endereco.bairro));
			 		memset(novosTerrenos.endereco.CEP, 0, sizeof(novosTerrenos.endereco.CEP));
			 		memset(novosTerrenos.endereco.cidade, 0, sizeof(novosTerrenos.endereco.cidade));
			 		memset(novosTerrenos.endereco.rua, 0, sizeof(novosTerrenos.endereco.rua));
			 		ultimoIndiceTerrenos++;
			 		n=0;
				}else{
					n++;
				}
			}else{
				n++;
			}
 		}
	 	fclose(fp);
	 	menu();	
	}
}

void lerArquivoApartamento(){
	FILE *fp;
 	char c;
 	int n = 0;
	char ap[800];
	
	int chaves = 0;
	
	/*
	char tituloDoAnuncio[30];
	double area;
	int numeroDeQuartos;
	char posicao[50];
	int andar;
	double valorDoCondominio;
	int numeroDeVagasDeGaragem;
	struct Endereco endereco;
	struct Informacoes informacoes;

	*/
	
	struct Apartamento novosApartamentos;
	
	if ((fp=fopen ("persistencia/apartamentos.txt","r")) != NULL) {
 		while( (c=fgetc(fp)) !=EOF) {
 			ap[n] = c;
 			//printf("casa[%d] -> %c\n",n,c);
 			if(c == '{'){
 				chaves++;
 				n++;
			 }else if(c == '}'){
			 	chaves --;
			 	if(chaves == 0){
			 		//printf("Casa:\n%s",casa);
			 		decodificadorApartamento(ap,&(novosApartamentos),800);
			 		apartamentos[ultimoIndiceApartamentos] = novosApartamentos;
			 		
			 		memset(ap, 0, sizeof(ap));
			 		memset(novosApartamentos.tituloDoAnuncio, 0, sizeof(novosApartamentos.tituloDoAnuncio));
			 		memset(novosApartamentos.posicao, 0, sizeof(novosApartamentos.posicao));
			 		
			 		memset(novosApartamentos.endereco.bairro, 0, sizeof(novosApartamentos.endereco.bairro));
			 		memset(novosApartamentos.endereco.CEP, 0, sizeof(novosApartamentos.endereco.CEP));
			 		memset(novosApartamentos.endereco.cidade, 0, sizeof(novosApartamentos.endereco.cidade));
			 		memset(novosApartamentos.endereco.rua, 0, sizeof(novosApartamentos.endereco.rua));
			 		ultimoIndiceApartamentos++;
			 		n=0;
				}else{
					n++;
				}
			}else{
				n++;
			}
 		}
	 	fclose(fp);
	 	lerArquivoTerreno();
	}
}

void lerArquivoCasa(){
	FILE *fp;
 	char c;
 	int n = 0;
	char casa[800];
	
	int chaves = 0;
	
	struct Casa novasCasas;
	
	if ((fp=fopen ("persistencia/casas.txt","r")) != NULL) {
 		while( (c=fgetc(fp)) !=EOF) {
 			casa[n] = c;
 			//printf("casa[%d] -> %c\n",n,c);
 			if(c == '{'){
 				chaves++;
 				n++;
			 }else if(c == '}'){
			 	chaves --;
			 	if(chaves == 0){
			 		//printf("Casa:\n%s",casa);
			 		decodificadorCasa(casa,&(novasCasas),800);
			 		casas[ultimoIndiceCasas] = novasCasas;
			 		
			 		memset(casa, 0, sizeof(casa));
			 		memset(novasCasas.tituloDoAnuncio, 0, sizeof(novasCasas.tituloDoAnuncio));
			 		memset(novasCasas.endereco.bairro, 0, sizeof(novasCasas.endereco.bairro));
			 		memset(novasCasas.endereco.CEP, 0, sizeof(novasCasas.endereco.CEP));
			 		memset(novasCasas.endereco.cidade, 0, sizeof(novasCasas.endereco.cidade));
			 		memset(novasCasas.endereco.rua, 0, sizeof(novasCasas.endereco.rua));
			 		ultimoIndiceCasas++;
			 		n=0;
				}else{
					n++;
				}
			}else{
				n++;
			}
 		}
	 	fclose(fp);
	 	lerArquivoApartamento();
	}
}
