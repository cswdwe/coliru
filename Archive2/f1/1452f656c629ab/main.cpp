#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

struct Entry { 
    std::string id, name; 
    int age; 
};

int main() {
    std::vector<Entry> table1;
    std::vector<Entry*> table2;
    std::sort(table2.begin(), table2.end(), [](Entry* a, Entry* b) {
        return a->id < b->id;
    });
}
