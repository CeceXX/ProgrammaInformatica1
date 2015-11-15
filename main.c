/*
 Progetto Informatica
 Gruppo 4: Belletta, De Cal, Tesi, Valeri
 Viene richiesto un programma organizzato per funzioni che preveda un menu con la possibilità di scelta tra le seguenti operazioni:
 1. Azzeramento del vettore
 2. Inserimento di tutti i dati da tastiera
 3. Inserimento di un solo dato nella prima posizione contente zero
 4. Inserimento di tutti i dati in maniera casuale con numeri compresi tra duecento e trecento
 5. La visualizzazione di tutti i dati presenti nel vettore
 6. Inserimento dei numeri della serie geometrica
 7. Il prodotto dei numeri di indice primo
 8. La somma dei resti della divisione per tre dei numeri pari
 9. Ricerca di un elemento nel vettore attraverso la ricerca sequenziale con sentinella
 10. Ordinamento attraverso l'algoritmo del merge sort
 11. Probabilità di Poisson
 12. (Probabilità di Poisson) Visualizza elementi vettore x
 13. (Probabilità di Poisson) Visualizza elementi vettore frequenze
 L'array verra dichiarato con una dimensione di 150 elementi, ma quando il programma parte, prima della visualizzazione del menu verra` richiesto di inserire il numero di elementi su cui operare.
 */
#include <stdio.h>
#include <stdlib.h> // serve per la 'macro' (è un po' come una funzione) che genera numeri random, RAND_MAX
#include <math.h> // serve per la funzione 'pow()', usata per calcolare il risultato di una potenza data una base e un esponente: 'pow(base, esponente);'
#include <time.h>

float acquisisciNumeroCompresoTraValori(int min, int max) {
    float inserimento;
    scanf("%f", &inserimento);
    while ((inserimento < min) || (inserimento > max)) {
        printf("'%.f' non e' un numero valido. Inserisci un valore compreso tra %d e %d: ", inserimento, min, max);
        scanf("%f", &inserimento);
    }
    return inserimento;
}

// 1. Azzeramento del vettore (Gianluca Tesi)
void azzeramentoElementiVettore(int array[], int lunghezza) {
    for (int i = 0; i < lunghezza; i++) {
        array[i] = 0;
    }
}

// 2. Inserimento di tutti i dati da tastiera (Elis Belletta)
void inserimentoElementiDaTastieraVettore(int array[], int lunghezza) {
    for (int i = 0; i < lunghezza; i++) {
        printf("Inserisci l'elemento per la positione %d: ", i+1);
        scanf("%d", &array[i]);
    }
}

// 3. Inserimento di un solo dato nella prima posizione contente zero (Gianluca Tesi)
int inserimentoSoloUnDatoSeZero(int array[], int lunghezza) {
    for (int i = 0; i < lunghezza; i++) {
        if (array[i] == 0) {
            printf("Ho trovato 0! Inserisci l'elemento per la posizione %d: ", i+1);
            scanf("%d", &array[i]);
            return 0; // appena trova 0, si esce subito dalla funzione con 'return' perchè non la funzione non ci serve più
        }
    }
    puts("Non ho trovato alcun elemento contenente 0.");
    return 1; // restituisci il val1ore 1 con 'return', ovvero la funzione non ha trovato alcun elemento uguale a zero
}

// 4. Inserimento di tutti i dati in maniera casuale con numeri compresi tra duecento e trecento (Gianluca Tesi)
int generaNumeroCasualeCompresoTraValori(int min, int max) {
    return rand() % (max-min) + min;
}

void inserimentoNumeriCasuali(int array[], int lunghezza) {
    for (int i = 0; i < lunghezza; i++) {
        array[i] = generaNumeroCasualeCompresoTraValori(200, 300);
    }
}

// 5. La visualizzazione di tutti i dati presenti nel vettore (Paolo Valeri)
void visualizzazioneElementiVettore(int array[], int lunghezza) {
    puts("-----------------"); // puts() e' simile a printf(), ma va a capo in automatico, non necessita '\n'
    puts("   n  |   valore  ");
    for (int i = 0; i < lunghezza; i++) {
        printf("  %2d  |    %3d    \n", i+1, array[i]); // stampa i numeri contenuti nel vettore, uno ad uno
    }
    puts("-----------------");
}

