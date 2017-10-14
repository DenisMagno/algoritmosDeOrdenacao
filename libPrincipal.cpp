#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "libPrincipal.h"
#include "algoritmosOrdenacao/heapSort.h"
#include "algoritmosOrdenacao/bubbleSort.h"
#include "algoritmosOrdenacao/insertionSort.h"
#include "algoritmosOrdenacao/quickSort.h"
#include "algoritmosOrdenacao/selectionSort.h"
#include "algoritmosOrdenacao/shellSort.h"
#include "algoritmosOrdenacao/mergeSort.h"

int *aloca_vetor(int n, int tipo){
    int *vetor;

    vetor = (int*) malloc(n*sizeof(int));
    if(vetor != NULL){
        int i;

        switch(tipo){
            //Vetor desordenado randomico
            case 1:
                for(i = 0; i < n; i++){
                    vetor[i] = rand() % 100000;
                }
            break;

            //Vetor ordenado ordem crescente
            case 2:
                for(i = 0; i < n; i++){
                    vetor[i] = i;
                }
            break;

            //Vetor ordenado ordem decrescente
            case 3:
                for(i = 0; i < n; i++){
                    vetor[i] = n-i;
                }
            break;
        }
    }
    return vetor;
}

void libera_vetor(int *vetor){
    free(vetor);
}

void aguarda_enter(){
    printf("\n\nDigite <enter> para continuar...");
    getchar();
    getchar();
}

void imprime_menu(){
    system("cls");

    printf("/___An�lise de Algoritmos de Ordena��o___\\\n");
    printf("|                                        |\n");
    printf("|***** DEFINA A QUANTIDADE DO VETOR *****|\n");
    printf("|                                        |\n");
    printf("| 1 - 1000 elementos                     |\n");
    printf("| 2 - 5000 elementos                     |\n");
    printf("| 3 - 10000 elementos                    |\n");
    printf("| 4 - 20000 elementos                    |\n");
    printf("| 5 - 50000 elementos                    |\n");
    printf("| 6 - 100000 elementos                   |\n");
    printf("|                                        |\n");
    printf("| 0 - Sair                               |\n");
    printf("|                                        |\n");
    printf("\\----------------------------------------/\n");
}

int solicita_opcao(){
    int opt, cont = 0;

    do{ //Roda do while at� digitar uma op��o v�lida.
        if(cont > 0){
            printf("\nOp��o inv�lida! Digite a op��o desejada: ");
            scanf("%d", &opt);
        }else{
            printf("\nDigite a op��o desejada: ");
            scanf("%d", &opt);
        }

        cont++;
    }while(opt < 0 || opt > 6);

    return opt;
}

void redireciona_para_opcao(int opt){
    switch(opt){ //Verifica qual op��o foi selecionada e redireciona para m�dulos respons�veis pela execu��o.
        case 1:
            analisaAlgoritmos(1000);
            aguarda_enter();
        break;

        case 2:
            analisaAlgoritmos(5000);
            aguarda_enter();
        break;

        case 3:
            analisaAlgoritmos(10000);
            aguarda_enter();
        break;

        case 4:
            analisaAlgoritmos(20000);
            aguarda_enter();
        break;

        case 5:
            analisaAlgoritmos(50000);
            aguarda_enter();
        break;

        case 6:
            analisaAlgoritmos(100000);
            aguarda_enter();
        break;

        case 0:
            printf("At� mais!");
            aguarda_enter();
            exit(1);
        break;
    }
}

/**Fun��es de ordena��o com vetores desosordenados rand�micamente**/
double analisaHeap(int tamanho){
    int i;
    double media = 0, tf, ti;
    timeval tempo_inicio, tempo_fim;

    int *vetor;
    for(i = 0; i < 10; i++){
        //Marca in�cio do tempo de execu��o
        gettimeofday(&tempo_inicio, NULL);

        vetor = aloca_vetor(tamanho, 1);
        //Algoritmo de ordena��o
        heapSort(vetor, tamanho);
        libera_vetor(vetor);

        //Marca fim do tempo de execu��o
        gettimeofday(&tempo_fim, NULL);

        //Filtra o valor recebido pela fun��o de tempo atribui nas variaveis
        tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
        ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));


        media = media + ((tf - ti) / 1000);
    }
    media = media / 10;

    return media;
}

