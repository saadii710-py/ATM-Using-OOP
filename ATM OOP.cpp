#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
float Bank_balance = 100000.0, tax_slip = 2.5;
class ATM
{
protected:
	char slp;
	string tr_account;
	string tr_reference;
	string tr_consumer;
	float balance;
	float tax;
	float rem_balance;
public:
	char getSlip(char slp)
	{
		return (slp);
	}
	string getTrAccount(string tr_account)
	{
		return (tr_account);
	}
	string getTrReference(string tr_reference)
	{
		return (tr_reference);
	}
	string getTrConsumer(string tr_consumer)
	{
		return (tr_consumer);
	}
	float getBalance(float balance)
	{
		return (balance);
	}
	float getTax(float tax)
	{
		return (tax);
	}
	float virtual current(float) = 0;
	float virtual saving(float) = 0;
};

class Withdraw : public ATM
{
public:
	float withdraw;
	void setValues(float wd)
	{
		withdraw = wd;
	}
	float getWithdraw(float withdraw)
	{
		return withdraw;
	}
	float receipt()
	{
		cout << "Do you want to Print Slip?" << endl;
		cout << "Extra 2.5Rs will be charged for Slip" << endl;
		cout << endl << "Press 'y' OR 'Y' for Slip OR Press any key to continue procedure" << endl;
		cin >> slp;
		//for slip
		if (slp == 'y' || slp == 'Y')
		{
			return(Bank_balance = Bank_balance - tax_slip);
		}
		else
		{
			return(Bank_balance);
		}
	}
	float balance_check(float amount)
	{
		do {
			if (amount >= (Bank_balance - 1000))
			{
				cout << "Error! Minimum Rs.1000 must be avaiable in your account OR The amount you enter is more than the actual amount in your account" << endl;
				cout << "Enter amount again" << endl;
				cin >> amount;
			}
		} while (amount >= (Bank_balance - 1000));
		return(amount);
	}
	float current(float withdraw)
	{
		cout << "0.6% tax will be deducted from your account balance" << endl;
		tax = (0.6 / 100) * withdraw;
		balance = receipt() - withdraw - tax;
		return (balance);
	}
	float saving(float withdraw)
	{
		balance = receipt() - withdraw;
		return(balance);
	}
};

class Dollar : public ATM
{
public:
	float dollar = 228.1;
	float dollar_fund;
	void setValues(float d_f)
	{
		dollar_fund = d_f;
	}
	float getDollar(float dollar_fund)
	{
		return dollar_fund;
	}
	void account_vr()
	{
		do {
			cout << "Enter 16-digit Account No. in which you want to transfer money = ";
			cin >> tr_account;
			if (tr_account.size() == 16)
			{
				cout << "Please wait while we access this account........." << endl;
			}
			else
			{
				cout << "Invalid Account No." << endl;
				cout << "Enter Account No. again" << endl;
			}
		} while (tr_account.size() != 16);
	}
	float receipt()
	{
		cout << "Do you want to Print Slip?" << endl;
		cout << "Extra 2.5Rs will be charged for Slip" << endl;
		cout << endl << "Press 'y' OR 'Y' for Slip OR Press any key to continue procedure" << endl;
		cin >> slp;
		//for slip
		if (slp == 'y' || slp == 'Y')
		{
			return(Bank_balance = Bank_balance - tax_slip);
		}
		else
		{
			return(Bank_balance);
		}
	}
	float balance_check(float amount)
	{
		do {
			if (amount >= (Bank_balance - 1000))
			{
				cout << "Error! Minimum Rs.1000 must be avaiable in your account OR The amount you enter is more than the actual amount in your account" << endl;
				cout << "Enter amount again" << endl;
				cin >> amount;
			}
		} while (amount >= (Bank_balance - 1000));
		return(amount);
	}
	float current(float dollar_fund)
	{
		cout << "0.8% tax will be deducted from your account balance" << endl;
		tax = (0.8 / 100) * dollar_fund;
		dollar = dollar_fund / dollar;
		rem_balance = receipt() - dollar_fund - tax;
		cout << "After conversion from Rs to Dollars, you transfer " << dollar << "$" << endl;
		return (rem_balance);
	}
	float saving(float dollar_fund)
	{
		dollar = dollar_fund / dollar;
		rem_balance = receipt() - dollar_fund;
		cout << "After conversion from Rs to Dollars, you transfer " << dollar << "$" << endl;
		return (rem_balance);
	}
};

