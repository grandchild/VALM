// Visual Animation Live Mixer - VALM

/**
 * Declares the interface for all communication
 * between GUI and main application
 */

#ifndef VALM_GUI_H
#define VALM_GUI_H

#include <string>
using namespace std;

/**
 * Data structure for all data passed
 * when executing a GUI action or when
 * passing receving information from
 * the main application.
 */
typedef struct VALM_GUI_Data {
	// what should go here to maximize flexibility/reusability?
	int data;
} VALM_GUI_Data_t;

/**
 * Interface class
 * Intentionally minimal.
 */
class VALM_GUI {
public:
	virtual ~VALM_GUI();
	
	
	//// Housekeeping ////
	
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
	virtual void VALM_GUI_Send(string actionName, VALM_GUI_Data_t data);
	
protected:
	VALM_GUI();
};


#endif // VALM_GUI_H


