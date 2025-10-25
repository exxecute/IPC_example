#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h> 
#include <sys/stat.h> 

#include "common.hpp"

const std::string FIFO_NAME = "/tmp/myfifo";

int main() {
    mkfifo(FIFO_NAME.c_str(), 0666);

    std::string message;

    std::ifstream fifo(FIFO_NAME, std::ios::binary);
    if (!fifo) {
        std::cerr << "ERROR: open fifo" << std::endl;
        return 1;
    }

    MyData received_data;
    std::cout << "Receiver: Waiting for data" << std::endl;

    fifo.read(reinterpret_cast<char*>(&received_data), sizeof(MyData));
    fifo.close();

    std::cout << " Receiver: Data received ->" << std::endl;
    std::cout << "  ID: " << received_data.id << std::endl;
    std::cout << "  Value: " << received_data.value << std::endl;
    std::cout << "  Name: " << received_data.name << std::endl;

    unlink(FIFO_NAME.c_str());

    return 0;
}
