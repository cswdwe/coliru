#include <limits>
#include <cassert>

int main() {
    assert(int((0.1 - std::numeric_limits<double>::epsilon()) * 10) == 0);
}