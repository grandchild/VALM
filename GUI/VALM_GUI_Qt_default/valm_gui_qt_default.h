#ifndef VALM_GUI_QT_DEFAULT_H
#define VALM_GUI_QT_DEFAULT_H

#include "VALM_GUI_Qt_default_global.h"
#include "../VALM_gui.h"
#include <QtGui>

class VALM_GUI_QT_DEFAULTSHARED_EXPORT VALM_GUI_Qt_default : VALM_GUI {
public:
    VALM_GUI_Qt_default();
	
	// Initialize libraries, resources, etc. Should also reinit if already initialized
	// (Start will be called seperately directly afterwards in any case)
	virtual bool VALM_GUI_Init();
	
	// Start the GUI. Should also restart if already running
	virtual bool VALM_GUI_Start();
	
	// Quitting the GUI before the main application terminates
	virtual bool VALM_GUI_Quit();
	
	//// Actions ////
	
	// Receive changes from main application
	virtual VALM_GUI_Data_t VALM_GUI_Receive(string actionName);
	
	// Send changes and data to main application
	// [...]
};

#endif // VALM_GUI_QT_DEFAULT_H
