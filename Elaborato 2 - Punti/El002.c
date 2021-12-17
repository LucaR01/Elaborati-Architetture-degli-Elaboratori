/*******************************************************************************
*                                                                              *
*                   Architetture dei sistemi di Elaborazione                   *
*                                                                              *
********************************************************************************

Elaborato 2
Descrizione: Dato un insieme di n punti m-dimensionali, scomporre in fattori 
             primi il prodotto degli indici del punto pi� vicino e di quello
			 pi� lontano rispetto a un punto p.

Note:
- I valori delle coordinate dei vari punti sono compresi nell�intervallo
  [-100;100].
- Per trovare la distanza minima e massima non � necessario calcolare la
  radice quadrata.
- I fattori primi devono essere riportati nell'array in ordine crescente.

********************************************************************************/

#include <stdio.h>

void main()
{
	// Input
	/*short pointP[] = { -52,13,47,-3 }; // TEST DEL SITO
	short pointset[] = { -33,29,-29,-77,-43,34,-97,-80,7,-37,83,-52,4,39,-64,9,12,66,49,-91,43,33,88,-93 };
	unsigned int m = 4;*/
	/*short pointP[] = { 44,-6,-81,77,-77,49,-77,-3,-54,32,40,39,61,-6,39,-40,51,29,73,-60 };
	short pointset[] = { -63,-21,-1,-81,-10,43,62,52,-43,-78,5,-60,-44,-66,-4,-11,6,39,100,50,32,22,87,-81,20,-76,55,-76,-45,-50,75,7,-63,25,56,-36,95,100,-13,-19,87,-28,-61,-76,-74,0,-17,26,99,-51,55,-88,30,-77,8,15,-8,-20,0,-34,89,38,-4,-93,-52,99,-98,31,-21,-69,-6,6,-48,19,63,-41,-17,63,93,-81,41,-72,-75,-95,-4,62,77,-86,-83,-60,72,15,0,-79,-7,-51,77,-68,77,-72,-2,52,-54,68,56,-52,60,-89,-40,-52,-68,30,-13,-19,25,60,12,-9,12,-14,-79,88,14,-61,-41,80,-94,-69,-75,14,-17,-50,87,65,21,90,83,-42,-50,-53,-98,66,55,69,-93,-58,-73,-82,-4,33,37,-14,21,-10,-94,11,-62,-93,8,76,-58,29,86,46,65,83,44,23,61,36,78,-46,-60,-36,-16,-44,-68,45,-69,-83,52,88,35,-7,78,98,29,-4,58,-90,51,75,51,-26,-95,-27,81,-91,-96,-75,-2,5,-42,61,56,-18,-55,-44,-94,51,-22,-7,77,-9,-77,-46,95,-7,68,67,-47,-52,65,51,85,-98,4,67,-41,-90,-25,-77,41,-95,20,-53,30,74,37,-5,53,-27,-11,-94,32,-42,98,-40,-50,51,-22,-13,-59,-63,73,-51,40,8,76,53,79,-21,98,96,-25,-46,53,71,71,77,25,-80,56,-27,-86,81,60,59,-82,27,-96,-56,16,8,33,89,83,3,-67,-30,7,-79,98,84,16,-26,-25,-7,31,-22,5,-73,-11,-27,-74,-43,31,68,-77,92,-10,82,-10,-51,48,35,63,-11,-37,-13,-29,-50,37,1,-30,3,-78,73,57,40,5,-34,-73,40,-79,78,55,-58,-18,-25,-43,-85,-21,-58,81,25,32,49,-65,82,11,86,-70,-56,-94,-45,-9,88,-97,23,-66,59,-89,-16,-13,-77,55,50,-73,71,80,21,-93,88,-70,-44,71,-5,21,45,72,-26,37,76,-71,20,-64,84,34,67,-13,68,-62,59,-60,-2,-97,96,55,57,71,82,21,-36,-99,90,79,-58,-87,50,-16,96,-33,-41,51,61,-79,-65,-46,67,88,72,-84,-39,-16,-88,-17,-52,48,32,-48,76,40,65,74,90,54,-27,75,-61,42,95,70,84,-18,-9,0,80,-92,-20,-23,69,41,89,69,100,66,-41,81,89,7,30,-5,-18,-2,9,-44,3,-15,62,-94,49,-39,-85,-75,94,-98,-68,80,93,13,3,-60,-33,-45,-16,-66,52,96,75,-76,-6,-8,86,32,-89,0,-13,-14,73,-65,98,-6,-53,-27,28,8,26,63,76,98,33,-20,88,-24,-96,-10,-73,-73,-87,-25,4,8,11,38,13,-43,-25,-17,-86,-6,15,47,-94,58,15,-92,94,95,27,77,8,90,-81,78,-9,-87,4,10,28,22,-28,-40,-28,-2,31,-10,84,9,61,-29,-68,-57,48,-18,-17,86,-26,-70,61,96,-4,-67,0,-63,67,15,-12,33,-54,-1,53,65,55,-7,-79,-46,-25,8,-74,-75,-76,-16,-67,-45,44,-35,-59,38,-6,5,40,-26,49,33,-75,-61,60,-65,32,-84,-99,-49,-37,-38,19,-32,-12,-45,-40,-72,11,66,-96,35,71,-88,100,-55,-7,1,-26,51,-61,41,59,-21,-85,-78,-33,82,-6,-61,77,-90,-76,74,-79,72,37,-24,78,86,-23,-34,95,74,-30,-87,62,-88,-60,15,42,-70,43,-50,-88,22,3,-60,-48,-34,89,-21,35,-29,89,95,11,97,92,-72,9,-83,24,-12,-26,73,47,85,-92,-99,-40,-46,42,79,-3,47,-33,74,62,-1,-32,-4,-77,11,98,98,31,23,86,-25,3,65,-79,-88,-94,25,6,-46,77,-61,75,19,-69,-50,-94,34,37,56,74,-58,27,38,-65,-8,60,-88,94,-88,-10,-24,-58,-76,100,33,-1,-5,-67,30,73,73,-60,-87,97,23,25,50,-36,73,5,-36,-40,76,49,43,49,66,30,29,-48,95,31,-7,64,1,98,51,19,-2,52,11,0,-93,84,-99,-99,14,41,12,68,-90,48,-80,8,-74,-85,-34,-25,-44,85,34,65,4,-22,79,-59,48,-51,-4,26,74,-70,67,-79,94,64,-47,93,48,42,-65,-76,-83,62,-59,-54,10,86,38,-15,31,-24,-37,14,-83,47,97,30,-95,60,-46,-36,-56,87,94,80,82,100,15,-37,63,-26,27,15,49,9,47,42,-64,32,31,63,12,-89,96,-2,68,-48,-97,-53,67,24,87,88,-12,72,81,-69,69,-38,-35,11,-30,-26,23,-44,49,48,66,9,100,-46,-6,-27,-71,-8,52,-67,91,-5,-88,29,96,-33,-4,-61,-13,39,-73,78,29,16,74,75,-33,-81,-8,-63,-12,39,50,-81,-13,-5,-52,13,-71,13,59,96,-81,47,-60,-27,-50,36,16,-97,79,-16,70,-91,21,88,81,-16,-20,20,-94,-91,-100,15,45,-48,46,93,-59,1,-81,83,-91,74,80,-69,58,82,-25,1,24,31,4,-12,-41,-96,70,40,-2,0,15,65,-68,10,7,50,96,5,-98,89,27,-43,-5,-85,85,96,-25,96,-71,-10,-71,99,-92,80,96,-24,5,12,-44,41,-18,-95,-6,42,86,-46,51,-1,-33,-70,-64,-47,80,-14,74,-33,-65,-11,4,-37,30,75,10,-92,-30,16,56,-47,15,-70,-55,-17,-51,-38,6,21,63,53,-71,30,-55,76,28,100,-46,77,-81,23,-95,28,-59,-85,-92,93,-90,8,-4,-14,-28,-30,-1,-2,84,-63,86,53,-96,17,80,-48,4,-18,-40,74,-83,54,-54,10,54,-7,-3,-67,-53,87,90,-71,-25,-44,-49,98,-75,-23,-19,59,-69,48,92,-9,-86,2,72,2,43,54,-76,59,56,-66,76,-44,-39,86,32,79,74,-34,-50,98,-53,56,-23,49,-34,82,-74,-73,-99,1,43,-30,63,56,-4,-48,21,95,-10,-7,63,-69,-27,-59,-20,95,36,-61,45,2,86,66,-3,95,-57,-42,-76,-77,-64,61,27,98,57,-46,-9,5,-6,6,-10,-20,-43,79,76,58,-66,-84,-17,-64,-32,-29,-55,88,-18,0,16,78,74,68,13,-63,-73,-2,58,29,67,65,-26,-81,50,76,1,-70,50,-35,-56,-94,90,39,60,-74,76,89,55,66,15,40,15,-43,38,14,32,27,93,-48,-48,59,-80,-53,92,-30,43,-37,-14,-7,71,-85,-63,-83,-45,9,89,-66,-93,-14,-38,-61,44,93,-87,-74,-51,-84,-19,-64,-57,74,-63,-3,-87,-15,86,43,48,-10,-16,12,2,-38,96,0,2,-2,-98,-72,25,-2,19,7,91,-88,-85,-72,-67,65,-80,26,83,-50,-51,97,78,41,-97,70,24,-54,-14,18,-98,50,37,-18,98,14,25,51,-86,-48,11,46,-46,31,6,-100,-30,58,9,84,-30,58,30,-48,-88,99,23,61,-5,-68,5,-21,-89,-99,4,-59,-25,34,-70,20,-60,-31,12,30,39,3,42,-53,-65,-98,0,66,37,3,-52,-56,-81,-15,-31,99,92,64,-44,82,47,-68,35,-47,-73,-35,26,36,27,90,44,-100,-54,100,14,10,-43,-25,26,-8,33,39,43,9,54,-41,-79,91,-35,-69,28,-24,-88,30,84,7,69,-11,-81,70,-23,65,-62,47,60,-53,99,-80,72,59,42,16,-63,65,-51,-93,-11,-75,-1,68,-57,36,-29,-4,-39,-33,88,17,-84,-93,42,69,-45,56,-86,68,1,96,50,7,-39,-99,-81,6,-10,-88,-62,-52,-20,76,-83,43,90,-48,26,42,-6,43,-15,-8,-41,-19,-97,64,-83,73,-40,-19,50,-19,7,-7,-24,93,7,-58,16,65,-95,-51,-72,40,-64,-59,90,100,79,-97,-71,-28,-26,58,11,-43,-53,80,98,-45,-11,18,53,57,-2,99,-32,24,-34,98,45,-16,-75,29,38,-64,-37,20,-56,63,75,-82,95,-44,-49,-22,-93,50,83,-81,45,28,-55,-39,-25,-12,-4,-29,-58,-62,73,-35,33,81,-42,46,-54,45,-81,-25,94,28,35,-65,-20,-29,24,-4,6,-80,92,19,42,-53,-47,-83,-62,65,-46,-50,40,92,-22,-94,90,9,-15,-87,98,6,-69,-38,30,8,-75,-83,93,-90,81,-97,64,100,66,-79,-54,-46,24,-14,28,-60,7,-18,-9,70,35,-98,-50,28,-55,72,87,11,-2,100,90,30,89,-67,-78,-65,-75,-72,85,-50,-14,40,-74,-44,61,35,85,99,-15,58,99,49,71,60,73,-77,67,-36,65,-92,-83,-47,2,66,-68,17,-35,-10,-36,-8,-85,-21,-2,-59,-16,95,76,94,68,10,87,88,-75,41,-99,-60,59,-71,-40,100,-32,61,-36,76,-68,-68,-62,-40,-77,-56,-30,-6,35,93,42,20,-49,30,-24,79,-53,74,-3,-46,-78,-70,-72,61,65,93,58,-64,-70,-35,-76,-45,-86,23,-92,-49,57,16,71,24,-60,-7,-48,-67,100,-18,90,-71,53,-18,52,-5,-37,-91,54,-98,-96,-22,-4,-69,-14,-67,-36,-30,69,-13,5,28,22,-75,-79,31,-98,74,-86,29,78,95,61,-18,-98,28,-16,48,13,29,92,-95,70,-95,-53,-22,-80,39,-63,-94,-72,83,-35,13,78,-39,8,27,-39,-79,-7,-10,95,-76,-75,-91,17,-87,-72,59,50,17,58,-60,-5,-1,59,16,79,43,10,-36,36,-93,1,95,29,-52,5,42,-80,57,-13,-9,-64,1,-90,45,81,-63,62,-93,11,-21,-43,12,-76,-75,-83,-22,2,92,49,18,11,-72,55,88,23,-70,-20,-31,8,-13,38,93,-71,-33,-96,94,-11,-87,36,41,82,3,53,-43,51,89,70,4,-70,-73,-60,-72,-93,69,80,-93,47,-77,-78,50,57,-8,-1,-76,41,-36,-18,58,-79,-77,90,-12,-44,-92,36,-93,-24,-3,-64,34,-39,77,-61,-19,-53,9,86,-39,-13,97,-53,-35,92,87,85,-10,-96,29,16,-14,7,-88,-17,-94,-62,52,73,100,-68,72,32,-50,87,-12 };
	unsigned int m = 20;*/ // test el2
	/*short pointP[] = { 60 }; // TEST 4
	short pointset[] = { -38,59,89,28,-44,99,80,97,81,77,-57,-38,-55,17,12,54,76,-22,-45,-99,60,25,-71,4,-63,62,-78,-6,62,-18,38,10,-9,31,46,-71,32,-24,-75,-19,97,-33,-66,39,100,-24,-32,-100,-47,93,-98,-72,-4,39,58,37,30,-45,52,66,-66,4,-83,15,-58,-34,52,31,0,-12,80,-22,50,97,-42,34,-9,-9,5,61,-6,-79,-59,70,-20,10,-86,53,73,-92,0,-24,24,-41,-54,-7,-50 };
	unsigned int m = 1;*/ 
	/*short pointP[] = { -87,84,-84,70,-69 }; // TEST 3
	short pointset[] = { 1,-75,-45,66,23,-78,-64,-54,64,-97,-93,-68,-5,88,-57,-67,25,-86,41,-72,0,-17,64,38,55,25,47,96,-26,-47,45,-46,-47,-25,62,57,93,38,-84,-86,-28,-34,-99,45,77,-83,18,-54,80,39,82,-11,-71,26,32,-82,-38,18,-89,99,-25,-59,72,10,-41,79,-29,39,79,-29,-86,-6,-22,73,71,-66,-19,-81,61,37,-94,0,-85,35,-29,-45,-76,28,44,44,-5,-25,27,-82,39,-69,-6,-8,-14,98,46,79,-33,9,24,-12,-89,-44,55,-3,37,-57,57,-26,92,76,-75,-64,-62,-97,54,44,95,-65,76,39,68,-40,-67,40,40,90,33,64,92,-73,-68,7,-89,84,-56,68,73,-53,-94,-48,19,-48,-74,64,-95,-43,-47,-18,-57,-99,84,-68,33,85,21,52,-77,-85,58,48,10,93,-17,64,43,19,-75,-46,60,86,72,48,-72,24,-80,15,-67,-30,35,-18,36,-50,20,90,-56,-100,75,-74,-37,-7,45,57,-10,-42,42,26,69,-37,-79,-13,-68,99,23,-43,-71,-64,-97,-92,65,-95,18,53,-19,-25,-88,-40,-28,-6,20,43,45,100,92,-34,-60,-86,-42,71,82,-6,46,70,-51,-53,-50,37,27,-37,60,-93,97,66,-39,-42,75,93,-24,-85,-54,-18,-46,-25,43,-22,43,-68,-93,-43,-84,-86,78,-67,-73,-30,-41,48,4,-67,-76,-25,33,-91,34,12,46,79,38,34,-8,-52,39,-57,24,0,-60,-29,-74,71,5,-82,30,-30,-54,45,-70,64,38,91,99,-74,-11,-57,91,71,50,-56,42,-69,33,64,-5,-26,65,69,-24,35,9,28,-70,89,21,33,29,-94,46,-38,63,89,-18,83,-60,47,36,-35,60,-4,-48,53,50,96,30,96,-62,41,23,-44,5,-22,-31,-5,-46,-90,61,-91,5,56,14,85,-75,-13,-19,53,50,51 };
	unsigned int m = 5;*/
	/*short pointP[] = { 45,-45,15,-30,76,32,25,63,32,-27,-81,-15,28,-74,-97 }; // TEST 2
	short pointset[] = { 52,69,8,-12,-35,-86,-14,38,25,61,-67,42,-42,-68,-98,-60,20,-30,-94,-15,-41,-35,-82,-62,3,-52,-89,-63,56,-93,40,94,-30,34,5,-24,3,-12,78,-55,-41,18,91,10,42,90,-34,31,29,-68,0,-85,22,41,44,-14,51,-31,86,-84,-97,-52,82,18,-80,-60,-28,24,27,26,37,-69,-8,61,-74,42,-25,8,-4,14,83,-20,8,24,7,25,-28,29,91,-82,26,-66,3,61,-59,-90,37,-28,-10,2,17,43,-96,-97,-5,-32,23,61,15,-98,-89,-57,74,-29,-66,23,41,-43,-90,-4,68,44,34,8,-100,3,29,32,20,-84,-95,-98,-83,94,97,-61,-24,5,-72,-61,-99,12,-86,89,-93,-18,-40,-69,26,19,-30,-21,-39,95,35,74,-91,-4,-97,93,40,92,-59,-2,97,-91,-75,80,-25,95,-53,-65,-71,72,-6,-44,29,45,1,18,-58,-3,-95,-100,46,26,41,-77,-41,-78,-70,80,2,-64,0,-91,-29,16,92,99,-43,-19,57,31,-29,-66,-50,-10,0,-22,-56,-36,96,-15,50,-57,87,-60,52,-30,-32,-98,20,-48,65,-33,34,93,-28,-15,86,-87,54,3,-39,62,40,-26,30,12,-24,-49,23,81,78,67,85,-84,-14,-43,-77,-69,64,22,30,-46,61,4,67,-96,1,-43,-82,-85,-7,-69,11,-8,-76,89,3,12,11,-60,95,-83,-20,40,-25,99,-17,17,7,-85,-39,55,-50,-68,73,-94,-100,-65,8,25,-89,-82,-67,7,-12,47,-44,-8,92,-3,54,12,20,23,28,13,75,-79,-71,69,22,84,50,-97,55,39,81,-21,19,-82,89,-33,-96,86,-71,76,85,73,-49,28,42,91,25,-90,-39,50,-66,28,5,-40,-68,80,-94,39,-97,-73,-31,-71,53,49,67,78,73,74,9,-13,7,35,-6,52,29,-99,70,1,-74,31,-42,40,42,-96,5,-47,75,-41,86,-92,-40,-35,83,-99,6,55,-81,3,62,65,-83,52,2,75,-58,-1,-67,53,32,-70,-91,6,12,-28,70,30,-12,48,-56,13,-97,14,88,0,-74,-59,53,-8,-54,75,82,-33,39,-38,13,7,-63,67,63,-95,-81,-79,28,56,100,55,53,10,-68,77,-34,-28,-41,-51,62,4,64,-99,49,-99 };
	unsigned int m = 15;*/
	/*short pointP[] = {0, 0}; // TEST 1
	short pointset[] = {1, 1, 3, 4};
	unsigned int m = 2;*/
	short pointP[] = { 0,0 };								//Punto p
	short pointset[] = { 42, -53, 96, 78, 1, 1, 100, 100};	//Array di short contenente
															//le coordinate degli n punti
	unsigned int m = 2;										//Numero delle dimensioni di
															//ogni punto
	unsigned int n = sizeof(pointset) / (sizeof(pointset[0]) * m); //Numero di punti

	// Output
	unsigned short indiceMin; 	//Indice del punto pi� vicino a p
	unsigned short indiceMax; 	//Indice del punto pi� lontano da p
	unsigned int prodotto; 		//Prodotto degli indici del punto pi� vicino e del punto
								//pi� lontano
	unsigned int fattori[100];	//Fattori primi trovati
	unsigned int numFattori;	// Numero dei fattori trovati
	

	// Blocco assembler
	__asm
	{
		XOR EAX, EAX // Azzero questi registri che andr� ad utilizzare
		XOR ECX, ECX
		XOR EDX, EDX
		XOR EBX, EBX
		XOR EDI, EDI
		XOR ESI, ESI
		MOV ESI, 2000000 // Salvo in ESI un valore molto grande, perch� dovr� contenere il valore minimo
		JMP Ciclo
Inizio:
		INC EBX // Utilizzo EBX per scorrere il pointP
Ciclo:
		CMP ECX, m // Utilizzo ECX per far scorrere il pointset
		JE FineCiclo
		MOV AX, pointP[EBX * 2] // Utilizzo EBX per far scorrere il pointP
		SUB AX, pointset[ECX * 2]
Quadrato:
		IMUL AX // Faccio il quadrato di AX, moltiplicandolo per se stesso
		PUSH AX
		XOR AX, AX
		XOR EDX, EDX
		JMP ControlloCiclo
ControlloCiclo:
		INC ECX
		CMP ECX, m
		JNE Inizio
		INC EBX // Aggiungo 1 a EBX per farlo tornare con il valore originale di m
		XOR ECX, ECX
		MOV ECX, EBX // Salvo in ECX il valore di EBX perch� devo fare il ciclo
DistanzaEuclidea:
		POP AX
		ADD EDX, EAX // Sommo a EDX il valore pushato di EAX
		XOR AX,AX
		DEC ECX
		TEST ECX, ECX
		JNZ DistanzaEuclidea
		XOR EAX, EAX
		ADD ECX, m // Ripristino il valore di ECX

		CMP EDI, EDX // EDI: Valore maggiore
		CMOVNG EDI, EDX
		CMP EDI, EDX
		JE IndiceMaggiore
ControlloIndiceMinore:
		CMP ESI, EDX // ESI: Valore minore
		CMOVG ESI, EDX // Salvo il valore della distanza euclidea minore in ESI
		CMP ESI, EDX
		JE IndiceMinore
		JMP FineCiclo
IndiceMaggiore:
		MOV AX, CX
		DIV BL // per trovare l'indice
		MOV CX, AX
		XOR AX, AX
		DEC ECX // Diminuisco di 1 per avere l'indice dei numeri
		MOV indiceMax, CX // Salvo l'indice Maggiore
		XOR ECX, ECX
		MOV ECX, m // Ritorno ad ECX il valore che aveva prima della divisione
		JMP ControlloIndiceMinore
IndiceMinore:
		MOV AX, CX
		DIV BL // per trovare l'indice
		MOV CX, AX
		XOR AX, AX
		DEC ECX // Diminuisco ECX di 1 per avere l'indice dei numeri
		MOV indiceMin, CX // Salvo l'indice Minore
		XOR ECX, ECX
		MOV ECX, m // Ritorno ad ECX il suo valore originale prima della divisione
		XOR EDX, EDX
FineCiclo:
		MOV AX, BX // Salvo in AX il valore di BX che sarebbe il valore originale di m
		MUL byte ptr n // Moltiplico AX per n (m * n) per poter trovare il numero di elementi del pointset
		CMP CX, AX // Controllo se CX (il contatore per scorrere il pointset) � arrivato alla fine del pointset
		JE Prodotto
		ADD m, EBX // Aggiungo ad m il valore di EBX (che sarebbe il valore originale di m)
		XOR EBX, EBX
		XOR EAX, EAX
		JMP Ciclo
Prodotto:
		XOR EAX, EAX
		XOR EDX, EDX
		MOV AX, indiceMax
		MOV DX, indiceMin
		MUL DX // Faccio il prodotto dell'indice minore per l'indice maggiore
		MOV prodotto, EAX // Salvo il valore del prodotto nella variabile prodotto
		// Pulisco i registri
		XOR ESI, ESI
		MOV ESI, EAX // ESI: prodotto
		XOR ECX, ECX
		MOV m, EBX // Salvo in m il vecchio valore originale prima della parte assembly
		XOR EBX, EBX
		XOR EAX, EAX
		XOR EDX, EDX
		XOR EDI, EDI

		TEST ESI, ESI // Controllo se ESI (ovvero il prodotto) � 0
		JZ Ritorno

		// Ora faccio la fattorizzazione del prodotto
		MOV ECX, 2 // ECX: indice
ControlloModulo:
		MOV AX, SI // Salvo in AX il valore del prodotto
		IDIV CX // AX (Prodotto) / CX (Indice)
		TEST EDX, EDX // equivalente CMP EDX, 0
		JZ Operazioni
		INC CX
		XOR EDX, EDX
		JMP ControlloNumero
Operazioni:
		XOR EDX, EDX
		XOR AX, AX
		MOV AX, SI
		IDIV CX // AX (prodotto) / CX (indice)
		MOV SI, AX // Salvo in SI (Prodotto) il valore di AX
		XOR EDX, EDX
		MOV fattori[EDI * 4], ECX
		INC EDI
ControlloNumero:		
		CMP SI, 1
		JNG Ritorno
		MOV fattori[EDI * 4], ESI
CicloNumeroPrimi:
		// Continuo a fare il ciclo se CX * CX <= SI
		XOR AX, AX
		MOV AX, CX			
		IMUL AX 
		XOR EDX, EDX
		CMP AX, SI
		JLE ControlloModulo
		INC EDI
Ritorno:
		MOV numFattori, EDI
	}
	
	// Stampa su video
	printf("Indice del punto piu' vicino a p: %d\n", indiceMin);
	printf("Indice del punto piu' lontano da p: %d\n", indiceMax);
	printf("Prodotto degli indici: %d\n", prodotto);
	printf("Numero di fattori primi=%d\n", numFattori);
	for (unsigned int i = 0; i < numFattori; i++)
		printf("%d\n", fattori[i]);
}


