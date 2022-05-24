/* 
   by: mamograg.
   description: this header file conatains the main frame's declcaration and other objects.
   created: 4-2022
   contact: mamograg17@protonmail.com
*/

//include the needed headers obviousely
#include <wx/panel.h>
#include <wx/menu.h>
#include <wx/string.h>
#include <wx/menuitem.h>
#include <wx/stattext.h>
#include <wx/frame.h>
#include <wx/timer.h>
#include <wx/notifmsg.h>
#include <wx/statline.h>
#include <wx/msgdlg.h>
#include <wx/hyperlink.h>
#include <wx/aboutdlg.h>

class frame : public wxFrame 
{
    public:
    frame(const wxString & title);
    void onAboutExercice(wxCommandEvent & event);
    void onAboutAPP(wxCommandEvent& event);
    void onAboutLink(wxHyperlinkEvent & event);
    
    
    enum IDs
    {
        ID_ABOUT_EXERCICE=3,
        ID_ABOUT_APP=wxID_ABOUT,
        ID_GITHUB_LINK=4
    };    
    
    //declare an event table
    DECLARE_EVENT_TABLE();

    protected:

    wxPanel * panel;
    wxStaticText * leftTimeForExercice;
    wxStaticText * leftTimeIsLabel;
    wxStaticLine * staticLine;
    wxStaticLine * staticLineTwo;
    wxMenuBar * menu_bar;
    wxMenu * about_menu;
    wxMenu * help_menu;
    wxMenuItem * about_exerice;
    wxTimer leftTimeToExerciceTimer;
    wxLongLong endTime;
    wxLongLong timeLeft;
    wxHyperlinkCtrl * githubLink;

};

