#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char* argv[]) {
    std::vector <std::string> FileNames;
    std::vector <std::string> FileCommands;
    for (int i = 1; i < argc; i++) {
        std::string str = argv[i];
        if (str.find('.') < str.length()) {
            FileNames.push_back(str);
        } else {
            FileCommands.push_back(str);
        }
    }
    int count = 0;
    for (int j = 0; j < FileNames.size(); j++) {
        std::ifstream file_in(FileNames[j]);
        for (auto & FileCommand : FileCommands) {
            if (FileCommand == "-l"  || FileCommand == "--lines") {
                std::string str;
                while (std::getline(file_in, str)) {
                    count++;
                }
                std::cout << "Count of line in " << j+1 << " file: " << count << std::endl;
                count = 0;
                file_in.clear();
                file_in.seekg(0);
            } else if (FileCommand == "-c" || FileCommand == "--bytes") {
                char c;
                while (file_in.get(c)) {
                    count++;
                }
                std::cout << "Bytes in " << j+1 << " file: " << count << std::endl;
                count = 0;
                file_in.clear();
                file_in.seekg(0);
            } else if (FileCommand == "-w" || FileCommand == "--words") {
                std::string word;
                while(file_in >> word){
                    count++;
                }
                std::cout << "Words in " << j+1 << " file: " << count << std::endl;
                count = 0;
                file_in.clear();
                file_in.seekg(0);
            }
        }
        file_in.close();
    }
    /*system("pause");*/
    return 0;
}