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

class Labyrinth {
private:
    std::vector<std::vector<char>> lab;
    int width;
    int height;
    //saves one integer for x and the other for y
    int entry [2];
    int exit [2];

public:
    void show() const;
    Labyrinth (std::fstream&);
    ~Labyrinth ();
};



#endif /* labyrinth_hpp */
