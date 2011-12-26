
/**
 * Basic color struct
 * 
 * @param red Red part of the color
 * @param green Green part of the color
 * @param blue Blue part of the color
 * @param alpha Alpha channel of the color
 */
typedef struct color_struct {
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	unsigned char alpha;
} color;

/**
 * Enumeration of the various possible types of components
 * 
 * @param Render Components that place pixels on the framebuffer
 * @param Trans Components that move pixels on the framebuffer
 * @param Sound Components that change values in the VALM_SoundData structs for components below this component
 * @param Misc Components that have some other effect (e.g. saving/restoring framebuffers)
 */
typedef enum VALM_EffectType_struct {
	Render,
	Trans,
	Sound,
	Misc
} VALM_EffectType;

/**
 * Sound data for components.
 * 
 * @param oscilloscope Waveform of the sound input (4096 samples)
 * @param spectrum FFT of the sound input (4096 samples)
 * @param beat True if a beat has occurred during the last frame
 */	
typedef struct VALM_Sound_struct {
	float oscilloscope[4096];
	float spectrum[4096];
	bool beat;
} VALM_Sound;

/**
 * Framebuffer structure.
 * 
 * @param width Width of the image (max: including overscan)
 * @param height Height of the image (including overscan)
 * @param depth Bitdepth of the image (RGBA)
 * @param flip Side of the framebuffer which is written to (0 or 1)
 */
typedef struct VALM_FramebufferConfig_struct {
	unsigned short width;
	unsigned short height;
	unsigned char depth;
	unsigned char flip;
} VALM_FramebufferConfig;
