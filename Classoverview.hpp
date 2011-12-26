#include "VALM_Types.hpp"
#include <list>
#include <string>

using namespace std;

/**
 * interface for any type of config data
 */
class VALM_EffectConfig
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
class VALM_Effect
{
private:
	list<VALM_Effect> children;
	VALM_Effect parent;
	VALM_EffectConfig config;
	
public:
	VALM_Effect getParent();
	list<VALM_Effect> getChild();
};

/**
 * Internal interface for any component of the tree, including the tree itself.
 * Inherits most of its fields and methods from the light interface but declares
 * executing and the settings needed for executing the component.
 */
class VALM_CoreEffect : public VALM_Effect
{
private:
	VALM_EffectSettings* settings;
	
public:
	virtual int Execute();
};
