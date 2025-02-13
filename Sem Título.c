#include <stdio.h>   // Biblioteca padrão de entrada e saída
#include <stdlib.h>  // Biblioteca para funções auxiliares como system() e remove()
#include <locale.h>  // Biblioteca para configuração do idioma e reconhecimento de acentos
#include <string.h>  // Biblioteca para manipulação de strings

// Função para registrar um usuário e salvar seus dados em um arquivo
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
    
    printf("Digite sua profissão a ser cadastrada: ");
    scanf("%39s", profissao);
    file = fopen(arquivo, "a"); // Abre o arquivo para adicionar a profissão
    fprintf(file, "%s", profissao);
    fclose(file);
    
    printf("Usuário cadastrado com sucesso!\n");
    printf("Pressione Enter para continuar...");
    getchar(); getchar();
}

// Função para consultar um usuário no sistema
void consulta() {
    setlocale(LC_ALL, "Portuguese");
    char cpf[40], conteudo[300];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%39s", cpf);
    
    FILE *file = fopen(cpf, "r"); // Abre o arquivo do CPF para leitura
    if (file == NULL) {
        printf("Não foi possível localizar o arquivo.\n");
        return;
    }
    
    printf("\nEssas são as informações do usuário:\n");
    while (fgets(conteudo, sizeof(conteudo), file) != NULL) {
        printf("%s", conteudo); // Exibe os dados do usuário
    }
    fclose(file);
    
    printf("\nPressione Enter para continuar...");
    getchar(); getchar();
}

// Função para deletar um usuário do sistema
void deletar() {
    char cpf[40];
    
    printf("Digite o CPF a ser deletado: ");
    scanf("%39s", cpf);
    
    if (remove(cpf) == 0) {
        printf("Usuário deletado com sucesso.\n");
    } else {
        printf("Erro ao deletar usuário.\n");
    }
    
    printf("Pressione Enter para continuar...");
    getchar(); getchar();
}

// Função chamada quando o usuário escolhe uma opção inválida
void indisponivel() {
    printf("Essa opção não está disponível.\n");
    printf("Pressione Enter para continuar...");
    getchar(); getchar();
}

// Função principal que exibe o menu e gerencia as operações do sistema
int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao;
    
    while (1) {
        system("cls"); // Limpa a tela do terminal
        printf("\tCartório da EBAC\n\n");
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1- REGISTRAR NOMES\n");
        printf("\t2- CONSULTAR NOMES\n");
        printf("\t3- DELETAR NOMES\n");
        printf("\t4- Sair do sistema\n\n");
        printf("Opção: ");
        
        scanf("%d", &opcao);
        getchar(); // Para evitar problemas com o buffer de entrada

        switch (opcao) {
            case 1:
                registro(); // Chama a função de registro
                break;
            case 2:
                consulta(); // Chama a função de consulta
                break;
            case 3:
                deletar(); // Chama a função de deletar
                break;
            case 4:
                printf("Obrigado por utilizar o sistema.\n");
                return 0;
            default:
                indisponivel(); // Chama a função para opção inválida
                break;
        }
    }
}

