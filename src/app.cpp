/* 
   by: mamograg.
   description:this header file conatains application's declcaration.
   created: 4-2022
   contact: mamograg17@protonmail.com
*/

#include "app.hpp"
#include "window.hpp"

IMPLEMENT_APP(application);

bool application::OnInit()
{
    frame * main_frame = new frame("window");
    main_frame->Show();

    return true;
}