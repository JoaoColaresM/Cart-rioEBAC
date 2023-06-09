#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável pelas strings

int registro() // função responsável por criar variáveis/strings
{
    char arquivo[40]; // início criação de string
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40]; // final criação de string
        
    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf); // coletando informações do usuário / %s referi-se à string

    strcpy(arquivo,cpf); // responsável por copiar os valores da string

    FILE *arq; // cria o arquivo (arq) no computador
    arq = fopen(arquivo, "w"); // abrir arquivo (fopen) e escrever "w"
    fprintf(arq,"CPF: %s", cpf); // salva o valor da variável cpf no arquivo
    fclose(arq); // fecha o arquivo

    arq = fopen(arquivo, "a"); // abrir arquivo (fopen) e acrescentar "a"
    fprintf(arq, ", "); // informação acrescentada no arquivo
    fclose(arq); // fecha o arquivo

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome); // coletando informações do usuário / %s referi-se à string

    arq = fopen(arquivo, "a"); // abrir arquivo (fopen) e acrescentar "a"
    fprintf(arq, "Nome: %s" ,nome); // salva o valor da variável nome no arquivo
    fclose(arq); // fecha o arquivo
        
    arq = fopen(arquivo, "a"); // abrir arquivo (fopen) e acrescentar "a"
    fprintf(arq, ", "); // informação acrescentada no arquivo
    fclose(arq); // fecha o arquivo
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome); // coletando informações do usuário / %s referi-se à string

    arq = fopen(arquivo, "a"); // abrir arquivo (fopen) e acrescentar "a"
    fprintf(arq, "Sobrenome: %s",sobrenome); // salva o valor da variável sobrenome no arquivo
    fclose(arq); // fecha o arquivo

    arq = fopen(arquivo, "a"); // abrir arquivo (fopen) e acrescentar "a"
    fprintf(arq, ", ");
    fclose(arq); // fecha o arquivo

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo); // coletando informações do usuário / %s referi-se à string

    arq = fopen(arquivo, "a"); // abrir arquivo (fopen) e acrescentar "a"
    fprintf(arq, "Cargo: %s",cargo); // salva o valor da variável cargo no arquivo
    fclose(arq); // fecha o arquivo
    
    printf("\nFim do cadastro.\n");
   
    system( "read -n 1 -s -p \"Pressione uma tecla...\"" ); // system("pause") do macOS
    return 0;
}
int consulta()
{
    setlocale(LC_ALL, "Portuguese"); // definino lingua
    char cpf [40]; // declarando strings
    char conteudo [200];

    printf("Digite o CPF para consulta: ");
    scanf("%s", cpf); // coletando informações do usuário / %s referi-se à string

    FILE *arq;
    arq = fopen(cpf, "r");

    if(arq == NULL)
    {
        printf("CPF não encontrado!\n");
        system( "read -n 1 -s -p \"Pressione uma tecla...\"" );
        return 0;
    }

    while(fgets(conteudo, 200, arq) != NULL)
    {
        printf("Informações do usuário:\n%s\n", conteudo);
    }
    
    fclose(arq);
    system( "read -n 1 -s -p \"Pressione uma tecla...\"" );

    return 0;
}
int deletar()
{
    char cpf[40];

    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);

    FILE *arq;
    arq = fopen(cpf, "r");

    if(arq == NULL)
    {
        printf("CPF não encontrado!\n");
    }
    else
    {
        printf("CPF %s será deletado\n", cpf);
        remove(cpf);
    }
    
    fclose(arq);
    system( "read -n 1 -s -p \"Pressione uma tecla...\"" );

    return 0;
}
int indisponivel()
{
    printf("opção não disponível\n\n");
    system( "read -n 1 -s -p \"Pressione uma tecla...\"" );

    return 0;
}
int sair()
{
    printf("Obrigado por utilizar o sistma!\n\n");
    system( "read -n 1 -s -p \"Pressione uma tecla...\"" );

    return 0;
}

int main()
{   system("clear");

    int opcao = 0; // definino variáveis
    int laco = 1;
    char senha[10] = "admin";
    char senhadigitada[10] = "";

    printf("### Cartório da EBAC ###\n\n");
    printf("digite a senha:\n");
    scanf("%s", senhadigitada);
    int comparacao = strcmp(senha, senhadigitada);

    if (comparacao == 0)
    {
        for(laco=1;laco==1;)
        {
            system("clear");
            setlocale(LC_ALL, "Portuguese"); // definino lingua
            
            printf("### Cartório da EBAC ###\n\n"); // início do menu
            printf("Escolha as opções do menu:\n\n");
            printf("\t1 - Registrar nomes\n");
            printf("\t2 - Consultar nomes\n");
            printf("\t3 - Deletar nomes\n");
            printf("\t4 - Sair do sistema\n\n");
            printf("Opção: "); // final do menu

            scanf("%d", &opcao); // armazenando a escolha do usuário
            system("clear");
        
            switch (opcao)
            {
                case 1:
                registro();
                break;
                
                case 2:
                consulta();
                break;
            
                case 3:
                deletar();
                break;

                case 4:
                sair();
                return 0;
                break;
                
                default:
                indisponivel();
                break;
            } 
        }
    }
    else {
    printf("Senha incorreta!\n");
    system( "read -n 1 -s -p \"Pressione uma tecla...\"" );
    main();
    }
}