# SigGen
A C++ library for signal and function generators.

## Building
To build the SigGen library, run the following in a terminal:
```
git clone https://github.com/Quickeman/SigGen.git
cd SigGen
git submodule update --init --recursive
cmake .
make
```

## Including In Your Own Project
### CMake-based Projects
If your project is CMake-based, you can include it in your own project by
including the commands:
```
add_subdirectory(SigGen)
include_directories(SigGen/include)
```
in your CMakeLists file or hierarchy.

If you do this you do not need to run `cmake .` and `make` when building (as in
the 'Building' section) as this will be accomplished by running these in your
project's root directory.

You can then link the SigGen library with your targets with:
```
target_link_libraries(<your_target> siggen)
```
If the linker can't find the `siggen` library for some reason, try adding:
```
link_libraries(SigGen/bin)
```

### Other Build Systems
Follow the instructions in the 'Building' section.
Once these are complete, include the `SigGen/include` and `SigGen/bin`
dirctories in the compiler's include path for your project.


## Unit Tests
To run the suite of unit tests, run in a terminal:
```
make test
```