// 6. L'inserimento dei numeri della serie geometrica (Elis Belletta)
// - Maggiori informazioni su come funziona la serie geometrica: https://www.youtube.com/watch?v=mcnblnEsf98
void insermentoSerieGeometricaVettore(int array[], int lunghezza) {
    int costante, primoTermine;
    
    printf("Inserisci 1 se desideri usare il primo elemento del vettore (ovvero '%d') come primo termine della serie geometrica, oppure 2 se vuoi usare un altro numero: ", array[0]);
    int inserimento = acquisisciNumeroCompresoTraValori(1, 2);
    
    if (inserimento == 1) {
        primoTermine = array[0];
    } else if (inserimento == 2) {
        printf("Inserisci il primo numero della serie geometrica: ");
        scanf("%d", &primoTermine);
    }
    
    printf("Inserisci la costante della serie geometrica: ");
    scanf("%d", &costante);
    for (int i = 0; i < lunghezza; i++) {
        array[i] = primoTermine * pow(costante, i);
    }
}

// 7. Il prodotto dei numeri di indice primo (Elis Belletta)
// - Ho usato due funzioni per questo esercizio, "controllaSeNumeroPrimo" e "prodottoNumeriIndicePrimo"
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

// 8. La somma dei resti della divisione per tre dei numeri pari (Elis Belletta)
void sommaRestoDivisioneNumeriPari(int array[], int lunghezza) {
    int somma = 0;
    for (int i = 0; i < lunghezza; i++) {
        
        // if (condizione) {...}
        // il codice all'interno dell'if viene eseguito solo se la (condizione) è VERA
        // altrimenti, se la condizione è FALSA, non viene eseguito
        // if (1) {...} viene eseguito perchè se all'interno della condizione c'è un numero DIVERSO DA ZERO, allora la condizione è VERA
        // if (0) {...} viene eseguito perchè se all'interno della condizione c'è ZERO, allora la condizione è FALSA
        if (!(array[i] % 2)) { // il punto esclamatico significa "opposto di", se if (condizione) {...} è VERO, allora if (!(condizione)) è FALSO a causa del punto esclamativo, che INVERTE la condizione
            somma += array[i] % 3; // 'somma += 1'rr è lo stesso modo di dire 'somma = somma + 1'
        }
    }
    printf("La somma e dei resti degli elementi del vettore e' %d.\n", somma);
}

// 9. Ricerca di un elemento nel vettore attraverso la ricerca sequenziale con sentinella (Cesare de Cal)
void ricercaLineareSentinella(int array[], int lunghezza) {
    int elementoDaCercare;
    printf("Inserisci l'elemento da cercare: ");
    scanf("%d", &elementoDaCercare);
    
    array[lunghezza + 1] = elementoDaCercare;
    int i = 0;
    
    while (array[i] != elementoDaCercare) {
        i++;
    }
    
    if (array[i] == elementoDaCercare) {
        printf("Ho trovato %d alla posizione %d.\n", elementoDaCercare, i);
    } else {
        printf("Non ho trovato %d nel vettore.\n", elementoDaCercare);
    }
}

// 10. Ordinamento attraverso l'algoritmo del merge sort (Cesare de Cal)
// - A è il vettore intero, L e R sono i due vettori da unire
void merge(int *A, int *L, int leftCount, int *R, int rightCount) {
    int i, j, k;
    
    // i - to mark the index of left aubarray (L)
    // j - to mark the index of right sub-raay (R)
    // k - to mark the index of merged subarray (A)
    i = 0; j = 0; k =0;
    
    while(i < leftCount && j < rightCount) {
        if(L[i]  < R[j]) A[k++] = L[i++];
        else A[k++] = R[j++];
    }
    while(i < leftCount) A[k++] = L[i++];
    while(j < rightCount) A[k++] = R[j++];
}

