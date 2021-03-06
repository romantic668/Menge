#ifndef __STRESS_TASK_H__
#define __STRESS_TASK_H__

/*!
 *	@file	StressTask.h
 *	@brief	task used for adding stress to agents
 */

#include "StressGlobals.h"

#include "MengeCore/BFSM/Tasks/Task.h"

#include <string>

#include "tinyxml.h"

// forward declarations
namespace Menge {
	namespace BFSM {
		class FSM;
	}
}

namespace StressGAS {
    /*!
	 *	@brief	Sub-class of Task that runs formation updates
	 */
	class StressTask : public Menge::BFSM::Task {
	public:
		/*!
		 *	@brief		Constructor 
		 */
		StressTask();

		/*!
		 *	@brief		The work performed by the task.
		 *
		 *	@param		fsm		The finite state machine for the task to operate on.
		 *	@throws		A TaskException if there was some non-fatal error
		 *				in execution.  It should be logged.
		 *	@throws		A TaskFatalException if there is a fatal error that
		 *				should arrest execution of the simulation.
		 */
		virtual void doWork( const Menge::BFSM::FSM * fsm ) throw( Menge::BFSM::TaskException );

		/*!
		 *	@brief		String representation of the task
		 *
		 *	@returns	A string containing task information.
		 */
		virtual std::string toString() const;

		/*!
		 *	@brief		Reports if this task is "equivalent" to the given task.
		 *				This makes it possible for a task to be redundantly added
		 *				to the fsm without fear of duplication as the equivalent
		 *				duplicates will be culled.
		 *
		 *	@param		task		The task to test against this one.
		 *	@returns	A boolean reporting if the two tasks are equivalent (true)
		 *				or unique (false).
		 */
		virtual bool isEquivalent( const Task * task ) const;
	};
}	// namespace StressGAS
#endif // __DENSITY_GRID_TASK_H__
