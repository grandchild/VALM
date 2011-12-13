#include "valm_gui_qt_default.h"


VALM_GUI_Qt_default::VALM_GUI_Qt_default()
{
}

bool VALM_GUI_Qt_default::VALM_GUI_Init()
{
}

// Start the GUI. Should also restart if already running
bool VALM_GUI_Qt_default::VALM_GUI_Start()
{
}

// Quitting the GUI before the main application terminates
bool VALM_GUI_Qt_default::VALM_GUI_Quit()
{
}

//// Actions ////

// Receive changes from main application
VALM_GUI_Data_t VALM_GUI_Qt_default::VALM_GUI_Receive(string actionName)
{
}

// Send changes and data to main application
void VALM_GUI_Qt_default::VALM_GUI_Send(string actionName, VALM_GUI_Data_t data)
{
}
