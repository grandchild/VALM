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
 * the main app.
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
	
	/**
	 * Initialize libraries, resources, etc. Should also reinit if already initialized.
	 * (Start will be called seperately directly afterwards in any case)
	 * 
	 * @return true if successful
	 */
	virtual bool VALM_GUI_Init();
	
	/**
	 * Start the GUI. Should also restart if already running
	 * 
	 * @return true if successful
	 */
	virtual bool VALM_GUI_Start();
	
	/**
	 * Quitting the GUI before the main application terminates
	 * 
	 * @return true if successful
	 */
	virtual bool VALM_GUI_Quit();
	
	
	//// Actions ////
	
	/*
	  Stuff that can be received by the GUI:
		- CRUD on display tree: (parameter always: position)
		- Load a new preset's tree (discard old one)
		- Add a preset's tree (parameter: position)
		- Preview textures (as textures?) -> Main output is handled by main app
	  
	  Stuff that can be sent from the GUI to main app:
		- CRUD on component tree: (parameter always: position)
			* Create new component
			* (Re-)Read component from preset file ("reset component" - whole preset tree is just a component as well)
			* Update changes to component
			* Delete component
		- 
	*/
	
	/**
	 * Receive changes from main app
	 * 
	 * @param actionName
	 */
	virtual VALM_GUI_Data_t VALM_GUI_Receive(string actionName);
	
	/**
	 * Tell the main app to create a new component
	 * 
	 * @param componentName The name of the component to be created. The list can be found in VALM_ComponentList.h
	 * 
	 * @return 0 if successful.
	 * @return 1 if component could not be created because of a wrong name string.
	 * @return 2 if component could not be created because of an internal error.
	 */
	virtual int VALM_GUI_CreateComponent(string componentName);
	
	// 
	
protected:
	VALM_GUI();
};


#endif // VALM_GUI_H


