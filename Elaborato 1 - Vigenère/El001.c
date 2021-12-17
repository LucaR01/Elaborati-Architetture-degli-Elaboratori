/*******************************************************************************
*                                                                              *
*                   Architetture dei sistemi di Elaborazione                   *
*                                                                              *
********************************************************************************

Elaborato 1

Descrizione: Data una stringa C (terminata dal carattere nullo), contenente una
			 frase (ossia parole separate da spazi e/o segni di punteggiatura),
			 trovare al suo interno la parola più lunga e successivamente
			 cifrare/decifrare un testo con il cifrario di Vigenère, usando come
			 chiave la parola trovata.

Note:
- In caso di parole di uguale lunghezza, considerare la prima da sinistra.
- La parola più lunga va copiata in un array di caratteri come stringa C
  (terminata dal carattere nullo).
- I segni di punteggiatura da considerare sono: ".,;:'?!"
- Nel testo cifrato il codice ASCII di ogni carattere è aumentato del codice ASCII
  del corrispondente carattere nella parola chiave sovrapposta (e ripetuta se
  necessario) al testo.

********************************************************************************/

#include <stdio.h>

void main()
{
	// Input
	char frase[1024] = "Cantami, o Diva, del Pelide Achille l'ira funesta che infiniti addusse lutti agli Achei";
	char testo[1024] = "Questo e' il testo da cifrare";
	//char frase[1024] = "Carlo e Carla";
	//char frase[1024] = "ciao a tutti gli infinitesimi";
	//char frase[1024] = " ciao";
	//char testo[1024] = "\xBA\xE3\xCB\xDC\xE2\xD8\x94\xCA\x9A\x89\xD6\xD5\x89\xE2\xCB\xDC\xE2\xD8\x94\xC9\xD4\x89\xD0\xD2\xCF\xE0\xC7\xDB\xD3";
	//char frase[1024] = ",:a,.";
	//char testo[1024] = "aBcD";
	//char testo[1024] = "\xC2\xA3\xC4\xA5"; // decifratura di ,a:a,. (frase precedente)
	//char frase[1024] = ""; // Se è vuoto, risultato = vuoto, parolaMax = vuoto;
	//char testo[1024] = "ciao";
	//char frase[1024] = "ciao";
	//char testo[1024] = ""; // In questo caso comunque cerca la parolaMax
	//char testo[1024] = "\xBA\xE3\xCB\xDC\xE2\xD8\x94\xCE\x90\x8E\xCF\xD5\x8E\xDD\xD9\xDC\xDD\xDD\x86\xCD\xCF\x89\xD7\xD2\xCF\xE0\xC7\xDB\xD3";
	char decifra = 0; // 0 = cifra; 1 = decifra

	// Output
	char parolaMax[100];	//La parola più lunga
	char risultato[1024]; 	//Il testo cifrato/decifrato

	// Blocco assembler
	__asm
	{
		XOR ECX, ECX // Pulisco questi registri che andrò ad utilizzare
		XOR EAX, EAX
		XOR EDX, EDX
		XOR EBX, EBX
		// Controllo se la frase è vuota (ovvero frase[1024] = "";) 
		CMP frase[ECX], '\0' // Se è vuota non è necessario fare i passaggi per trovare la parolaMax e la cifratura/decifratura
		JNE Inizio
		MOV parolaMax[ECX], '\0' // Salvo in parolaMax il terminatore (ovvero parolaMax = niente)
		MOV risultato[ECX], '\0' // Salvo in risultato il terminatore (ovvero risultato = niente)
		JMP Fine
Inizio:		
		JMP ControlloCarattere // Vado a controllare se il carattere è uno spazio, una virgola, ecc..
Ciclo:
		INC ECX // Aumento l'indice dello scorrimento delle lettere della frase
		CMP frase[ECX], '\0'
		JNE Inizio // Se non è arrivato alla fine della frase, continuo il ciclo
		JE ParolaMax // ALtrimenti vado a formare la parolaMax
ControlloCarattere:
		XOR AH, AH
		MOV AH, 32 // Utilizzo AH come controllo caratteri
		MOV AL, frase[ECX] // Salvo in AL il carattere corrente
		MOV DL, frase[ECX-1] // Salvo in DL il carattere precedente
		MOV BL, frase[ECX+1] // Salvo in BL il carattere successivo
ControlloCarattere2:
		CMP DL, AH // Controllo se il carattere precedente è uno spazio, virgola, ecc..
		JNE Passaggio
		MOV DL, 1 // Se DL è 1 allora vuol dire che è uno spazio, virgola,ecc..
Passaggio:
		CMP BL, AH // Controllo se il carattere successivo è uno spazio, virgola, ecc..
		JNE Passaggio2
		MOV BL, 1 // Se BL è 1 allora vuol dire che è uno spazio, virgola, ecc..
Passaggio2:
		CMP AL, AH
		JE Ciclo // Se il carattere corrente è uno spazio, virgola,ecc.. torno all'inizio del ciclo ed incremento l'indice della frase
Passaggio3:
		INC AH
		CMP AH, 34 // Controllo dal carattere 32 al 33 (ovvero lo spazio e il punto esclamativo)
		JNE Salta
		MOV AH, 44 // Controllo del carattere 44 della tabella ASCII (ovvero la virgola)
Salta:
		CMP AH, 45
		JNE Salta2
		INC AH // Controllo del carattere 46 della tabella ASCII (ovvero il punto)
Salta2:
		CMP AH, 47
		JNE Salta3
		MOV AH, 58 // Controllo dal carattere 58 al 59 della tabella ASCII (ovvero : e il ;)
Salta3:
		CMP AH, 60
		JNE Salta4
		MOV AH, 63 // Controllo del carattere 63 della tabella ASCII (ovvero ?)
Salta4:
		CMP AH, 64
		JNE Salta5
		MOV AH, 96 // Controllo del carattere 96 della tabella ASCII (ovvero ')
Salta5:
		CMP AH, 97
		JNE Salta6
		MOV AH, -52 // Controllo il carattere prima della prima lettera
Salta6:
		CMP AH, -51
		JNE ControlloCarattere2
		// Controllo se il carattere precedente a quello corrente è uno spazio, virgola, ecc..
ControlloPrimaLettera:
		CMP DL, 1// Controllo la lettera Precedente. Se DL è 1 vuol dire che è uno spazio, virgola, ecc..
		// Se il carattere precedente è uno spazio, virgola, ecc.. e quella corrente è una lettera allora è la prima lettera della parola
		JNE ControlloUltimaLettera
Base:
		MOV ESI, ECX // Salvo l'indice di ECX perchè è la base (ovvero la prima lettera della parola)
		// Faccio il controllo per vedere se è una parola formata da una sola lettera
ControlloUltimaLettera:
		CMP BL, 1 // Controllo la lettera Successiva (Se BL è 1 vuol dire che è uno spazio, virgola, ecc..)
		JE UltimaLettera // Se il carattere successivo è uno spazio, virgola, ecc.. e quella corrente è una lettera allora (quella corrente) è l'ultima lettera della parola
		CMP frase[ECX+1], '\0' // Controllo se il carattere successivo è il terminatore di controllo (ovvero la fine della frase)
		JNE Ciclo
UltimaLettera:
		MOV EDI, ECX // Salvo in EDI l'indice di ECX perchè è l'ultima lettera della parola
Parola:
		XOR AX, AX // Pulisco AX
		ROR EAX, 16 // Sposto,a destra,dai 16 bit non raggiungibili di EAX, il valore della lunghezzaMax (lunghezza parola più lunga).
		INC EDI // Aggiungo 1 per l'ultima lettera
		SUB EDI, ESI // Numero lettere della parola (indice ultima lettera - indice prima lettera)
		CMP EAX, EDI // Se EAX non è più grande di EDI, salvo in EAX il valore di EDI (lunghezza parola più lunga)
		JE SaltoIndiciParola // Faccio questa JE perchè salvo come parolaMax solo la prima occorrenza e non la seconda (cioè se due parole sono di lunghezza uguale e sono entrambe la parolaMax 
		// salvo come parolaMax solo la prima e non la seconda)
		CMOVNG EAX, EDI // se EAX non è più grande di EDI allora salvo in EAX la lunghezza parola più lunga; EAX = Lunghezza della Parola più lunga
		CMP EAX, EDI 
		JE IndiciParola // Se EAX ed EDI sono uguali salvo i nuovi indici della prima lettera e dell'ultima lettera
		JNE SaltoIndiciParola
SaltoIndiciParola:
		ROL EAX, 16 // Risposto nei 16 bit irragiungibili di EAX, il valore della lunghezza della parola più lunga.
		JMP Ciclo
IndiciParola:
		ROL EAX, 16
		XOR EBX, EBX
		XOR EDX, EDX
		DEC EDI // Decremento EDI di 1 perchè prima avevo aggiunto 1 per l'ultima lettera
		ADD EDI, ESI // Riaggiungo a EDI ciò che avevo sottrato per trovare la lunghezza
		// Salvo Indice Ultima Lettera
		ROR EDX, 16
		MOV EDX, EDI
		ROL EDX, 16 // Salvo l'indice ultima lettera nei 16 bit non raggiungibili di EDX
		// Salvo Indice Prima Lettera
		ROR EBX, 16
		MOV EBX, ESI
		ROL EBX, 16 // Salvo l'indice prima lettera nei 16 bit non raggiungibili di EBX
		// Pulisco i due indici
		XOR EDI, EDI
		XOR ESI, ESI
		JMP Ciclo

ParolaMax:
		XOR EAX, EAX
		XOR ECX, ECX
		XOR ESI, ESI // Ora uso ESI come indice della parolaMax
		XOR DX, DX
		XOR BX, BX
		ROR EDX, 16 // Porto in DX il valore dell'indice ultima lettera
		ROR EBX, 16 // Porto in BX il valore dell'indice prima lettera
		INC EDX // Aumento di 1 EDX per l'ultima lettera
CicloParolaMax:
		MOV AL, frase[EBX] // Salvo in AL una lettera della parolaMax
		MOV parolaMax[ESI], AL // Salvo in parolaMax, la lettera che avevo salvato in AL
		INC EBX
		INC ESI
		CMP EBX, EDX // Confronto se EBX: indice prima lettera è uguale a EDX: indice ultima lettera
		JNE CicloParolaMax
		MOV parolaMax[ESI], '\0' // Aggiungo a parolaMax, nel suo ultimo indice, il terminatore.
		XOR EBX, EBX
		XOR EDX, EDX
		// Controllo se il testo è vuoto
		CMP testo[EBX], '\0'
		JNE Scelta
		MOV risultato[EBX], '\0'
		JMP Fine
Scelta:
		MOV AH, decifra
		TEST AH, AH // equivalente a CMP AH, 0
		JZ Cifrare
		JMP Decifrare

Cifrare:
		// CIFRATURA
		XOR EAX, EAX
CicloCifratura:
		MOV DL, testo[ECX] // Salvo in DL una lettera del testo
		MOV DH, parolaMax[EAX] // Salvo in DH una lettera della parolaMax
		ADD DL, DH // Sommo la lettera del testo e la lettera della parolaMax
		MOV risultato[ECX], DL // Salvo in risultato la somma
		INC ECX
		INC EAX
		CMP parolaMax[EAX], '\0' // Controllo se ho raggiunto il termine della parolaMax se è così azzero l'indice
		JNE SaltaAzzera
		XOR EAX, EAX
SaltaAzzera:
		CMP testo[ECX], '\0' // Controllo se ho raggiunto il termine del testo
		JNE CicloCifratura
		MOV risultato[ECX], '\0' // Salvo il terminatore nell'ultimo indice del risultato
		JMP Fine

Decifrare:
		// DECIFRATURA
		XOR EAX, EAX
CicloDecifratura:
		MOV DL, testo[ECX] // Salvo in DL una lettera del testo
		MOV DH, parolaMax[EAX] // Salvo in DH una lettera della parolaMax
		SUB DL, DH // Sottraggo la lettera del testo e la lettera della parolaMax
		MOV risultato[ECX], DL // Salvo il risultato della sottrazione in risultato
		INC ECX
		INC EAX
		CMP parolaMax[EAX], '\0' // Controllo se ho raggiunto il termine della parolaMax se è così azzero l'indice
		JNE SaltaAzzera2
		XOR EAX, EAX
SaltaAzzera2:
		CMP testo[ECX], '\0' // Controllo se ho raggiunto il termine del testo
		JNE CicloDecifratura
		MOV risultato[ECX], '\0' // Salvo il terminatore nell'ultimo indice del risultato
Fine:
	}

	// Stampa a video
	printf("Frase: %s\n", frase);
	printf("Testo: %s\n", testo);
	printf("Parola piu' lunga: %s\n", parolaMax);
	// Stampa su video testo cifrato
	printf("Risultato: %s\n", risultato);
	printf("Risultato (in esadecimale):\n");
	// N.B. Nella stringa precedente alcuni caratteri possono non essere stampabili: 
	//		crea anche una stringa con tutti i caratteri come codici ascii esadecimali
	char* t = risultato;
	while (*t)
	{
		printf("\\x%02X", (unsigned char)(*t++));
	}
}


