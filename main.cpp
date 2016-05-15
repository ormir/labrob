//
//  main.cpp
//  labrob
//
//  Created by Ormir G. on 13/05/16.
//  Copyright © 2016 Nitika Kumar, Ormir Gjurgjej. All rights reserved.
//

#include <iostream>
#include "labyrinth.hpp"

int main(int argc, const char * argv[]) {
    
    if (argc > 1){
        // Read from given filename
        std::fstream file(argv[1]);
        if(file.is_open()){
            Labyrinth lab (file);
            lab.show();
        } else {
            std::cout << "File '" << argv[1] << "' cold not be oppend." << std::endl;
        }
        file.close();
    } else {
        std::cout << "Filename missing" << std::endl;
    }
    
    return 0;
}
