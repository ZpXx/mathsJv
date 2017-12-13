#ifndef INPUT
#define INPUT

#include <irrlicht/irrlicht.h>

using namespace irr;

class Input : public IEventReceiver{
public:
  virtual bool OnEvent(const SEvent& event);
  virtual bool IsKeyDown(EKEY_CODE keyCode) const;
  Input(){
    for (u32 i=0;i<KEY_KEY_CODES_COUNT;i++)
      KeyIsDown[i]=false;
  }
private:
  bool KeyIsDown[KEY_KEY_CODES_COUNT];
};

#endif