double analisaBubble(int tamanho){
    int i;
    double media = 0, tf, ti;
    timeval tempo_inicio, tempo_fim;

    int *vetor;
    for(i = 0; i < 10; i++){
        //Marca in�cio do tempo de execu��o
        gettimeofday(&tempo_inicio, NULL);

        vetor = aloca_vetor(tamanho, 1);
        //Algoritmo de ordena��o
        bubbleSort(vetor, tamanho);
        libera_vetor(vetor);

        //Marca fim do tempo de execu��o
        gettimeofday(&tempo_fim, NULL);

        //Filtra o valor recebido pela fun��o de tempo atribui nas variaveis
        tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
        ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));


        media = media + ((tf - ti) / 1000);
    }
    media = media / 10;

    return media;
}

double analisaInsertion(int tamanho){
    int i;
    double media = 0, tf, ti;
    timeval tempo_inicio, tempo_fim;

    int *vetor;
    for(i = 0; i < 10; i++){
        //Marca in�cio do tempo de execu��o
        gettimeofday(&tempo_inicio, NULL);

        vetor = aloca_vetor(tamanho, 1);
        //Algoritmo de ordena��o
        insertionSort(vetor, tamanho);
        libera_vetor(vetor);

        //Marca fim do tempo de execu��o
        gettimeofday(&tempo_fim, NULL);

        //Filtra o valor recebido pela fun��o de tempo atribui nas variaveis
        tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
        ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));


        media = media + ((tf - ti) / 1000);
    }
    media = media / 10;

    return media;
}

double analisaQuick(int tamanho){
    int i;
    double media = 0, tf, ti;
    timeval tempo_inicio, tempo_fim;

    int *vetor;
    for(i = 0; i < 10; i++){
        //Marca in�cio do tempo de execu��o
        gettimeofday(&tempo_inicio, NULL);

        vetor = aloca_vetor(tamanho, 1);
        //Algoritmo de ordena��o
        quickSort(vetor, 0, tamanho - 1);
        libera_vetor(vetor);

        //Marca fim do tempo de execu��o
        gettimeofday(&tempo_fim, NULL);

        //Filtra o valor recebido pela fun��o de tempo atribui nas variaveis
        tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
        ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));


        media = media + ((tf - ti) / 1000);
    }
    media = media / 10;

    return media;
}

double analisaSelection(int tamanho){
    int i;
    double media = 0, tf, ti;
    timeval tempo_inicio, tempo_fim;

    int *vetor;
    for(i = 0; i < 10; i++){
        //Marca in�cio do tempo de execu��o
        gettimeofday(&tempo_inicio, NULL);

        vetor = aloca_vetor(tamanho, 1);
        //Algoritmo de ordena��o
        selectionSort(vetor, tamanho);
        libera_vetor(vetor);

        //Marca fim do tempo de execu��o
        gettimeofday(&tempo_fim, NULL);

        //Filtra o valor recebido pela fun��o de tempo atribui nas variaveis
        tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
        ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));


        media = media + ((tf - ti) / 1000);
    }
    media = media / 10;

    return media;
}

double analisaShell(int tamanho){
    int i;
    double media = 0, tf, ti;
    timeval tempo_inicio, tempo_fim;

    int *vetor;
    for(i = 0; i < 10; i++){
        //Marca in�cio do tempo de execu��o
        gettimeofday(&tempo_inicio, NULL);

        vetor = aloca_vetor(tamanho, 1);
        //Algoritmo de ordena��o
        shellSort(vetor, tamanho);
        libera_vetor(vetor);

        //Marca fim do tempo de execu��o
        gettimeofday(&tempo_fim, NULL);

        //Filtra o valor recebido pela fun��o de tempo atribui nas variaveis
        tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
        ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));


        media = media + ((tf - ti) / 1000);
    }
    media = media / 10;

    return media;
}

double analisaMerge(int tamanho){
    int i;
    double media = 0, tf, ti;
    timeval tempo_inicio, tempo_fim;

    int *vetor;
    for(i = 0; i < 10; i++){
        //Marca in�cio do tempo de execu��o
        gettimeofday(&tempo_inicio, NULL);

        vetor = aloca_vetor(tamanho, 1);
        //Algoritmo de ordena��o
        mergeSort(vetor, 0, tamanho-1);
        libera_vetor(vetor);

        //Marca fim do tempo de execu��o
        gettimeofday(&tempo_fim, NULL);

        //Filtra o valor recebido pela fun��o de tempo atribui nas variaveis
        tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
        ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));


        media = media + ((tf - ti) / 1000);
    }
    media = media / 10;

    return media;
}