// Merge sort è un algoritmo di ordinamento che ordina crescentemente un array di interi (Int)
void mergeSort(int *A, int n) {
    int mid, i, *L, *R;
    if (n < 2) return; // Condizione di base. Se il vettore contiene meno di due elementi, non fare nulla
    mid = n / 2; // Trova l'indice che si trova nella metà del vettore
    
    // create left and right subarrays
    // mid elements (from index 0 till mid-1) should be part of left sub-array
    // and (n-mid) elements (from mid to n-1) will be part of right sub-array
    L = (int*)malloc(mid*sizeof(int)); // crea uno spazio in memoria con malloc()
    R = (int*)malloc((n- mid)*sizeof(int));
    
    for(i = 0;i<mid;i++) L[i] = A[i]; // creating left subarray
    for(i = mid;i<n;i++) R[i-mid] = A[i]; // creating right subarray
    
    mergeSort(L,mid);  // sorting the left subarray
    mergeSort(R,n-mid);  // sorting the right subarray
    merge(A, L, mid, R, n-mid);  // Unisce i vettori L e R into A as sorted list.
    free(L); // dopo aver creato uno spazio in memoria, ora liberalo con free() - questa funzione libera lo spazio di memoria HEAP
    free(R);
}

// Dichiarazione vettori che raccoglieranno i fattoriali di x e di (N-x)
float vettoreX[1000], vettoreXFattoriale[1000], vettoreNMenoXFattoriale[1000], vettoreProbabilitaCompreseTraIntervallo[1000];
int p = 0;

// Funzione ricorsiva
int fattoriale(int n) {
    if (n < 0) return -1; // Fattoriale non è definito per interi negativi!
    
    if (n == 0) return 1;
    else return n*fattoriale(n-1);
}


void probabilitaPoisson(int lunghezzaVettoreX, int opzioneSceltaUtente) {
    
    if (opzioneSceltaUtente == 0) {
        float N, probabilita;
        
        printf("Inserisci N (compreso tra 10 e 1000): ");
        scanf("%f", &N);
        N = acquisisciNumeroCompresoTraValori(10, 1000);
        
        // Acquisizione probabilità
        printf("Inserisci la probabilita': ");
        scanf("%f", &probabilita);
        probabilita = acquisisciNumeroCompresoTraValori(0, 1);
        
        for (int i = 0; i < lunghezzaVettoreX; i++) {
            vettoreX[i] = generaNumeroCasualeCompresoTraValori(0, N);
        }
        
        /* La formula necessita di tre variabili: N, p, x:
         x          N-x
         N! * p  * (1 - p)
         p  =  ------------------
         x      x! * (N - x)!
         */
        
        // Fattoriale di un numero, cioè il numero moltiplicato per tutti i numeri precedenti a esso. Ad esempio: 5! = 1 * 2 * 3 * 4 * 5
        long unsigned int fattorialeN = fattoriale(N), fattorialeNMenoX = 1;
        
        for (int i = 0; i < lunghezzaVettoreX; i++) {
            vettoreXFattoriale[i] = fattoriale(vettoreX[i]);
        }
        
        // Calcola il fattoriale di (N - x)
        // Per ogni elemento del vettoreX...
        for (int p = 0; p < lunghezzaVettoreX; p++) {
            
            int nMenoX = N - vettoreX[p];
            
            for (int i = 1; i < nMenoX+1; i++) {
                fattorialeNMenoX *= i; // ...Calcola il fattoriale di (N - x)
            }
            
            //printf("Ok: N = %f, x = %f, n-m = %f, il fattoriale e' %f\n", N, vettoreX[p], nMenoX, fattorialeNMenoX);
            vettoreNMenoXFattoriale[p] = fattorialeNMenoX;
            fattorialeNMenoX = 1;
        }
        
        // Calcola la probabilità di Poisson
        float pPoisson;
        for (int i = 0; i < lunghezzaVettoreX; i++) {
            pPoisson = (fattorialeN * pow(probabilita, vettoreX[i])) * pow(1 - probabilita, N - vettoreX[i]) /
            (vettoreXFattoriale[i] * vettoreNMenoXFattoriale[i]);
            //printf("La probabilita' di Poisson e' %f ed e' stata calcolata con N = %f, fattorialeN = %f, x = %f, probabilita = %f, N-xFattoriale = %f.\n", pPoisson, N, fattorialeN, vettoreX[i], probabilita, vettoreNMenoXFattoriale[i]);
            if ((pPoisson >= 0 && pPoisson <= 31.25) || (pPoisson >= 31.25 && pPoisson <= 187.5) || (pPoisson >= 500 && pPoisson >= 812.5) || (pPoisson >= 968.75 && pPoisson <= 1000)) {
                pPoisson = vettoreProbabilitaCompreseTraIntervallo[p];
                p++;
            }
        }
        // Distingui il singolare/plurale: "c'è" e "ci sono", "compresa" e "comprese"
        if (p == 1) {
            printf("C'e' %d probabilita' di Poisson compresa tra i valori richiesti.\n", p);
        } else {
            printf("Ci sono %d probabilita' di Poisson comprese tra i valori richiesti.\n", p);
        }
        
    }
    if (opzioneSceltaUtente == 1) {
        // L'utente ha scelto di visualizzare gli elmenti contenuti nel vettore x
        for (int i = 0; i < lunghezzaVettoreX; i++) {
            printf("Posizione %d vettore x '%f'.\n", i, vettoreX[i]);
        }
    } else if (opzioneSceltaUtente == 2) {
        if (p == 0) {
            puts("Non ho trovato alcun valore nel vettore delle frequenze di estrazione.");
        }
        
        // L'utente ha scelto di visualizzare gli elmenti contenuti nel vettore delle frequenze di estrazione
        for (int i = 0; i < p; i++) {
            printf("Posizione %d vettore frequenze estrazione '%f'\n", i, vettoreProbabilitaCompreseTraIntervallo[i]);
        }
    }
}

