# Push_Swap

<img width="667" alt="Push_swap" src="https://github.com/user-attachments/assets/7d944994-9812-417a-b16e-151a42b47257">

## Description

The **Push_swap** project is a data sorting algorithm challenge where you are tasked with sorting a stack of integers using a limited set of operations. The goal is to find the most efficient way to sort the numbers with the least number of moves. This project emphasizes the importance of algorithmic complexity and is a key exercise in learning about sorting algorithms, which are a common topic in technical interviews.

## Project Objectives

- **Algorithmic Complexity**: Understanding and implementing efficient algorithms.
- **C Programming**: Enhancing skills in C, focusing on memory management, and adhering to coding norms.
- **Problem-Solving**: Finding the optimal solution among various algorithmic approaches.

## Requirements

- You must implement a program named `push_swap` that sorts a list of integers provided as arguments using the least number of operations.
- The project must be written in C and follow the coding standards provided by the school.
- Memory leaks are not allowed, and the program should handle errors gracefully, displaying "Error" followed by a newline on the standard error when applicable.

## Instructions

### Operations

You have two stacks, `a` and `b`, and a set of operations at your disposal:

- **sa (swap a)**: Swap the first two elements at the top of stack `a`.
- **sb (swap b)**: Swap the first two elements at the top of stack `b`.
- **ss**: Perform `sa` and `sb` simultaneously.
- **pa (push a)**: Take the first element at the top of `b` and put it at the top of `a`.
- **pb (push b)**: Take the first element at the top of `a` and put it at the top of `b`.
- **ra (rotate a)**: Shift all elements of stack `a` up by one.
- **rb (rotate b)**: Shift all elements of stack `b` up by one.
- **rr**: Perform `ra` and `rb` simultaneously.
- **rra (reverse rotate a)**: Shift all elements of stack `a` down by one.
- **rrb (reverse rotate b)**: Shift all elements of stack `b` down by one.
- **rrr**: Perform `rra` and `rrb` simultaneously.

### Compilation

To compile the project, a `Makefile` is provided with the following rules:

- `make` or `make all`: Compile the `push_swap` program.
- `make clean`: Remove object files.
- `make fclean`: Remove object files and the executable.
- `make re`: Recompile the project.

```bash
make
```

### Usage

To run the push_swap program, pass a list of integers as arguments:

```bash
./push_swap 2 1 3 6 5 8
```

This will output a series of operations that will sort the stack in ascending order.

### Error handling

The program will output "Error" if:

- Arguments aren't integers.
- There are duplicate integers.
- Any argument is larger than an integer.