/**Fun��es de ordena��o com vetores ordenados em ordem crescente**/
double analisaOrdenadoCHeap(int tamanho){
    double tf, ti, tempo;
    timeval tempo_inicio, tempo_fim;

    int *vetor;
    //Marca in�cio do tempo de execu��o
    gettimeofday(&tempo_inicio, NULL);

    vetor = aloca_vetor(tamanho, 2);
    //Algoritmo de ordena��o
    heapSort(vetor, tamanho);
    libera_vetor(vetor);

    //Marca fim do tempo de execu��o
    gettimeofday(&tempo_fim, NULL);

    //Filtra o valor recebido pela fun��o de tempo atribui nas variaveis
    tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
    ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));

    tempo = (tf - ti) / 1000;

    return tempo;
}

double analisaOrdenadoCBubble(int tamanho){
    double tf, ti, tempo;
    timeval tempo_inicio, tempo_fim;

    int *vetor;
    //Marca in�cio do tempo de execu��o
    gettimeofday(&tempo_inicio, NULL);

    vetor = aloca_vetor(tamanho, 2);
    //Algoritmo de ordena��o
    bubbleSort(vetor, tamanho);
    libera_vetor(vetor);

    //Marca fim do tempo de execu��o
    gettimeofday(&tempo_fim, NULL);

    //Filtra o valor recebido pela fun��o de tempo atribui nas variaveis
    tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
    ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));

    tempo = (tf - ti) / 1000;

    return tempo;
}

double analisaOrdenadoCInsertion(int tamanho){
    double tf, ti, tempo;
    timeval tempo_inicio, tempo_fim;

    int *vetor;
    //Marca in�cio do tempo de execu��o
    gettimeofday(&tempo_inicio, NULL);

    vetor = aloca_vetor(tamanho, 2);
    //Algoritmo de ordena��o
    insertionSort(vetor, tamanho);
    libera_vetor(vetor);

    //Marca fim do tempo de execu��o
    gettimeofday(&tempo_fim, NULL);

    //Filtra o valor recebido pela fun��o de tempo atribui nas variaveis
    tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
    ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));

    tempo = (tf - ti) / 1000;

    return tempo;
}

double analisaOrdenadoCQuick(int tamanho){
    double tf, ti, tempo;
    timeval tempo_inicio, tempo_fim;

    int *vetor;
    //Marca in�cio do tempo de execu��o
    gettimeofday(&tempo_inicio, NULL);

    vetor = aloca_vetor(tamanho, 2);
    //Algoritmo de ordena��o
    quickSort(vetor, 0, tamanho-1);
    libera_vetor(vetor);

    //Marca fim do tempo de execu��o
    gettimeofday(&tempo_fim, NULL);

    //Filtra o valor recebido pela fun��o de tempo atribui nas variaveis
    tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
    ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));

    tempo = (tf - ti) / 1000;

    return tempo;
}

double analisaOrdenadoCSelection(int tamanho){
    double tf, ti, tempo;
    timeval tempo_inicio, tempo_fim;

    int *vetor;
    //Marca in�cio do tempo de execu��o
    gettimeofday(&tempo_inicio, NULL);

    vetor = aloca_vetor(tamanho, 2);
    //Algoritmo de ordena��o
    selectionSort(vetor, tamanho);
    libera_vetor(vetor);

    //Marca fim do tempo de execu��o
    gettimeofday(&tempo_fim, NULL);

    //Filtra o valor recebido pela fun��o de tempo atribui nas variaveis
    tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
    ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));

    tempo = (tf - ti) / 1000;

    return tempo;
}

double analisaOrdenadoCShell(int tamanho){
    double tf, ti, tempo;
    timeval tempo_inicio, tempo_fim;

    int *vetor;
    //Marca in�cio do tempo de execu��o
    gettimeofday(&tempo_inicio, NULL);

    vetor = aloca_vetor(tamanho, 2);
    //Algoritmo de ordena��o
    shellSort(vetor, tamanho);
    libera_vetor(vetor);

    //Marca fim do tempo de execu��o
    gettimeofday(&tempo_fim, NULL);

    //Filtra o valor recebido pela fun��o de tempo atribui nas variaveis
    tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
    ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));

    tempo = (tf - ti) / 1000;

    return tempo;
}

