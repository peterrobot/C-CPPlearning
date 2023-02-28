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

## Disassemble for judgements and branchings in C

`if(){}else{}`
After assemble

```asm
# In each branch
CMP     <condition1>
JLE     NEXT_BRANCH
CMP     <condition2>
JGE     NEXT_BRANCH
(BRANCH_BODY)
JMP     END_OF_BRANCH   # Only exist when it is no the last branch.
# Type of jump is editable
# Any amount of condition is acceptable
```

Source code:

```c++
if(<condition1> && <condition2>)
{
    // BRANCH_BODY
    ...
}// NEXT_BRANCH
else(<condition>)
{
    // BRANCH_BODY
    ...
}// END_OF_BRANCH
```

---
`switch(){case:}`
After assemble:

```asm
START:  CMP     ARGUMENT,CASE1
        JE      ADDRESS_CASE_1
        CMP     ARGUMENT,CASE2
        JE      ADDRESS_CASE_2
        # More cases are the same
        ...
        JE      ADDRESS_DEFAULT
        # To the default case. Go to end the of scope implicitly.
CASE1:  (BODY_OF_CASE1)
CASE2:  (BODY_OF_CASE2)
        JMP     END_OF_SCOPE
        # Translated from the 'break'
...
(More cases)
DEFAULT:(BODY_OF_DEFAULT)
        # Default can be any place actually, usually it is at the end.
END_OF_SCOPE:
```

Source code:

```c++
#define ARGUMENT i

switch(i)
{
    case CASE1:
        ...
        // Body of case1
    case CASE2:
        ...
        // Body of case2
        break;
    ...
    // More cases
    default:
        ...
        // Body of default
}
// End of scope
```
