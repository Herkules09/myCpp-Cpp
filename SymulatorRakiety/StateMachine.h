#ifndef STATEMACHINE_H
#define STATEMACHINE_H
#include <memory>
#include <stack>
#include "State.h"


typedef std::unique_ptr<State> StateRef;

class StateMachine
{
private:
	std::stack<StateRef> states;
	StateRef newState;

	bool isRemoving;
	bool isAdding;
	bool isReplacing;

public:
	StateMachine() { }
	~StateMachine() { }

	void addState(StateRef newState, bool isReplacing = true);
	void removeState();
	void processStateChanges();

	StateRef& getActiveState();


};

#endif