Niyebe
---

_Niyebe_, simple password generator for the forgetful

### Usage
```
$ niyebe -l 16      # generate random string with 16 characters
TJ1q!5@!VTo40eUe
```

### Features & Benefits
- generate random custom password

### Random Algorithm
_Niyebe_ is using the [Mersenne Twister](https://en.wikipedia.org/wiki/Mersenne_Twister) to generate a pseudo-random number which is provided by the `<random>` header in the C++ standard library.

### Build Instruction
```
$ cmake -H. -Bbuild
$ make -C build
$ ./build/bin/niyebe
```