double analisaOrdenadoCMerge(int tamanho){
    double tf, ti, tempo;
    timeval tempo_inicio, tempo_fim;

    int *vetor;
    //Marca in�cio do tempo de execu��o
    gettimeofday(&tempo_inicio, NULL);

    vetor = aloca_vetor(tamanho, 2);
    //Algoritmo de ordena��o
    mergeSort(vetor, 0, tamanho-1);
    libera_vetor(vetor);

    //Marca fim do tempo de execu��o
    gettimeofday(&tempo_fim, NULL);

    //Filtra o valor recebido pela fun��o de tempo atribui nas variaveis
    tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
    ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));

    tempo = (tf - ti) / 1000;

    return tempo;
}

/**Fun��es de ordena��o com vetores ordenados em ordem decrescente**/
double analisaOrdenadoDHeap(int tamanho){
    double tf, ti, tempo;
    timeval tempo_inicio, tempo_fim;

    int *vetor;
    //Marca in�cio do tempo de execu��o
    gettimeofday(&tempo_inicio, NULL);

    vetor = aloca_vetor(tamanho, 3);
    //Algoritmo de ordena��o
    heapSort(vetor, tamanho);
    libera_vetor(vetor);

    //Marca fim do tempo de execu��o
    gettimeofday(&tempo_fim, NULL);

    //Filtra o valor recebido pela fun��o de tempo atribui nas variaveis
    tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
    ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));

    tempo = (tf - ti) / 1000;

    return tempo;
}

double analisaOrdenadoDBubble(int tamanho){
    double tf, ti, tempo;
    timeval tempo_inicio, tempo_fim;

    int *vetor;
    //Marca in�cio do tempo de execu��o
    gettimeofday(&tempo_inicio, NULL);

    vetor = aloca_vetor(tamanho, 3);
    //Algoritmo de ordena��o
    bubbleSort(vetor, tamanho);
    libera_vetor(vetor);

    //Marca fim do tempo de execu��o
    gettimeofday(&tempo_fim, NULL);

    //Filtra o valor recebido pela fun��o de tempo atribui nas variaveis
    tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
    ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));

    tempo = (tf - ti) / 1000;

    return tempo;
}

double analisaOrdenadoDInsertion(int tamanho){
    double tf, ti, tempo;
    timeval tempo_inicio, tempo_fim;

    int *vetor;
    //Marca in�cio do tempo de execu��o
    gettimeofday(&tempo_inicio, NULL);

    vetor = aloca_vetor(tamanho, 3);
    //Algoritmo de ordena��o
    insertionSort(vetor, tamanho);
    libera_vetor(vetor);

    //Marca fim do tempo de execu��o
    gettimeofday(&tempo_fim, NULL);

    //Filtra o valor recebido pela fun��o de tempo atribui nas variaveis
    tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
    ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));

    tempo = (tf - ti) / 1000;

    return tempo;
}

double analisaOrdenadoDQuick(int tamanho){
    double tf, ti, tempo;
    timeval tempo_inicio, tempo_fim;

    int *vetor;
    //Marca in�cio do tempo de execu��o
    gettimeofday(&tempo_inicio, NULL);

    vetor = aloca_vetor(tamanho, 3);
    //Algoritmo de ordena��o
    quickSort(vetor, 0, tamanho-1);
    libera_vetor(vetor);

    //Marca fim do tempo de execu��o
    gettimeofday(&tempo_fim, NULL);

    //Filtra o valor recebido pela fun��o de tempo atribui nas variaveis
    tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
    ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));

    tempo = (tf - ti) / 1000;

    return tempo;
}

double analisaOrdenadoDSelection(int tamanho){
    double tf, ti, tempo;
    timeval tempo_inicio, tempo_fim;

    int *vetor;
    //Marca in�cio do tempo de execu��o
    gettimeofday(&tempo_inicio, NULL);

    vetor = aloca_vetor(tamanho, 3);
    //Algoritmo de ordena��o
    selectionSort(vetor, tamanho);
    libera_vetor(vetor);

    //Marca fim do tempo de execu��o
    gettimeofday(&tempo_fim, NULL);

    //Filtra o valor recebido pela fun��o de tempo atribui nas variaveis
    tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
    ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));

    tempo = (tf - ti) / 1000;

    return tempo;
}

