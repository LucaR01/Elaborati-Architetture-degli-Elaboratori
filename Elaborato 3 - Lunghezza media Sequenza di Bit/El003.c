/*******************************************************************************
*                                                                              *
*                   Architetture dei sistemi di Elaborazione                   *
*                                                                              *
********************************************************************************

Elaborato 3
Descrizione: Data una sequenza di bit, restituire la lunghezza media (arrotondata
             all’intero più vicino), minima e massima delle sotto-sequenze di
			 bit (contigui) a 0 e a 1.

********************************************************************************/

#include <stdio.h>

void main()
{
	// Input
	//unsigned char vet[] = { 0xFC, 0xFF }; // TEST 6
	//unsigned short int len = 16;
	//unsigned char vet[] = { 0xFF, 0x01 }; // TEST 5
	//unsigned short int len = 9;
	//unsigned char vet[] = { 0xFC, 0xFF, 0x00 }; // TEST 4
	//unsigned short int len = 17;
	//unsigned char vet[] = { 0x95, 0xDF, 0xFF, 0xC2, 0x13, 0xEA, 0x26, 0x89, 0x90, 0x8D, 0x87, 0x66, 0x18, 0x92, 0x21, 0x35, 0xC0, 0x05, 0xAD, 0x18, 0xD4, 0x1E, 0x39, 0x20, 0xDF, 0x10, 0x3A, 0x33, 0x23, 0x74, 0xE1, 0x9F, 0x61, 0x7B, 0x97, 0xC4, 0xD5, 0xCE, 0x4B, 0x69, 0x6F };
	//unsigned short int len = 327; // TEST 3 NON SUPERATO
	//unsigned char vet[] = { 0x00 }; // TEST 1
	//unsigned short int len = 1;
	unsigned char vet[] = { 0xBC,0xFF,0x01 };	//Sequenza di bit
	unsigned short int len = 18;				// Lunghezza (in bit) della sequenza
	
	// Output
	unsigned short int minLungSeq0;		//Lunghezza minima sotto-sequenza di 0
	unsigned short int maxLungSeq0;		//Lunghezza massima sotto-sequenza di 0
	unsigned short int mediaLungSeq0;	//Media arrotondata sotto-sequenze di 0
	unsigned short int minLungSeq1;		//Lunghezza minima sotto-sequenza di 1
	unsigned short int maxLungSeq1;		//Lunghezza massima sotto-sequenza di 1
	unsigned short int mediaLungSeq1;	// Media arrotondata sotto-sequenze di 1

	// Blocco assembler
	__asm
	{
		XOR EAX, EAX // Pulisco questi registri che andrò ad utilizzare
		XOR ECX, ECX
		XOR EDX, EDX
		XOR EBX, EBX
		XOR EDI, EDI
		XOR ESI, ESI
		MOV maxLungSeq0, 0 // Salvo in maxLungSeq0, maxLungSeq1, minLungSeq0, minLungSeq1 dei valori provvisori
		MOV maxLungSeq1, 0
		MOV minLungSeq0, 20000
		MOV minLungSeq1, 20000
		PUSH AX // Pusho nello stack il valore 0
		XOR AX, AX
		JMP Inizio

Indice:
		XOR AX, AX // Azzero AX perchè ora dovrò controllare un nuovo byte e quindi ho bisogno del contatore AX libero
		PUSH AX // Pusho nello stack il valore di AX: ovvero 0
		INC ECX // Incremento ECX per poter passare al byte successivo
		CMP vet[ECX], -52 // Se vet[ECX] è uguale a -52, ovvero ha finito gli elementi del vettore
		JE PuliziaStack // Salta alla fine del ciclo e alla pulizia dello stack
		JMP Inizio
PreInizio:
		ROL EAX, 16
		POP AX
		INC AX // Incremento il valore di AX
		CMP AX, 7 // Faccio una CMP tra AX e 7 per vedere se si finito di controllare il byte (gli 8 bits)
		JG Indice // Se AX è maggiore salto ad indice dove il valore di AX verrà azzerato
		PUSH AX // Pusho nello stack il valore di AX, perchè ho bisogno di AX libero per le varie operazioni successive
		XOR AX, AX // Pulisco AX
		ROR EAX, 16 // Nei 16 bits irraggiungibili di EAX ho il valore del vet[ECX]
		JMP Ciclo
Inizio:
		MOV AL, vet[ECX] // Salvo in AL il valore di vet nella posizione ECX
Ciclo:
		SHR AL, 1 // Shifto il valore di AL
		JC SalvaUno // In base al registro del CARRY, salto per salvare un uno od uno zero
		JMP SalvaZero
SalvaUno:
		TEST DX, DX // CMP DX, 0 // DX: Contatore corrente degli 0
		JZ Dopo // Se è vuoto salto questi controlli
		CMP DX, maxLungSeq0 
		JNG ControlloMin0 // Se DX è più grande di maxLungSeq0 allora salvo il suo valore in maxLungSeq0
		MOV maxLungSeq0, DX
ControlloMin0:
		CMP DX, minLungSeq0
		JG Dopo // Se DX è maggiore di minLungSeq0 salto a Dopo, altrimenti salvo il suo valore in minLungSeq0
		MOV minLungSeq0, DX
Dopo:
		ROL EAX, 16
		TEST DX, DX
		JZ Passo
		ROR ESI, 16
		INC SI // ESI(16 Bit a sinistra): Numero Sequenze di 0
		ROL ESI, 16
Passo:
		MOV AX, DX
		XOR DX, DX // Azzero il contatore degli 0, perchè ora c'è un uno e quindi non è più in sequenza
		ROR EDX, 16
		ADD DX, AX
		ROL EDX, 16 // EDX(16 Bit a sinistra): Numero Totale degli 0
		XOR AX, AX
		ROR EAX, 16

		INC BX // BX: Contatore degli 1
		JMP ControlloCiclo
SalvaZero:
		TEST BX, BX // CMP BX, 0
		JZ Dopo2
		CMP BX, maxLungSeq1
		JNG ControlloMin1 // Se BX non è più grande di maxLungSeq1 salto a ControlloMin1, altrimenti salvo il suo valore in maxLungSeq1
		MOV maxLungSeq1, BX
ControlloMin1:
		CMP BX, minLungSeq1
		JG Dopo2 // Se BX è più grande di minLungSeq1 allora salto, altrimenti salvo il suo valore in minLungSeq1
		MOV minLungSeq1, BX
Dopo2:
		TEST BX, BX
		JZ Passo2
		ROR EDI, 16
		INC DI // Nei 16 bit irraggiunbili di EDI salvo il numero di sequenze a 1
		ROL EDI, 16
Passo2:
		ROL EAX, 16
		MOV AX, BX
		XOR BX, BX // Azzero il contatore degli 1, perchè ora c'è uno zero e quindi non è più in sequenza
		ROR EBX, 16
		ADD BX, AX // Salvo nei 16 bit irraggiungibili di EBX il valore totale degli 1
		ROL EBX, 16
		XOR AX, AX
		ROR EAX, 16
		// EBX(16 Bit a sinistra): Numero Totale di 1; EDI(16 Bit a sinistra): Numero di sequenze a 1

		INC DX //DX: Contatore degli 0
ControlloCiclo:
		INC DI
		CMP DI, len // Controllo se DI: Contatore bits è uguale a len
		JNE PreInizio
		// Controllo Finale per gli ultimi bits
PuliziaStack:
		XOR AX, AX
		POP AX
		XOR AX, AX // Pulisco lo stack
ControlloUltimiBits:
		TEST DX, DX // Se DX: Contatore corrente degli 0 è vuoto allora salto i passaggi successivi
		JZ Successivo2
		XOR SI, SI
		ROR ESI, 16
		INC SI // Aggiungo 1 al Numero Sequenze di 0
		ROL ESI, 16
		XOR AX, AX
		MOV AX, DX
		ROR EDX, 16
		ADD DX, AX // Salvo nei 16 bit a sinistra di EDX il valore totale degli 0
		ROL EDX, 16
		XOR AX, AX
		CMP DX, maxLungSeq0 // Controllo se DX è maggiore a maxLungSeq0, se lo è salvo il suo valore nella variabile
		JNG Successivo
		MOV maxLungSeq0, DX
Successivo:
		CMP DX, minLungSeq0 // Controllo se DX è minore di minLungSeq0, se lo è salvo il suo valore nella variabile
		JG Successivo2
		MOV minLungSeq0, DX
Successivo2:
		TEST BX, BX // Controllo se BX: Contatore corrente degli 1 è vuoto, se lo è salto questi passaggi di controllo
		JZ ControlloMinLungSeq01
		XOR DI, DI
		ROR EDI, 16
		INC DI // Incremento di 1 il Numero delle Sequenze di 1
		ROL EDI, 16
		MOV AX, BX
		ROR EBX, 16
		ADD BX, AX // Salvo nei 16 bit a sinistra di EBX il valore totale degli 1
		ROL EBX, 16
		XOR AX, AX
		CMP BX, maxLungSeq1 // Controllo se BX è maggiore di maxLungSeq1, se lo è salvo il suo valore nella variabile
		JNG Successivo3
		MOV maxLungSeq1, BX
Successivo3:
		CMP BX, minLungSeq1 // Controllo se BX è minore di minLungSeq1, se lo è salvo il suo valore nella variabile
		JG ControlloMinLungSeq01
		MOV minLungSeq1, BX

ControlloMinLungSeq01:
		CMP minLungSeq1, 20000 // Se il valore di minLungSeq1 non è variato, rispetto a quello che era stato assegnato provvisoriamente all'inizio
		JNE NonAzzeraMin1 
		MOV minLungSeq1, 0 // allora azzero il suo valore
NonAzzeraMin1:
		CMP minLungSeq0, 20000 // Se il valore di minLungSeq0 non è variato, rispetto a quello che è stato assegnato, provvisoriamente, all'inizio
		JNE MediaSottoSequenze
		MOV minLungSeq0, 0 // allora azzero il suo valore
		
MediaSottoSequenze:
		XOR BX, BX
		XOR DX, DX
		// Media Sotto-Sequenze di 0
		ROR EDX, 16 // Numero Totale degli 0
		XOR SI, SI
		ROR ESI, 16 // Numero delle Sequenze di 0
		XOR AX, AX
		MOV AX, DX // Salvo in AX il valore del numero totale di bits a zero
		XOR DX, DX
		TEST AX, AX // Controllo se AX è vuoto
		JZ SaltaDivisione
		IDIV SI // Divido AX: Numero Totale di bits a 0 per SI: Numero Totale Sequenze di bits a 0
SaltaDivisione:
		MOV CX, AX // Salvo il risultato della divisione in CX
		TEST CX, CX // Controllo se CX sta a zero
		JZ MediaSottoSequenza0
		MOV BX, DX // Salvo in BX: il resto della divisione
		XOR AX, AX // Pulisco AX
		MOV AX, 2 // Salvo 2 in AX
		IMUL DX // Moltiplico DX * AX ( che era 2)
		CMP AX, SI // Controllo AX che ha il risultato della moltiplicazione precedente e SI: che era il divisore nella divisione precedente
		JNGE MediaSottoSequenza0 // Se AX non è maggiore o uguale a SI
		INC CX // Incremento CX, che aveva il risultato della divisione precedente
MediaSottoSequenza0:
		MOV mediaLungSeq0, CX // Salvo in mediaLungSeq0 il valore di CX

		XOR AX, AX // Pulisco i registri
		XOR DX, DX
		XOR CX, CX
		XOR BX, BX
		XOR SI, SI
		// Media Sotto-Sequenze di 1
		ROR EBX, 16 // Numero Totale di 1
		XOR DI, DI
		ROR EDI, 16 // Numero Sequenze di 1
		XOR AX, AX
		MOV AX, BX // Salvo in AX: Numero Totale di bits a 1
		TEST AX, AX // Controllo se AX è vuoto
		JZ SaltaDivisione2
		IDIV DI // Divido AX: Numero Totale di bits a 1 per DI: Numero Sequenze di bits a 1
SaltaDivisione2:
		MOV CX, AX // CX: Quoziente
		TEST CX, CX // Controllo se CX è vuoto
		JZ MediaSottoSequenza1
		XOR BX, BX
		MOV BX, DX // Salvo in BX il valore del resto
		XOR AX, AX // Pulisco AX
		MOV AX, 2 // Salvo 2 in AX
		IMUL BX // Moltiplico AX: 2 * BX
		CMP AX, DI // AX: Risultato della moltiplicazione e DI: Numero Sequenze di bits 1 (Divisore nella divisione precedente)
		JNGE MediaSottoSequenza1 // Se AX non è maggiore o uguale a DI
		INC CX // Incremento di 1 il valore di CX: Quoziente
MediaSottoSequenza1:
		MOV mediaLungSeq1, CX // Salvo in mediaLungSeq1 il valore di CX
	}

	// Stampa su video
	printf("Lunghezza minima delle sotto-sequenze di 0: %d\n", minLungSeq0);
	printf("Lunghezza massima delle sotto-sequenze di 0: %d\n", maxLungSeq0);
	printf("Lunghezza Media delle sotto-sequenze di 0: %d\n", mediaLungSeq0);
	printf("Lunghezza minima delle sotto-sequenze di 1: %d\n", minLungSeq1);
	printf("Lunghezza massima delle sotto-sequenze di 1: %d\n", maxLungSeq1);
	printf("Lunghezza Media delle sotto-sequenze di 1: %d\n", mediaLungSeq1);
}

