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

### Software Requirements
- GNU Compiler Collection
- CMake
- Cygwin (if you're on Windows)

### System Requirements
- Operating System: Linux (Ubuntu 64-bit)

### Build & Install Instruction

Using `make`
```
$ make
$ ./niyebe
```

Using `cmake`
```
$ cmake -H. -Bbuild
$ make -C build
$ ./build/bin/niyebe
```

To install
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
![GNU LGPL v3](https://upload.wikimedia.org/wikipedia/commons/3/3b/LGPLv3_Logo.svg)
