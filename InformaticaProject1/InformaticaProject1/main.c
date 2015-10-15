/*
 Gruppo 4: Belletta, De Cal, Tesi, Valeri
 Viene richiesto un programma organizzato per funzioni che preveda un menu con la possibilità di scelta tra le seguenti operazioni:
 1. azzeramento del vettore
 2. inserimento di tutti i dati da tastiera
 3. inserimento di un solo dato nella prima posizione contente zero
 4. inserimento di tutti i dati in maniera casuale con numeri compresi tra duecento e
 trecento
 5. la visualizzazione di tutti i dati presenti nel vettore
 6. l'inserimento dei numeri della serie geometrica
 7. la prodotto dei numeri di indice primo
 8. la somma dei resti delle divisione per tre dei numeri pari
 9. ricerca di un elemento nel vettore attraverso la ricerca sequenziale con sentinella
 10. ordinamento attraverso l'algoritmo del merge sort
 L'array verrà dichiarato con una dimensione di 150 elementi, ma quando il programma parte, prima della visualizzazione del menu verrà richiesto di inserire il numero di elementi su cui operare
 */

#include <stdio.h>

void inserimentoElementiVettore(int array[], int lunghezza) {
    for (int i = 0; i < lunghezza; i++) {
        printf("Inserisci l'elemento per la positione %d: ", i+1);
        scanf("%d", &array[i]);
    }
}

void visualizzazioneElementiVettore(int array[], int lunghezza) {
    puts("-----------------"); // puts() e' simile a printf(), ma va a capo in automatico, senza '\n'
    puts("  n  |  valore  "); // crea una tabellina carina per inserire i nostri numeri
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

void inserimentoSoloUnDatoSeZero(int array[], int lunghezza) {
    for (int i = 0; i < lunghezza; i++) {
        if (array[i] == 0) {
            printf("Ho trovato 0! Inserisci l'elemento per la positione %d: ", i+1);
            scanf("%d", &array[i]);
            break;
        }
    }
    puts("Non ho trovato alcun elemento contenente 0.");
}

int main() {
    int myArray[150], maxNumero, inserimento;
    
    printf("Inserisci il numero massimo di numeri che vuoi che il vettore contenga: ");
    scanf("%d", &maxNumero);
    
    while (1) {
        puts("--------------------------------------------------------------------------");
        puts("|  1  |  Azzeramento del vettore                                         |");
        puts("|  2  |  Inserimento di tutti gli elementi da tastiera                   |");
        puts("|  3  |  Inserimento di un solo dato nella prima posizione contente zero |");
        puts("|  5  |  Visualizzazione di tutti gli elementi presenti nel vettore      |");
        puts("--------------------------------------------------------------------------");

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
            case 5:
                visualizzazioneElementiVettore(myArray, maxNumero);
                break;
            default:
                puts("Non ho riconosciuto l'opzione. Riprova!");
                break;
        }
    }
    
    return 0;
}
