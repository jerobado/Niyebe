Niyebe
---
_Niyebe_, simple pseudo-random password generator for the forgetful

### Usage
```
$ niyebe -l 16      # generate random string with 16 characters
y}n59q\'1W8o=4_i
```

### Features & Benefits
- generate random custom password

### Random Algorithm
_Niyebe_ is using the [Mersenne Twister](https://en.wikipedia.org/wiki/Mersenne_Twister) to generate a pseudo-random number which is provided by the `<random>` header in the C++ standard library.


### System Requirements
- Operating System: Linux (Ubuntu 64-bit) or Windows 10/11 (64-bit)

## Software Requirements
### Windows
- CMake
- MinGW or Cygwin
- OpenSSL

### Linux
- GNU Compiler Collection


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
