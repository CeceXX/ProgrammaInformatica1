/*
 Gruppo 4: Belletta, De Cal, Tesi, Valeri
 Viene richiesto un programma organizzato per funzioni che preveda un menu con la possibilita` di scelta tra le seguenti operazioni:
 1. azzeramento del vettore
 2. inserimento di tutti i dati da tastiera
 3. inserimento di un solo dato nella prima posizione contente zero
 4. inserimento di tutti i dati in maniera casuale con numeri compresi tra duecento e trecento
 5. la visualizzazione di tutti i dati presenti nel vettore
 6. l'inserimento dei numeri della serie geometrica
 7. il prodotto dei numeri di indice primo
 8. la somma dei resti della divisione per tre dei numeri pari
 9. ricerca di un elemento nel vettore attraverso la ricerca sequenziale con sentinella
 10. ordinamento attraverso l'algoritmo del merge sort
 L'array verra` dichiarato con una dimensione di 150 elementi, ma quando il programma parte, prima della visualizzazione del menu verra` richiesto di inserire il numero di elementi su cui operare
 */

#include <stdio.h>
#include <stdlib.h> // serve per la 'macro' (è un po' come una funzione) che genera numeri random, RAND_MAX
#include <math.h> // serve per la funzione 'pow()', usata per calcolare il risultato di una potenza dato una base e un esponente 'pow(base, esponente);'

//  1. Azzeramento del vettore
void azzeramentoElementiVettore(int array[], int lunghezza) {
    for (int i = 0; i < lunghezza; i++) {
        array[i] = 0; // ogni elemento del vettore verrà azzerato, uno ad uno
    }
}

// 2. inserimento di tutti i dati da tastiera
void inserimentoElementiVettore(int array[], int lunghezza) {
    for (int i = 0; i < lunghezza; i++) {
        printf("Inserisci l'elemento per la positione %d: ", i + 1);
        scanf("%d", &array[i]); // acquisisci un numero da tastiera da inserire nel vettore
    }
}

//  3. inserimento di un solo dato nella prima posizione contente zero
int inserimentoSoloUnDatoSeZero(int array[], int lunghezza) {
    for (int i = 0; i < lunghezza; i++) {
        if (array[i] == 0) {
            printf("Ho trovato 0! Inserisci l'elemento per la posizione %d: ", i + 1);
            scanf("%d", &array[i]); // acquisici un numero da tastiera
            return 0; // appena trova 0, si esce dalla funzione con 'return' perchè non la funzione non ci serve più
        }
    }
    puts("Non ho trovato alcun elemento contenente 0.");
    return 1; // restituisci il val1ore 1 con 'return', ovvero la funzione non ha trovato alcun elemento uguale a zero
}

void visualizzazioneElementiVettore(int array[], int lunghezza) {
    puts("-----------------"); // puts() e' simile a printf(), ma va a capo in automatico, non necessita '\n'
    puts("   n  |   valore  ");
    for (int i = 0; i < lunghezza; i++) {
        printf("  %2d  |    %3d    \n", i + 1, array[i]); // stampa i numeri contenuti nel vettore, uno ad uno
    }
    puts("-----------------");
}

int numeroRandom(int min, int max) {
    int differenza = max - min; // dato una fascia di valori definita da 'min' e 'max'...
    return (int) (((double)(differenza+1) / RAND_MAX) * rand() + min); // ...genera un numero random con RAND_MAX
}

void inserimentoNumeriCasuali(int array[], int lunghezza) {
    for (int i = 0; i < lunghezza; i++) {
        int r = numeroRandom(200, 300); // passa alla funzione 'numeroRandom' il numero 'min' e quello 'max' su cui operare
        array[i] = r; // poi assegna a ciasuno elemento il valore casuale generato
    }
    puts("");
}

int controllaSeNumeroPrimo(int numero) {
    for (int i = 2; i < numero; i++) {
        if (numero % i == 0 && i != numero) {
            return 0;
        }
    }
    return 1;
}

void prodottoNumeriIndicePrimo(int array[], int lunghezza) {
    int prodotto = 1;
    for (int i = 0; i < lunghezza; i++) {
        if (controllaSeNumeroPrimo(i)) {
            prodotto *= array[i];
        }
    }
    printf("Il prodotto degli elementi del vettore e' %d.\n", prodotto);
}

void sommaRestoDivisioneNumeriPari(int array[], int lunghezza) {
    int somma = 0;
    for (int i = 0; i < lunghezza; i++) {
        
        // - if (condizione) {...}
        // il codice all'interno dell'if viene eseguito se la condizione è VERA
        // altrimenti, se la condizione è FALSA, non viene eseguito
        // if (1) {...} viene eseguito perchè se all'interno della condizione c'è un numero DIVERSO DA ZERO, allora la condizione è VERA
        // if (0) {...} viene eseguito perchè se all'interno della condizione c'è ZERO, allora la condizione è FALSA
        if (!(array[i] % 2)) { // il punto esclamatico significa "opposto di", se if (condizione) {...} è FALSO, allora if (!(condizione)) è FALSO per il punto esclamativo
            somma += array[i] % 3;
        }
    }
    printf("La somma e' %d.\n", somma);
}

void Merge(int *A, int *L, int leftCount, int *R, int rightCount) {
    int i, j, k;
    
    // i - to mark the index of left aubarray (L)
    // j - to mark the index of right sub-raay (R)
    // k - to mark the index of merged subarray (A)
    i = 0; j = 0; k =0;
    
    while(i<leftCount && j< rightCount) {
        if(L[i]  < R[j]) A[k++] = L[i++];
        else A[k++] = R[j++];
    }
    while(i < leftCount) A[k++] = L[i++];
    while(j < rightCount) A[k++] = R[j++];
}

