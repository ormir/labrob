//
//  wallfollower.cpp
//  labrob
//
//  Created by Ormir G. on 15/05/16.
//  Copyright © 2016 Nitika Kumar, Ormir Gjurgjej. All rights reserved.
//

#include "wallfollower.hpp"

WallFollower::WallFollower(const Labyrinth l) :
Robot(l) {}

bool WallFollower::solve() {
    while (!lab.isAtExit(curX, curY)) {
        lab.markPosition(curX, curY);
        std::map<char, char> surr = lab.getSurrounding(curX, curY);
        

        if (surr['w'] == ' ') curX --;
        else if (surr['s'] == ' ') curY ++;
        else if (surr['e'] == ' ') curX ++;
        else if (surr['n'] == ' ') curY --;
        else if (surr['w'] == 'x') curX --;
        else if (surr['s'] == 'x') curY ++;
        else if (surr['e'] == 'x') curX ++;
        else if (surr['n'] == 'x') curY --;
        
//        lab.show();
        steps++;
    }
    lab.show();
    return true;
}

void WallFollower::changeDirection() {
    std::map<char, char> surr = lab.getSurrounding(curX, curY);
}

WallFollower::~WallFollower() {}