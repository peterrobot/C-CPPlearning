# Introduction

## Module programming

First, author have a glance at the procedure programming of origin "C".

The motto of **module programming** is data hiding principle. That is, as programmers, we are more focus on how variables are arranged instead of certain procedure. Then, the properly arranged *variables* and the all the *functions* needed to interact with these variables are pack as **an abstract data structure**. While other users(including the writer and others) can only see and use some functions to control the behaviour of the structure, we call these certain variables are **hid**. Finally, the definitions are clear, those *abstract data structures* are **modules** and the *visible functions* are **user interface**. Guiding by this idea, what programmers do most changes into designing some good *modules* and finally linking these *modules* in simple procedure.

1. Namespace(prevent duplicate name)
2. Override operators(override functions)
3. Concrete type(hide variables/functions)
4. Abstract type(virtual functions)
5. Class Hierarchy(inheritance)
6. Generic Design(container/generic algorithm)
