//
//  tremaux.hpp
//  labrob
//
//  Created by Ormir G. on 15/05/16.
//  Copyright © 2016 Nitika Kumar, Ormir Gjurgjej. All rights reserved.
//

#ifndef tremaux_hpp
#define tremaux_hpp

#include <stdio.h>
#include "robot.hpp"

class Tremaux : public Robot {
    
public:
    Tremaux(const Labyrinth);
    bool solve();
    ~Tremaux();
};

#endif /* tremaux_hpp */
