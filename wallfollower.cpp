//
//  wallfollower.cpp
//  labrob
//
//  Created by Ormir G. on 15/05/16.
//  Copyright © 2016 Nitika Kumar, Ormir Gjurgjej. All rights reserved.
//

#include "wallfollower.hpp"

WallFollower::WallFollower(const Labyrinth l) :
Robot(l),
direction('s') {}

bool WallFollower::solve() {
    std::vector<std::pair<int, int>> path;
    
    while (!lab.isAtExit(curX, curY)) {
        direction = changeDirection();

        if (direction == 'w') curX--;
        else if (direction == 's') curY ++;
        else if (direction == 'e') curX ++;
        else if (direction == 'n') curY --;
        
        // Save path
        path.push_back(std::make_pair(curX, curY));
        
        steps++;
    }
    
    // Write path to labyrinth
    for(unsigned int i = 0; i < path.size(); i++)
        lab.at(path[i].first, path[i].second) = 'x';
    
    return true;
}

char WallFollower::changeDirection() {
    std::map<char, char> surr = lab.getSurrounding(curX, curY);
    char newDir = 's';
    
    if (direction == 's') {
        if(surr['w'] == ' ') newDir = 'w';
        else if(surr['s'] == ' ') newDir = 's';
        else if(surr['e'] == ' ') newDir = 'e';
        else if(surr['n'] == ' ') newDir = 'n';
    } else if (direction == 'w') {
        if(surr['n'] == ' ') newDir = 'n';
        else if(surr['w'] == ' ') newDir = 'w';
        else if(surr['s'] == ' ') newDir = 's';
        else if(surr['e'] == ' ') newDir = 'e';
    } else if (direction == 'n') {
        if(surr['e'] == ' ') newDir = 'e';
        else if(surr['n'] == ' ') newDir = 'n';
        else if(surr['w'] == ' ') newDir = 'w';
        else if(surr['s'] == ' ') newDir = 's';
    } else if (direction == 'e') {
        if(surr['s'] == ' ') newDir = 's';
        else if(surr['e'] == ' ') newDir = 'e';
        else if(surr['n'] == ' ') newDir = 'n';
        else if(surr['w'] == ' ') newDir = 'w';
    }
    
    return newDir;
}

WallFollower::~WallFollower() {}