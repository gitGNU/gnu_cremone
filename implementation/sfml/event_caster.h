#ifndef sfml_EVENT_CASTER_H
#define sfml_EVENT_CASTER_H

#include <stdint.h>
#include <SFML/Window.hpp>
#include <definitions.h>

EVENT_TYPE sfml2cremoneEVENT_TYPE(uint8_t type);
KEY_NAME sfml_cast_KEY(SDLKey key);
MOUSE::BUTTON sfml_cast_BUTTON(SDLKey key);

#endif