class Euro :public ATM
{
public:
	float euro = 243.8;
	float euro_fund;
	void setValues(float e_f)
	{
		euro_fund = e_f;
	}
	float getEuro(float euro_fund)
	{
		return euro_fund;
	}
	void account_vr()
	{
		do {
			cout << "Enter 16-digit Account No. in which you want to transfer money = ";
			cin >> tr_account;
			if (tr_account.size() == 16)
			{
				cout << "Please wait while we access this account........." << endl;
			}
			else
			{
				cout << "Invalid Account No." << endl;
				cout << "Enter Account No. again" << endl;
			}
		} while (tr_account.size() != 16);
	}
	float receipt()
	{
		cout << "Do you want to Print Slip?" << endl;
		cout << "Extra 2.5Rs will be charged for Slip" << endl;
		cout << endl << "Press 'y' OR 'Y' for Slip OR Press any key to continue procedure" << endl;
		cin >> slp;
		//for slip
		if (slp == 'y' || slp == 'Y')
		{
			return(Bank_balance = Bank_balance - tax_slip);
		}
		else
		{
			return(Bank_balance);
		}
	}
	float balance_check(float amount)
	{
		do {
			if (amount >= (Bank_balance - 1000))
			{
				cout << "Error! Minimum Rs.1000 must be avaiable in your account OR The amount you enter is more than the actual amount in your account" << endl;
				cout << "Enter amount again" << endl;
				cin >> amount;
			}
		} while (amount >= (Bank_balance - 1000));
		return(amount);
	}
	float current(float euro_fund)
	{
		cout << "0.8% tax will be deducted from your account balance" << endl;
		tax = (0.8 / 100) * euro_fund;
		euro = euro_fund / euro;
		rem_balance = receipt() - euro_fund - tax;
		cout << "After conversion from Rs to Euros, you transfer " << euro << "€" << endl;
		return (rem_balance);
	}
	float saving(float euro_fund)
	{
		euro = euro_fund / euro;
		rem_balance = receipt() - euro_fund;
		cout << "After conversion from Rs to Euros, you transfer " << euro << "€" << endl;
		return (rem_balance);
	}
};

class Pound :public ATM
{
public:
	float pound = 277.3;
	float pound_fund;
	void setValues(float p_f)
	{
		pound_fund = p_f;
	}
	float getPound(float pound_fund)
	{
		return pound_fund;
	}
	void account_vr()
	{
		do {
			cout << "Enter 16-digit Account No. in which you want to transfer money = ";
			cin >> tr_account;
			if (tr_account.size() == 16)
			{
				cout << "Please wait while we access this account........." << endl;
			}
			else
			{
				cout << "Invalid Account No." << endl;
				cout << "Enter Account No. again" << endl;
			}
		} while (tr_account.size() != 16);
	}
	float receipt()
	{
		cout << "Do you want to Print Slip?" << endl;
		cout << "Extra 2.5Rs will be charged for Slip" << endl;
		cout << endl << "Press 'y' OR 'Y' for Slip OR Press any key to continue procedure" << endl;
		cin >> slp;
		//for slip
		if (slp == 'y' || slp == 'Y')
		{
			return(Bank_balance = Bank_balance - tax_slip);
		}
		else
		{
			return(Bank_balance);
		}
	}
	float balance_check(float amount)
	{
		do {
			if (amount >= (Bank_balance - 1000))
			{
				cout << "Error! Minimum Rs.1000 must be avaiable in your account OR The amount you enter is more than the actual amount in your account" << endl;
				cout << "Enter amount again" << endl;
				cin >> amount;
			}
		} while (amount >= (Bank_balance - 1000));
		return(amount);
	}
	float current(float pound_fund)
	{
		cout << "0.8% tax will be deducted from your account balance" << endl;
		tax = (0.8 / 100) * pound_fund;
		pound = pound_fund / pound;
		rem_balance = receipt() - pound_fund - tax;
		cout << "After conversion from Rs to Pounds, you transfer " << pound << "£" << endl;
		return (rem_balance);
	}
	float saving(float pound_fund)
	{
		pound = pound_fund / pound;
		rem_balance = receipt() - pound_fund;
		cout << "After conversion from Rs to Pounds, you transfer " << pound << "£" << endl;
		return (rem_balance);
	}
};

