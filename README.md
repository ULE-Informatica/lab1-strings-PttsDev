# MUIC - DPS - Laboratorio 1

## ejemplo1.c

Follow the instructions explained in the beginning of file ejemplo1.c for compiling with gcc and g++ (you can try also clang).

SOLUTION:

In the base file of ejemplo1 the rules and recomendations are pointed and a solution is proposed
then in the files ejemplo1g++.c and ejemplo1gcc99.c fixes for g++ and gcc -std=c99 are proposed

## ejemplo2.c. Program Instrumentation

Find the memory errors presented in file ejemplo2 using gcc instrumentation option **AddressSanitizer (ASan)**.
Explain in this file each error.

Errors:

When executing option three:

=================================================================
==1030==ERROR: AddressSanitizer: heap-use-after-free on address 0x60b0000000f0 at pc 0x7f70c7f212c3 bp 0x7ffc17aeaf30 sp 0x7ffc17aea6d8
WRITE of size 19 at 0x60b0000000f0 thread T0

Since the space is freed before the string is copied, there's no space
for it, so it overflows.

When executing the option four:

==1031==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x603000000052 at pc 0x7fc38f5a12c3 bp 0x7ffea60257c0 sp 0x7ffea6024f68
WRITE of size 19 at 0x603000000052 thread T0

The space that we have is 18, but for the string we need 19, since
18 is not enought space it overflows.
