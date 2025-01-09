#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
int AcessarFuncao;
int Voltar;

struct Cards
{
    int id;
    char Titulo[20];
    char Descricao[20];
};
struct Bd
{
    struct Cards Tarefas[10];
    int ContadorDeTarefas;
    char TempArray[10];
};
struct Bd Banco;

VoltarPagAnterior() {
    int Voltar;
    printf("Envie 1 pra voltar e 0 para sair do programa:\n");
    scanf_s("%d", &Voltar);
    if (Voltar == 1) {
        main();
    }
    else {
        printf("Inicie o programa novamente.\n");
    }
}

int main()
{
    
    system("cls");
    printf("Digite o que você gostaria de fazer: \n");
    printf("1 - Criar \n");
    printf("2 - Editar \n");
    printf("3 - Excluir \n");
    printf("4 - Visualizar Todos \n");
    printf("5 - Visualizar por ID \n");
    printf("6 - Visualizar por Descricao \n");
    scanf_s("%d", &AcessarFuncao);
    while (getchar() != '\n');  

    switch (AcessarFuncao) {
    case 1:
        system("cls");
        printf("Você escolheu Criar Tarefa.\n");
        printf("Digite o titulo que voce deseja criar:\n");
        fgets(Banco.Tarefas[Banco.ContadorDeTarefas].Titulo, sizeof(Banco.Tarefas[Banco.ContadorDeTarefas].Titulo), stdin);
        printf("Digite a descricao que voce deseja criar:\n");
        fgets(Banco.Tarefas[Banco.ContadorDeTarefas].Descricao, sizeof(Banco.Tarefas[Banco.ContadorDeTarefas].Descricao), stdin);
        Banco.Tarefas[Banco.ContadorDeTarefas].id = Banco.ContadorDeTarefas;
        printf("Tarefa Criada com SUCESSO o  id e %i:\n", Banco.Tarefas[Banco.ContadorDeTarefas].id);
        Banco.ContadorDeTarefas++;
          printf("Envie 1 pra voltar e 0 para continuar criando :\n");
             scanf_s("%d", &Voltar);
            if (Voltar == 1) {
             main();
    }
        break;
    case 2:
        system("cls");
        printf("Você escolheu Editar Tarefa.\n");
        int LocalizaEdit;
        printf("-------------------- Editar -------------------\n");
        printf("Digite o id do card a ser alterado\n");
        scanf_s("%d", &LocalizaEdit);
    
        break;
    case 3:
        system("cls");
        printf("Você escolheu Excluir.\n");
         
        break;
    case 4:
         printf("Você escolheu Visualizar todos.\n");
         int *PonteiroContador;
         char *PonteiroTitulo;
         char *PonteiroDescricao;
    
        for (int i = 0; i < Banco.ContadorDeTarefas; i++) {
            PonteiroContador = &Banco.Tarefas[i].id;
            PonteiroTitulo  = &Banco.Tarefas[i].Titulo;
            PonteiroDescricao = &Banco.Tarefas[i].Descricao;
            printf("Quantidade de tarefas: %d\n", *PonteiroContador);
            printf("Titulo: %s\n", PonteiroTitulo);    
            printf("Descricao: %s\n", PonteiroDescricao);
        }
         
        break;
    case 5:
        system("cls");
        printf("Você escolheu Visualizar por ID.\n");
        int *FiltarId = malloc(10 * sizeof(char));
        scanf_s("%d", &FiltarId);
        int Voltar;
        printf("Teste: %d\n", FiltarId);
        
      for(int i = 0; i < Banco.ContadorDeTarefas; i++) {
            if (FiltarId == Banco.Tarefas[i].id) {
                printf("Id %i\n", Banco.Tarefas[i].id);
                printf("Titulo %s\n", Banco.Tarefas[i].Titulo);
                printf("Descrcao %s\n", Banco.Tarefas[i].Descricao);
            }
      }

      VoltarPagAnterior();
        
        
        break;
    case 6:
        system("cls");
        printf("Você escolheu Visualizar por Descrição.\n");
      
        break;
    default:
        system("cls");
        printf("Opção inválida. Tente novamente.\n");
        break;
    }
}
