#include <iostream>
#include <fstream>
#include <string>

#include "common.hpp"

const std::string FIFO_NAME = "/tmp/myfifo";

int main() {

    std::ofstream fifo(FIFO_NAME, std::ios::binary);
    if (!fifo) {
        std::cerr << "ERROR: open fifo" << std::endl;
        return 1;
    }

    MyData data_to_send = {123, 45.67, "Test data"};
    std::cout << "Sender: Sending ID=" << data_to_send.id << std::endl;

    fifo.write(reinterpret_cast<const char*>(&data_to_send), sizeof(MyData));

    fifo.close();

    std::cout << "Sender: Message sent" << std::endl;
    return 0;
}
