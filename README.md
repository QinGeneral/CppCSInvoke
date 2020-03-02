# C++ and C# invoke Demo

This repo show how the C++ and C# invoke eachother by Mono. It include two parts:

- CppInvokeCS: C++ invoke C# demo
- CSInvokeCpp: C# Invoke C++ demo

> Target OS: macOS

## C++ invoke C# Steps

1. Confirm g++ installed, macOS installed default. If you got those output, it means g++ is installed.

  ```sh
  $ g++
  clang: error: no input files
  ```

2. Intall pkgconfig by homebrew, use pkgconfig to link C/C++ program and mono lib

  ```sh
  $ brew install pkg-config
  ```

3. Install Mono Environment [Click to Download](https://www.mono-project.com/download/stable/). Input those command in your terminal to confirm mono is ready.

  ```sh
  $ mono --version
  Mono JIT compiler version 6.4.0.208 (2019-06/07c23f2ca43 Wed Oct  2 04:52:23 EDT 2019)
  ```

4. Code: CppInvokeCS.cpp、CppInvokeCS.cs, you can find the source code in the repo.

5. Compile and run

  ```sh
  // compile C++
  $ g++ CppInvokeCS.cpp `pkg-config --cflags --libs mono-2`
  // compile C#
  $ mcs CppInvokeCS.cs -t:library
  // run
  $ ./a.out
  // output
  Hello World
  ```

## C# invoke C++ Steps

1. Confirm g++ installed, macOS installed default. If you got those output, it means g++ is installed.

  ```sh
  $ g++
  clang: error: no input files
  ```

2. Intall pkgconfig by homebrew, use pkgconfig to link C/C++ program and mono lib

  ```sh
  $ brew install pkg-config
  ```

3. Install Mono Environment [Click to Download](https://www.mono-project.com/download/stable/). Input those command in your terminal to confirm mono is ready.

  ```sh
  $ mono --version
  Mono JIT compiler version 6.4.0.208 (2019-06/07c23f2ca43 Wed Oct  2 04:52:23 EDT 2019)
  ```

4. Code: CSInvokeCpp.CSInvokeCpp.cs, you can find the source code in the repo.

5. Compile and run

  ```sh
  // compile C++
  $ g++ CSInvokeCpp.cpp -framework CoreFoundation -lobjc -liconv `pkg-config --cflags --libs mono-2`
  // compile C#
  $ mcs CSInvokeCpp.cs -t:library
  // run
  $ ./a.out
  // output
  component id is0
  component tag is0
  component id is1
  component tag is4
  component id is2
  component tag is8
  component id is3
  component tag is12
  component id is4
  component tag is16
  ```

## Note
> If you got a problem when run ``g++ CppInvokeCS.cpp `pkg-config --cflags --libs mono-2` `` , like this output:
> ```
> Package mono-2 was not found in the pkg-config search path. Perhaps you should add the directory containing `mono-2.pc' to the PKG_CONFIG_PATH environment variable No package 'mono-2' found CppInvokeCS.cpp:1:10: fatal error: 'mono/jit/jit.h' file not found.
> ```
> You can solve this problem by run the below command in your terminal: 
> ```
> export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig:/usr/lib/pkgconfig:/Library/Frameworks/Mono.framework/Versions/6.4.0/lib/pkgconfig:$PKG_CONFIG_PATH
> ```
