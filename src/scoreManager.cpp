#include "../include/scoreManager.hpp"

namespace Ikah
{
    int ScoreManager::getScore()
    {
        return this->_score;
    }

    void ScoreManager::setScore(int score)
    {
        this->_score = score;
    }

    void ScoreManager::loadScore()
    {
        this->_loadScoreFile.open(SCORE_FILE_PATH);
        this->_loadScoreFile >> this->_score;
        this->_loadScoreFile.close();
    }

    void ScoreManager::saveScore()
    {
        this->_saveScoreFile.open(SCORE_FILE_PATH);
        this->_saveScoreFile << this->_score;
        this->_saveScoreFile.close();
    }
}