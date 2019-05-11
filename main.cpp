

#include <iostream>
#include <random>
#include <vector>
#include<array>
#include "ReadData.hpp"
#include "FeedForward.h"

const int numHidden = 1024;
const int numInput = 784;
const int numOutput = 10;




float genetate_random_weights()
{
    float weight = (float) rand()/float(RAND_MAX);
    return weight;
}


void InitlilizeRandomWeights(std::array<std::array<float, numHidden>,numInput> &weights_IH,
                             std::array<std::array<float,numOutput>,numHidden> &weights_HO,
                             std::array<float,numHidden> &b_Hidden,
                             std::array<float,numOutput> &b_Output)
{
    
    // Initilize Random Weights Input->Hidden
    for (int i = 0; i < numInput; i++)
    {
        for (int j = 0; j < numHidden; j++) {
            
            weights_IH[i][j] = genetate_random_weights();
// assert(weights_IH > 0);
        }
    }
    
    //Initilize Random Weights Hidden->Output
    
    for (int i = 0 ; i < numHidden; i++) {
        for (int j = 0; j < numOutput; j++) {
            
            weights_HO[i][j] =  genetate_random_weights();
            assert(weights_HO[i][j] > 0);
        
        }
    }
    
    // Initilize Bias for the Hidden layer
    for (int i = 0; i < numHidden; i ++) {
        b_Hidden[i]  =  genetate_random_weights();
        assert(b_Hidden[i] > 0);
    }
    
    // Initilize Bias for Output layer
    for(int i = 0; i < numOutput; i++)
    {
        b_Output[i] = genetate_random_weights();
        assert(b_Output[i] > 0);
    }
    
    
   
}


int main() {
    
    
    //
    static float training_images[60000][INPUT_SIZE];
    static unsigned char training_labels[60000];
    
    
    
    // Weights for the Input to Hidden layer
    //float w_INPUT_HIDDEN[numInput][numHidden];
    static std::array<std::array<float, numHidden>,numInput> w_INPUT_HIDDEN;
    // Weights for the Hidden to Output layer
    //float w_HIDDEN_OUTPUT[numHidden][numOutput];
    static std::array<std::array<float, numOutput>,numHidden> w_HIDDEN_OUTPUT;
    //Bias for Hidden Layer
    //float b_Hidden[numHidden];

    static std::array<float,numHidden> b_Hidden;
    //Bias for Output Layer
   // float b_Output[numOutput];
    static std::array<float,numOutput> b_Output;
    
    
    
    //TODO: Read Training data
    
    ReadMnist *read_train = new ReadMnist();
    read_train->read_mnist_images("mnist/train-images-idx3-ubyte", training_images);
    read_train->read_mnist_labels("mnist/train-labels-idx1-ubyte", training_labels);
                       
    std::cout<<"Read Sucessfull"<<std::endl;
    //TODO: Initilize Inititial weights to the network
    
    //InitlilizeRandomWeights(w_INPUT_HIDDEN, w_HIDDEN_OUTPUT, b_Hidden, b_Output);
    InitlilizeRandomWeights(w_INPUT_HIDDEN,w_HIDDEN_OUTPUT,b_Hidden,b_Output);
    std::cout<<"Init Random weights Sucessfull"<<std::endl;
    

    //TODO: Train the Network (Feedforward and backprop)
    
 
    
    //TODO: Read Testing data
    
    //TODO: Test our NeuralNetwork
    
    
    
    
    
    return 0;
}
