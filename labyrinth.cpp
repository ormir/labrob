//
//  labyrinth.cpp
//  labrob
//
//  Created by dolly sharma on 5/13/16.
//
//

#include "labyrinth.hpp"


Labyrinth::Labyrinth(std::fstream &file) {

    std::string line;
    while(std::getline(file, line))  {
        //all vectors within lab vector
        //if a line of the maze only contains one character, don't save in lab vector
        if (line.size() > 1) {
            std::vector<char> labline(line.begin(), line.end());
            //labline is "pushed into"(stored) in lab vector
            lab.push_back(labline);
        }
    }
    
    entry[0]= {-1};
    exit [0] = {-1};
    width = (int) lab.begin()->size();
    height = (int) lab.size();
    
    // Get empty entry or exit
    auto enOrEx = [&](){ return entry[0] == -1 ? entry : exit; };
    
    //first vector -> first character until first vector -> last character
    // Horisontal top check
    for(auto it = lab.begin()->begin(); it != lab.begin()->end() && enOrEx()[0] == -1; ++it){
        if((*it) == ' ') {
            enOrEx() [1] = 0;
            enOrEx() [0] = (int) (it - lab.begin()->begin());
        }
    }
    
    // Vertical right check
    for (auto it = lab.begin(); it != lab.end() && enOrEx()[0] == -1; ++it){
        if(*(it->end()) == ' '){
            enOrEx() [1] = (int) (it - lab.begin());
            enOrEx() [0] = width-1;
        }
    }
    
    // Horisontal bottom check
    for (auto it = lab.rbegin()->rbegin(); it != (lab.rend()-1)->rend() && enOrEx()[0] == -1; ++it){
        if((*it) == ' '){
            enOrEx() [1] = height - 1;
            enOrEx() [0] = (int) (-(it - lab.rbegin()->rend()));
        }
    }
    
    // Vertical left check
    for (auto it = lab.rbegin(); it != lab.rend() && enOrEx()[0] == -1; ++it){
        if(*(it->begin()) == ' '){
            enOrEx()[1] = (int) (it-lab.rend());
            enOrEx()[0] = 0;
        }
    }
}

           
void Labyrinth::show() const{
    //don't use int i dammit, use iteratoooorsss. data types of iterator --> auto (short)
    for(auto it = lab.begin(); it != lab.end(); ++it){
        for (auto cit = (*it).begin(); cit != (*it).end(); ++cit){
            std::cout << *cit;
        }
        std::cout << std::endl;
    }
    std::cout << "entry: " << entry[0] << "," << entry[1] << std::endl;
    std::cout << "exit: " << exit [0] << "," << exit[1] << std::endl;
    std::cout << "height: " << height << std::endl;
    std::cout << "width: " << width << std::endl;
 }

Labyrinth::~Labyrinth(){}