//
//  robot.hpp
//  labrob
//
//  Created by Ormir G. on 15/05/16.
//  Copyright © 2016 Nitika Kumar, Ormir Gjurgjej. All rights reserved.
//

#ifndef robot_hpp
#define robot_hpp

#include <stdio.h>
#include "labyrinth.hpp"

class Robot {
protected:
    int steps;
    char direction;
    int curX;
    int curY;
    Labyrinth lab;
public:
    Robot(const Labyrinth);
    int getSteps() const;
    virtual bool solve() = 0;
    virtual ~Robot();
};

#endif /* robot_hpp */
