//writen by: Dylan Griffioen 
//Prints a string one character at a time
//Written on 17-9-2019




  
  //Use the cortex-m0 (16 bit) instruction set
.cpu cortex-m0
    //What follows goes into the code section
.text
    //If needed skip 1 or 2 bytes
.align 2
    //Make the subroutine_name available
.global print_asciz
    
//push r5 and lr to the stack and move the data from r0 into r5 to keep them safe
print_asciz:
   push { r5, lr }
   mov  r5, r0
//load the first byte from the memory space the r5 points to into r0
//If this byte is equal to 0 end the program if not print the byte
//add 1 to r5 so it points to the next letter and restart the loop
loop: 
   ldrb r0, [ r5 ]
   add  r0, r0, #0
   beq  done
   bl   uart_put_char
   add  r5, r5, #1
   b    loop
//pop r5 and program counter so the program can continue with the next instruction
done: 
   pop  { r5, pc }