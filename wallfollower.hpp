//
//  wallfollower.hpp
//  labrob
//
//  Created by Ormir G. on 15/05/16.
//  Copyright © 2016 Nitika Kumar, Ormir Gjurgjej. All rights reserved.
//

#ifndef wallfollower_hpp
#define wallfollower_hpp

#include <stdio.h>
#include "robot.hpp"

class WallFollower: public Robot {
    char direction;
    char changeDirection();
    bool solve();
public:
    WallFollower(const Labyrinth);
    ~WallFollower();
};

#endif /* wallfollower_hpp */