class SameLocal :public ATM
{
public:
	float rs_same;
	void setValues(float rsS)
	{
		rs_same = rsS;
	}
	float getSameRS(float rs_same)
	{
		return rs_same;
	}
	void account_vr()
	{
		do {
			cout << "Enter 16-digit Account No. in which you want to transfer money = ";
			cin >> tr_account;
			if (tr_account.size() == 16)
			{
				cout << "Please wait while we access this account........." << endl;
			}
			else
			{
				cout << "Invalid Account No." << endl;
				cout << "Enter Account No. again" << endl;
			}
		} while (tr_account.size() != 16);
	}
	float receipt()
	{
		cout << "Do you want to Print Slip?" << endl;
		cout << "Extra 2.5Rs will be charged for Slip" << endl;
		cout << endl << "Press 'y' OR 'Y' for Slip OR Press any key to continue procedure" << endl;
		cin >> slp;
		//for slip
		if (slp == 'y' || slp == 'Y')
		{
			return(Bank_balance = Bank_balance - tax_slip);
		}
		else
		{
			return(Bank_balance);
		}
	}
	float balance_check(float amount)
	{
		do {
			if (amount >= (Bank_balance - 1000))
			{
				cout << "Error! Minimum Rs.1000 must be avaiable in your account OR The amount you enter is more than the actual amount in your account" << endl;
				cout << "Enter amount again" << endl;
				cin >> amount;
			}
		} while (amount >= (Bank_balance - 1000));
		return(amount);
	}
	float current(float rs_same)
	{
		cout << "0.2% tax will be deducted from your account balance" << endl;
		tax = (0.2 / 100) * rs_same;
		balance = receipt() - rs_same - tax;
		return (balance);
	}
	float saving(float rs_same)
	{
		balance = receipt() - rs_same;
		return (balance);
	}
};

class DiffLocal :public ATM
{
public:
	float rs_diff;
	void setValues(float rsD)
	{
		rs_diff = rsD;
	}
	float getDiffRs(float rs_diff)
	{
		return rs_diff;
	}
	void account_vr()
	{
		do {
			cout << "Enter 16-digit Account No. in which you want to transfer money = ";
			cin >> tr_account;
			if (tr_account.size() == 16)
			{
				cout << "Please wait while we access this account........." << endl;
			}
			else
			{
				cout << "Invalid Account No." << endl;
				cout << "Enter Account No. again" << endl;
			}
		} while (tr_account.size() != 16);
	}
	float receipt()
	{
		cout << "Do you want to Print Slip?" << endl;
		cout << "Extra 2.5Rs will be charged for Slip" << endl;
		cout << endl << "Press 'y' OR 'Y' for Slip OR Press any key to continue procedure" << endl;
		cin >> slp;
		//for slip
		if (slp == 'y' || slp == 'Y')
		{
			return(Bank_balance = Bank_balance - tax_slip);
		}
		else
		{
			return(Bank_balance);
		}
	}
	float balance_check(float amount)
	{
		do {
			if (amount >= (Bank_balance - 1000))
			{
				cout << "Error! Minimum Rs.1000 must be avaiable in your account OR The amount you enter is more than the actual amount in your account" << endl;
				cout << "Enter amount again" << endl;
				cin >> amount;
			}
		} while (amount >= (Bank_balance - 1000));
		return(amount);
	}
	float current(float rs_diff)
	{
		cout << "0.6% tax will be deducted from your account balance" << endl;
		tax = (0.6 / 100) * rs_diff;
		rs_diff = tax + rs_diff;
		balance = receipt() - rs_diff;
		return (balance);
	}
	float saving(float rs_diff)
	{
		cout << "0.3% tax will be deducted from your account balance" << endl;
		tax = (0.3 / 100) * rs_diff;
		rs_diff = tax + rs_diff;
		balance = receipt() - rs_diff;
		return (balance);
	}
};

