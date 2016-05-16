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
            enOrEx() [0] -= 1;
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

char& Labyrinth::at(int x, int y){ return lab.at(y).at(x); }

std::map<char, char> Labyrinth::getSurrounding(int x, int y) const {
    std::map<char, char> surrounding;
    
    // North
    surrounding['n'] = (y-1) >= 0 ? lab.at(y-1).at(x) : '#';
    
    // Sowth
    surrounding['s'] = (y+1) < height ? lab.at(y+1).at(x) : '#';
    
    // West    
    surrounding['w'] = (x-1) >= 0 ? lab.at(y).at(x-1) : '#';
    
    // East
    surrounding['e'] = (x+1) < width ? lab.at(y).at(x+1) : '#';
    
    return surrounding;
}

int Labyrinth::getHeight() const { return height; }
int Labyrinth::getWidth() const { return width; }

void Labyrinth::markPosition(int x, int y) {
    if(lab.at(y).at(x) == ' ') {
        // Check if corner
        std::map<char, char> surr = getSurrounding(x, y);
        if((surr['s'] == '#' && surr['w'] == '#' && surr['e'] == '#') ||
           (surr['n'] == '#' && surr['w'] == '#' && surr['e'] == '#') ||
           (surr['n'] == '#' && surr['s'] == '#' && surr['e'] == '#') ||
           (surr['n'] == '#' && surr['w'] == '#' && surr['s'] == '#')) {
               lab.at(y).at(x) = 'y';
        } else
           lab.at(y).at(x) = 'x';
    } else {
        lab.at(y).at(x) += 1;
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

bool Labyrinth::isAtExit(int x, int y) const {
    if(x == exit[0] && y == exit[1]) return true;
    return false;
}

void  Labyrinth::getEntry(int &x, int &y) const {
    x = entry[0];
    y = entry[1];
}

Labyrinth::~Labyrinth(){}