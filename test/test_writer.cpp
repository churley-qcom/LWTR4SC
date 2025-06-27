#include "lwtr/lwtr_text.cpp"
#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Use a test file name
    const std::string test_file = "test_writer_output.lwtrt";
    // Create a Writer<PlainWriter> and open the file
    lwtr::Writer<lwtr::PlainWriter> writer;
    if (!writer.open(test_file)) {
        std::cerr << "Failed to open test file for writing\n";
        return 1;
    }
    // Write a formatted string
    writer.write("Hello {}! The answer is {}.\n", "world", 42);
    writer.close();

    // Read back the file and check contents
    std::ifstream in(test_file);
    std::string line;
    std::getline(in, line);
    if (line == "Hello world! The answer is 42.") {
        std::cout << "Test passed!\n";
        return 0;
    } else {
        std::cerr << "Test failed! Output: '" << line << "'\n";
        return 2;
    }
}

// Dummy sc_main for SystemC linkage
int sc_main(int, char**) { return 0; }
