#pragma once
#define ORGANIZATION_NAME_LENGTH 32

#include "bank_account.hpp"
#include <string>

class OrganizationBankAccount : public BankAccount
{
public:

	OrganizationBankAccount() :
		BankAccount(-1, -1)
	{ }

	OrganizationBankAccount(const char *organizationName, int accountId, double balance) :
		BankAccount(accountId, balance)
	{ 
		strcpy(_organizationName, organizationName);
	}

	const char* GetOrganizationName() const
	{
		return _organizationName;
	}

private:

	char _organizationName[ORGANIZATION_NAME_LENGTH];

};
