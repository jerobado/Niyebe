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
- CMake

### System Requirements
- Operating System: Linux (Ubuntu)

### Build Instruction
```
$ cmake -H. -Bbuild
$ make -C build
$ ./build/bin/niyebe
```

### Resources
- [ASCII Table](https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html)
- [How Do Random Password Generators Work?](https://blog.dashlane.com/how-random-password-generators-work/)
- [The big password mistake that hackers are hoping you’ll make](http://stateofthenet.net/2014/10/the-big-password-mistake-that-hackers-are-hoping-youll-make/)