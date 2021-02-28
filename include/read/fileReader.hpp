#ifndef FILE_READER
#define FILE_READER

#include <string>

namespace read {
    class FileReader {
        public:
            FileReader();
            ~FileReader();

            std::string* readFile(std::string filePath, int numberOfLinesToRead);
    };
}

#endif
