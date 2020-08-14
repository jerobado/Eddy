Eddy
---

_Eddy_ is a simple text editor written in C++ and Qt.

### Features & Benefits
- autosave document
- create, save and open text files

### System Requirements
- OS: Ubuntu

### Development Requirements
- Qt
- GCC

### Build Instruction
1. Run `qmake` to generate a Makefile from the `eddy.pro` Qt project file
```
    $ qmake -o Makefile eddy.pro
```
2. Build `Makefile` using `make`
```
    $ make
```
3. Run the application
```
    $ ./eddy
```
