//
//  labyrinth.cpp
//  labrob
//
//  Created by dolly sharma on 5/13/16.
//
//

#include "labyrinth.hpp"


Labyrinth::Labyrinth(std::string filename) {
    //open the file that is handed over as 'filename'
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while(std::getline(file, line))  {
            //all vectors within lab vector
            std::vector<char> labline(line.begin(), line.end()-1);
            //labline is "pushed into"(stored) in lab vector
            lab.push_back(labline);
        }
    }
    file.close();
}

Labyrinth::~Labyrinth(){}