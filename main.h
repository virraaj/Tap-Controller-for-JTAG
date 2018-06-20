#ifndef MAIN_TAP_H
#define MAIN_TAP_H


#include "systemc.h"
#include "tap.h"
#include "tap_tb.h"
SC_MODULE(SYSTEM)
{
  tap_tb *tb0; //reference name
  tap *tap0;//reference name
public:
  sc_fifo<char> td_i_sig;//include vector
  sc_signal<bool> tms_i_sig;
  sc_fifo<char> td_o_sig;
  sc_signal<bool> tck_i_sig;
  sc_signal<bool> shift_dr_o_signal;
  sc_signal<bool> shift_ir_o_signal;
  sc_signal<bool> pause_dr_o_signal;
  sc_signal<bool> pause_ir_o_signal;
  sc_fifo<char> tdi_serial_o_signal;
  sc_fifo<char> tdo_serial_i_signal;
  sc_signal<bool> rst_i_signal;
  sc_signal<bool> capture_ir_o_signal;
  sc_signal<bool> capture_dr_o_signal;
  sc_signal<bool> update_ir_o_signal;
  sc_signal<bool> update_dr_o_signal;
//private:
  sc_signal<bool> exit1_ir_o_signal;
  sc_signal<bool> exit1_dr_o_signal;
  sc_signal<bool> exit2_ir_o_signal;
  sc_signal<bool> exit2_dr_o_signal;
  SC_CTOR(SYSTEM);

    //tb0 = new tap_tb("tb0"); //allocates memory space
    //tap0 = new tap("tap0"); //allocates memory space
    //tap_tb* tb0;
    //tap* tap0;

  };

#endif
