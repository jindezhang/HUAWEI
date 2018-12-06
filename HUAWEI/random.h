//明明的随机数
#pragma once


#include <iostream>
#include <set>

void main_random(){
    int num = 0;
    std::set<int> value;
    value.clear();
    std::cin >> num;
    if (num <= 0){
        std::cout << "input eorro!\n";
        return;
    }
    int temp;
    while ( num-- ){
        std::cin >> temp;
        value.insert( temp );
    }

    for(auto i = value.begin(); i != value.end(); i++){
        std::cout << *i << std::endl;
    }

}