class SoundManager
{
private:
    int shotCount = 6;
    int currentShot = 0;
    Mix_Chunk** shots;
    bool soundOn = false;
public:
    SoundManager()
    {
        shots = new Mix_Chunk* [shotCount];

        for(int i=0; i<shotCount; i++)      //Although it looks strange, we have to load the same sound separately x times,
        {                                   //so it can be played once again before the previous ended. That's how SDL_Mixer works.
        shots[i] = Mix_LoadWAV("sounds/shot.wav");
        }
    }
    void playShot()
    {
        if (soundOn)
        {
        Mix_PlayChannel(currentShot, shots[currentShot++], 0);
        if (currentShot == shotCount) currentShot = 0;
        }
    }
    void toogleSound()
    {
        soundOn = !soundOn;
    }
};
