# Assemble instructions and C codes

## Common assemble instructions

Meaning of symbols below:

1. REG -> register(address)
2. FUNC -> function(address)
3. ADDR -> address

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

MOV     ECX,30H
MOV     EAX,0CCCCCCCh
REP     STOS DWORD PTR ES:[EDI]
```

`STOS`: Move the content in *AX/EAX* to *ES:[EDI]/ES:[DI]*. Then automatically increase the *EDI/DI*, whose step is decide by the type of `STOS`. The precise step is shown in the sheet below.

instruction|step(byte)
:---------:|---:
STOS       |4
STOSD      |4
STOSW      |2
STOSB      |1

To better understand the function of `STOS`, it's useful to take a closer look at the example code above.
The first line assign the *ECX*, which is the repeat time that `REP` looking for. The second line assigned the *EAX*, which is used to fill the given address. The third line is started with `REP`, which means there is a loop in this line. Each loop, `STOS` will first fill the *ES:[EDI]* with content in *EAX*, in this case particularly, fill the *ES:[EDI]* with 0CCCCCCCh, and then *ES:[EDI]* will be automatically added by the length of data.
Logically, it is similar to the C code below.

```c
void* ADDR;
uint16 EAX = 0x0CCCCCCC;
for(uint32 ECX = 30h; ECX > 0; --ECX)
{
    *(DWORD*)(ADDR) = EAX;
    ADDR += sizeof(EAX);
}
```
