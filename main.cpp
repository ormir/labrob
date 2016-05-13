//
//  main.cpp
//  labrob
//
//  Created by Ormir G. on 13/05/16.
//  Copyright © 2016 Nitika Kumar, Ormir Gjurgjej. All rights reserved.
//

#include <iostream>
#include "labyrinth.hpp"

int main(int argc, const char * argv[]) {
    //lab is "this"
    Labyrinth lab ("maze1_small.txt");
    lab.show();
    
    return 0;
}
