# C

## Introduction

C is my life, here I try to have good time with C. Most of these examples using the Linux system calls
and demonstrates operating system concepts.

## Introduction to Makefile

Makefile is useful to building C-based project. The following example
shows a Makefile for building project that has `main.c`, `gcd.c` and `lcm.c`.
The `functions.h` contains the required definitions.

```make
all: calc_lcm_gcd

calc_lcm_gcd: main.o gcd.o lcm.o
 $(CC) -o $@ $^ $(CFLAGS) $(LDLIBS)

%.o: %.c functions.h
 $(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean
clean:
 rm main.o gcd.o lcm.o calc_lcm_gcd
```

Check [here](http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/) to read more.

## [Clone](clone)

Linux provides the ability to create threads using the `clone()` system call.
When `clone()` is invoked, it is passed a set of flags that determine how much
sharing is to take place between the parent and child tasks.

## [Threads](Threads)

Let's learn to use new feature in C11, C11 threads.
Please see [here](http://en.cppreference.com/w/c/thread) as a reference for C11 threads.

**But at the current time nobody implements this feature.**

## [Generic](Generic)

Generic selection is implemented with a new keyword: `_Generic`.
The syntax is similar to a simple switch statement for types:

```c
_Generic( 'a', char: 1, int: 2, long: 3, default: 0)
```

The above expression evaluates to 2 (character constants are `int`s in C).
The use of `_Generic` can be abstracted in a macro:

```c
#define type_idx(T) _Generic( (T), char: 1, int: 2, long: 3, default: 0)
```

So that `type_idx('a')` evaluates to 2 and `type_idx("a")` evaluates to 0.

## [Ahmad's Guess](AhmadGuess)

Ahmad Asadi, had guess about floating point number implementation in C:

$$
1 + \frac{1}{2} + \frac{1}{3} + \ldots + \frac{1}{n} \ne \frac{1}{n} + \frac{1}{n - 1} + \ldots + \frac{1}{2} + 1
$$

Let's check it.

## [Alloca](alloca)

The `alloca()` function allocates `size` bytes of space in the stack
frame of the caller. This temporary space is automatically freed
when the function that called `alloca()` returns to its caller.

```c
#include <alloca.h>

void *alloca(size_t size);
```

## [Fork](./fork)

Learn about `fork` system call with its related system calls like `wait`.

## [Bahador's Guess](BahadorGuess)

This program shows that the expressions with side effects has no side effect in an unevaluted context.

```c
sizeof(a++)
```

## [CMakeTest](CmakeTest)

A minimal `libglib`-based "hello world", built through a real `CMakeLists.txt`
(with a `src/` subdirectory) instead of a Makefile. Run `git clean -f -d -X`
to remove the files CMake generates.

## [DataToFile](DataToFile)

Reads a line from stdin, finds occurrences of a couple of known words inside
it, appends each match to `test.txt`, and prints a final timestamp to the
console.

## [C to Assembly](c-to-assembly)

A grab-bag of tiny C snippets (globals vs. `bss`/`data`, `for`/`if` control
flow, function calls, inline `__asm__`, section attributes, argument counts,
float promotion) meant to be compiled to assembly and read side by side with
the C, one concept per file.

## [random](random)

Generate random number between 0 to 3 with `random` instead of `rand`.

## [Pointer](pointer)

Review on pointer concepts and some common mistakes about them.

## [Twin Primes](TwinPrimes)

A twin prime is a prime number that is either 2 less or 2 more than another prime number—for example, either member of the twin prime pair (41, 43).

## [Double To Byte](DoubleToByte)

Convert a double number into byte representation.

## [Slice](./slice)

Slices are a Golang concept but here we tried to implement it in C and check how is the idea working.

## [Hello Raspberry Pi](./hello-PI/)

There is a first time for everything, this is the first time that I saw an ARMv6.

## [Pipe & Fork](./pipe-and-fork)

Using pipe to communicate between parent and child processes.

## Root Project (main.c)

The root-level `main.c` (built via the top-level `CMakeLists.txt` or `just build`)
reads lines from a text file, reverses each word and wraps it with `A`/`a`, and
writes the result to another file. Update the hardcoded input/output paths at the
top of `main()` before running it.

## [asprintf](asprintf)

A hand-rolled implementation of `asprintf()`, which allocates a string
buffer of exactly the right size for a formatted print instead of forcing
the caller to guess a buffer size up front.

## [bits-struct](bits-struct)

Bit-field struct members (`unsigned char p1 : 1`) and how they change the
overall size of a `struct` compared to using full-width members.

## [Blackjack](blackjack)

An early, unfinished blackjack game: deals cards to the player and dealer
and lets the player hit. Left here as-is, bugs included.

## [bufsize](bufsize)

Reads a `FILE*`'s internal stdio buffer size with the glibc extension
`__fbufsize()`.

## [bytes](bytes)

Writes a fixed-size number to a file and reads it back with `fwrite()` /
`fread()`, using `fseek()` and `ftell()` to check its position and size.

## [cmp-without-if](cmp-without-if)

Finds the maximum of two doubles and compares two numbers without a single
`if` statement, using `fabs()` and integer arithmetic tricks instead.

## [crypt](crypt)

Authenticates a username/password pair against the system's password and
shadow databases using `getpwnam()`, `getspnam()` and `crypt()`, then
overwrites the plaintext password in memory as soon as it's been hashed.

## [DecToBin](DecToBin)

Converts a decimal number to binary by pushing its bits onto a hand-built
linked-list stack and popping them back off in order.

## [Derivative](derivative)

Numeric differentiation using the symmetric-difference formula, computing
both the first and second derivative of a function passed in as a function
pointer.

## [directory-recursing](directory-recursing)

Recursively walks a directory tree, using C's designated-initializer
default arguments to call `process_dir()` with just the arguments that
matter.

## [div-zero](div-zero)

A single integer division by zero, to observe how this platform actually
handles it.

## [dynamic](dynamic)

Reads a C function body typed at runtime, compiles it into a shared object
with `gcc`, and calls it immediately via `dlopen()` / `dlsym()`.

## [errortuple](errortuple)

Emulates Go-style `(value, error)` return tuples in C with a macro that
generates a small `{value, error}` struct per type.

## [exiting](exiting)

Compares the different ways a C program can terminate — `exit()`,
`_Exit()`, `quick_exit()` — and which cleanup handlers each one runs
(`atexit()` vs `at_quick_exit()`).

## [ext2](ext2)

Reads raw fields (signature, filesystem state, OS id, last-mount and
last-written timestamps) directly out of an ext2 superblock on a block
device.

## [F4F](F4F)

Nibble-level arithmetic building blocks (a half-multiplier and half-adder
over a 4-bit finite field), the kind of primitive used to build an AES-style
S-box.

## [fib](fib)

Recursive Fibonacci next to an iterative version that keeps its running
state in `static` locals.

## [filep](filep)

Pokes at glibc's private `FILE` struct fields (`_r`, `_w`) to see how stdio
tracks its read/write buffering internally.

## [fstr](fstr)

A small "fat string" library — `fstr_new()`, `fstr_cpy()`, `fstr_free()` —
implementing reference-counted substrings over a shared backing buffer.

## [Glist](Glist)

Using GLib's doubly linked list, `GList`, and a demonstration that it only
stores pointers: mutating a local array after appending it changes what
the node holding that pointer prints, while nodes appended with string
literals are unaffected.

## [got](got)

A single function that assigns to an `extern int i` never defined in this
translation unit, built with `gcc -nostdlib -shared -fPIC` into `got.so` —
inspect the resulting shared object (e.g. `objdump -R got.so`) to see the
GOT entry created for the unresolved external write.

## [grid](grid)

Reads an `N x N` grid size and contents from a text file into a dynamically
allocated 2D array.

## [Gsoup](Gsoup)

Making an HTTP request with GNOME's `libsoup`, using `SoupSession` and
`SoupMessage`.

## [GsoupServer](GsoupServer)

A `libsoup`-based HTTP server that proxies another response back to the
client, copying headers across messages.

## [GSource](GSource)

Implements a custom GLib `GSource` (`MessageQueueSource`) that dispatches
whenever a message becomes available on a `GAsyncQueue`.

## [IO](IO)

`scanf()` format specifiers, in particular the `%[...]` scanset conversion,
and how easily it overflows a fixed-size buffer.

## [JNI](JNI)

A minimal Java Native Interface example: a native method implemented in C
and called from Java.

## [lines](lines)

Reads lines of input with the long-removed, inherently unsafe `gets()` on
purpose, as a cautionary example. The buffer-growth helper is declared but
never actually wired up, so despite the bookkeeping this is capped at 16
lines, not unbounded.

## [linked-list](linked-list)

A singly linked list built around a generic `linked_list_append()` macro
that works over any `struct` with a `next` pointer.

## [LongJmp](LongJmp)

Nonlocal control flow with `setjmp()` / `longjmp()`, jumping back into two
independent call sites through two separate jump buffers.

## [malloc](malloc)

Peeks just behind a pointer returned by `malloc()` to read glibc's internal
chunk-size header.

## [MemoryMaping](MemoryMaping)

Maps a file into memory read-only with `mmap()` and dumps its contents
byte by byte.

## [mfh](mfh)

Sorts an array of `struct date` records ascending or descending with
`qsort()` and a pair of custom comparators.

## [mini-shell](mini-shell)

A minimal shell: reads a command line, tokenizes it on whitespace, and
runs it.

## [multiplicationtable](multiplicationtable)

Builds a multiplication table with a GSL matrix (via `libapop`), scaling
each row and column by its index.

## [non-blocking](non-blocking)

Switches stdin to `O_NONBLOCK` with `fcntl()` and shows how `fgets()`
fails immediately when there's nothing to read, instead of blocking.

## [parallel-for](parallel-for)

An OpenMP `#pragma omp parallel for` loop, wrapped in a small `pfor()`
macro.

## [parallel-sections](parallel-sections)

OpenMP `#pragma omp parallel sections`, where each section body runs on
its own thread.

## [preproc](preproc)

Preprocessor tricks: stringizing an expression to print it alongside its
value (`Peval`), and generating an array declaration via token pasting
(`ListGen`).

## [ProcessAffinity](ProcessAffinity)

Reads the calling process's CPU affinity mask with `sched_getaffinity()`.

## [pthread-scheduling](pthread-scheduling)

Queries a pthread attribute object for its contention scope and scheduling
policy.

## [saisir](saisir)

A French-language console CRUD app over a dynamic array of employee
records: add, list, search, delete, and sort by name or age.

## [shared-memory](shared-memory)

A POSIX shared-memory producer/consumer pair (`shm_open()` + `mmap()`) for
basic inter-process communication.

## [sockline](sockline)

A minimal single-client TCP server that binds, listens, and accepts a
connection.

## [stackoverflow](stackoverflow)

A grab-bag of small, standalone programs originally written as answers to
Stack Overflow questions — dynamic 2D array allocation, fork + pipe +
sort, and similar.

## [subsets](subsets)

Recursively generates every subset of size `k` from a fixed set.

## [symboling](symboling)

Prints the address of an `extern` global to inspect how symbol resolution
works across translation units.

## [TCPEchoClient](TCPEchoClient)

A TCP echo client: connects to a server, sends a word, and prints whatever
comes back.

## [typeof](typeof)

The `typeof` compiler extension, used to declare a pointer whose type is
derived from another variable's type instead of being spelled out.

## [valgrinding](valgrinding)

An array walk that deliberately reads past the end of a heap allocation,
meant to be run under Valgrind to see it catch the invalid access.

## [wayland-hello](wayland-hello)

Connects to a Wayland display and prints the protocol version — the
"hello world" of Wayland clients.

## [WC](WC)

A `wc`-like line reader that grows a 2D `char` array on the fly as it reads
stdin one character at a time.

## [who](who)

A `who`-like utility built on GLib hash tables, grouping logged-in users
(pulled from `utmpx`) by user id.
