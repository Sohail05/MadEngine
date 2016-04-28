#pragma once
#ifndef DEFINES_H
#define DEFINES_H

#define MADENGINE_VERSION "0.1"

//MSVC
#define _SECURE_SCL 0
#define _HAS_ITERATOR_DEBUGGING 0

//Windows
#ifdef _WIN32
#include <Windows.h>
#endif

#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 900
#define WINDOW_TITLE "Mad Engine " MADENGINE_VERSION

#endif
