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
            //if a line of the maze only contains one character, don't save in lab vector
            if (line.size() > 1) {
                std::vector<char> labline(line.begin(), line.end());
                //labline is "pushed into"(stored) in lab vector
                lab.push_back(labline);
            }
        }
    }
    file.close();
    
    entry[0]= {-1};
    exit [0] = {-1};
    width = (int) lab.begin()->size();
    height = (int) lab.size();
    
    //first vector -> first character until first vector -> last character
    for(auto it = lab.begin()->begin(); it != lab.begin()->end(); ++it){
        if((*it) == ' ' && entry[0] == -1) {
            entry [0] = (int) (it - lab.begin()->begin());
            entry [1] = 0;
        } else if ((*it) == ' ' && exit[0] == -1) {
            exit [0] = (int) (it - lab.begin()->begin());
            exit [1] = 0;
        }
    }
    for (auto it = lab.begin(); it != lab.end(); ++it){
        if(*(it->end()) == ' ' && entry[0] == -1){
            entry [0] = width-1;
            entry [1] = (int) (it - lab.begin());
        } else if (*(it->end()) == ' ' && exit[0] == -1) {
            exit [0] = width-1;
            exit [1] = (int) (it - lab.begin());
        }
    }
    
    for (auto it = lab.rbegin()->rbegin(); it != lab.rend()->rend(); ++it){
        if((*it) == ' ' && entry[0] == -1){
            entry [0] = (int) (it - lab.rbegin()->rend());
            entry [1] = height-1;
        } else if ((*it) == ' ' && exit[0] == -1){
            exit [0] = (int) (it - lab.rbegin()->rend());
            exit [1] = height-1;
        }
    }
    
    for (auto it = lab.rbegin(); it != lab.rend(); ++it){
        if(*(it->begin()) == ' ' && entry[0] == -1){
            entry[0] = 0;
            entry[1] = (int) (it-lab.rend());
        } else if (*(it->begin()) == ' ' && exit[0] == -1) {
            exit[0] = 0;
            exit[1] = (int) (it-lab.rend());
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