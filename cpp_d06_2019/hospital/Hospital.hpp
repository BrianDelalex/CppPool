/*
** EPITECH PROJECT, 2019
** Hospital.hpp
** File description:
** 
*/

#ifndef HOSPITAL_HPP_
#define HOSPITAL_HPP_

#include "KoalaNurseList.hpp"
#include "SickKoalaList.hpp"
#include "./KoalaDoctorList.hpp"

class Hospital
{
public:
    Hospital();
    ~Hospital();
    void addDoctor(KoalaDoctorList *ptr);
    void addSick(SickKoalaList *ptr);
    void addNurse(KoalaNurseList *ptr);
    void run(void);
private:
    KoalaDoctorList *doctorList;
    KoalaNurseList *nurseList;
    SickKoalaList *patientList;

};

#endif
