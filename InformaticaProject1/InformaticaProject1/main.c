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
 8. la somma dei resti delle divisione per tre dei numeri pari
 9. ricerca di un elemento nel vettore attraverso la ricerca sequenziale con sentinella
 10. ordinamento attraverso l'algoritmo del merge sort
 L'array verra` dichiarato con una dimensione di 150 elementi, ma quando il programma parte, prima della visualizzazione del menu verra` richiesto di inserire il numero di elementi su cui operare
 */

#include <stdio.h>
#include <stdlib.h> // serve per random()

void inserimentoElementiVettore(int array[], int lunghezza) {
    for (int i = 0; i < lunghezza; i++) {
        printf("Inserisci l'elemento per la positione %d: ", i+1);
        scanf("%d", &array[i]);
    }
}

void visualizzazioneElementiVettore(int array[], int lunghezza) {
    puts("-----------------"); // puts() e' simile a printf(), ma va a capo in automatico, senza '\n'
    puts("  n  |  valore  ");
    for (int i = 0; i < lunghezza; i++) {
        printf("  %d  |    %d    \n", i+1, array[i]);
    }
    puts("-----------------");
}

void azzeramentoElementiVettore(int array[], int lunghezza) {
    for (int i = 0; i < lunghezza; i++) {
        array[i] = 0;
    }
}

int inserimentoSoloUnDatoSeZero(int array[], int lunghezza) {
    for (int i = 0; i < lunghezza; i++) {
        if (array[i] == 0) {
            printf("Ho trovato 0! Inserisci l'elemento per la positione %d: ", i+1);
            scanf("%d", &array[i]);
            return 0;
        }
    }
    puts("Non ho trovato alcun elemento contenente 0.");
    return 1;
}

int numeroRandom(int min, int max) {
    int differenza = max - min;
    return (int) (((double)(differenza+1) / RAND_MAX) * rand() + min);
}

void inserimentoNumeriCasuali(int array[], int lunghezza) {
    for (int i = 0; i < lunghezza; i++) {
        int r = numeroRandom(200, 300);
        array[i] = r;
    }
    puts("");
}

void prodottoElementiIndiceZero(int array[], int lunghezza) [
	for (int i = 0; i < lunghezza; i++) {
		//if (i % i == 0 && i != i) return false;

	}
}

int main() {
    int myArray[150], maxNumero, inserimento;
    
    printf("Inserisci il numero massimo di numeri che vuoi che il vettore contenga: ");
    
    scanf("%d", &maxNumero);
	
	// controlla se il numero e' maggiore compreso di 1. Non esiste un'array con 0 elementi!
	while (maxNumero < 1) {
		printf("Riprova! Inserisci un numero maggiore di 0: ");
		scanf("%d", &maxNumero);
	}
	
    while (1) {
        puts("-------------------------------------------------------------------------------------------------------");
        puts("|  1  |  Azzeramento del vettore                                                                      |");
        puts("|  2  |  Inserimento di tutti gli elementi da tastiera                                                |");
        puts("|  3  |  Inserimento di un solo dato nella prima posizione contente zero                              |");
        puts("|  4  |  Inserimento di tutti i dati in maniera casuale con numeri compresi tra duecento e trecento   |");
        puts("|  5  |  Visualizzazione di tutti gli elementi presenti nel vettore                                   |");
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
            default:
                printf("'%d' non e' un'opzione valida. Riprova!\n", inserimento);
                break;
        }
    }
    
    return 0;
}
