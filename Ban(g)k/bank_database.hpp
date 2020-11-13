#pragma once
#include "bank_account.hpp"
#include "organization_bank_account.hpp"
#include "client_bank_account.hpp"

#include <string>
#include <list>
#include <fstream>

class BankDataBase
{

public:
    
    template<class T>
    std::list<BankAccount*>* LoadAll(const std::string& fileName) const
    {
       return new std::list<BankAccount*> //database abstraction 
        {
            new ClientBankAccount("Hendery", 1, 1000),
            new ClientBankAccount("Elli", 2, 700),
            new ClientBankAccount("Saeong", 7, 707),
            new ClientBankAccount("Lois", 4, 350),
            new ClientBankAccount("Saeran", 6, 666),
            new OrganizationBankAccount("BSUIR", 3, 150),
            new OrganizationBankAccount("OOZ", 5, 800),
            new OrganizationBankAccount("CHERRY", 8, 570),
            new OrganizationBankAccount("SKY", 9, 390),
            new OrganizationBankAccount("BILLIBILLI", 10, 850)
        };
        
        //read from file
        
    }

    template<class T>
    bool SaveAll(const std::string& fileName, const std::list<T>& accounts) const
    {
	   //create database in file
    }
    
private:
    
};
