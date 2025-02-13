#include <stdio.h>   // Biblioteca padr�o de entrada e sa�da
#include <stdlib.h>  // Biblioteca para fun��es auxiliares como system() e remove()
#include <locale.h>  // Biblioteca para configura��o do idioma e reconhecimento de acentos
#include <string.h>  // Biblioteca para manipula��o de strings

// Fun��o para registrar um usu�rio e salvar seus dados em um arquivo
void registro() {
    setlocale(LC_ALL, "Portuguese");
    
    char arquivo[40], cpf[40], nome[40], sobrenome[40], profissao[40];
    
    printf("Digite o CPF a ser cadastrado: ");
    scanf("%39s", cpf);
    strcpy(arquivo, cpf);
    
    FILE *file = fopen(arquivo, "w"); // Cria um arquivo com o nome do CPF
    if (file == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }
    fprintf(file, "%s,", cpf); // Escreve o CPF no arquivo
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%39s", nome);
    file = fopen(arquivo, "a"); // Abre o arquivo para adicionar o nome
    fprintf(file, "%s ", nome);
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%39s", sobrenome);
    file = fopen(arquivo, "a"); // Abre o arquivo para adicionar o sobrenome
    fprintf(file, "%s,", sobrenome);
    fclose(file);
    
    printf("Digite sua profiss�o a ser cadastrada: ");
    scanf("%39s", profissao);
    file = fopen(arquivo, "a"); // Abre o arquivo para adicionar a profiss�o
    fprintf(file, "%s", profissao);
    fclose(file);
    
    printf("Usu�rio cadastrado com sucesso!\n");
    printf("Pressione Enter para continuar...");
    getchar(); getchar();
}

// Fun��o para consultar um usu�rio no sistema
void consulta() {
    setlocale(LC_ALL, "Portuguese");
    char cpf[40], conteudo[300];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%39s", cpf);
    
    FILE *file = fopen(cpf, "r"); // Abre o arquivo do CPF para leitura
    if (file == NULL) {
        printf("N�o foi poss�vel localizar o arquivo.\n");
        return;
    }
    
    printf("\nEssas s�o as informa��es do usu�rio:\n");
    while (fgets(conteudo, sizeof(conteudo), file) != NULL) {
        printf("%s", conteudo); // Exibe os dados do usu�rio
    }
    fclose(file);
    
    printf("\nPressione Enter para continuar...");
    getchar(); getchar();
}

// Fun��o para deletar um usu�rio do sistema
void deletar() {
    char cpf[40];
    
    printf("Digite o CPF a ser deletado: ");
    scanf("%39s", cpf);
    
    if (remove(cpf) == 0) {
        printf("Usu�rio deletado com sucesso.\n");
    } else {
        printf("Erro ao deletar usu�rio.\n");
    }
    
    printf("Pressione Enter para continuar...");
    getchar(); getchar();
}

// Fun��o chamada quando o usu�rio escolhe uma op��o inv�lida
void indisponivel() {
    printf("Essa op��o n�o est� dispon�vel.\n");
    printf("Pressione Enter para continuar...");
    getchar(); getchar();
}

// Fun��o principal que exibe o menu e gerencia as opera��es do sistema
int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao;
    
    while (1) {
        system("cls"); // Limpa a tela do terminal
        printf("\tCart�rio da EBAC\n\n");
        printf("Escolha a op��o desejada do menu:\n\n");
        printf("\t1- REGISTRAR NOMES\n");
        printf("\t2- CONSULTAR NOMES\n");
        printf("\t3- DELETAR NOMES\n");
        printf("\t4- Sair do sistema\n\n");
        printf("Op��o: ");
        
        scanf("%d", &opcao);
        getchar(); // Para evitar problemas com o buffer de entrada

        switch (opcao) {
            case 1:
                registro(); // Chama a fun��o de registro
                break;
            case 2:
                consulta(); // Chama a fun��o de consulta
                break;
            case 3:
                deletar(); // Chama a fun��o de deletar
                break;
            case 4:
                printf("Obrigado por utilizar o sistema.\n");
                return 0;
            default:
                indisponivel(); // Chama a fun��o para op��o inv�lida
                break;
        }
    }
}

