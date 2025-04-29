Niyebe
---
_Niyebe_, simple and secure pseudo-random string generator for the forgetful.

### Usage

Generate random string with 46 characters:
```
$ niyebe 46      
FYiM6%F[4"76.Td4<[xH3m2QEk-Pvoi%16H7H9mqEzp3a^
```

### Features & Benefits
- generate secure random strings based on given length
- using OpenSSL under the hood

### Random Algorithm
Niyebe is using OpenSSL's `RAND_bytes` function to generate secure random string.


### System Requirements
- Operating System:
    - Ubuntu, Debian (64-bit)
    - Windows 10 or 11 (64-bit)

## Software Requirements
### Windows
- CMake
- MinGW or Cygwin
- OpenSSL

### Linux
- GNU Compiler Collection
- CMake
- OpenSSL


## Build Instruction

### Windows

Using `cmake`

Debug build

```
> cmake -G "MinGW Makefiles" -DCMAKE_CXX_COMPILER=x86_64-w64-mingw32-g++ -DCMAKE_BUILD_TYPE=Debug -B build/debug
> cmake --build build/debug
> .\build\debug\bin\niyebe.exe 
```

Release build

```
> cmake -G "MinGW Makefiles" -DCMAKE_CXX_COMPILER=x86_64-w64-mingw32-g++ -DCMAKE_BUILD_TYPE=Release -B build/release
> cmake --build build/release
> .\build\release\bin\niyebe.exe 
```

Using `mingw32-make`

```
> mingw32-make
> niyebe.exe
```

### Linux

Using `cmake`
```
$ cmake -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Debug -B build/debug
$ cmake --build build/debug
$ ./build/debug/bin/niyebe
```


Using `make`
```
$ make
$ ./niyebe
```

## Install Instruction

### Linux

```
$ sudo make install
```
This will install/copy the compiled executable to `/opt/niyebe`.

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
