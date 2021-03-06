/*!
 *	@file		GoalRendererDatabase.h
 *	@brief		The definition of the database for all goal renderers.
 */

#ifndef __GOAL_RENDERER_DATABASE_H__
#define __GOAL_RENDERER_DATABASE_H__

#include "MengeVis/Runtime/VisElementDatabase.h"

// forward declaration
namespace Menge {
	namespace BFSM {
		class Goal;
	}
}

namespace MengeVis {
	namespace Runtime {
		class VisAgent;
		namespace GoalVis {
			class GoalRenderer;
		}
		/*!
		 *	@brief		The database of registered agent contexts.
		 */
		typedef VisElementDB<GoalVis::GoalRenderer, Menge::BFSM::Goal> GoalRendererDB;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
		// Declrations of explicit specializations
		template<> GoalVis::GoalRenderer *
		Runtime::VisElementDB<GoalVis::GoalRenderer,
													Menge::BFSM::Goal>::getDefaultElement();

		template<> void
		Runtime::VisElementDB<GoalVis::GoalRenderer,
													Menge::BFSM::Goal>::addBuiltins();

		template<> std::string
		Runtime::VisElementDB<GoalVis::GoalRenderer,
													Menge::BFSM::Goal>::getElementName();
#endif	// DOXYGEN_SHOULD_SKIP_THIS
		
	}	// namespace VCContext
}	// namespace Runtime

#endif	// __GOAL_RENDERER_DATABASE_H__
