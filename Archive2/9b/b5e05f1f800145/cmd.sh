set -x;
clang++ -O0 -Wall -Wextra -Wconversion -pedantic -Wno-unused-variable -std=c++11 main.cpp && ./a.out
g++-4.8 -O0 -Wall -Wextra -Wconversion -pedantic -Wno-unused-variable -std=c++11 main.cpp && ./a.out