class Utility :public ATM
{
public:
	float bill;
	void setValues(float b)
	{
		bill = b;
	}
	float getBill(float bill)
	{
		return bill;
	}
	void referenceNo()
	{
		do {
			cout << "Enter 14 digit Reference No. written on your bill = ";
			cin >> tr_reference;
			if (tr_reference.size() == 14)
			{
				cout << "Please wait while we are Processing your Bill........." << endl;
			}
			else
			{
				cout << "Invalid Reference No." << endl;
				cout << "Enter 14-digit Reference No. again" << endl;
			}
		} while (tr_reference.size() != 14);
	}
	float receipt()
	{
		cout << "Do you want to Print Slip?" << endl;
		cout << "Extra 2.5Rs will be charged for Slip" << endl;
		cout << endl << "Press 'y' OR 'Y' for Slip OR Press any key to continue procedure" << endl;
		cin >> slp;
		//for slip
		if (slp == 'y' || slp == 'Y')
		{
			return(Bank_balance = Bank_balance - tax_slip);
		}
		else
		{
			return(Bank_balance);
		}
	}
	float balance_check(float amount)
	{
		do {
			if (amount >= (Bank_balance - 1000))
			{
				cout << "Error! Minimum Rs.1000 must be avaiable in your account OR The amount you enter is more than the actual amount in your account" << endl;
				cout << "Enter amount again" << endl;
				cin >> amount;
			}
		} while (amount >= (Bank_balance - 1000));
		return(amount);
	}
	float current(float bill)
	{
		cout << "2.5% tax will be deducted from your account balance" << endl;
		tax = (2.5 / 100) * bill;
		balance = receipt() - bill - tax;
		return (balance);
	}
	float saving(float bill)
	{
		balance = receipt() - bill;
		return (balance);
	}
};

class OneBill :public ATM
{
public:
	float onebill;
	void setValues(float ob)
	{
		onebill = ob;
	}
	float getOneBill(float onebill)
	{
		return onebill;
	}
	void consumerNo()
	{
		do {
			cout << "Enter 17 digit Consumer No. written on your bill = ";
			cin >> tr_consumer;
			if (tr_consumer.size() == 17)
			{
				cout << "Please wait while we are Processing your Bill........." << endl;
			}
			else
			{
				cout << "Invalid Consumer No." << endl;
				cout << "Enter 17-digit Consumer No. again" << endl;
			}
		} while (tr_consumer.size() != 17);
	}
	float balance_check(float amount)
	{
		do {
			if (amount >= (Bank_balance - 1000))
			{
				cout << "Error! Minimum Rs.1000 must be avaiable in your account OR The amount you enter is more than the actual amount in your account" << endl;
				cout << "Enter amount again" << endl;
				cin >> amount;
			}
		} while (amount >= (Bank_balance - 1000));
		return(amount);
	}
	float receipt()
	{
		cout << "Do you want to Print Slip?" << endl;
		cout << "Extra 2.5Rs will be charged for Slip" << endl;
		cout << endl << "Press 'y' OR 'Y' for Slip OR Press any key to continue procedure" << endl;
		cin >> slp;
		//for slip
		if (slp == 'y' || slp == 'Y')
		{
			return(Bank_balance = Bank_balance - tax_slip);
		}
		else
		{
			return(Bank_balance);
		}
	}
	float current(float onebill)
	{
		cout << "5% tax will be deducted from your account balance" << endl;
		tax = (5 / 100) * onebill;
		balance = receipt() - onebill - tax;
		return (balance);
	}
	float saving(float onebill)
	{
		float balance;
		balance = receipt() - onebill;
		return (balance);
	}
};

