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
            if (line.size() > 1) {
                std::vector<char> labline(line.begin(), line.end());
                //labline is "pushed into"(stored) in lab vector
                lab.push_back(labline);
            }
        }
    }
    file.close();
}

void Labyrinth::show() const{
    //don't use int i dammit, use iteratoooorsss. data types of iterator --> auto (short)
    for(auto it = lab.begin(); it != lab.end(); ++it){
        for (auto cit = (*it).begin(); cit != (*it).end(); ++cit){
            std::cout << *cit;
        }
        std::cout << std::endl;
    }
}

Labyrinth::~Labyrinth(){}