#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char* argv[]) {
    std::vector <std::string> FileNames;
    std::vector <std::string> FileCommands;

    for ( int i = 1; i < argc; i++ ) {
        std::string str = argv[i];
        if ( str.find('.') < str.length() ) {
            FileNames.push_back(str);
        } else {
            FileCommands.push_back(str);
        }
    }

    for ( int j = 0; j < FileCommands.size(); j++ ) {
        if ( FileCommands[j].length() > 2 && FileCommands[j].length() < 6 ) {
            for (int i = 1; i < FileCommands[j].length(); i++ ) {
                char str[] = {'-', FileCommands[j][i], '\0'};
                FileCommands.push_back(str);
            }
            FileCommands.erase(FileCommands.begin() + j);
        }
    }

    int count = 0;
    for ( int j = 0; j < FileNames.size(); j++ )
    {
        std::ifstream file_in( FileNames[j] );
        for ( auto & FileCommand : FileCommands )
        {
            if ( FileCommand == "-l"  || FileCommand == "--lines" ) {
                std::string str;
                while ( std::getline( file_in, str ) ) {
                    count++;
                } std::cout << "Count of line in " << j + 1 << " file: " << count << std::endl;
                count = 0;
                file_in.clear();
                file_in.seekg(0);
            }
            else if ( FileCommand == "-c" || FileCommand == "--bytes" ) {
                file_in.seekg(0, std::ios ::end);
                int size_file = file_in.tellg();
                file_in.seekg( 0, std::ios ::beg );
                std::cout << "Bytes in " << j + 1 << " file: " << size_file << std::endl;
                file_in.clear();
                file_in.seekg(0);
            }
            else if ( FileCommand == "-w" || FileCommand == "--words" ) {
                std::string word;
                while( file_in >> word ){
                    count++;
                } std::cout << "Words in " << j + 1 << " file: " << count << std::endl;
                count = 0;
                file_in.clear();
                file_in.seekg(0);
            }
            else if ( FileCommand == "-m" || FileCommand == "--chars" ) {
                char c;
                while( file_in.get(c) ){
                    if( std::isalpha(c) ){
                        count++;
                    }
                } std::cout << "Letters in " << j + 1 << " file: " << count << '\n' << '\n';
                count = 0;
                file_in.clear();
                file_in.seekg(0);
            }
        }
        file_in.close();
    }
    system("pause");
    return 0;
}