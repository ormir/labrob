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
lab(l) {
    l.getEntry(curX, curY);
}

void Robot::path() {
    thSolve = std::thread([this](){ solve(); });
}

void Robot::showPath() const { lab.show(); }

bool Robot::solve() { return false; }

int Robot::getSteps() {
    thSolve.join();
    return steps;
}

Robot::~Robot() {}