// Recursive function to sort an array of integers.
void mergeSort(int *A, int n) {
    int mid, i, *L, *R;
    if (n < 2) return; // base condition. If the array has less than two element, do nothing.
    
    mid = n / 2;  // find the mid index.
    
    // create left and right subarrays
    // mid elements (from index 0 till mid-1) should be part of left sub-array
    // and (n-mid) elements (from mid to n-1) will be part of right sub-array
    L = (int*)malloc(mid*sizeof(int)); // crea uno spazio in memoria con malloc()
    R = (int*)malloc((n- mid)*sizeof(int));
    
    for(i = 0;i<mid;i++) L[i] = A[i]; // creating left subarray
    for(i = mid;i<n;i++) R[i-mid] = A[i]; // creating right subarray
    
    mergeSort(L,mid);  // sorting the left subarray
    mergeSort(R,n-mid);  // sorting the right subarray
    Merge(A, L, mid, R, n-mid);  // Unisce i vettori L e R into A as sorted list.
    free(L); // dopo aver creato uno spazio in memoria, ora liberalo con free() - questa funzione libera lo spazio di memoria HEAP
    free(R);
}

void serieGeometrica(int array[], int lunghezza) {
    int r, p, somma; // r è la costante della serie geometrica, p è il primo termine della serie geometrica
    char inserimento[2];
    // Maggiori informazioni: https://www.youtube.com/watch?v=mcnblnEsf98
    printf("Desideri usare il primo elemento del vettore come primo termine della serie geometrica, oppure un altro termine? Y/N: ");
    scanf("%1s", inserimento);
    if ((inserimento[0] == 'y') || (inserimento[0] == 'Y')) {
        p = array[0];
    } else {
        printf("Inserisci il primo numero della serie geometrica: ");
        scanf("%d", &p);
    }
    printf("Inserisci r: ");
    scanf("%d", &r);
    // la somma geometrica è uguale a a(r^n)/r-1
    // n è il numero di elementi della serie
    // il nostro compito qui è quello di inserire tutti gli elementi della somma geometrica nel vettore
    for (int i = 0; i < lunghezza; i++) {
        array[i] = p * pow(r, i);
    }
    
    somma = (p*(pow(r, lunghezza)-1))/(r-1);
    printf("Ho inserito tutti i termini della serie geometrica nel vettore. La somma della serie geometrica equivale a %d.\n", somma);
}

void ricercaSequenzialeSentinella(int array[], int lunghezza) {

}

int main() {
    int myArray[150], maxNumero, inserimento;
    
    printf("Inserisci il numero massimo di numeri che vuoi che il vettore contenga: ");
    scanf("%d", &maxNumero);
    
    // controlla se il numero è maggiore compreso di 1. Non esiste un'array con 0 elementi!
    while ((maxNumero < 1) || (maxNumero > 10)) {
        printf("Riprova! Inserisci un numero compreso tra 1 e 10: ");
        scanf("%d", &maxNumero);
    }
    
    while (1) { // while (1) {...} eseguirà il codice all'infinito perchè 1 (come qualsiasi numero != 0) è considerato VERO
        puts("-------------------------------------------------------------------------------------------------------");
        puts("|  1  |  Azzeramento del vettore                                                                      |");
        puts("|  2  |  Inserimento di tutti gli elementi da tastiera                                                |");
        puts("|  3  |  Inserimento di un solo dato nella prima posizione contente zero                              |");
        puts("|  4  |  Inserimento di tutti i dati in maniera casuale con numeri compresi tra duecento e trecento   |");
        puts("|  5  |  Visualizzazione di tutti gli elementi presenti nel vettore                                   |");
        puts("|  6  |  Inserimento dei numeri della serie geomtrica                                                 |");
        puts("|  7  |  Prodotto dei numeri di indice primo                                                          |");
        puts("|  8  |  Somma dei resti della divisione per tre dei numeri pari                                      |");
        puts("|  9  |  Ricerca di un elemento nel vettore attraverso la ricerca sequenziale con sentinella          |");
        puts("|  10 |  Ordinamento attraverso l'algoritmo del merge sort                                            |");
        puts("-------------------------------------------------------------------------------------------------------");
        
        printf("Scegli un'opzione del menu: ");
        scanf("%d", &inserimento);
        
        switch (inserimento) {
            case 1:
                azzeramentoElementiVettore(myArray, maxNumero);
                break;
            case 2:
                inserimentoElementiVettore(myArray, maxNumero);
                break;
            case 3:
                inserimentoSoloUnDatoSeZero(myArray, maxNumero);
                break;
            case 4:
                inserimentoNumeriCasuali(myArray, maxNumero);
                break;
            case 5:
                visualizzazioneElementiVettore(myArray, maxNumero);
                break;
            case 6:
                serieGeometrica(myArray, maxNumero);
                break;
            case 7:
                prodottoNumeriIndicePrimo(myArray, maxNumero);
                break;
            case 8:
                sommaRestoDivisioneNumeriPari(myArray, maxNumero);
                break;
            case 9:
                ricercaSequenzialeSentinella(myArray, maxNumero);
                break;
            case 10:
                mergeSort(myArray, maxNumero);
                break;
            default:
                printf("'%d' non e' un'opzione valida. Riprova!\n", inserimento); // se l'opzione scelta non è compresa tra 1 e 10, allora non è valida
                break;
        }
    }
    
    return 0;
}
