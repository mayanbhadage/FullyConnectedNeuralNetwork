//
//  FeedForward.h
//  HPC-Assignment3
//
//  Created by Mayan Bhadage on 5/10/19.
//  Copyright © 2019 Mayan Bhadage. All rights reserved.
//

#ifndef FeedForward_h
#define FeedForward_h

// Here is the code for feedforward network

// From Input layer to the Hidden layer

class FeedForward{
public:
    double Input_for_Hidden;
    
    void train_imgs(float (*imgs)[INPUT_SIZE], unsigned char* labels);

    //Images to the Hidden Layer
    
};

void FeedForward::train_imgs(float (*imgs)[INPUT_SIZE], unsigned char* labels)
{
    int Training_size = 200;
    for (int i = 0 ; i < Training_size; i++) {
        
        float * img = imgs[i];
        unsigned char label = labels[i];
        
        //Forward Pass
        
        //feedforward_input_to_hidden();
        // Input layer to Hidden layer : Calculate Input for the hidden layer
        
        
        //Backward Pass
        
        //Update weights
    }
}




#endif /* FeedForward_h */
