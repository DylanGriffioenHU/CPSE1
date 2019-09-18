//writen by: Dylan Griffioen
//Changes the uppercase letters to lowercase letters 
//And changes the lowercase letters to uppercase letters
//After that prints the string one character at a time
//Written on 17-9-2019



    //Use the cortex-m0 (16 bit) instruction set
.cpu cortex-m0
    //What follows goes into the code section
.text
    //If needed skip 1 or 2 bytes
.align 2
    //Make the subroutine_name available
.global print_asciz
.global application

//loads the message lable into r0 and branch links the print_asciz function
application:
    push    { lr }
    ldr     r0, =message
    bl      print_asciz
    pop     { pc }
    

//push r5, r6 and lr to the stack for safekeeping
//mov r0 to r5 for safe keeping and mov 32 into r6 for the bitwise operators
//orr r0 with r6 to make sure its lowercase
//compare r0 to #'a' to check if r0 contains a letter
//if r0 is greater or equal to a branch to ge_a if not move r5 back to r0
//and end the function by popping r5, r6 and pc
toggle_case:
    push { r5, r6, lr }
    mov r5, r0
    mov r6, #32
    orr r0, r0, r6
    cmp r0, #'a'
    bge ge_a
    mov r0, r5
    pop {r5, r6, pc}
    
//compare r0 to #'z' if r0 is less or equal branch to le_z
//if not mov r5 back into r0 and pop r5, r6 and pc to end the function
ge_a:
    cmp r0, #'z'
    ble le_z
    mov r0, r5
    pop {r5, r6, pc}

//move r5 back into r0 and xor r0 with r6
//the xor makes it so any uppercase letters turn into lowercase letters
//and any lowercase letters turn into uppercase letters
//then end the function by popping r5, r6 and pc
le_z:
    mov r0, r5
    eor r0, r0, r6
    pop {r5, r6, pc}
    
    


        

    
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
   bl   toggle_case
   bl   uart_put_char
   add  r5, r5, #1
   b    loop
//pop r5 and program counter so the program can continue with the next instruction
done: 
   pop  { r5, pc }
   
   
.data
message:
    .asciz "Hello world, the ANSWER is 42! @[]`{}~"
