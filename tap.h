#ifndef TAP_H
#define TAP_H
#include <systemc.h>

SC_MODULE(tap)
{
public:
  sc_in<bool> tms_i;
  sc_port<sc_fifo_in_if<char> > td_i;
  sc_in<bool> tck_i;
  sc_port<sc_fifo_out_if<char> > td_o;
  sc_out<bool> shift_dr_o;
  sc_out<bool> shift_ir_o;
  sc_out<bool> pause_dr_o;
  sc_out<bool> pause_ir_o;
  sc_port<sc_fifo_out_if<char> > tdi_serial_o;
  sc_port<sc_fifo_in_if<char> > tdo_serial_i;
  sc_in<bool> rst_i;
  sc_out<bool> capture_ir_o;
  sc_out<bool> capture_dr_o;
  sc_out<bool> update_ir_o;
  sc_out<bool> update_dr_o;
//private:
  sc_out<bool> exit1_ir_o;
  sc_out<bool> exit1_dr_o;
  sc_out<bool> exit2_ir_o;
  sc_out<bool> exit2_dr_o;
  //char buffer1[16];
  //char buffer2[16];
  //events

  void tap_main();
  //void dread();
  //void fread();
//  void output();

  SC_CTOR(tap)//inside module, must have same nameas a module,runs once
  {//Changes depending on clock design
  //void AThread(void);
   SC_THREAD(tap_main);
   //444SC_THREAD(dread);
   //SC_THREAD(output);

   //SC_METHOD(fread);
  //reset_signal_is(rst,true); //Declaring reset signal, need to ask about it

  }
};

#endif
