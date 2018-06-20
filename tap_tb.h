#ifndef TAP_TB_H
#define TAP_TB_H
#include "systemc.h"

SC_MODULE(tap_tb)
{
public:
  sc_out<bool> tms_i;
  sc_port<sc_fifo_out_if<char> > td_i;
  sc_out<bool> tck_i;
  sc_port<sc_fifo_in_if<char> > td_o;
  //sc_port<sc_fifo_out_if<char> > td_o;
  sc_port<sc_fifo_in_if<char> > tdi_serial_o;
  sc_port<sc_fifo_out_if<char> > tdo_serial_i;
  //sc_fifo_in<char> td_o;
  sc_in<bool> shift_dr_o;
  sc_in<bool> shift_ir_o;
  sc_in<bool> pause_dr_o;
  sc_in<bool> pause_ir_o;
  //sc_fifo_in<char> tdi_serial_o;
  //sc_fifo_out<char> tdo_serial_i;
  sc_out<bool> rst_i;
  sc_in<bool> capture_ir_o;
  sc_in<bool> capture_dr_o;
  sc_in<bool> update_ir_o;
  sc_in<bool> update_dr_o;
//private:
  sc_in<bool> exit1_ir_o;
  sc_in<bool> exit1_dr_o;
  sc_in<bool> exit2_ir_o;
  sc_in<bool> exit2_dr_o;


void source();//Where output port values will be produced
//void sink();//Read value coming back to tdo port
//FILE *outfp;
SC_CTOR(tap_tb)
{
   SC_THREAD(source);
   //sensitive << tms_i;
   //sensitive << tck_i;
   //SC_THREAD(sink);
}
};

#endif
