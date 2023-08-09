#ifndef scoreManager_hpp

#include "../include/definitions.hpp"
#include <fstream>
#include <iostream>

namespace Ikah
{
    class ScoreManager
    {
        public:
            int getScore();
            void setScore(int score);
            void loadScore();
            void saveScore();
        private:
            int _score;
            std::ofstream _saveScoreFile;
            std::ifstream _loadScoreFile;
    };
}

#endif