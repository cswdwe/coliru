gcc -O3 -pedantic main.cpp -S && grep -C 20 MyFunc main.s