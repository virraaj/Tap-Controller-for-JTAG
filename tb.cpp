#include "tap_tb.h"
//#include <string>
#include <string>
#include <fstream>
using namespace std;
ifstream fp_in;
void tap_tb :: source()
{
  //tdi,tms_i,clk
  int i;

  /*tms_i.write(1);
  tck_i.write(0);
  //capture_ir_o.write(0);
  //capture_dr_o.write(0);
  //shift_ir_o.write(0);
  //shift_dr_o.write(0);
  //pause_ir_o.write(0);
  //pause_dr_o.write(0);
  rst_i.write(0);
  ////exit1_ir_o.write(0);
  ////exit1_dr_o.write(0);
  ////exit2_ir_o.write(0);
  ////exit2_dr_o.write(0);*/
  //td_i = "The test Signal";





  while(true)
  {
    tms_i.write(1);
    for(i=1;i<=5;i++)                    //Initialize JTAG
    {
    tck_i.write(1);
    wait(10,SC_NS);                       //50ns
    }
    tms_i.write(0);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);
      wait(10,SC_NS);             //60ns

    }
    tms_i.write(1);
    for(i=1;i<=2;i++)
    {
      tck_i.write(1);
      wait(10,SC_NS);               //80ns

    }
    tms_i.write(0);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);

      //capture_ir_o.write(1);
      wait(10,SC_NS);                    //90ns

    }

    tms_i.write(0);
    for(i=0;i<=8;i++)     // i=0 for excluding length;
    {
      tck_i.write(1);
      ////shift_ir.write(1);
      wait(10,SC_NS);                       //180ns
    }
    tms_i.write(1);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);                     //190ns
      wait(10,SC_NS);
      ////update_ir.write(1);

    } ;
    tms_i.write(1);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);
      wait(10,SC_NS);                    //200ns

    }
    tms_i.write(1);//For data scan
    for(i=1;i<2;i++)
    {
      tck_i.write(1);
      wait(10,SC_NS);                    //210ns

    }

    // towards select Data Register
    //--------------------------------------------------------------------
    tms_i.write(0);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);

      //capture_dr_o.write(1);
      wait(10,SC_NS);                  //220ns

    }

    tms_i.write(0);
    for(i=0;i<=8;i++)     // i=0 for excluding length;
    {
      tck_i.write(1);
      //shift_dr_o.write(1);
      wait(10,SC_NS);//310ns
    }
    tms_i.write(1);
    for(i=1;i<=2;i++)
    {
      tck_i.write(1);
      wait(10,SC_NS);//330ns
      //update_dr_o.write(1);

    } ;
    tms_i.write(1);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);
      wait(10,SC_NS);//340ns

    }
    //............................................................................................
    //ends towards select data DataScan, one cycle od dr and ir completed...now heading for advanced stages
    //
    tms_i.write(1);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);
      wait(10,SC_NS);

    }
    tms_i.write(0);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);

      //capture_ir_o.write(1);
      wait(10,SC_NS);

    }

    tms_i.write(0);
    for(i=0;i<=8;i++)     // i=0 for excluding length;
    {
      tck_i.write(1);
      //shift_ir_o.write(1);
      wait(10,SC_NS);
    }
    tms_i.write(1);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);
      ////exit1_ir_o.write(1);
      wait(10,SC_NS);

    }
    tms_i.write(0);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);
      //pause_ir_o.write(1);
      wait(10,SC_NS);
    }
    tms_i.write(1);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);
      ////exit2_ir_o.write(1);
      wait(10,SC_NS);
    }
    tms_i.write(1);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);
      //update_ir_o.write(1);
      wait(10,SC_NS);
    }
    tms_i.write(1);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);
      wait(10,SC_NS);

    }
//--------------------------------------------------------------------------------------------------------------
    ////Towards DataScan

    tms_i.write(0);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);

      //capture_dr_o.write(1);
      wait(10,SC_NS);

    }

    tms_i.write(0);
    for(i=0;i<=8;i++)     // i=0 for excluding length;
    {
      tck_i.write(1);
      //shift_dr_o.write(1);
      wait(10,SC_NS);
    }
    tms_i.write(1);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);
      ////exit1_dr_o.write(1);
      wait(10,SC_NS);

    }
    tms_i.write(0);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);
      //pause_dr_o.write(1);
      wait(10,SC_NS);
    }
    tms_i.write(1);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);
      ////exit2_dr_o.write(1);
      wait(10,SC_NS);
    }
    tms_i.write(1);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);
      //update_dr_o.write(1);
      wait(10,SC_NS);
    }
    tms_i.write(1);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);
      wait(10,SC_NS);

    }
     //Towards datascan
    //-----------------------------------------------------------------------
    //The following loop is for skipping the //shift ir and dr.
    tms_i.write(1);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);
      wait(10,SC_NS);

    }
    tms_i.write(0);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);

      //capture_ir_o.write(1);
      wait(10,SC_NS);

    }

    tms_i.write(1);
    for(i=1;i<2;i++)     // i=0 for excluding length;
    {
      tck_i.write(1);
      wait(10,SC_NS);
      ////exit1_ir_o.write(1);
    }
    tms_i.write(1);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);
      wait(10,SC_NS);
      //update_ir_o.write(1);

    } ;
    tms_i.write(1);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);
      wait(10,SC_NS);

    }
    // Towards DataScan
    //--------------------

    tms_i.write(0);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);

      //capture_dr_o.write(1);
      wait(10,SC_NS);

    }

    tms_i.write(1);
    for(i=1;i<2;i++)     // i=0 for excluding length;
    {
      tck_i.write(1);
      ////exit1_dr_o.write(1);
      wait(10,SC_NS);

    }
    tms_i.write(1);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);
      //update_dr_o.write(1);
      wait(10,SC_NS);


    } ;
    tms_i.write(1);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);
      wait(10,SC_NS);

    }

    // Towards Datascan
    //------------------------------------------------------------------------------------
/*    //The follwing loop is for back to //shift from ////exit2
    tms_i.write(1);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);
      wait(10,SC_NS);

    }
    tms_i.write(0);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);

      //capture_ir_o.write(1);
      wait(10,SC_NS);

    }

    tms_i.write(0);
    for(i=0;i<=8;i++)     // i=0 for excluding length;
    {
      tck_i.write(1);
      //shift_ir_o.write(1);
      wait(10,SC_NS);
    }
    tms_i.write(1);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);
      ////exit1_ir_o.write(1);
      wait(10,SC_NS);

    }
    tms_i.write(0);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);
      //pause_ir_o.write(1);
      wait(10,SC_NS);
    }
    tms_i.write(1);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);
      ////exit2_ir_o.write(1);
      wait(10,SC_NS);
    }
    tms_i.write(0);
    for(i=0;i<=8;i++)     // i=0 for excluding length;
    {
      tck_i.write(1);
      //shift_ir_o.write(1);
      wait(10,SC_NS);
    }
    for(i=1;i<2;i++)
    {
      tck_i.write(1);
      //update_dr_o.write(1);
      wait(10,SC_NS);
    }
    tms_i.write(1);
    for(i=1;i<2;i++)
    {
      tck_i.write(1);
      wait(10,SC_NS);

    }*/











  std::ifstream fp_in;
    fp_in.open("tdi.txt", ios::in | ios::binary);
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
      td_i-> write(cstr[a]);

      cout<<"td_i is"<<cstr[a]<<endl;
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

//End simulation

sc_stop();
};
exit(0);
}
/*void tap_tb :: sink()
{



  std::ifstream fp_in;
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

//End simulation

sc_stop();

}*/
