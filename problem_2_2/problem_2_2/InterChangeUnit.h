//
//  InterChangeUnit.h
//  problem_1_1
//
//  Created by Lee Haw on 13/4/9.
//  Copyright (c) 2013年 Lee Haw. All rights reserved.
//

#ifndef __problem_1_1__InterChangeUnit__
#define __problem_1_1__InterChangeUnit__

#include <iostream>
#include "systemc.h"
#include "Mem_if.h"
#include "Memory.h"

SC_MODULE(InterChangeUnit) {
        
    sc_in_clk CLK;
    sc_out<bool> LD;
    sc_out<bool> RW;
    sc_out<unsigned> X;
    sc_out<unsigned> Y;
    sc_inout_rv<32> D;
    
    SC_HAS_PROCESS(InterChangeUnit);
    
    InterChangeUnit(sc_module_name name) {

        SC_THREAD(test_thread);
        
        size = Memory::SIZE;
    }
    
    void test_thread();
    int size;
};



#endif /* defined(__problem_1_1__InterChangeUnit__) */
