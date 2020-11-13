#pragma once
#define NAME_LENGTH 16

#include "bank_account.hpp"
#include <string>

class ClientBankAccount : public BankAccount
{
public:

	ClientBankAccount() :
		BankAccount(-1, -1)
	{ }

	ClientBankAccount(const char* name, int identificator, double balance) :
		BankAccount(identificator, balance)
	{ 
        strcpy(_name, name);
	}

	const char* GetName() const
	{
		return _name;
	}

private:

	char _name[NAME_LENGTH];

};
