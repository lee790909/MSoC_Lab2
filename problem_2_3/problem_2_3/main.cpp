//
//  main.cpp
//  problem_1_1
//
//  Created by Lee Haw on 13/4/9.
//  Copyright (c) 2013年 Lee Haw. All rights reserved.
//

#include <systemc.h>
#include "Memory.h"
#include "InterChangeUnit.h"

SC_MODULE(Top) {
    
    Memory memory;
    InterChangeUnit interChangeUnit;
    
    sc_signal<bool> LD;
    sc_signal<bool> RW;
    sc_signal<unsigned> X;
    sc_signal<unsigned> Y;
    sc_signal_rv<32> D;
    sc_in_clk clk;
    
    Top(sc_module_name name) :
    memory("memory"),
    interChangeUnit("inter_change_unit") {
        
        dont_initialize();
        
        interChangeUnit.LD(LD);
        interChangeUnit.RW(RW);
        interChangeUnit.X(X);
        interChangeUnit.Y(Y);
        interChangeUnit.D(D);
        interChangeUnit.CLK(clk);
        
        memory.LD(LD);
        memory.RW(RW);
        memory.X(X);
        memory.Y(Y);
        memory.D(D);
        memory.CLK(clk);
        
    }
    
    void display() {
        memory.display();
    }
};


int sc_main (int argc, char * argv[]) {
			
    sc_report_handler::set_actions (SC_ID_VECTOR_CONTAINS_LOGIC_VALUE_, SC_DO_NOTHING);
    
    // insert code here...
    Top top("top");
    
    sc_clock clk("clk",10, SC_NS);
    top.clk(clk);
    
    std::cout << "Hello, SystemC!\n";
    sc_start(500, SC_US);
    
    top.display();
    
    return 0;
}

