To-do-List-c
Um gerenciador de tarefas simples feito em C

Objetivo
Treinar habilidades em linguagem C e estimular a prática de lógica de programação, incluindo manipulação de estruturas, arrays e fluxos condicionais.

Funcionalidades
1. Criar Tarefas
Permite criar tarefas com os seguintes atributos:

Título: Exemplo - "Lavar a louça".
Descrição: Exemplo - "Usar o detergente de limão".
Cada tarefa recebe um identificador único (ID) baseado na ordem de criação.

2. Editar Tarefas
O usuário pode editar uma tarefa existente fornecendo o ID.
O programa acessa o índice correspondente no array e permite modificar os campos de título e descrição.


3. Excluir Tarefas
A lógica de exclusão é feita usando um loop.

Inicialização:

É criada uma variável chamada encontrado, que inicia com o valor 0.
Essa variável verifica se a tarefa foi ou não localizada no array.
Busca pelo ID:

O programa percorre o array de tarefas.
Se o ID de uma tarefa no array for diferente do ID fornecido, a tarefa é mantida.
Se o ID coincidir, o programa "remove" a tarefa ajustando os índices do array.
Ajuste do Array:

O índice do array é reorganizado para preencher o espaço deixado pela tarefa excluída.
Isso é feito com uma variável auxiliar j, que gerencia os índices ajustados.
Resultado:

Se o valor de encontrado for alterado para 1, significa que a tarefa foi excluída com sucesso.
Caso contrário, o programa informa que a tarefa não foi encontrada.

