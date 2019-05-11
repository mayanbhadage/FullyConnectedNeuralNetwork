//
//  ReadData.hpp
//  HPC-Assignment3
//
//  Created by Mayan Bhadage on 5/6/19.
//  Copyright © 2019 Mayan Bhadage. All rights reserved.
//
#ifndef ReadData_hpp
#define ReadData_hpp

#include <fcntl.h>
#include <fstream>
#include <string>
#include <unistd.h>
#include <assert.h>


const  int INPUT_SIZE = 784;// 28 x 28
class ReadMnist
{
public:
    void swap(int &i);
    int read_int(int fd);
    
    template<int N>
    void read_mnist_images(const std::string &fn, float (&imgs)[N][INPUT_SIZE]);
    
    template <int N>
    void read_mnist_labels(const std::string &fn, unsigned char (&labels)[N]);
};


void ReadMnist::swap(int &i)
{
    i =
    (0xff&(i >> 24)) |
    (0xff00&(i >> 8)) |
    (0xff0000&(i << 8)) |
    (0xff000000&(i << 24));
}

int ReadMnist::read_int(int fd)
{
    size_t rv;
    int i;
    
    rv = read(fd,&i,4);
    swap(i);
    return i;
}


template<int N>
void ReadMnist::read_mnist_images(const std::string &fn, float (&imgs)[N][INPUT_SIZE])
{
    size_t rv;
    int fd;
    
    fd = open(fn.c_str(),O_RDONLY);
    assert(fd>0);
    
    int magic = read_int(fd);
    assert(magic == 0x803);
    
    int n_images = read_int(fd);
    assert(n_images == N);
    
    int n_rows = read_int(fd);
    assert(n_rows == 28);
    
    int n_cols = read_int(fd);
    assert(n_cols == 28);
    
    for (int i = 0; i < N; i++) {
        unsigned char tmp[INPUT_SIZE];
        rv = read(fd, tmp, INPUT_SIZE); assert(rv == INPUT_SIZE);
        for (int r = 0; r < INPUT_SIZE; r++) {
            // Make go from -1 to 1.
            imgs[i][r] = double(tmp[r])/127.5 - 1;
        }
    }
    
    rv = close(fd); assert(rv == 0);
}

template <int N>
void ReadMnist::
read_mnist_labels(const std::string &fn, unsigned char (&labels)[N])
{
    size_t rv;
    
    int fd;
    fd = open(fn.c_str(), O_RDONLY);
    assert(fd >= 0);
    
    int magic = read_int(fd);
    assert(magic == 0x801);
    
    int n_labels = read_int(fd);
    assert(n_labels == N);
    
    rv = read(fd, labels, N); assert(rv == N);
    for (int i = 0; i < N; i++) {
        assert(labels[i] >= 0 && labels[i] <= 9);
    }
    
    rv = close(fd); assert(rv == 0);
}

#endif /* ReadData_hpp */
