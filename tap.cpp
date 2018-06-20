#include "tap.h"
/*#include <string>
#include <fstream>
using namespace std;
ifstream fp_in;*/
void tap :: tap_main(void)
{
  //Reset Code


                 //reset_signal_is(rst,true);



   /*sc_trace_file *tf;
   tf = sc_create_vcd_trace_file("jtag");
         tf->set_time_unit(1, SC_NS);
   sc_trace(tf,tms_i, "tms");
   sc_trace(tf, tck_i, "clock");
   sc_trace(tf, shift_dr_o, "shift_dr");
   sc_trace(tf, shift_ir_o, "shift_ir");
   sc_trace(tf, pause_dr_o, "pause_dr");
   sc_trace(tf, pause_ir_o, "pause_ir");
   sc_trace(tf, rst_i, "rst");
   sc_trace(tf, capture_ir_o, "capture_ir");
   sc_trace(tf, capture_dr_o, "capture_dr");
   sc_trace(tf, update_ir_o, "update_ir");
   sc_trace(tf, update_dr_o, "update_dr");
   sc_trace(tf, exit1_ir_o, "exit1_ir");
   sc_trace(tf, exit1_dr_o, "exit1_dr");
   sc_trace(tf, exit2_ir_o, "exit2_ir");
   sc_trace(tf, exit2_ir_o, "exit2_ir");

   sc_start(10,SC_NS);*/


  int r = 2;
  //Reset output

  while(r < 6)
  {
    wait(10, SC_NS);
    cout<<"tms_i=1 , "<<tms_i<<endl ;         // 1st
    wait(10, SC_NS);
    cout<<"tms_i=1 , "<<tms_i<<endl ;            // 2nd
    wait(10, SC_NS);
    cout<<"tms_i=1 , "<<tms_i<<endl ;           // 3rd
    wait(10, SC_NS);
    cout<<"tms_i=1, "<<tms_i<<endl ;            // 4th
    wait(5, SC_NS);//45, 5th wait
    cout<<"Reset; tms_i=11111, "<<tms_i<<endl ;    // 5th ,ready for reset & abt to transit
    wait(10, SC_NS);//55,6th wait
    if(tms_i.read() == 0)
    {
      cout<<"Run test idle"<<endl;


    }

    wait(20, SC_NS);//75, 7th wait
    if(tms_i.read() ==1)
    {
      cout<<"Select IR"<<endl;
    }
    wait(6, SC_NS);//81, 8th wait
    if(tms_i.read()==0)
    {
      cout<<"Capture IR"<<endl;
      capture_ir_o.write(1);
    }
    wait(10, SC_NS);//91, 9th wait
    if(tms_i.read() == 0)
    {
      cout << "Shift_IR will begin"<<endl;

    }
    wait(10, SC_NS);//101, 10th wait
    if(tms_i.read() == 0)
    {
      cout<<"shift_ir"<<endl;
      shift_ir_o.write(1);
    }
    wait(80, SC_NS);//181, 11th wait
    if(tms_i.read() == 1)
    {
      cout <<"exit1_ir"<<endl;
      exit1_ir_o.write(1);
    }
    wait(10, SC_NS);//191, 12th
    if(tms_i.read() == 1)
    {
      cout<<"update ir"<<endl;
      update_ir_o.write(1);
    }

    //-----------------------------------------------------------
    //Towards dr
    //-----------------------------------------------------------------
    wait(10, SC_NS);//201, 13th wait
    if(tms_i.read() ==1)
    {
      cout<<"Select DR Scan"<<endl;
    }
    wait(10, SC_NS);//211, 14th wait
    if(tms_i.read()==0)
    {
      cout<<"Capture DR"<<endl;
      capture_dr_o.write(1);
    }
    wait(10, SC_NS);//221, 15th wait
    if(tms_i.read() == 0)
    {
      cout << "Shift_DR will begin"<<endl;
    }
    wait(10, SC_NS);//231, 16th wait
    if(tms_i.read() == 0)
    {
      cout<<"shift_dr"<<endl;
      shift_dr_o.write(1);
    }
    wait(80, SC_NS);//311, 17th wait
    if(tms_i.read() == 1)
    {
      cout <<"exit1_dr"<<endl;
      exit1_dr_o.write(1);
    }
    wait(10, SC_NS);//321, 18th wait
    if(tms_i.read() == 1)
    {
      cout<<"update dr"<<endl;
      update_dr_o.write(1);
    }
    wait(10, SC_NS);//331,19th
    if(tms_i.read() == 1)
    {
      cout<<"select dr scan"<<endl;
    }
    wait(10,SC_NS);//341ns,20th wait

    //----------------------First stage----------------//
    //wait(20, SC_NS);//75, 7th wait
    if(tms_i.read() ==1)
    {
      cout<<"Select IR"<<endl;
        ////sc_start(1,SC_NS);

    }
    wait(10, SC_NS);//81, 8th wait
    if(tms_i.read()==0)
    {
      cout<<"Capture IR"<<endl;
      capture_ir_o.write(1);
      //sc_start(1,SC_NS);
    }
    wait(10, SC_NS);//91, 9th wait
    if(tms_i.read() == 0)
    {
      cout << "Shift_IR will begin"<<endl;
      //sc_start(1,SC_NS);

    }
    wait(10, SC_NS);//101, 10th wait
    if(tms_i.read() == 0)
    {
      cout<<"shift_ir"<<endl;
      shift_ir_o.write(1);
      //sc_start(1,SC_NS);

    }
    wait(80, SC_NS);//181, 11th wait
    if(tms_i.read() == 1)
    {
      cout <<"exit1_ir"<<endl;
      exit1_ir_o.write(1);
      //sc_start(1,SC_NS);
    }
    wait(10,SC_NS);
    if(tms_i.read() == 0)
    {
      cout<<"Pause IR"<<endl;
      pause_ir_o.write(1);
    }
    wait(10,SC_NS);
    if(tms_i.read() == 1)
    {
      cout<<"Exit2_IR"<<endl;
      exit2_ir_o.write(1);
    }
    wait(10,SC_NS);
    if(tms_i.read() == 1)
    {
      cout<<"Update IR"<<endl;
      update_ir_o.write(1);
    }
    wait(10,SC_NS);
    if(tms_i.read() == 1)
    {
      cout<<"Select DR Scan"<<endl;
      update_ir_o.write(1);
    }
    wait(10, SC_NS);//81, 8th wait
    if(tms_i.read()==0)
    {
      cout<<"Capture DR"<<endl;
      capture_ir_o.write(1);
      //sc_start(1,SC_NS);
    }
    wait(10, SC_NS);//91, 9th wait
    if(tms_i.read() == 0)
    {
      cout << "Shift_DR will begin"<<endl;
      //sc_start(1,SC_NS);

    }
    wait(10, SC_NS);//101, 10th wait
    if(tms_i.read() == 0)
    {
      cout<<"shift_dr"<<endl;
      shift_dr_o.write(1);
      //sc_start(1,SC_NS);

    }
    wait(80, SC_NS);//181, 11th wait
    if(tms_i.read() == 1)
    {
      cout <<"exit1_dr"<<endl;
      exit1_dr_o.write(1);
      //sc_start(1,SC_NS);
    }
    wait(10,SC_NS);
    if(tms_i.read() == 0)
    {
      cout<<"Pause DR"<<endl;
      pause_dr_o.write(1);
    }
    wait(10,SC_NS);
    if(tms_i.read() == 1)
    {
      cout<<"Exit2_DR"<<endl;
      exit2_dr_o.write(1);
    }
    wait(10,SC_NS);
    if(tms_i.read() == 1)
    {
      cout<<"Update DR"<<endl;
      update_dr_o.write(1);
    }
    wait(10,SC_NS);
    if(tms_i.read() == 1)
    {
      cout<<"Select DR Scan"<<endl;

    }
    //--------skip shift ir dr stages---------------------------
    wait(10,SC_NS);
    if(tms_i.read() == 1)
    {
      cout<<"Select IR Scan"<<endl;
    }
    wait(10,SC_NS);
    if(tms_i.read() == 0)
    {
      cout<<"Capture IR"<<endl;
      capture_ir_o.write(1);
    }
    wait(10,SC_NS);
    if(tms_i.read() == 1)
    {
      cout<<"Exit1 IR"<<endl;
      exit1_ir_o.write(1);
    }
    wait(10,SC_NS);
    if(tms_i.read() == 1)
    {
      cout<<"Update IR"<<endl;
      update_ir_o.write(1);
    }
    wait(10,SC_NS);
    if(tms_i.read() == 1)
    {
      cout<<"Select DR Scan"<<endl;

    }
    wait(10,SC_NS);
    if(tms_i.read() == 0)
    {
      cout<<"Capture DR"<<endl;
      capture_ir_o.write(1);
    }
    wait(10,SC_NS);
    if(tms_i.read() == 1)
    {
      cout<<"Exit1 DR"<<endl;
      exit1_ir_o.write(1);
    }
    wait(10,SC_NS);
    if(tms_i.read() == 1)
    {
      cout<<"Update DR"<<endl;
      update_ir_o.write(1);
    }
    wait(10,SC_NS);
    if(tms_i.read() == 1)
    {
      cout<<"Select DR Scan"<<endl;

    }
    //------------This is for back to //shift from ////exit2.....
  /*  wait(10,SC_NS);
    if(tms_i.read() == 1)
    {
      cout<<"Select IR Scan"<<endl;

    }
    wait(10,SC_NS);
    if(tms_i.read() == 0)
    {
      cout<<"Capture IR"<<endl;
      capture_ir_o.write(1);

    }
    wait(10,SC_NS);
    if(tms_i.read() == 0)
    {
      cout << "Shift_IR will begin"<<endl;
      //sc_start(1,SC_NS);

    }
    wait(10, SC_NS);//101, 10th wait
    if(tms_i.read() == 0)
    {
      cout<<"shift_ir"<<endl;
      shift_ir_o.write(1);
      //sc_start(1,SC_NS);

    }
    wait(10, SC_NS);//101, 10th wait
    if(tms_i.read() == 1)
    {
      cout<<"exit1 ir"<<endl;
      exit1_ir_o.write(1);
      //sc_start(1,SC_NS);

    }
    wait(10, SC_NS);//101, 10th wait
    if(tms_i.read() == 0)
    {
      cout<<"pause ir"<<endl;
      pause_ir_o.write(1);
      //sc_start(1,SC_NS);

    }
    wait(10, SC_NS);//101, 10th wait
    if(tms_i.read() == 1)
    {
      cout<<"exit2 ir"<<endl;
      exit2_ir_o.write(1);
      //sc_start(1,SC_NS);

    }
    wait(10,SC_NS);
    if(tms_i.read() == 0)
    {
      cout << "Shift_IR will begin"<<endl;
      //sc_start(1,SC_NS);

    }
    wait(10, SC_NS);//101, 10th wait
    if(tms_i.read() == 0)
    {
      cout<<"shift_ir"<<endl;
      shift_ir_o.write(1);
      //sc_start(1,SC_NS);

    }
    wait(80, SC_NS);*/






  //sc_close_vcd_trace_file(tf);
    /*cout<<"Reading starts for tdi"<<endl;
    for(int a = 0; a < 100; a++)
    {


    tdi_serial_o[a] -> td_i[a].read();
    cout<<"tdi serial is"<<tdi_serial_o[a]<<endl;
  };*/
r = r * 2;

};
std::ifstream fp_in;
  fp_in.open("tdo.txt", ios::in | ios::binary);
    if (fp_in.is_open())
    {
          cout  << "file opened for reading" << endl;
         fp_in.seekg(0, ios::beg ); // put file pointer to beginning of file
    char cstr[100];
    cout<< "reading from the file" <<endl;
    fp_in >>cstr;		//reading from the file into the buffer1
    cout<< cstr <<"@" << sc_time_stamp() <<endl;



     //buffer_t1 = cstr;
     for(int a = 0; a < 100; a++)
  {
    td_o-> write(cstr[a]);

    cout<<"td_o is"<<cstr[a]<<endl;
    cout<<"tdi_serial_o is "<<cstr[a]<<endl;
    //exit(0);
    /*tdi_serial_o[a] -> write(td_i[a]);
    cout<<"td_o is"<<td_o[a]<<endl;*/
  };


    //cout<< cstr[0]<<"@" << sc_time_stamp() <<endl;
    //wait(1000,SC_NS);
  }

    else
   {
         cout << "Unable to open data.txt for reading"<<endl;

   }
   fp_in.close();
exit(0);
}