void mostraMenu(int vettore[], int lunghezzaVettore) {
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
    puts("|  11 |  Probabilita' di Poisson (12 per visualizzare vettore delle x, 13 per vettore frequenze       |");
    puts("-------------------------------------------------------------------------------------------------------");
    
    printf("Scegli un'opzione del menu: ");
    int scelta = acquisisciNumeroCompresoTraValori(1, 13);
    
    switch (scelta) {
        case 1:
            azzeramentoElementiVettore(vettore, lunghezzaVettore);
            break;
        case 2:
            inserimentoElementiDaTastieraVettore(vettore, lunghezzaVettore);
            break;
        case 3:
            inserimentoSoloUnDatoSeZero(vettore, lunghezzaVettore);
            break;
        case 4:
            inserimentoNumeriCasuali(vettore, lunghezzaVettore);
            break;
        case 5:
            visualizzazioneElementiVettore(vettore, lunghezzaVettore);
            break;
        case 6:
            insermentoSerieGeometricaVettore(vettore, lunghezzaVettore);
            break;
        case 7:
            prodottoNumeriIndicePrimo(vettore, lunghezzaVettore);
            break;
        case 8:
            sommaRestoDivisioneNumeriPari(vettore, lunghezzaVettore);
            break;
        case 9:
            ricercaLineareSentinella(vettore, lunghezzaVettore);
            break;
        case 10:
            mergeSort(vettore, lunghezzaVettore);
            break;
        case 11:
            probabilitaPoisson(lunghezzaVettore, 0);
            break;
        case 12:
            probabilitaPoisson(lunghezzaVettore, 1);
            break;
        case 13:
            probabilitaPoisson(lunghezzaVettore, 2);
            break;
        default:
            break;
    }
}

// Il compilatore inzia a compilare il codice dalla funzione main() (Paolo Valeri)
int main() {
    int numeri[150];
    
    printf("Inserisci il numero massimo di numeri che vuoi che il vettore contenga: ");
    int lunghezzaVettore = acquisisciNumeroCompresoTraValori(10, 150);
    
    while (1) {
        mostraMenu(numeri, lunghezzaVettore);
    }
    
    return 0;
}
