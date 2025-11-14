#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

void makeNote(std::string name, std::string contents) {
  std::ofstream writeFile(name);
  writeFile << contents;
  writeFile.close();
  std::ifstream readFile(name);
  if (readFile.is_open()) {
    std::string line;
    while(std::getline(readFile,line)) {
      std::cout << line;
    }
    readFile.close();
  }
  
}



int running = 1;
int main(int argc, char **argv) {
  int i = 0;
  std::string args[argc];
  if(argc >= 1) {
    while(i < argc) {
      args[i] = argv[i];
      if (args[i] == "-t") std::cout << "test" << std::endl;
      i++;
    }
  }
  std::string input;
  int handled;
  while(running) {
    handled = 0;
    std::cout << "> ";
    std::getline(std::cin,input);
    if (input == "quit") { running = 0; handled = 1; }
    if (!handled) {
      std::stringstream ss(input);
      std::string arg;
      std::vector<std::string> args;
      while (ss >> arg) {
        args.push_back(arg);
      }
      int i = 1;
      std::string cont;
      while (i < args.size()) {
        cont += args[i] + " ";
        i++;
      }
      makeNote(args[0], cont);
    }
    //if (!handled) std::cout << input << std::endl;

  }
  return 0;
}
