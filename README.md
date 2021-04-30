# Brace Expansion

## Requires:
cmake, fmt, catch2

## Building
CMake Boilerplate used: https://github.com/LesleyLai/cmake-cpp-boilerplate

```
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
make
make test
```

## Bugs
Does not work with polynomial distribution (eg {a,b}{b,c})