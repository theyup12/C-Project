#include <string>

#include "Bank.hpp"

/************************************************
** Member function definitions
************************************************/
// PLEASE ADD IMPLEMENTATIONS OF ALL FUNCTION MEMBERS OF CLASS BANK
// create a constructor for the bank, and insert the amount of the money 
Bank::Bank( const std::string & name,
    const double & starting,
    const double & salary):name_(name),amount_starting_(starting), amount_salary_(salary) {}
