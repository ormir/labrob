//
//  main.cpp
//  labrob
//
//  Created by Ormir G. on 13/05/16.
//  Copyright © 2016 Nitika Kumar, Ormir Gjurgjej. All rights reserved.
//

#include <iostream>
#include "labyrinth.hpp"
#include "wallfollower.hpp"
#include "tremaux.hpp"
#include "recursive.hpp"

int main(int argc, const char * argv[]) {
    
    if (argc > 1){
        // Read from given filename
        std::fstream file(argv[1]);
        if(file.is_open()){
            Labyrinth lab (file);
            Recursive rob(lab);
            if (rob.solve()) std::cout << "Robot finished on " << rob.getSteps() << " steps" << std::endl;
        } else {
            std::cout << "File '" << argv[1] << "' cold not be oppend." << std::endl;
        }
        file.close();
    } else {
        std::cout << "Filename missing" << std::endl;
    }
    
    return 0;
}
