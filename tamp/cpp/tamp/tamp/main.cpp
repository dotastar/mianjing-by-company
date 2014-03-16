//
//  main.cpp
//  tamp
//
//  Created by 吴洋 on 14-3-16.
//  Copyright (c) 2014年 吴洋. All rights reserved.
//

#include <iostream>
#include <thread>

using namespace std;

void hello()
{
    cout<<"Hello world"<<endl;
}

int main(int argc, const char * argv[])
{
    thread t(hello);
    t.join();
    return 0;
}

