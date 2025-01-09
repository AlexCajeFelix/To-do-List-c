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
    printf("Envie 1 pra voltar e 0 para sair do programa:\n");
    scanf_s("%d", &Voltar);
    if (Voltar == 1) {
        main();
    }
    else {
        printf("Inicie o programa novamente.\n");
    }
}
CriarTarefa() {
    printf("Digite o titulo que voce deseja criar:\n");
    fgets(Banco.Tarefas[Banco.ContadorDeTarefas].Titulo, sizeof(Banco.Tarefas[Banco.ContadorDeTarefas].Titulo), stdin);
    printf("Digite a descricao que voce deseja criar:\n");
    fgets(Banco.Tarefas[Banco.ContadorDeTarefas].Descricao, sizeof(Banco.Tarefas[Banco.ContadorDeTarefas].Descricao), stdin);
    Banco.Tarefas[Banco.ContadorDeTarefas].id = Banco.ContadorDeTarefas;
    printf("Tarefa Criada com SUCESSO o  id e %i:\n", Banco.Tarefas[Banco.ContadorDeTarefas].id);
    Banco.ContadorDeTarefas++;
    VoltarPagAnterior();
}
EditarTarefa() {
    int LocalizaEdit;
    printf("-------------------- Editar -------------------\n");
    printf("Digite o id do card a ser alterado\n");
    scanf_s("%d", &LocalizaEdit);
    while (getchar() != '\n');

    for (int i = 0; i < Banco.ContadorDeTarefas; i++) {
        if (LocalizaEdit == Banco.Tarefas[i].id) {
            printf("Digite o titulo que voce deseja editar:\n");
            fgets(Banco.Tarefas[i].Titulo, sizeof(Banco.Tarefas[i].Descricao), stdin);
            printf("Digite a descricao que voce deseja editar:\n");
            fgets(Banco.Tarefas[i].Descricao, sizeof(Banco.Tarefas[i].Descricao), stdin);
        }
    }
    VoltarPagAnterior();
}
Excluir() {
    printf("--------------------Excluir -------------------\n");
    printf("Digite o ID desejado para excluir: ");
    int ExcluirId;
    scanf_s("%d", &ExcluirId);  
    int i, j = 0;
    int tarefaEncontrada = 0;

    for (i = 0; i < Banco.ContadorDeTarefas; i++) {
        if (Banco.Tarefas[i].id != ExcluirId) {

            Banco.Tarefas[j++] = Banco.Tarefas[i];
        }
        else {
            tarefaEncontrada = 1; 
        }
    }
    if (tarefaEncontrada) {
        Banco.ContadorDeTarefas = j; 
        printf("Tarefa com ID %d foi excluída com sucesso!\n", ExcluirId);
    }
    else {
        printf("Tarefa com ID %d não encontrada.\n", ExcluirId);
    }
    VoltarPagAnterior();
}
VisualizarTodos() {
    printf("--------------------Vsualizar todos -------------------\n");
    for (int i = 0; i < Banco.ContadorDeTarefas; i++) {
        printf("Id %i\n", Banco.Tarefas[i].id);
        printf("Titulo %s\n", Banco.Tarefas[i].Titulo);
        printf("Descrcao %s\n", Banco.Tarefas[i].Descricao);
    }
    VoltarPagAnterior();
}
VisualizarporID() {
    int LocalizaId;
    printf("--------------------Vsualizar por ID -------------------\n");
    printf("Digite o ID desejado\n");
    scanf_s("%d", &LocalizaId);
    if (LocalizaId == Banco.Tarefas[LocalizaId].id) {
        printf("Id %i\n", Banco.Tarefas[LocalizaId].id);
        printf("Titulo %s\n", Banco.Tarefas[LocalizaId].Titulo);
        printf("Descrcao %s\n", Banco.Tarefas[LocalizaId].Descricao);
    }
    else
    {
        printf("Esse id não existe!");
    }
    VoltarPagAnterior();
}
VisualizarporDescricao() {
    
    printf ("--------------------Vsualizar por Descrção -------------------\n");
    printf("Digite a descricao que voce deseja filtrar\n");

    char *FiltarDescricao = malloc(10 * sizeof(char));
    fgets(FiltarDescricao, 100, stdin);
   
    FiltarDescricao[strcspn(FiltarDescricao, "\n")] = '\0';

    for (int i = 0; i < Banco.ContadorDeTarefas; i++) {
       if(strstr(Banco.Tarefas[i].Descricao, FiltarDescricao) != NULL) {
            printf("Id %i\n", Banco.Tarefas[i].id);
            printf("Titulo %s\n", Banco.Tarefas[i].Titulo);
            printf("Descrcao %s\n", Banco.Tarefas[i].Descricao);
        }
    }
    VoltarPagAnterior();
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
        CriarTarefa();
        break;
    case 2:
        system("cls");
        printf("Você escolheu Editar Tarefa.\n");
        EditarTarefa();
        break;
    case 3:
        system("cls");
        printf("Você escolheu Excluir.\n");
        Excluir();
        break;
    case 4:
        VisualizarTodos();
        break;
    case 5:
        system("cls");
        printf("Você escolheu Visualizar por ID.\n");
        VisualizarporID();
        break;
    case 6:
        system("cls");
        printf("Você escolheu Visualizar por Descrição.\n");
        VisualizarporDescricao();
        break;
    default:
        system("cls");
        printf("Opção inválida. Tente novamente.\n");
        break;
    }
}
