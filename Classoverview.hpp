#include "VALM_Types.hpp"
#include <list>
#include <string>

using namespace std;

/**
 * interface for any type of config data
 */
class VALM_ComponentConfigData
{
private:
	list<string> strings;
	list<bool> bools;
	list<int> ints;
	list<double> doubles;
	list<color> colors;
	
public:
	bool setConfig(); // gui needs to set this
	bool getConfig(); // gui needs to read this, how?
	
};

/**
 * External interface for any component of the tree, including the tree itself.
 * Defines most of the elemts of a component, but omits the internal stuff
 * like rendering/executing the component and such, so it can be safely used by
 * the anyone.
 */
class VALM_ComponentLight
{
private:
	list<VALM_ComponentLight> children;
	VALM_ComponentLight parent;
	VALM_ComponentConfigData config;
	VALM_ComponentType type;
	
public:
	VALM_ComponentLight getParent();
	list<VALM_ComponentLight> getChild();
};

/**
 * Defines the settings struct for executing a Component.
 * This is distinct from VALM_ComponentConfigData in that
 * anyone else external from the Rendering process (e.g.
 * the GUI) knows nothing about this.
 */
typedef struct VALM_ComponentSettings_struct {
	VALM_SoundData* sound;
	VALM_FramebufferConfiguration* fbConf;
} VALM_ComponentSettings;

/**
 * Internal interface for any component of the tree, including the tree itself.
 * Inherits most of its fields and methods from the light interface but declares
 * executing and the settings needed for that.
 */
class VALM_Component : public VALM_ComponentLight
{
private:
	VALM_ComponentSettings* settings;
	
public:
	virtual int Execute();
};
