.cpu cortex-m0 
.text 
.align 2 
.global decoder

decoder:
	PUSH {R4, R5, R6, R7, LR} 	//push alle registers naar de stack
	LDR	R4, =compressed			//in R4 word een pointer naar de eerste geheugenlocatie geplaatst
	MOV	R5, #0					//init index pointer met 0	
	MOV	R6, #0					//init offset met 0
	MOV	R7, #0					//init lengte met 0
	
mainLoop:
	ADD R0, R4, R5				//stop het geheugenadress van R4 met index R5 in R0
	LDRB R0, [R0]				//haal de waarde van het geheugenadress op en stop het in R0
	ADD R5, R5, #1				//verhoog index pointer met 1
	CMP R0, #0					//controleer of we het einde van compressed bereikt hebben
	BEQ	done

	CMP R0, #'@'				//controleer of het character in R0 compressed is
	BEQ	decompress				//in geval van compressie branch naar decompress
	bl uart_put_char			//print het character in R0
	b mainLoop					//ga verder met door compressed itereren
	
decompress:
	ADD R6, R4, R5				//stop het geheugenadress van R4 met index R5 in R6
	LDRB r6, [R6]				//haal de waarde van het geheugenadress op en stop het in R6
	ADD R5, R5, #1				//verhoog de index pointer met 1
	ADD R7, R4, R5				//stop het geheugenadress van R4 met index R5 in R7
	LDRB r7, [R7]				//haal de waarde van het geheugenadress op en stop het in R7
	ADD R5, R5, #1				//verhoog de index pointer met 1
	SUB R6, R6, #'0'			//trek er '0'(==48) van af
	SUB R7, R7, #'0'			//trek er '0'(==48) van af
	MOV R3, R5					//kopieer de index pointer naar R3
	SUB R3, R3, #4				//verlaag R3 met 4 om de pointer terug op het @ teken te zetten
	SUB R3, R3, R6				//verlaag R3 met R6 zodat de pointer op de juiste plek staat
	
decompressLoop:
	ADD R0, R4, R3				//stop het geheugenadress van R4 met index R3 in R0
	LDRB R0, [R0]				//haal de waarde van het geheugenadress op en stop het in R0
	bl uart_put_char			//print het character in R0
	ADD R3, R3, #1				//verhoog index pointer met 1
	SUB	R7, R7, #1				//verlaag lengte met 1
	CMP R7, #0					//compare R7 met 0 om te kijken of het hele woord gedecompressed is
	BEQ mainLoop				//als het hele woord gedecompressed is ga door met mainloop
	b decompressLoop			//ga verder met het woord decompressen
	
done:
	POP {R4, R5, R6, R7, PC} 	//pop alles weer van de stack