/*void tap :: dread(void)
{
while(1)
{
  cout<<"Reading starts for tdi"<<endl;
for(int j=0;j<16;j++)
{
cout<<"Reading starts for tdi"<<endl;
buffer1[j] = td_i.read();
tdi_serial_o.write(buffer1[j]);
cout<<"tdi reading ended"<<endl;
};
for(int k=0;k<16;k++)
{
  cout<<"Reading starts for tdo"<<endl;
  buffer2[k] = tdo_serial_i.read();
  td_o.write(buffer2[k]);
  cout<<"Reading ends for tdo"<<endl;

};
};

    //Read inputs
    //Algorithm Code
    //write outputs
  }*/
  /*void tap :: output(void)
  {
   system("./main.x >> output.txt");
   exit(0);
 }*/
/*void tap :: fread(void)


  {std::ifstream fp_in;
  	fp_in.open("nmea.txt", ios::in | ios::binary);
    	if (fp_in.is_open())
    	{
        		cout  << "file opened for reading" << endl;
       		 fp_in.seekg(0, ios::beg ); // put file pointer to beginning of file
  		char cstr[100];
  		cout<< "reading from the file" <<endl;
  		fp_in >>cstr;		//reading from the file into the buffer1
      cout<< cstr <<"@" << sc_time_stamp() <<endl;



  		 //buffer_t1 = cstr;
       for(int a = 0; a < 100; a++)
    {
  		td_i -> write(cstr[a]);

      cout<<"td_i is"<<td_i[a]<<endl;
      //exit(0);
  		//tdi_serial_o >> write(td_i);
    };


  		//cout<< cstr[0]<<"@" << sc_time_stamp() <<endl;
  		//wait(1000,SC_NS);
    }

    	else
  	 {
       		 cout << "Unable to open data.txt for reading";

  	 }
     fp_in.close();
   }*/
