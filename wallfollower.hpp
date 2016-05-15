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
    
    
public:
    WallFollower(const Labyrinth);
    void changeDirection();
    bool solve();
    ~WallFollower();
};

#endif /* wallfollower_hpp */
