# Assemble instructions and C codes

## Common assemble instructions

Meaning of symbols below:

1. REG -> register(address)
2. NUM -> number
3. FUNC -> function(address)
4. ADDR -> address

---

All the "Equal to" is implicitly compared with C/C++ by default.

### Instructions relevant to stack

```asm
PUSH REG
```

`PUSH`: Push an number(32bits) to the stack. Meanwhile, this operation will decrease the *ESP* by 4(bytes). The *ESP* here is often called the top of the stack, cause it is the place where the address is the lowest.

```asm
POP REG
```

`POP`: Pop the number(32bits) from the stack to the *REG*. Increase the *ESP* by 4(bytes).

```asm
SUB REG1,REG2
SUB REG,NUM
```

`SUB`: Equal to `REG1 = REG1 - REG2` \ `REG = REG - NUM`.

```asm
ADD REG1,REG2
ADD REG,NUM
```

`ADD`: Equal to `REG1 = REG1 + REG2` \ `REG = REG + NUM`.

```asm
REC
```

`REC`: Note the end of a function. Return to the parent function.

```asm
CALL FUNC
```

`CALL`: Call a function whose address is *FUNC*.

### Instructions relevant to data transfer

```asm
MOV REG1,REG2
```

`MOV`: Move data from *REG2* to *REG1*. Equal to `REG1 = REG2`.

```asm
XOR REG1,REG2
```

`XOR`: As its name, it is the "exclusive or" operation. Equal to `REG1 = REG1 ^ REG2`.
> **Thing to know:** `XOR REG1,REG2` equals to `REG1 = 0`. In assemble instruction that is `SUB REG,REG` or `MOV REG,0`. Apparently, using `XOR` is more efficient.

```asm
LEA REG,[ADDR]
```

`LEA`: Move the address(*ADDR*) to the register(*REG*). Compare with `MOV`, `LEA` allows computation on the address. For example: `LEA EAX, [EBP-0001h]` is feasible but `MOV EAX, EBP-0001h` is illeagle.

```asm
STOS ADDR
STOSD ADDR
STOSW ADDR
STOSB ADDR

# Example code
MOV     ECX,30H
MOV     EAX,0cccccccch
REP     STOS DWORD PTR ES:[EDI]
```

`STOS`: Move the content in *AX/EAX* to *ES:[EDI]/ES:[DI]*. Then automatically increase the *EDI/DI*, whose step is decide by the type of `STOS`. The precise step is shown in the sheet below.

instruction|step(byte)
:---------:|---:
STOS       |depends
STOSD      |4
STOSW      |2
STOSB      |1

To better understand the function of `STOS`, it's useful to take a closer look at the example code above.
The first line assign the *ECX*, which is the repeat time that `REP` is looking for. The second line assigned the *EAX*, whose content is used to fill the given address. The third line is started with `REP`, which means there is a loop in this line. In each loop, `STOS` will first fill the *ES:[EDI]* with content in *EAX*, in this case particularly, fill the *ES:[EDI]* with `0x0CCCCCCCh`, and then *ES:[EDI]* will be automatically added by the length of data.
Logically, it is similar to the C code below.

```c++
void* ADDR;
uint16 EAX = 0xcccccccc;
for(uint32 ECX = 30h; ECX > 0; --ECX)
{
    *(DWORD*)(ADDR) = EAX;
    ADDR += sizeof(EAX);
}
```

### Jump & Comparaison

```asm
JMP
JG
JL
JGE
CMP REG1 REG2/NUM
```

`JMP`: Jump unconditionally.
`CMP`: Compare two elements.
The following instructions are often used along with `CMP`.
`JG`: Jump when is greater.
`JL`: Jump when is lower.
`JGE`: Jump when is greater or equal.

## The procedure of how a C function passes its arguments

Three common methods of function call on **Windows**

1. Pascal Method
2. WINAPI Method(_stdcall)
3. C Method(_cdecl)

External Methods: In Windows NT(_fastcall), In C++(_thiscall).

Learn from an example

```c++
void function(int a, int b)
{
    int c = a + b;
}

int main()
{
    ...
    function(a,b);
}
```

After assembling:

```asm
void function(int a, int b)
{
    # Store Registers
    PUSH    EBP         # Store EBP
    MOV     EBP, ESP    # Store previous ESP in EBP. Generally, every function find its variable with ESP while EBP allways store the ESP for the previous function.
    SUB     ESP, 0cch   # Upper the top of stack, free some space to store the local variables.
    PUSH    EBX         # Store some registers
    PUSH    ESI
    PUSH    EDI
    # Initialize the local variable field with 0cccccccch. 0cch is the machine code of INT 3 and its meaning is break. Hence, the following codes are only generated in debug mode(in visual studio particularly), and they will ensure the function will break whenever we want to access memory uninitialized.
    LEA     EDI,[EBP-0cch]
    MOV     ECX,033h
    MOV     EAX,0cccccccch
    REP     STOS DWORD PTR [EDI]
    # Body of function
    MOV     EAX,DWORD PTR [a]
    ADD     EAX,DWORD PTR [b]
    MOV     DWORD PTR [c],EAX
    # Equal to c = a + b;
    # Actually there is no such thing like "DWORD PTR [a]". instead, it is transferred to "DWORD PTR [EDI+8]". The same for '[b]' and '[c]'.
}
# Restore the register in the stack and return.
POP     EDI
POP     ESI
POP     EBX
MOV     ESP,EBP
POP     EBP
RET

int main()
{
    ...
    # Push the arguments to the stack.
    MOV     EAX,DWORD PTR [b]
    PUSH    EAX
    MOV     ECX,DWORD PTR [a]
    PUSH    ECX
    CALL    function
    ADD     ESP,8
}
```
