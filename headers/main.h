#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <unistd.h>
#include <random>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <json/json.h>
#include "../PerlinNoise/PerlinNoise.hpp"
#include "../headers/constrained.h"

#define SPEED_LIMITER 16666
#define HM_SIZE 256

Json::Value* GetJson(std::string filename);

#include "../headers/window.h"
#include "../headers/terminal.h"

using namespace std;
#endif