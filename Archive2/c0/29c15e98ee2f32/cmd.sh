set -x ; clang++ -O2 -Wall main.cpp && ./a.out | c++filt -t