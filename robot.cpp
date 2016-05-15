//
//  robot.cpp
//  labrob
//
//  Created by Ormir G. on 15/05/16.
//  Copyright © 2016 Nitika Kumar, Ormir Gjurgjej. All rights reserved.
//

#include "robot.hpp"

Robot::Robot(const Labyrinth l) :
steps(0),
direction('s'),
lab(l) {
    l.getEntry(curX, curY);
}

int Robot::getSteps() const { return steps; }

Robot::~Robot() {}