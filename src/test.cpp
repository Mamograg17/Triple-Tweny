#include <iomanip>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

int main()
{
    // const auto timer_duration = 20min;
    // const auto start = std::chrono::steady_clock::now();
    
    // std::chrono::duration<double> time_left = timer_duration - (std::chrono::steady_clock::now() - start);
    // while (time_left > 0s)
    // {
    //     const auto hrs = std::chrono::duration_cast<std::chrono::hours>(time_left);
    //     const auto mins = std::chrono::duration_cast<std::chrono::minutes>(time_left - hrs);
    //     const auto secs = std::chrono::duration_cast<std::chrono::seconds>(time_left - hrs - mins);
    //     std::cout << std::setfill('0') << std::setw(2) << hrs.count() << ":"
    //               << std::setfill('0') << std::setw(2) << mins.count() << ":"
    //               << std::setfill('0') << std::setw(2) << secs.count() << "\n";

    //     std::this_thread::sleep_for(1s);

    //     time_left = timer_duration - (std::chrono::steady_clock::now() - start);
    // }
    // std::cout << "Done\n";
   //we set the duration of the timer
   const auto timer_duration = 20min;

   //we start the timer with the application's launch
   const auto start = std::chrono::steady_clock::now();
   
   //calcualte the left time before sending the notification
   auto time_left = timer_duration - (std::chrono::steady_clock::now() - start);
   

   //make an ostringsstream to convert the time_left to it

   //check if the left time is greater than 0s and set a new value to left_time variable
   while (time_left > 0s)
    {
        //get thr left minutes and seconds
        const auto mins = std::chrono::duration_cast<std::chrono::minutes>(time_left);
        const auto secs = std::chrono::duration_cast<std::chrono::seconds>(time_left - mins);
        
        std::cout << std::setfill('0') << std::setw(2) << mins.count() << ":"
                  << std::setfill('0') << std::setw(2) << secs.count() << "\n";

        std::this_thread::sleep_for(1s);


        //get the new left time
        time_left = timer_duration - (std::chrono::steady_clock::now() - start);
      
       }
}
std::ostringstream frame::calculate_time(){
  
   //we set the duration of the timer
   const auto timer_duration = 20min;

   //we start the timer with the application's launch
   const auto start = std::chrono::steady_clock::now();
   
   //calcualte the left time before sending the notification
   auto time_left = timer_duration - (std::chrono::steady_clock::now() - start);
   

   //make an ostringsstream to convert the time_left to it
   std::ostringstream timeLeftToString;
   
   while (true)
   {
   
   //check if the left time is greater than 0s and set a new value to left_time variable
     if (time_left > 0s)
       {
         //get thr left minutes and seconds
           const auto mins = std::chrono::duration_cast<std::chrono::minutes>(time_left);
           const auto secs = std::chrono::duration_cast<std::chrono::seconds>(time_left - mins);
        
           std::cout << std::setfill('0') << std::setw(2) << mins.count() << ":"
                     << std::setfill('0') << std::setw(2) << secs.count() << "\n";

           std::this_thread::sleep_for(1s);


           //get the new left time
           time_left = timer_duration - (std::chrono::steady_clock::now() - start);
      
           //put the left time in a ostringostream object
           timeLeftToString << std::chrono::duration<double>(timer_duration - (std::chrono::steady_clock::now() - start)).count();
           timeLeftToString << std::setfill('0') << std::setw(2) << mins.count() << ":"
                            << std::setfill('0') << std::setw(2) << secs.count();


           //return timeLeftToString as an ostringstream object
           return timeLeftToString;
    }
   }
}