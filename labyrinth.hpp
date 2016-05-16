//
//  labyrinth.hpp
//  labrob
//
//  Created by dolly sharma on 5/13/16.
//
//

#ifndef labyrinth_hpp
#define labyrinth_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>

class Labyrinth {
private:
    std::vector<std::vector<char>> lab;
    int width;
    int height;
    //saves one integer for x and the other for y
    int entry [2];
    int exit [2];
    char charAt(int, int) const;
public:
    Labyrinth (std::fstream&);
    char &at(int, int);
    
    void markPosition(int, int);
    void show() const;
    void getEntry(int&, int&) const;
    std::map<char, char> getSurrounding(int, int) const;
    int getHeight() const;
    int getWidth() const;
    bool isAtExit(int, int) const;
    void help() const;
    ~Labyrinth ();
};



#endif /* labyrinth_hpp */
