// Rafael Bonfim Zacco

/*
Sua  tarefa  será  construir  um  código  capaz de  somar,  item  a  item,  todos os  inteiros  entre  1  e 
1.000.000. Existe, pelo menos uma fórmula matemática que pode ser usada para validar o resultado. 
Contudo,  você  deverá  criar  uma  pilha,  armazenar  este  inteiros  nesta  pilha,  depois  percorrer    pilha 
somando estes valores. A tarefa é para exercitar o uso de pilhas, não da matemática.  

Seu  objetivo  será  medir  o  tempo  para  inserção  de  1.000.000  milhão  de  inteiros  em  uma 
estrutura  de  dados  e  o  tempo  para  percorrer  e  somar  1.000.000  de  inteiros  em  uma  determinada 
estrutura de dados, e o tempo para garantir que um determinado inteiro já está na pilha. Finalmente 
você deverá medir estes tempos percorrendo a pilha em dois sentidos. De cima para baixo e de baixo 
para cima. 

Seu resultado será a média dos tempos gastos para as operações citadas acima em, no mímino 
50 operações de cada tipo. As saídas apresentadas devem seguir o seguinte padrão: operação: tempo 
conforme pode ser visto no exemplo a seguir: 

Preenchimento da Pilha: 1.234s 

Programas cuja saída tenham linhas que não sejam relativas as operações realizadas ou que não 
apresentem a formatação correta sofrerão um demérito na nota. 

Para resolver esta tarefa você poderá usar as linguagens Python, Java, C ou C++ de acordo com 
a  sua  preferência.  A  tarefa  deverá  ser  entregue  no  ambiente  virtual  de  aprendizagem  conforme  as 
instruções constante neste documento.

Lembre-se: uma estrutura de dados consiste em uma definição de estrutura de memória, e dos 
métodos,  ou  funções  para  trabalhar  com  esta  estrutura.  No  mínimo  teremos  que  ter  métodos  para 
escrever, ler, remover e buscar valores na pilha. Programas que realizem as tarefas necessárias sem a 
definição da estrutura de dados serão zerados.
*/

#include <stdbool.h>
#include <stdio.h>
#include <time.h>

int pilha[1000000];
int final;

void criarPilha() {
    final = -1;
}

bool pilhaVazia() {
    if (final == -1){
        return true;
    }
    else{
        return false;
    }
}

bool pilhaCheia() {
    if (final == 1000000-1){
        return true;
    }
    else{
        return false;
    }
}

bool escreverPilha(int valor) {
    if (pilhaCheia()){
        return false;
    }
    else{
        final++;
        pilha[final] = valor;
        return true;
    }
}

bool removerPilha() {
    if (pilhaVazia()){
        return false;
    }
    else{
        final--;
        return true;
    }
}

int lerPilha() {
    if (pilhaVazia()){
        printf("\nA pilha esta vazia\n");
        return 0;
    }
    else{
        return pilha[final];
    }
}

void buscarPilha(){
    int i;

    for(i=0;i<1000000;i++){
        if (pilha[i] != i+1){
            printf("Valor não está no local certo");
        }
    }
    for(i=999999;i>=0;i--){
        if (pilha[i] != i+1){
            printf("Valor não está no local certo");
        }
    }
}

int main () {

    int i, j;
    double media, soma;
    double media_parcial = 0;
    clock_t tictac;

    criarPilha();

    for (j=0 ; j<=50 ; j++){
        tictac = clock();
        for (i=1 ; i<=1000000 ; i++){
            escreverPilha(i);
        }
        tictac = clock() - tictac;
        media_parcial = media_parcial + ((double)tictac)/CLOCKS_PER_SEC;

        for (i=1 ; i<=1000000 ; i++){
            removerPilha();
        }
    }
    media = media_parcial/50;
    printf("Preenchimento da Pilha: %fs",media);

    for (j=0 ; j<=50 ; j++){
        soma = 0;
        tictac = clock();
        for (i=0 ; i<1000000 ; i++){
            soma += pilha[i];
        }
        tictac = clock() - tictac;
        media_parcial = media_parcial + ((double)tictac)/CLOCKS_PER_SEC;
    }
    media = media_parcial/50;
    printf("\nPercorrer e somar: %fs",media);

    for (j=0 ; j<=50 ; j++){
        tictac = clock();
        buscarPilha();
        tictac = clock() - tictac;
        media_parcial = media_parcial + ((double)tictac)/CLOCKS_PER_SEC;
    }
    media = media_parcial/50;
    printf("\nBuscar valores: %fs",media);

    return 0;
}