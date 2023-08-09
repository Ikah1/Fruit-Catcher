#ifndef state_hpp
#define state_hpp

namespace Ikah
{
    class State
    {
        public:
            virtual void init() = 0;
            virtual void handleInput() = 0;
            virtual void update(float dt) = 0;
            virtual void render(float dt) = 0;
            virtual void pause(){};
            virtual void resume(){};
    };
}

#endif