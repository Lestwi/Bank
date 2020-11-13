#pragma once

class BankAccount
{
public:

	BankAccount(int identificator, double balance) :
		_identificator(identificator),
		_balance(balance)
	{ }

	virtual int GetIdentificator() const
	{
		return _identificator;
	}

	virtual double GetBalance() const
	{
		return _balance;
	}

	virtual void AddBalance(double addMoneyAmount)
	{
		_balance += addMoneyAmount;
	}

protected:

	int _identificator;

	double _balance;

};