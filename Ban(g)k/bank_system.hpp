#pragma once
#define CLIENTS_FILE "clients.txt"
#define ORGANIZATIONS_FILE "governments.txt"

#include "bank_database.hpp"

#include <list>
#include <algorithm>

class BankSystem
{
public:

	BankSystem()
	{
		ApplySpecificAccounts<ClientBankAccount>(CLIENTS_FILE);
		ApplySpecificAccounts<OrganizationBankAccount>(ORGANIZATIONS_FILE);
	}
    
    double ChekBalance (int accountId)
        {
            ClientBankAccount *client = FindSpecificAccount<ClientBankAccount>(accountId);
            
            if (client == nullptr)
                return false;
            
            return client->GetBalance();
        }

	bool WithdrawC(int accountId, double moneyAmount)
	{
		if (moneyAmount <= 0)
			return false;

		ClientBankAccount *client = FindSpecificAccount<ClientBankAccount>(accountId);

		if (client == nullptr)
			return false;

		if (client->GetBalance() < moneyAmount)
			return false;
		
		client->AddBalance(-moneyAmount);

		return true;
	}

	bool TransferC2C(int fromAccountId, int toAccountId, double moneyAmount)
	{
		if (moneyAmount <= 0)
			return false;

		ClientBankAccount *fromClient = FindSpecificAccount<ClientBankAccount>(fromAccountId);

		if (fromClient == nullptr)
			return false;

		ClientBankAccount *toClient = FindSpecificAccount<ClientBankAccount>(toAccountId);

		if (toClient == nullptr)
			return false;

		if (fromClient->GetBalance() < moneyAmount)
			return false;

		fromClient->AddBalance(-moneyAmount);
		toClient->AddBalance(moneyAmount);

		return true;
	}

	bool TransferC2O(int fromAccountId, int toOrganizationId, double moneyAmount)
	{
		if (moneyAmount <= 0)
			return false;

		ClientBankAccount *fromClient = FindSpecificAccount<ClientBankAccount>(fromAccountId);

		if (fromClient == nullptr)
			return false;

		OrganizationBankAccount *toOrganization = FindSpecificAccount<OrganizationBankAccount>(toOrganizationId);

		if (toOrganization == nullptr)
			return false;

		fromClient->AddBalance(-moneyAmount);
		toOrganization->AddBalance(moneyAmount);

		return true;
	}
    

private:

	BankDataBase _bankDataBase;
	std::list<BankAccount*> _bankAccounts;

	template <class T>
	T* FindSpecificAccount(int accountId)
	{
		for (auto it = _bankAccounts.begin(); it != _bankAccounts.end(); ++it)
			if ((*it)->GetIdentificator() == accountId)
				return dynamic_cast<T*>(*it);

		return nullptr;
	}

	template <class T>
	void ApplySpecificAccounts(const std::string& fileName)
	{
		std::list<BankAccount*> *accounts = _bankDataBase.LoadAll<T>(fileName);

		std::for_each(accounts->begin(), accounts->end(), [this](auto& account)
		{
			_bankAccounts.push_back(account);
		});
	}
};
