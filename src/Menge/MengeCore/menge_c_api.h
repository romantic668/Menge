/*!
 *	@file	menge_c_api.h
 *	@brief	Defines a c-level api for the basic Menge simulator.
 */

#ifndef __MENGE_C_API__
#define __MENGE_C_API__

#include "MengeCore/CoreConfig.h"
#ifndef _WIN32
#include <cstddef>
#endif

extern "C" {
	/*!
	 *	@brief		Initializes a simulator.  The simulator uses the given pedestrian @p model type
	 *				and is initialized using the given behavior file and scene file.
	 *
	 *	@param		behaveFile		Path to the behavior file.
	 *	@param		sceneFile		Path to the scene specification file.
	 *	@param		model			Name of the model type to use.
	 *	@param		pluginPath		Optional path to location of plugin directories.  If not
	 *								provided, plugins will *not* be loaded.
	 *	@returns	True if initialization was successful.
	 */
	MENGE_API bool   InitSimulator( const char * behaveFile,
									const char * sceneFile,
									const char * model,
									const char * pluginPath=0x0 );

	/*!
	 *	@brief		Reports the number of agents in the simulation.
	 *
	 *	@returns	The agent count.
	 */
	MENGE_API size_t  AgentCount();

	/*!
	 *	@brief		Sets the time step for the simulator.
	 */
	MENGE_API void  SetTimeStep( float timeStep );

	/*!
	 *	@brief		Advances the state of the simulator one time step.
	 *
	 *	@returns	True if the simulation can keep running.
	 */
	MENGE_API bool  DoStep();

	/*!
	 *	@brief		Reports the 3D position of the indicated agent.
	 *
	 *	@param		i		The index of the desired agent.
	 *	@param[out]	x		The position's x-component.
	 *	@param[out]	y		The position's y-component.
	 *	@param[out]	z		The position's z-component.
	 *	@returns			True if the values were successfully set.
	 */
	MENGE_API bool  GetAgentPosition( size_t i, float * x, float * y, float * z );

	/*!
	 *	@brief		Reports the 3D velocity of the indicated agent.
	 *
	 *	@param		i		The index of the desired agent.
	 *	@param[out]	x		The velocity's x-component.
	 *	@param[out]	y		The velocity's y-component.
	 *	@param[out]	z		The velocity's z-component.
	 *	@returns			True if the values were successfully set.
	 */
	MENGE_API bool  GetAgentVelocity( size_t i, float * x, float * y, float * z );

	/*!
	 *	@brief		Reports the 2D orientation of the indicated agent.  It is the facing direction
	 *				of the agent, projected onto the xz plane.
	 *
	 *	@param		i		The index of the desired agent.
	 *	@param[out]	x		The orient's x-component.
	 *	@param[out]	y		The orient's y-component.
	 *	@returns			True if the values were successfully set.
	 */
	MENGE_API bool  GetAgentOrient( size_t i, float * x, float * y );

	/*!
	*	@brief		Reports the agent class for this particular class.
	*
	*	@param		i		The index of the desired agent.
	*	@returns			The agent's class (-1 if it can't be found).
	*/
	MENGE_API int GetAgentClass( size_t i );

	/*!
	*	@brief		Reports the radius of the given agent.
	*
	*	@param		i		The index of the desired agent.
	*	@returns			The agent's radius (negative for errors).
	*/
	MENGE_API float GetAgentRadius( size_t i );
}

#endif	// __MENGE_C_API__
