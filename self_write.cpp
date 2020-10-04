#include <iostream>
#include <fstream>
#include <vector>
#include <string>

//inject

int main() {
    const std::string FILE_NAME = "self_write.cpp";
    std::ifstream file(FILE_NAME);
    std::string line;
    std::vector<std::string> lines; 

    while(getline(file, line)) {
        if (line.find("//inject") == 0) {
                lines.push_back("int counter = 0;");
                lines.push_back("");
                lines.push_back("void new_function() {");
                lines.push_back("");
                lines.push_back("    std::cout << \"This code has been self overwritten \" << std::to_string(++counter) << std::endl;" );
                lines.push_back("");
                lines.push_back("}");
                lines.push_back("");
                continue;
        } else if (line.find("//inject") == 4) {
                lines.push_back("    new_function();");
        }

        lines.push_back(line);
    }

    std::ofstream output (FILE_NAME);
    int totalLines = lines.size();

    for(std::string l : lines) {
        output << l << std::endl;
    }
    
    //inject

    return 0;
}