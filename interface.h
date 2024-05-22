//
// Created by jantr on 16.05.2024.
//

#ifndef PROJEKT_ZESPOLOWY_INTERFACE_H
#define PROJEKT_ZESPOLOWY_INTERFACE_H
#include <iostream>
#include "University.h"
University* init();
void start(University* university);
void start(Student* student);
void start(Teacher* teacher);
void downloadAnimation();
void validatedInput(int& value);
void validatedInput(float& value);
#endif //PROJEKT_ZESPOLOWY_INTERFACE_H
