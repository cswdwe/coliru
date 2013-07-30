#include <iostream>
#include <iterator>
#include <sstream>

template <int tabwidth, typename In, typename Out>
    Out mogrify(In f, const In l, Out out)
{
    intmax_t ws = -1, col = 0;

    auto emit = [&]() mutable { 
    	if (ws >= 0 && col>ws) {
			auto tabs   = (col-ws)/tabwidth;
			auto spaces = (col-ws)-(tabs*tabwidth); // or use %
			while (tabs--)   *out++ = '\t';
			while (spaces--) *out++ = ' ';

			ws = -1;
		}
    };

    while (f!=l) {
        switch(*f) {
            case ' ':
                 ws = ws<0? col : ws;
				 col++;
                 break;
            case '\t':
                 ws = ws<0? col : ws;
                 col = ((col/tabwidth)+1) * tabwidth;
                 break;
            case '\n': 
                 emit();
                 col = 0; *out++ = '\n';
                 break;
            default: 
                 emit();
				 col++;
                 *out++ = *f;
        }
        ++f;
    }
	emit();

    return out;
}


int main()
{
	std::stringstream ss;
	ss << std::cin.rdbuf();
	auto input = ss.str();

	mogrify<4>(begin(input), end(input), std::ostream_iterator<char>(std::cout));
}
