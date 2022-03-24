# Procedure and modification in C

## Disassemble for loops in C

`for(){}`
After disassemble:

```asm
MOV     VAR_LOOP,INIT
JMP     B
A:  (MODIFY VAR_LOOP HERE)
    ...
B:  CMP     VAR_LOOP,BOARDER
    JGE     OUT_OF_LOOP
    (LOOP_BODY)
    ...
    JMP     A
```

Source code:

```c++
#define VAR_LOOP    i
#define INIT        a
#define BOARDER     n
#define MODIFY      f

auto f = [](int i) -> void { ... }

for(int i = a; i < n; f(i) )
{
    // LOOP_BODY
    ...
}
// OUT_OF_LOOP
```

---
`do{}while();`
After disassemble

```asm
S:  (LOOP_BODY)
    ...
    CMP     VAR_LOOP,BOARDER
    JL      S
    # The last code can be anyone of JL,JG,JLE,JGE depending on the purpose.
```

Source code:

```c++
#define VAR_LOOP    i
#define BOARDER     n

do{
    // LOOP_BODY
    ...
}(i < n)

```

---
`while`
After disassemble:

```asm
S:  CMP     VAR_LOOP,BOARDER
    JGE     E
    # Jump here is the same changable as above.
    # Be cautious, the boarder condition is a bit counterintutive here. Consider refer to the source code below.
    (LOOP_BODY)
    ...
    JMP     S
E:  (OUT_OF_LOOP)
```

Source code:

```c++
#define VAR_LOOP    i
#define BOARDER     n

while(i < n)
{
    // LOOP_BODY
    ...
}
// OUT_OF_LOOP
```
