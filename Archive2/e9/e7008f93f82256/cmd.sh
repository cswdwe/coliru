echo ..........................
echo -e '\n\nstandard c++ (-std=c++11)\n------------------------------'
echo g++
g++-4.8 -std=c++11 -Wall -Wextra -pedantic-errors main.cpp && echo 'g++ ok'
echo -e '\nclang++'
clang++ -std=c++11 -stdlib=libc++ -Wall -Wextra -pedantic-errors main.cpp -lsupc++ && echo 'clang++ ok.'
echo -e '\nlegacy standard c++ (-std=c++98)\n------------------------------'
echo g++
g++-4.8 -std=c++98 -Wall -Wextra -pedantic-errors main.cpp && echo 'g++ ok'
echo -e '\nclang++'
clang++ -std=c++98 -stdlib=libc++ -Wall -Wextra -pedantic-errors main.cpp -lsupc++ && echo 'clang++ ok.'
echo -e '\nnon-standard (g++/clang++ default)\n------------------------------'
g++-4.8 -Wall -Wextra -pedantic-errors main.cpp && echo 'g++ ok'
clang++ -stdlib=libc++ -Wall -Wextra -pedantic-errors main.cpp -lsupc++ && echo 'clang++ ok.'