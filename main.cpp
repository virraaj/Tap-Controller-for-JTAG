#include "systemc.h"
#include "tap.h"
#include "tap_tb.h"
#include "main.h"
SYSTEM::SYSTEM(sc_module_name nm):sc_module(nm),td_i_sig(16),td_o_sig(16),tdi_serial_o_signal(16),tdo_serial_i_signal(16)
  {
    tb0 = new tap_tb("tb0"); //allocates memory space
    tb0 -> tck_i(tck_i_sig); //since tb0 is pointer, use arrow style
    tb0 -> td_i(td_i_sig);
    tb0 -> tms_i(tms_i_sig);
    tb0 -> td_o(td_o_sig);
    tb0 -> shift_dr_o(shift_dr_o_signal);
    tb0 -> shift_ir_o(shift_ir_o_signal);
    tb0 -> pause_dr_o(pause_dr_o_signal);
    tb0 -> pause_ir_o(pause_ir_o_signal);
    tb0 -> tdi_serial_o(tdi_serial_o_signal);
    tb0 -> tdo_serial_i(tdo_serial_i_signal);
    tb0 -> rst_i(rst_i_signal);
    tb0 -> capture_ir_o(capture_ir_o_signal);
    tb0 -> capture_dr_o(capture_dr_o_signal);
    tb0 -> update_ir_o(update_ir_o_signal);
    tb0 -> update_dr_o(update_dr_o_signal);
    tb0 -> exit1_ir_o(exit1_ir_o_signal);
    tb0 -> exit1_dr_o(exit1_dr_o_signal);
    tb0 -> exit2_ir_o(exit2_ir_o_signal);
    tb0 -> exit2_dr_o(exit2_dr_o_signal);
    tap0 = new tap("tap0"); //allocates memory space
    tap0 -> tck_i(tck_i_sig); //since tb0 is pointer, use arrow style
    tap0 -> td_i(td_i_sig);
    tap0 -> tms_i(tms_i_sig);
    tap0 -> td_o(td_o_sig);
    tap0 -> shift_dr_o(shift_dr_o_signal);
    tap0 -> shift_ir_o(shift_ir_o_signal);
    tap0 -> pause_dr_o(pause_dr_o_signal);
    tap0 -> pause_ir_o(pause_ir_o_signal);
    tap0 -> tdi_serial_o(tdi_serial_o_signal);
    tap0 -> tdo_serial_i(tdo_serial_i_signal);
    tap0 -> rst_i(rst_i_signal);
    tap0 -> capture_ir_o(capture_ir_o_signal);
    tap0 -> capture_dr_o(capture_dr_o_signal);
    tap0 -> update_ir_o(update_ir_o_signal);
    tap0 -> update_dr_o(update_dr_o_signal);
    tap0 -> exit1_ir_o(exit1_ir_o_signal);
    tap0 -> exit1_dr_o(exit1_dr_o_signal);
    tap0 -> exit2_ir_o(exit2_ir_o_signal);
    tap0 -> exit2_dr_o(exit2_dr_o_signal);
  }
  /*~SYSTEM()
  {
    delete tb0;
    delete tap0;
  }*/

//SYSTEM MODULE INSTANTIATION
SYSTEM *top=NULL; // Declare instance pointer "top" and set pointer to NULL, so points to NULL port of memory
int sc_main(int argc, char *argv[])
{
  top=new SYSTEM("top");
  sc_start(); //start systemc simulation
  return 0;
}
