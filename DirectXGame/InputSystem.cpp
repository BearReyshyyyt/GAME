#include "InputSystem.h"
#include <Windows.h>


InputSystem::InputSystem()
{
}

InputSystem::~InputSystem()
{
}

void InputSystem::update()
{
	if (::GetKeyboardState(m_keys_state))
	{


		for (unsigned int i = 0; i < 256; i++)
		{
			// Key is down
			if (m_keys_state[i] && 0x80)
			{
				std::map<InputListener*, InputListener*>::iterator it = m_map_listeners.begin();

				while (it != m_map_listeners.end())
				{
					it->second->onKeyDown(i);
					++it;
				}

			}
			else // key is up
			{
				if (m_keys_state[i] != m_old_keys_state[i])
				{
					std::map<InputListener*, InputListener*>::iterator it = m_map_listeners.begin();

					while (it != m_map_listeners.end())
					{
						it->second->onKeyUp(i);
						++it;
					}
				}

			}
		}
		// record the current state of the keys in the old key state array (or buffer)
		::memcpy(m_old_keys_state, m_keys_state, sizeof(unsigned char) * 256);
	}
}

void InputSystem::addListener(InputListener * listener)
{
	m_map_listeners.insert(std::make_pair<InputListener*, InputListener*>
		(std::forward<InputListener*>(listener), std::forward<InputListener*>(listener)));
}

void InputSystem::removeListener(InputListener * listener)
{
	std::map<InputListener*, InputListener*>::iterator it = m_map_listeners.find(listener);

	if (it != m_map_listeners.end())
	{
		m_map_listeners.erase(it);
	}
} 

InputSystem * InputSystem::get()
{
	static InputSystem system;
	return &system;
}
