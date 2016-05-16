//
//  recursive.hpp
//  labrob
//
//  Created by Ormir G. on 16/05/16.
//  Copyright © 2016 Nitika Kumar, Ormir Gjurgjej. All rights reserved.
//

#ifndef recursive_hpp
#define recursive_hpp

#include <stdio.h>
#include "robot.hpp"

class Recursive : public Robot {
    bool recursiveSolve(int, int);
public:
    Recursive(const Labyrinth);
    bool solve();
    ~Recursive();
};

#endif /* recursive_hpp */
