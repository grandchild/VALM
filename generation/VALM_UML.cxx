/* generated by dia/codegen.py */
class VALM_Effect 
{
public:
	VALM_Effect getParent ();
	VALM_Effect getChildren ();
protected:
	list<VALM_Effect> children;
	VALM_Effect parent;
	VALM_EffectConfig config;
	VALM_EffectGui gui;
};

class VALM_CoreEffect : VALM_Effect 
{
public:
	void Execute ();
private:
	VALM_Audio* audio;
	VALM_FramebufferConfig* fbConf;
};

class VALM_Renderer 
{
public:
	void Render (VALM_CoreEffect effect);
private:
	VALM_CoreOutFrame* outFrame;
};

class VALM_FramebufferConfigCollection 
{
};

class VALM_EffectConfig 
{
/* implementation: */
	list<string> strings;
	list<bool> bools;
	list<int> ints;
	list<double> doubles;
	list<color> colors;
};

class VALM_CoreOutFrame : VALM_OutFrame 
{
public:
	void setFrame (OGL_Frame frame);
private:
	OGL_Frame frame;
};

class VALM_OutFrame 
{
public:
	OGL_Frame getFrame ();
};

class VEffect_FramebufferModifier : VALM_CoreEffect 
{
public:
	void Execute ();
private:
	void ResizeFrame (int width,
	                  int heigth,
	                  bool keepAspect,
	                  bool scale,
	                  color borderFillColor);
};

class VEffect_Collection : VALM_Effect 
{
public:
	void Execute ();
};

class VALM_Audio 
{
/* implementation: */
	float[] oscilloscope;
	float[] spectrum;
	bool beat;
};

class VEffect_AudioModifier : VALM_CoreEffect 
{
public:
	void Execute ();
private:
	VALM_Audio* createNewAudio ();
	VALM_Audio* createNewAudio (VALM_Audio audio);
	int updateAudioInEffects (VALM_Audio newAudio);
};

class VALM_AudioCollection 
{
};

class VALM_FramebufferConfig 
{
/* implementation: */
	unsigned short width;
	unsigned short height;
	unsigned char depth;
	unsigned char flip;
};

class VALM_EffectGui 
{
public:
	list<GuiElement> gui;
};

/*(NULL)*/
class VALM_Collection 
{
public:
	T get (int index);
	T add (T item);
	int delete (int index);
	int delete (T item);
	T getDefault ();
	int setDefault (int index);
	int setDefault (T item);
private:
	list<T> collection;
	int default;
};

