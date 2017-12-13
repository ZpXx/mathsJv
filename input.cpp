#include "input.h"

 bool Input::OnEvent(const SEvent & event){
  if (event.EventType== irr::EET_KEY_INPUT_EVENT)
  KeyIsDown[event.KeyInput.Key]= event.KeyInput.PressedDown;

  return false;
}
 bool Input::IsKeyDown (EKEY_CODE keyCode) const{
  return KeyIsDown[keyCode];
}
