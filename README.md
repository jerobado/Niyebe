❄️ Niyebe
---
_Niyebe_, simple and secure pseudo-random string generator for the forgetful.

### Usage

Generate random string with 46 characters:
```
$ niyebe 46      
FYiM6%F[4"76.Td4<[xH3m2QEk-Pvoi%16H7H9mqEzp3a^
```

Generate random digits only
```
$ niyebe 20 --digits
16270019754304914183
```

Generate random ASCII characters in lowercase (a-z)
```
$ niyebe 20 --lowercase
befkycnjqdxmwwvxeykv
```

Generate random ASCII characters in uppercase (A-Z)
```
$ niyebe 20 --uppercase
VFBSOUMBDKAOBRLZGVGK
```

Generate random ASCII special characters
```
$ niyebe 20 --symbols
`;?_.#/?`<\+?_||&`(=
```

### Features & Benefits
- generate secure random strings based on given length
- using OpenSSL under the hood

### Random Algorithm
Niyebe is using OpenSSL's `RAND_bytes` function to generate secure random string. See code in action [here](https://github.com/jerobado/Niyebe/blob/958984f9b24c91e3c0d6f5a6a3cdc65d048fd220/src/encryption.cpp#L9).

### System Requirements
- Operating System:
    - Ubuntu, Debian (64-bit)
    - Windows 10 or 11 (64-bit)

## Software Requirements
### Windows
- MSYS2 (UCRT64)
    - CMake - `mingw-w64-ucrt-x86_64-cmake`
    - MinGW-w64 - `mingw-w64-ucrt-x86_64-gcc` 
    - OpenSSL - `mingw-w64-ucrt-x86_64-openssl`

    CMake, MinGW and OpenSSL can be installed inside MSYS2 via `pacman`

### Linux
- GNU Compiler Collection
- Git
- CMake
- libssl-dev


## Build Instruction

### Windows

Using `cmake` via MSYS2 (UCRT64)

**Debug** build

```
> cmake.exe -G "MinGW Makefiles" -DCMAKE_CXX_COMPILER=x86_64-w64-mingw32-g++ -DCMAKE_BUILD_TYPE=Debug -B build/debug
> cmake.exe --build build/debug
> .\build\debug\bin\niyebe.exe 
```

Using `mingw32-make`

```
> mingw32-make.exe
> niyebe.exe
```

### Linux

#### Using `cmake`

**Debug** build

```
$ cmake -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Debug -B build/debug
$ cmake --build build/debug
$ ./build/debug/bin/niyebe
```

#### Using `make`
```
$ make
$ ./niyebe
```

## Install Instruction

### Windows

1. Create **Release** build

    ```
    > cmake.exe -G "MinGW Makefiles" \ 
        -DCMAKE_CXX_COMPILER=x86_64-w64-mingw32-g++ \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_PREFIX_PATH=C:/msys64/ucrt64 \
        -B build/release
    > cmake.exe --build build/release
    > .\build\release\bin\niyebe.exe 
    ```

2. Build

    ```
    cmake.exe --build build/release
    ```

2. Install in `C:/Niyebe` directory

    ```
    > cmake --install build/release --config Release --prefix C:/Niyebe
    ```

3. Run `niyebe.exe`

    ```
    > C:/Niyebe/bin/niyebe.exe -v
    ```

### Linux


1. Create **Release** build

    ```
    $ cmake -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Release -B build/release
    $ cmake --build build/release
    $ ./build/release/bin/niyebe
    ```

2. Install

    ```
    $ sudo cmake --install build/release --prefix /opt/niyebe
    ```
    This will install/copy the compiled executable to `/opt/niyebe`.

3. Run `niyebe`

    ```
    $ /opt/niyebe/bin/niyebe -v
    ```

To add `niyebe` to PATH

```
$ echo "export PATH="$PATH:/opt/niyebe"" >> ~/.bashrc
$ source ~/.bashrc
```

### Resources
- [ASCII Table](https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html)
- [How Do Random Password Generators Work?](https://blog.dashlane.com/how-random-password-generators-work/)
- [The big password mistake that hackers are hoping you’ll make](http://stateofthenet.net/2014/10/the-big-password-mistake-that-hackers-are-hoping-youll-make/)

### License
<img width="40%" height="auto" title="GNU LGPL v3" src="https://upload.wikimedia.org/wikipedia/commons/3/3b/LGPLv3_Logo.svg">
