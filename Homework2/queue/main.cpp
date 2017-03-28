/*
  A simple program that simulates 5 MM1 queues at an airport. The first queue
  feeds 3 other queues that work in parallel. These feed a final queue.
  Simulation runs until error below threshold and, at the end,
  a performance evaluation report is shown, and logs are generated
  for plotting and analysis.
*/

using namespace std;

#include <random>
#include "customer.h"
#include "mm1_queue.h"


std::random_device rd;

void pause()
{
 std::string sInputString;
 // Wait for input from stdin (the keyboard)
 cout << "Continue (y)?";
 std::cin >> sInputString;
}



int main(int argc, char* argv[])
{
   int next = 0;
//   test_random_number_generator();

   for (int cur_lambda = 3; cur_lambda < 34; cur_lambda++)
   {
      
	   //TODO Create MM1_Queue objects to capture the airport senario.
	   MM1_Queue    IDCHECKPOINT;
	   IDCHECKPOINT.set_file_names("IDCHECKPOINT_log.txt", "IDCHECKPOINT_wait.txt", "IDCHECKPOINT_service.txt");
	   IDCHECKPOINT.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   IDCHECKPOINT.set_mu(53);
	   IDCHECKPOINT.initialize();
	   IDCHECKPOINT.set_seed(1, rd());   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())

	   MM1_Queue    SECURITY1;
	   SECURITY1.set_file_names("SECURITY1_log.txt", "SECURITY1_wait.txt", "SECURITY1_service.txt");
	   SECURITY1.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   SECURITY1.set_mu(20);
	   SECURITY1.autogenerate_new_arrivals(false);
	   SECURITY1.initialize();
	   SECURITY1.set_seed(rd(), rd());
	   
	   MM1_Queue    SECURITY2;
	   SECURITY2.set_file_names("SECURITY2_log.txt", "SECURITY2_wait.txt", "SECURITY2_service.txt");
	   SECURITY2.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   SECURITY2.set_mu(20);
	   SECURITY2.autogenerate_new_arrivals(false);
	   SECURITY2.initialize();
	   SECURITY2.set_seed(rd(), rd());
	   
	   MM1_Queue    SECURITY3;
	   SECURITY3.set_file_names("SECURITY3_log.txt", "SECURITY3_wait.txt", "SECURITY3_service.txt");
	   SECURITY3.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   SECURITY3.set_mu(20);
	   SECURITY3.autogenerate_new_arrivals(false);
	   SECURITY3.initialize();
	   SECURITY3.set_seed(rd(), rd());
	   
	   MM1_Queue    BOARDING;
	   BOARDING.set_file_names("BOARDING_log.txt", "BOARDING_wait.txt", "BOARDING_service.txt");
	   BOARDING.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   BOARDING.set_mu(80);
	   BOARDING.initialize();
	   BOARDING.set_seed(rd(), rd()); 

	   //************************************************************

   for (; 
		//TODO: add is_within_error_range check
	   !IDCHECKPOINT.is_within_error_range(0.002) ||
	   !SECURITY1.is_within_error_range(0.002) ||
	   !SECURITY2.is_within_error_range(0.002) ||
	   !SECURITY3.is_within_error_range(0.002) ||
	   !BOARDING.is_within_error_range(0.002)
       ;)
   {
	   Customer cust  = IDCHECKPOINT.process_next_event();	// =  Process ID Checkpoint
	   Customer cust2 = SECURITY1.process_next_event();		// =  Process Security Queue 1
	   Customer cust3 = SECURITY2.process_next_event();		// =  Process Security Queue 2
	   Customer cust4 = SECURITY3.process_next_event();		// =  Process Security Queue 3
	   Customer cust5 = BOARDING.process_next_event();		// =  Process Boarding Queue
	   
       if (cust.get_type() == Customer::COMPLETED())
       {
          switch(next)
          {
            case 0:
				//TODO add_external_arrival() for ID Checkpoint;
				SECURITY1.add_external_arrival();
				break;
            case 1:
				//TODO add_external_arrival() for Security Queues;
				SECURITY2.add_external_arrival();
                 break;
            case 2:
                //TODO add_external_arrival() for Boarding;
				SECURITY3.add_external_arrival();
				 break;
          }
          next++;
          if (next%3==0) next = 0;
       }
       if (cust2.get_type() == Customer::COMPLETED() || cust3.get_type() == Customer::COMPLETED() || cust4.get_type() == Customer::COMPLETED())
       {
		   //TODO add_external_arrival(); on your final boarding MM1_Queue object
		   // Didnt we do this in case 2?
		   BOARDING.add_external_arrival();
       }
   }



   //TODO Output statistics airport senario.
   IDCHECKPOINT.output(); cout << "*********" << endl;
   SECURITY1.output(); cout << "*********" << endl;
   SECURITY2.output(); cout << "*********" << endl;
   SECURITY3.output(); cout << "*********" << endl;
   BOARDING.output(); cout << "*********" << endl;
   //**************************************************************************



   }

   return(0);
}

