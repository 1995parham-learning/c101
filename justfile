default:
    @just --list

[no-cd]
build:
    cc main.c -o a.out

[no-cd]
clean:
    rm a.out