double analisaOrdenadoDShell(int tamanho){
    double tf, ti, tempo;
    timeval tempo_inicio, tempo_fim;

    int *vetor;
    //Marca in�cio do tempo de execu��o
    gettimeofday(&tempo_inicio, NULL);

    vetor = aloca_vetor(tamanho, 3);
    //Algoritmo de ordena��o
    shellSort(vetor, tamanho);
    libera_vetor(vetor);

    //Marca fim do tempo de execu��o
    gettimeofday(&tempo_fim, NULL);

    //Filtra o valor recebido pela fun��o de tempo atribui nas variaveis
    tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
    ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));

    tempo = (tf - ti) / 1000;

    return tempo;
}

double analisaOrdenadoDMerge(int tamanho){
    double tf, ti, tempo;
    timeval tempo_inicio, tempo_fim;

    int *vetor;
    //Marca in�cio do tempo de execu��o
    gettimeofday(&tempo_inicio, NULL);

    vetor = aloca_vetor(tamanho, 3);
    //Algoritmo de ordena��o
    mergeSort(vetor, 0, tamanho-1);
    libera_vetor(vetor);

    //Marca fim do tempo de execu��o
    gettimeofday(&tempo_fim, NULL);

    //Filtra o valor recebido pela fun��o de tempo atribui nas variaveis
    tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
    ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));

    tempo = (tf - ti) / 1000;

    return tempo;
}

void analisaAlgoritmos(int tamanho){
    system("cls");
    printf("\nAn�lise de algoritmos com vetor de %d elementos desordenados randomicamente", tamanho);
    double _heap = analisaHeap(tamanho);
    printf("\nHeapSort: \t%f ms\n",_heap);

    double _bubble = analisaBubble(tamanho);
    printf("BubbleSort: \t%f ms\n",_bubble);

    double _insertion = analisaInsertion(tamanho);
    printf("InsertionSort: \t%f ms\n",_insertion);

    double _quick = analisaQuick(tamanho);
    printf("QuickSort: \t%f ms\n",_quick);

    double _selection = analisaSelection(tamanho);
    printf("SelectionSort: \t%f ms\n",_selection);

    double _shell = analisaShell(tamanho);
    printf("ShellSort: \t%f ms\n",_shell);

    double _merge = analisaMerge(tamanho);
    printf("MergeSort: \t%f ms\n",_merge);

    printf("\nAn�lise de algoritmos com vetor de %d elementos ordenados em ordem crescente", tamanho);
    _heap = analisaOrdenadoCHeap(tamanho);
    printf("\nHeapSort: \t%f ms\n",_heap);

    _bubble = analisaOrdenadoCBubble(tamanho);
    printf("BubbleSort: \t%f ms\n",_bubble);

    _insertion = analisaOrdenadoCInsertion(tamanho);
    printf("InsertionSort: \t%f ms\n",_insertion);

    /*_quick = analisaOrdenadoCQuick(tamanho);
    printf("QuickSort: \t%f ms\n",_quick);

    _selection = analisaOrdenadoCSelection(tamanho);
    printf("SelectionSort: \t%f ms\n",_selection);

    /_shell = analisaOrdenadoCShell(tamanho);
    printf("ShellSort: \t%f ms\n",_shell);

    _merge = analisaOrdenadoCMerge(tamanho);
    printf("MergeSort: \t%f ms\n",_merge);*/

    printf("\nAn�lise de algoritmos com vetor de %d elementos ordenados em ordem decrescente", tamanho);
    _heap = analisaOrdenadoDHeap(tamanho);
    printf("\nHeapSort: \t%f ms\n",_heap);

    _bubble = analisaOrdenadoDBubble(tamanho);
    printf("BubbleSort: \t%f ms\n",_bubble);

    _insertion = analisaOrdenadoDInsertion(tamanho);
    printf("InsertionSort: \t%f ms\n",_insertion);

    /*_quick = analisaOrdenadoDQuick(tamanho);
    printf("QuickSort: \t%f ms\n",_quick);

    _selection = analisaOrdenadoDSelection(tamanho);
    printf("SelectionSort: \t%f ms\n",_selection);

    _shell = analisaOrdenadoDShell(tamanho);
    printf("ShellSort: \t%f ms\n",_shell);

    _merge = analisaOrdenadoDMerge(tamanho);
    printf("MergeSort: \t%f ms\n",_merge);*/
}