int main()
{
	ATM *atm;
	Withdraw wd;
	Dollar dollar;
	Euro euro;
	Pound pound;
	SameLocal slt;
	DiffLocal dt;
	Utility ubill;
	OneBill bill1;
	string pin, tf_account;
	int card, choice, menu, wd_menu, fund_menu, inter_fund, payment_menu, utility_menu;;
	float wd_amount, rs_dollar, rs_euro, rs_pound, rs_samelocal, rs_difflocal, elec_bill, gas_bill, one_bill;
	char ch;
	do
	{
		system("cls");
		cout << "**********WELCOME TO ATM**********" << endl;
		do
		{
			cout << endl << "Enter your Card and Press 1" << endl;
			cin >> card;
			if (card == 1)
			{
				do
				{
					cout << endl << "Enter your 4-digit Pin: ";
					cin >> pin;
					if (pin.size() == 4)
					{
						system("cls");
						cout << endl << "Press 1 for Current Account." << endl;
						cout << "Press 2 for Savings Account." << endl;
						cin >> choice;
						switch (choice)
						{

							//--------------------------------Current Account------------------------------------------------------//

						case 1:
						{
							system("cls");
							cout << endl;
							cout << "Press (1) to Withdraw Cash" << endl;
							cout << "Press (2) for Balance Inquiry " << endl;
							cout << "Press (3) for Funds Transfer" << endl;
							cout << "Press (4) for Bill Payments" << endl;
							cin >> menu;
							switch (menu)
							{
							case 1:		//Withdraw Cash Case
							{
								system("cls");
								cout << endl;
								cout << "Press (1) to Widthdraw 1,000 " << endl;
								cout << "Press (2) to Widthdraw 5,000 " << endl;
								cout << "Press (3) to Widthdraw 10,000 " << endl;
								cout << "Press (4) to Widthdraw Custom Amount" << endl;
								cin >> wd_menu;
								switch (wd_menu)
								{
									//Menu of Withdrawing the Cash
								case 1:
								{
									wd_amount = 1000.0;
									atm = &wd;
									Bank_balance = atm->current(wd_amount);
									cout << "Your Remaining Account Balance is = " << Bank_balance << endl;
									break;
								}
								case 2:
								{
									wd_amount = 5000.0;
									atm = &wd;
									Bank_balance = atm->current(wd_amount);
									cout << "Your Remaining Account Balance is = " << Bank_balance << endl;
									break;
								}
								case 3:
								{
									wd_amount = 10000.0;
									atm = &wd;
									Bank_balance = atm->current(wd_amount);
									cout << "Your Remaning Account Balance is = " << Bank_balance << endl;
									break;
								}
								case 4:
								{
									cout << "Enter Custom Amount to Widthdraw : " << endl;
									cin >> wd_amount;
									float amount = wd.balance_check(wd_amount);
									atm = &wd;
									Bank_balance = atm->current(amount);
									cout << "Your Remaining Account Balance is = " << Bank_balance << endl;
									break;
								}
								}//Withdraw Menu Ending
								break;
							}
							//Withdraw Case 1 Ending
							case 2:		//Balance Inquiry Case
							{
								system("cls");
								cout << "Your Account Balance is = " << Bank_balance << endl;
								break;
							}
							//Balance Inquiry Case 2 Ending
							case 3:		//Funds Transfer Case
							{
								system("cls");
								cout << endl;
								cout << "Press (1) for Foreign Fund Transfer (International Banks)" << endl;
								cout << "Press (2) for Local Fund Transfer (Same Local Bank)" << endl;
								cout << "Press (3) for Local Fund Transfer (Other Local Banks)" << endl;
								cin >> fund_menu;
								switch (fund_menu)
								{
								case 1:		//Foreign Fund Transfer
								{
									system("cls");
									cout << endl;
									cout << "In which Currency you want to Transfer Funds Internationally?!" << endl;
									cout << endl;
									cout << "Press (1) from Rs to Dollars ($)" << endl;
									cout << "Press (2) from Rs to Euros (€)" << endl;
									cout << "Press (3) from Rs to Pounds (£)" << endl;
									cin >> inter_fund;
									switch (inter_fund)
									{
									case 1:
									{
										dollar.account_vr();
										cout << "Current Rate of 1 Dollar in Pakistan is \"Rs.228.1\"" << endl;
										cout << "Enter Rs amount you want to Transfer to Foreign Account in Dollars($)" << endl;
										cin >> rs_dollar;
										float amount = dollar.balance_check(rs_dollar);
										atm = &dollar;
										cout << "Your Remaining Account Balance after Transaction is = " << atm->current(amount) << " Rs" << endl;
										break;
									}
									case 2:
									{
										euro.account_vr();
										cout << "Current Rate of 1 Euro in Pakistan is \"Rs.243.8\"" << endl;
										cout << "Enter Rs amount you want to Transfer to Foreign in Euros(€)" << endl;
										cin >> rs_euro;
										float amount = euro.balance_check(rs_euro);
										atm = &euro;
										cout << "Your Remaining Account Balance after Transaction is = " << atm->current(amount) << " Rs" << endl;
										break;
									}
									case 3:
									{
										pound.account_vr();
										cout << "Current Rate of 1 Pound in Pakistan is \"Rs.277.3\"" << endl;
										cout << "Enter Rs amount you want to Transfer to Foreign in Pounds(£)" << endl;
										cin >> rs_pound;
										float amount = pound.balance_check(rs_pound);
										atm = &pound;
										cout << "Your Remaining Account Balance after Transaction is = " << atm->current(amount) << " Rs" << endl;
										break;
									}
									}
									break;
								}//Foreign Fund Transfer Case 1 Ending
								case 2:		//Local Same Bank Fund Transfer
								{
									system("cls");
									slt.account_vr();
									cout << "Enter Rs amount you want to transfer to other account " << endl;
									cin >> rs_samelocal;
									float amount = slt.balance_check(rs_samelocal);
									atm = &slt;
									cout << "Your Remaining Account Balance after transaction is = " << atm->current(amount) << endl;
									break;
								}//Local Same Bank Fund Transfer Case 2 Ending
								case 3:		//Local Diff Bank Fund Transfer
								{
									system("cls");
									dt.account_vr();
									cout << "Enter Rs amount you want to transfer to other account " << endl;
									cin >> rs_difflocal;
									float amount = dt.balance_check(rs_difflocal);
									atm = &dt;
									cout << "Your Remaining Account Balance after transaction is = " << atm->current(amount) << endl;
									break;
								}//Local Diff Bank Fund Transfer Case 2 Ending
								}//Funds Transfer Menu Ending
								break;
							}
							//Funds Transfer Case 3 Ending
							case 4:		//Bill Payments Case
							{
								system("cls");
								cout << endl;
								cout << "Press (1) for Utility Bills" << endl;
								cout << "Press (2) for 1 Bill Invoice" << endl;
								cin >> payment_menu;
								switch (payment_menu)
								{
								case 1:		//Utility Bills
								{
									system("cls");
									cout << endl;
									cout << "Press (1) for Electricity Bill" << endl;
									cout << "Press (2) for Gas Bill" << endl;
									cin >> utility_menu;
									switch (utility_menu)
									{
									case 1:		//Electricity Bill
									{
										ubill.referenceNo();
										cout << "Enter your Bill Amount " << endl;
										cin >> elec_bill;
										float amount = ubill.balance_check(elec_bill);
										atm = &ubill;
										cout << "Your Remaining Account Balance after Bill Payment is = " << atm->current(amount) << endl;
										break;
									}
									case 2:		//Gas Bill
									{
										ubill.referenceNo();
										cout << "Enter your Bill Amount " << endl;
										cin >> gas_bill;
										float amount = ubill.balance_check(gas_bill);
										atm = &ubill;
										cout << "Your Remaining Account Balance after Bill Payment is = " << atm->current(amount) << endl;
										break;
									}
									}
									break;
								}
								case 2:		//1 Bill Invoice
								{
									system("cls");
									bill1.consumerNo();
									cout << "Enter your Bill Amount" << endl;
									cin >> one_bill;
									float amount = bill1.balance_check(one_bill);
									atm = &bill1;
									cout << "Your Remaining Account balance after payment is = " << atm->current(amount) << endl;
									break;
								}
								}
								break;
							}
							//Bill Payments Case 4 Ending
							}
							//Current Account Menu Ending
							break;
						}

						//--------------------------------Saving Account------------------------------------------------------//

						case 2:
						{
							system("cls");
							cout << endl;
							cout << "Press (1) to Withdraw cash" << endl;
							cout << "Press (2) for Balance Inquiry " << endl;
							cout << "Press (3) for Funds Transfer" << endl;
							cout << "Press (4) for Bill Payments" << endl;
							cin >> menu;
							switch (menu)
							{
							case 1:		//Withdraw Cash Case
							{
								system("cls");
								cout << endl;
								cout << "Press (1) to Widthdraw 1,000 " << endl;
								cout << "Press (2) to Widthdraw 5,000 " << endl;
								cout << "Press (3) to Widthdraw 10,000 " << endl;
								cout << "Press (4) to Widthdraw Custom Amount" << endl;
								cin >> wd_menu;
								switch (wd_menu)
								{
									//Menu of withdrawing the cash
								case 1:
								{
									wd_amount = 1000.0;
									atm = &wd;
									Bank_balance = atm->saving(wd_amount);
									cout << "Your Remaining Account Balance is = " << Bank_balance << endl;
									break;
								}
								case 2:
								{
									wd_amount = 5000.0;
									atm = &wd;
									Bank_balance = atm->saving(wd_amount);
									cout << "Your Remaining Account Balance is = " << Bank_balance << endl;
									break;
								}
								case 3:
								{
									wd_amount = 10000.0;
									atm = &wd;
									Bank_balance = atm->saving(wd_amount);
									cout << "Your Remaning Account Balance is = " << Bank_balance << endl;
									break;
								}
								case 4:
								{
									cout << "Enter Custom Amount to Widthdraw : " << endl;
									cin >> wd_amount;
									float amount = wd.balance_check(wd_amount);
									atm = &wd;
									Bank_balance = atm->saving(amount);
									cout << "Your Remaining Account Balance is = " << Bank_balance << endl;
									break;
								}
								}//Withdraw Menu Ending
								break;
							}
							//Withdraw Case 1 Ending
							case 2:		//Balance Inquiry Case
							{
								system("cls");
								cout << "Your Account Balance is = " << Bank_balance << endl;
								break;
							}
							//Balance Inquiry Case 2 Ending
							case 3:		//Funds Transfer Case
							{
								system("cls");
								cout << endl;
								cout << "Press (1) for Foreign Fund Transfer (International Banks)" << endl;
								cout << "Press (2) for Local Fund Transfer (Same Local Bank)" << endl;
								cout << "Press (3) for Local Fund Transfer (Other Local Banks)" << endl;
								cin >> fund_menu;
								switch (fund_menu)
								{
								case 1:		//Foreign Fund Transfer
								{
									system("cls");
									cout << endl;
									cout << "In which Currency you want to transfer funds internationally?!" << endl;
									cout << endl;
									cout << "Press (1) from Rs to Dollars ($)" << endl;
									cout << "Press (2) from Rs to Euros (€)" << endl;
									cout << "Press (3) from Rs to Pounds (£)" << endl;
									cin >> inter_fund;
									switch (inter_fund)
									{
									case 1:
									{
										dollar.account_vr();
										cout << "Current rate of 1 Dollar in Pakistan is \"Rs.228.1\"" << endl;
										cout << "Enter Rs amount you want to transfer to foreign account in Dollars($)" << endl;
										cin >> rs_dollar;
										float amount = dollar.balance_check(rs_dollar);
										atm = &dollar;
										cout << "Your Remaining Account Balance after transaction is = " << atm->saving(amount) << " Rs" << endl;
										break;
									}
									case 2:
									{
										euro.account_vr();
										cout << "Current rate of 1 Euro in Pakistan is \"Rs.243.8\"" << endl;
										cout << "Enter Rs amount you want to transfer to foreign in Euros(€)" << endl;
										cin >> rs_euro;
										float amount = euro.balance_check(rs_euro);
										atm = &euro;
										cout << "Your Remaining Account Balance after transaction is = " << atm->saving(amount) << " Rs" << endl;
										break;
									}
									case 3:
									{
										pound.account_vr();
										cout << "Current rate of 1 Pound in Pakistan is \"Rs.277.3\"" << endl;
										cout << "Enter Rs amount you want to transfer to foreign in Pounds(£)" << endl;
										cin >> rs_pound;
										float amount = pound.balance_check(rs_pound);
										atm = &pound;
										cout << "Your Remaining Account Balance after transaction is = " << atm->saving(amount) << " Rs" << endl;
										break;
									}
									}//Foreign Fund Transfer Menu Ending
									break;
								}
								case 2:		//Local Same Bank Fund Transfer
								{
									system("cls");
									slt.account_vr();
									cout << "Enter Rs amount you want to transfer to other account " << endl;
									cin >> rs_samelocal;
									float amount = slt.balance_check(rs_samelocal);
									atm = &slt;
									cout << "Your Remaining Account Balance after transaction is = " << atm->saving(amount) << endl;
									break;
								}
								case 3:		//Local Diff Bank Fund Transfer
								{
									system("cls");
									dt.account_vr();
									cout << "Enter Rs amount you want to transfer to other account " << endl;
									cin >> rs_difflocal;
									float amount = dt.balance_check(rs_difflocal);
									atm = &dt;
									cout << "Your Remaining Account Balance after transaction is = " << atm->saving(amount) << endl;
									break;
								}
								}//Funds Transfer Menu Ending
								break;
							}
							//Funds Transfer Case 3 Ending
							case 4:		//Bill Payments Case
							{
								system("cls");
								cout << endl;
								cout << "Press (1) for Utility Bills" << endl;
								cout << "Press (2) for 1 Bill Invoice" << endl;
								cin >> payment_menu;
								switch (payment_menu)
								{
								case 1:		//Utility Bills
								{
									system("cls");
									cout << endl;
									cout << "Press (1) for Electricity Bill" << endl;
									cout << "Press (2) for Gas Bill" << endl;
									cin >> utility_menu;
									switch (utility_menu)
									{
									case 1:		//Electricity Bill
									{
										ubill.referenceNo();
										cout << "Enter your bill amount " << endl;
										cin >> elec_bill;
										float amount = ubill.balance_check(elec_bill);
										atm = &ubill;
										cout << "Your Remaining Account Balance after Bill Payment is = " << atm->saving(amount) << endl;
										break;
									}
									case 2:		//Gas Bill
									{
										ubill.referenceNo();
										cout << "Enter your bill amount " << endl;
										cin >> gas_bill;
										float amount = ubill.balance_check(gas_bill);
										atm = &ubill;
										cout << "Your Remaining Account Balance after Bill Payment is = " << atm->saving(amount) << endl;
										break;
									}
									}
									break;
								}//Utility Bills Menu Ending
								case 2:		//1 Bill Invoice
								{
									system("cls");
									bill1.consumerNo();
									cout << "Enter your bill amount" << endl;
									cin >> one_bill;
									float amount = bill1.balance_check(one_bill);
									atm = &bill1;
									cout << "Your Remaining Account balance after payment is = " << atm->saving(amount) << endl;
									break;
								}
								}//Bill Payment Menu Ending 
								break;
							}
							//Bill Payment Case 4 Ending
							}//Saving Account Menu Ending
						}
						}
					}
					else
					{
						cout << "Error! Invalid Pin Code..." << endl << endl;
					}
				} while (pin.size() != 4);
			}
			else
			{
				cout << "Error! Please Press '1' only" << endl << endl;
			}
		} while (card != 1);
		cout << endl << endl << "Do you want to use ATM again?!" << endl;
		cout << "Press 'y' OR 'Y' to use ATM again OR Press any key to exit ATM " << endl;
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	system("cls");
	cout << endl << "***** Hope you like our Services *****" << endl;
	cout << "*****   Thank you for visiting   *****" << endl;
}