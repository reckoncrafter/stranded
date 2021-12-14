#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <thread>
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
#define NUM_ITEMS 8
#define NUM_POIS 2

Json::Value* GetJson(std::string filename);

#include "../headers/terminal.h"
#include "../headers/window.h"

using namespace std;
#endif