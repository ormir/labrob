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
            
            if (argc == 2) {
                WallFollower rob(lab);
                rob.solve();
                std::cout << "Robot finished on " << rob.getSteps() << " steps" << std::endl;
            } else {
                std::vector<Robot*> robList;
                
                for (int i = 2; i < argc; i++) {
                    std::string arg = argv[i];
                    
                    if (arg == "-h") lab.help();
                    else if (arg == "-t1") robList.push_back(new WallFollower(lab));
                    else if (arg == "-t2") robList.push_back(new Tremaux(lab));
                    else if (arg == "-t3") robList.push_back(new Recursive(lab));
                    else std::cout << "Argument " << arg << " not recognised" << std::endl;
                }
                
                // Solve robots
                for(auto it = robList.begin(); it != robList.end(); ++it)
                    (*it)->solve();
            
                
                // Show steps
                for(auto it = robList.begin(); it != robList.end(); ++it)
                    std::cout << "Robot " << it - robList.begin() << " has taken " << (*it)->getSteps() << " steps"<< std::endl;
                
                // Remove robots
                for(auto it = robList.begin(); it != robList.end(); ++it)
                    delete *it;
                
            }
        } else {
            std::cout << "File '" << argv[1] << "' cold not be oppend." << std::endl;
        }
        file.close();
    } else {
        std::cout << "Filename missing" << std::endl;
    }
    
    return 0;
}
