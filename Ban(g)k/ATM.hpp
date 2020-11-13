#include "bank_system.hpp"
#include <iostream>

class ATM
{
private:
    
    int choose, id_card, summ;
        BankSystem request;
    
public:
    
    void Welcome (){
        std::cout << "\t\tWelcome!" << std::endl;
        
        while (true){
        std::cout << "\n~Please,choose operation:\n\n1. Transfer from card to card. \n2. Transfer to organization.\n3. Withdraw from card. \n4. Chek balance. \n5. Exit." << std::endl;

        std::cout << "\nEnter: "; std::cin >> choose;
        
        switch (choose) {
            case 1:
                std::cout << "\nTo: "; std::cin >> id_card;
                std::cout << "Summ: "; std::cin >> summ;
                
                if (request.TransferC2C(1, id_card, summ))
                {
                    std::cout << "Successed!" << std::endl;
                }
                else
                    std::cout << "Error." << std::endl;
                break;
                
            case 2:
                std::cout << "\nTo: "; std::cin >> id_card;
                std::cout << "Summ: "; std::cin >> summ;

                if (request.TransferC2O(1, id_card, summ))
                {
                    std::cout << "\nSuccessed!" << std::endl;
                }
                else
                    std::cout << "\nError." << std::endl;
                break;
                
            case 3:
                std::cout << "Summ: "; std::cin >> summ;
          
                if (request.WithdrawC(1, summ))
                {
                    std::cout << "\nSuccessed!" << std::endl;
                }
                else
                    std::cout << "\nNot enough funds." << std::endl;
                break;
                
            case 4:
                std::cout << "Your current balance: " << request.ChekBalance(1) << std::endl;
                break;
                
            case 5:
                std::cout << "\nThank you for choosed our bank!" << std::endl;
                exit(0);
                break;
                
            default:
                continue;
                break;
        }
        }
    }
};
