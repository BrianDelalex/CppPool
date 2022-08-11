/*
** EPITECH PROJECT, 2019
** Hospital.cpp
** File description:
** 
*/

#include "Hospital.hpp"

Hospital::Hospital()
{
    this->doctorList = nullptr;
    this->nurseList = nullptr;
    this->patientList = nullptr;
}

Hospital::~Hospital()
{
    if (this->doctorList)
        delete(doctorList);
    if (this->nurseList)
        delete(nurseList);
    if (this->patientList)
        delete(patientList);
}

void Hospital::addDoctor(KoalaDoctorList *ptr)
{
    if (this->doctorList == nullptr)  {
        doctorList = new KoalaDoctorList(ptr->getContent());
        std::cout << "[HOSPITAL] Doctor " << ptr->getContent()->getName() << " just arrived!" << std::endl;
        ptr->getContent()->timeCheck();
    } else {
        doctorList->append(ptr);
        std::cout << "[HOSPITAL] Doctor " << ptr->getContent()->getName() << " just arrived!" << std::endl;
        ptr->getContent()->timeCheck();
    }
}

void Hospital::addSick(SickKoalaList *ptr)
{
    if (patientList == nullptr) {
        patientList = new SickKoalaList(ptr->getContent());
        std::cout << "[HOSPITAL] Patient "  << ptr->getContent()->getName() <<  " just arrived!" << std::endl;
    } else {
        if (!patientList->is_koala_in(ptr->getContent())) {
            patientList->append(ptr);
            std::cout << "[HOSPITAL] Patient "  << ptr->getContent()->getName() <<  " just arrived!" << std::endl;
        }
    }
}

void Hospital::addNurse(KoalaNurseList *ptr)
{
    if (nurseList == nullptr) {
        nurseList = new KoalaNurseList(ptr->getContent());
        std::cout << "[HOSPITAL] Nurse " << ptr->getContent()->getID() << " just arrived!" << std::endl;
        ptr->getContent()->timeCheck();
    } else {
        nurseList->append(ptr);
        std::cout << "[HOSPITAL] Nurse " << ptr->getContent()->getID() << " just arrived!" << std::endl;
        ptr->getContent()->timeCheck();
    }
}

void Hospital::run()
{
    KoalaDoctorList *doc_ptr = doctorList;
    KoalaNurseList *nurse_ptr = nurseList;
    SickKoalaList *patient_ptr = patientList;
    std::cout << "[HOSPITAL] Work starting with:" << std::endl;
    doctorList->dump();
    nurseList->dump();
    patientList->dump();
    std::cout << std::endl;
    while (patientList) {
        nurseList->getContent()->giveDrug(nurseList->getContent()->readReport((doctorList->getContent()->diagnose(patientList->getContent()))), patientList->getContent());
        if (doctorList->isEnd()) {
            doctorList = doc_ptr;
        } else {
            doctorList = doctorList->getNext();
        }
        if (nurseList->isEnd()) {
            nurseList = nurse_ptr;
        } else {
            nurseList = nurseList->get_next();
        }
        patientList = patientList->getNext();
    }
    nurseList = nurse_ptr;
    while (nurseList) {
        nurseList->getContent()->timeCheck();
        nurseList = nurseList->get_next();
    }
    doctorList = doc_ptr;
    while (doctorList) {
        doctorList->getContent()->timeCheck();
        doctorList = doctorList->getNext();
    }
    doctorList = doc_ptr;
    nurseList = nurse_ptr;
    patientList = patient_ptr;
}