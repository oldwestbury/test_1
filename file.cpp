#include <iostream>
#include <fstream>

struct Data {
    int id;
    char name[100];
    double score;
};

int main() {
    std::ofstream outFile("data.bin", std::ios::binary);
    if (!outFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    Data record = {1, "Alice", 95.5};
    outFile.write(reinterpret_cast<char*>(&record), sizeof(record));

    outFile.close();
    return 0;
}
