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
#include <thread>
#include "labyrinth.hpp"

class Robot {
protected:
    int steps;
    int curX;
    int curY;
    Labyrinth lab;
    std::thread thSolve;
    virtual bool solve();
public:
    Robot(const Labyrinth);
    int getSteps();
    void path();
    virtual ~Robot();
};

#endif /* robot_hpp */
