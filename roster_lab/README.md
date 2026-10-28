# University Course Roster Lab — Starter Code

This C++17 starter project provides the data types, required function declarations, a step-by-step driver, and build configuration for the pointer-based linked-list lab. The students are responsible for implementing every function in `src/CourseRoster.cpp`.

## Project layout

- `include/CourseRoster.h` — provided roster data structures and function declarations; keep signatures unchanged.
- `src/CourseRoster.cpp` — TODO stubs for students to implement.
- `src/main.cpp` — verification sequence for insertion, display, DOB update, deletion, and clearing the roster.
- `Makefile` — portable build using a C++17 compiler such as `g++` or `clang++`.

## Build and run

From the project directory:

```sh
make
./roster_lab
```

To remove the generated executable:

```sh
make clean
```

The starter implementation is intentionally incomplete; the driver can compile, but its output will not satisfy the lab checks until the TODO functions are implemented.

## Implementation guidance

Implement the helper navigation functions first, then insertion/deletion and lookup/update, followed by cleanup and display. Consider empty-list behavior, deleting the head or tail, invalid positions, and keeping the caller's head pointer up to date. Run the driver after each function is implemented.
