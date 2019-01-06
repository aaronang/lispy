# Lispy

A Lisp implemented in C++.

## Getting Started

1. Install third-party libraries:
   ```shell
   $ sudo apt-get install libedit-dev
   ```

2. Build with CMake:
   ```shell
   $ cmake -H. -Bbuild
   $ make -C build
   ```
   
3. Run the REPL:
   ```shell
   $ ./build/lispy
   Lispy 1.0.0
   lispy>
   ```