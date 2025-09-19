#pragma once

#include <iostream>
#include "Base.hpp"
#include <cstdlib> //for std::rand
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void);
void identify(Base* p);
void identify(Base& p);