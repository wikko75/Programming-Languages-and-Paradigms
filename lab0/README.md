# C
## Compilation
```Bash
gcc main.c -o main
 ```

---

 # Ada
## Compilation
```Bash
gnat compile hello.adb
gnat bind -x hello.ali
gnat link hello.ali
```
or simply:
 ```Bash
gnat make hello.adb
 ```

----
# Common Lisp
## Running
```Bash
clisp hello.list
```
----

# Go 
Requires .mod file to track dependencies.
## Preparation
```Bash
go mod init <module name>
```
## Running
```Bash
go run .
```
----

# Haskel
Using just ghc although GHCup is useful and advised.
## Compilation
```Bash
ghc hello.hs
```
----

# Java
## Compilation
```Bash
javac Hello.java
```
----

# Prolog
## Running

```Bash
swipl
?- [hello]  // loads hello.pl file content
?- greet.   // invoke predicate
```
----

# Standard ML
## Running
```Bash
sml hello.sml
```