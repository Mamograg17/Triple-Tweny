/* 
   By: mamograg.
   Description: this cpp file conatains the main frame's constructor defination.
   Created: 4-2022
   Contact me: mamograg17@protonmail.com
*/

//include the needed headers
#include "window.hpp"

BEGIN_EVENT_TABLE(frame,wxFrame)

  EVT_MENU(frame::ID_ABOUT_EXERCICE,frame::onAboutExercice)
  EVT_MENU(frame::ID_ABOUT_APP,frame::onAboutAPP)
  EVT_HYPERLINK(frame::ID_GITHUB_LINK,frame::onAboutLink)

END_EVENT_TABLE()

//the main frame 
frame::frame(const wxString & title) : wxFrame(NULL,wxID_ANY,title,wxDefaultPosition,wxSize(400,300))
{

  leftTimeToExerciceTimer.Start(1000);
  
  //the main panel
  panel = new wxPanel(this); 

  //make the window's size unchangeable
  this->SetMaxSize(wxSize(400,300));
  this->SetMinSize(wxSize(400,300));

  leftTimeIsLabel = new wxStaticText(panel,wxID_ANY,"left time is:",wxPoint(135,20),wxSize(350,30));
  leftTimeIsLabel->SetFont(wxFont(20,wxFONTFAMILY_DECORATIVE,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_MEDIUM));

  //sone static lines to make it beautiful
  staticLine = new wxStaticLine(panel,wxID_ANY,wxPoint(25,60),wxSize(350,1));
  staticLineTwo = new wxStaticLine(panel,wxID_ANY,wxPoint(25,270),wxSize(350,1));

  //initialize leftTimeForExercice
  leftTimeForExercice = new wxStaticText(panel,wxID_ANY,"",wxPoint(140,130),wxSize(270,120),wxCENTRE);

  //make a wxColor object
  wxColour color;

  //give it a hex value
  color.Set("#307caf");

  //set static text's color
  leftTimeForExercice->SetForegroundColour(color);

  //change the label's font 
  leftTimeForExercice->SetFont(wxFont(38,wxFONTFAMILY_UNKNOWN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_SEMIBOLD));

  //calculate the endtime
  endTime = ::wxGetLocalTime() + 60*20;

  //set leftTimeToExerciceTimer's owner
  leftTimeToExerciceTimer.SetOwner(this);

  Bind(wxEVT_TIMER, [=] (wxTimerEvent &event) 
  {
    //get the left time and put it in a variable called timeLeft
    timeLeft = endTime - ::wxGetLocalTime();
      
    //span timeLeft
    wxTimeSpan span( 0, 0, timeLeft);

    //we need to remove the hours format, so we will put span in a string,then erase the first three chars 
    wxString * withNoHoursSpan = new wxString(span.Format());
    withNoHoursSpan->erase(0,3);

    //set withNoHoursSpan as leftTimeForExercice's label
    leftTimeForExercice->SetLabel(withNoHoursSpan->GetData());
      
    //if timeLeft is equal to zero
    if (timeLeft == 0)
    {
      //add 10 seconds to the endTime
      endTime +=(60*20);

      //calculate the new left time 
      timeLeft.operator+=(endTime - ::wxGetLocalTime());

      //make a new notification and show it to the user for 10 seconds
      wxNotificationMessage * notification = new wxNotificationMessage("MReminder","time for exercice");
      notification->Show(10);
    }
      
  });
   
  leftTimeToExerciceTimer.Start(1000);

  
  //the menu_bar declaration
  menu_bar = new wxMenuBar();

  //about and help menu declaration
  help_menu = new wxMenu();
  about_menu = new wxMenu();
   
  //about_exercice MenuItem declaration
  about_exerice = new wxMenuItem(help_menu,ID_ABOUT_EXERCICE,"about exercice");
  
  //about the app
  about_menu->Append(ID_ABOUT_APP,"About");

  //append the about_exercice MenuItem to the help_menu and set its text
  help_menu->Append(about_exerice);
  
  //append the about_menu and help_menu to the menu bar
  menu_bar->Append(about_menu,"About");
  menu_bar->Append(help_menu,"Help");
    
  //set the default menu bar of thr program
  SetMenuBar(menu_bar);

  Centre();

}

//the function tha
void frame::onAboutExercice(wxCommandEvent & event)
{

  wxMessageBox("20-20-20 rule is a handy tool you can use at work or at home to \nreduce eye fatigue.\nthe 20-20-20 rule says that every 20 minutes of screen time, you\nshould look away at something at least20 feet away \nfor at least 20 seconds.\nThese regular screen breaks give your eyes some \nmuch-needed rest and help prevent eye strain.","about exercice");
}

void frame::onAboutLink(wxHyperlinkEvent & event)
{

  wxLaunchDefaultBrowser("https://github.com/Mamograg17/");

}

void frame::onAboutAPP(wxCommandEvent& event)
{
  //we make a wxAboutDialoginfo object
  wxAboutDialogInfo info;
  
  //set the app name
  info.SetName("triple-tweny");

  //add the developer name  
  info.AddDeveloper("mamograg");
  
  //set the descriotion
  info.SetDescription(wxString::Format
                       (
                        "Welcome to Triple-tweny!\n"
                        "\n"
                        "This is a simple app, you can check it my github below !\n",
                        "             You are running ",
                        wxGetOsDescription(),
                        wxALIGN_CENTER
                       )
                   );

  //set the version
  info.SetVersion("version 1.0");

  info.SetWebSite("https://github.com/Mamograg17/","Github");
  
  wxAboutBox(info,this);

}


