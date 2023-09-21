#include <iostream>
#include <windows.h>
#include <sstream>
#include <time.h>
#include <string>
#include "Avl.h"
#include "Linked_List.h"
using namespace std;

int main();
struct node *root = NULL;
int admin_pswd= 1234;
int staff_pswd= 5678;

int create_Acc()
{
  //Declared Variables
  string full_name;
  string cnic;
  string Acc_type;
  char g;
  int acc_no;
  int pin;
  long long Balance;
  int load=0;
  int a=1;
  //END Declared Variables
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  cout<<""<<endl;
  cout<<"                                                 Create User Account"<<endl;
  cout<<" "<<endl;
  cout<<"                                            Enter Customer's Full Name : ";cin.ignore();getline(cin,full_name);
  cout<<" "<<endl;
  cout<<"                                            Enter CNIC (xxxxx-xxxxxxx-x) : ";getline(cin,cnic);
  cout<<" "<<endl;
  cout<<"                                            Enter Gender  (M/F) : ";cin>>g;
  cout<<" "<<endl;
  cout<<"                                            Enter Account Type (C/S) : ";cin.ignore();cin>>Acc_type;
  cout<<" "<<endl;
  load=findMax(root);
  acc_no = load + 1;
  cout<<"                                            Your Account Number is : "<<acc_no<<endl;
  cout<<" "<<endl;
  cout<<"                                            Enter Pin : " ;cin.ignore();cin>>pin;
  cout<<" "<<endl;
  jump2:
  cout<<"                                            Enter Balance (Min:500) : ";cin.ignore();cin>> Balance;
  if(Balance >= 500){goto jump3;}
  else{cout<<"                                            Minimum Balance is 500Rs. "<<endl;goto jump2;}

  jump3:
      root = insertion(root,full_name,cnic,g,Acc_type,acc_no,pin,Balance); //insertion(root)
      insertion_for_log(acc_no);
  return 1;
}


int admin_panel()
{
  //Declared Variables
  int b;
  int admin_delete_cin;
  int admin_search_cin;
  int result_admin_1;
  int result_admin_2;
  int result_admin_3;
  int result_admin_4;
  int admin_return;

  int acc_1;
  int pin_1;
  string cnc_1;
  char gen_1;
  string acc_type_1;
  string new_cnc_1;
  int new_pin_1;
  string new_acc_1;
  int admin_logs_cin;
  //END Declared Variables

  /////////////JUMP_2
  jump2:
  system("Color B");
  system("cls");
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"                                                       ***************************************"<<endl;
  cout<<"                                                       *************ADMIN|||PANEL*************"<<endl;
  cout<<"                                                       ***************************************"<<endl;
  cout<<"                                                       *  Press 1 To Create Account          *"<<endl;
  cout<<"                                                       *  Press 2 To Delete Account          *"<<endl;
  cout<<"                                                       *  Press 3 To Search Account          *"<<endl;
  cout<<"                                                       *  Press 4 To Show List of All Acc    *"<<endl;
  cout<<"                                                       *  Press 7 To Go Back to Main Menu    *"<<endl;
  cout<<"                                                       ***************************************"<<endl;
  cout<<"                                                       Enter an Option : ";
  cin>>b;
  if(b == 1){
            lol_admin_1:
            system("cls");
            create_Acc();
            lol_admin_2:
            cout<<" "<<endl;
            cout<<" "<<endl;
            cout<<"                                         Press 1 to create another account or Press 7 to return to ADMIN PANEL ...!!! ";
            cin>>admin_return;
            if(admin_return == 7){goto jump2;}
            else if(admin_return == 1){goto lol_admin_1;}
            else{goto lol_admin_2;}}
  else if(b == 2){
  	 		lol_admin_3:
                system("cls");
                cout<<"                                         Enter the Account Number to Delete :";
                cin>>admin_delete_cin;
                result_admin_1 = search(root,admin_delete_cin);
			    cout<<result_admin_1<<endl;
	        if(result_admin_1 == 1){
			    cout<<"                                         Account number Found....!!!"<<endl;
			    cout<<" " <<endl;
			    deletion(root,admin_delete_cin);
			    cout<<" " <<endl;
			    cout<<"                                         Account is Deleted....!!!"<<endl;}
			else{
			    cout<<" " <<endl;
			    cout<<"                                         Account not found ....!!!"<<endl;
				cout<<" "<<endl;}
	        lol_admin_4:
                cout<<" "<<endl;
                cout<<" "<<endl;
                cout<<"                                         Press 2 to Delete another account or Press 7 to return to ADMIN PANEL ...!!! ";
                cin>>admin_return;
                if(admin_return==7){goto jump2;}
                else if(admin_return==2){goto lol_admin_3;}
                else{cout<<"                                         Invalid Output !! "<<endl;goto lol_admin_4; }}

  else if(b == 3){
            lol_admin_5:
  			  system("cls");
              cout<<"                                         Enter the Account Number to Search : ";
			  cin>>admin_search_cin;
              result_admin_2 = search(root,admin_search_cin);
              if(result_admin_2 == 1){
				cout<<" "<<endl;
				cout<<"                                         User Found..!!"<<endl;
				cout<<" "<<endl;
				print_data(root,admin_search_cin);
	      	    cout<<" "<<endl;}
	      	  else if(result_admin_2 == 0){
				     cout<<" "<<endl;
					 cout<<" "<<endl;
					 cout<<"                                         User not found..!! :("<<endl;
				     cout<<" "<<endl;
				     cout<<" "<<endl;}
		        cout<<" "<<endl;
			lol_admin_6:
                cout<<" "<<endl;
             	cout<<" "<<endl;
                cout<<"                                         Press 3 to Search another account or Press 7 to return to ADMIN PANEL ...!!! ";
                cin>>admin_return;
                if(admin_return==7){goto jump2;}
                else if(admin_return == 3){goto lol_admin_5;}
                else{cout<<"                                         Invalid Output !!"<<endl;goto lol_admin_6; }}

  else if(b == 4){
    	    lol_admin_7:
  	            system("cls");
                cout<<"        ####################################################################################################################################"<<endl;
    		    cout<<" "<<endl;
    			cout<<"          "<<"ACC_Number"<<"                 "<<"NAME"<<"                   "<<"CNIC"<<"                     "<<"GENDER"<<"            "<<"Type"<<"          "<<"PIN"<<"          "<<"BALANCE"<<endl;
    			cout<<" "<<endl;
    			cout<<"        ####################################################################################################################################"<<endl;
    			cout<<" "<<endl;
				print_for_admin(root);
            lol_admin_8:
                cout<<" "<<endl;
                cout<<" "<<endl;
                cout<<"                                         Press 4 to Show list of accounts or Press 7 to return to ADMIN PANEL ...!!! ";
                cin>>admin_return;
                if(admin_return==7){goto jump2;}
                else if(admin_return == 4){goto lol_admin_7;}
                else{cout<<"                                         Invalid Output !!"<<endl;goto lol_admin_8;}}

  else if(b == 7){main();}
            else{
                system("cls");
	            goto jump2;}
}

int staff_panel(){
   //Variable Used
   int staff_acc_no;
   int staff_pin_no;
   int staff_amount_to_dep;
   int staff_acc_no_1;
   int staff_pin_no_1;
   int staff_amount_to_wdraw_1;
   int account_logs_cin;
   int c;
   int staff_return;
   int lol_staff_1;
   int lol_staff_2;
   int account_info_cin;
   int result_staff_1;
   int result_staff_2;
   int result_staff_3;
   int result_staff_4;
   //End Variable Declaration

   ////////////JUMP_3:
  jump3:
  system("Color B");
  system("cls");
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"                                                       ***************************************"<<endl;
  cout<<"                                                       *************STAFF|||PANEL*************"<<endl;
  cout<<"                                                       ***************************************"<<endl;
  cout<<"                                                       *  Press 1 To Check Account Info      *"<<endl;
  cout<<"                                                       *  Press 2 To Deposit Cash            *"<<endl;
  cout<<"                                                       *  Press 3 To With_Draw Cash          *"<<endl;
  cout<<"                                                       *  Press 4 To Check Logs of User      *"<<endl;
  cout<<"                                                       *  Press 5 To Go Back to Main Menu    *"<<endl;
  cout<<"                                                       ***************************************"<<endl;
  cout<<"                                                       Enter an Option : ";
  cin>>c;
  if(c == 1){
  	    lol_staff_1:
  	        system("cls");
            cout<<"                                         Enter the Account Number to Check info : ";
			cin>>account_info_cin;
            result_staff_1= search(root,account_info_cin);
			if(result_staff_1 == 1){cout<<" "<<endl;
             	cout<<"                                         User Found..!!"<<endl;
				cout<<" "<<endl;
				print_data(root,account_info_cin);
				cout<<" "<<endl;}
            else if(result_staff_1 == 0){cout<<"                                         User not found..!! :("<<endl;
				cout<<" "<<endl;
				cout<<" "<<endl;}

				cout<<" "<<endl;
			lol_staff_2:
				cout<<"                                         Press 1 to search again or Press 5 to return to STAFF PANEL..!! ";
				cin>>staff_return;
				if(staff_return  == 1){goto lol_staff_1;}
				else if(staff_return == 5){ goto jump3;}
				else{cout<<"                                         Invalid Output !!"<<endl;goto lol_staff_2;}
				}
  else if(c == 2){
  	  		lol_staff_3:
  				system("cls");
  	            cout<<"                                         Enter Account : ";
  	            cin>>staff_acc_no;
  	            cout<<"                                         Enter Account PIN : ";
  	            cin>>staff_pin_no;
  	            cout<<"                                         Enter The Amount Deposit : ";
  	            cin>>staff_amount_to_dep;
  	            cout<<" "<<endl;
  	            cout<<"                                                   Status ""BEFORE"" Deposit Amount in ACCOUNT"<<endl;
  	            cout<<" "<<endl;
    			print_data(root,staff_acc_no);
    			cout<<" "<<endl;
    			cout<<" "<<endl;
    			result_staff_2 = deposit(root,staff_acc_no,staff_pin_no,staff_amount_to_dep);
    			if(result_staff_2 == 1){
    		    		cout<<"                                                   Status ""AFTER"" Deposit Amount in ACCOUNT"<<endl;
  	            		cout<<" "<<endl;
    					print_data(root,staff_acc_no);
    					cout<<" "<<endl;
    					cout<<" "<<endl;
    			time_t now = time(0);
                char* dt = ctime(&now);
                ostringstream str1;
                str1 << staff_amount_to_dep;
                        string add = "Amount " + str1.str();
                        string add1 = add + " has been deposited  at " + dt;

						cout<<"                                         Amount "<<staff_amount_to_dep<<" has been Deposited in Account Number  "<<staff_acc_no<<endl; insert_log(staff_acc_no,add1);}
    			else if(result_staff_2 == 0){cout<<"                                                     Account not Found....Amount is not Deposit in your Account...!"<<endl;}
				else if(result_staff_2 == -1){cout<<"                                                     PIN is Incorrect"<<endl;}
    			cout<<" "<<endl;
    			cout<<" "<<endl;
			lol_staff_4:
				cout<<"                                         Press 4 to Deposit amount in another account : 5 to return to STAFF PANEL...!!! ";
                cin>>staff_return;
                if(staff_return==4){goto lol_staff_3;}
                else if(staff_return==5){goto jump3;}
                else{cout<<"                                         Invalid Output !!"<<endl;goto lol_staff_4;}}
  else if(c == 3){cout<<"with draw cash"<<endl;
            lol_staff_5:
  				system("cls");
  	            cout<<"                                         Enter Account Number : ";
  	            cin>>staff_acc_no_1;
  	            cout<<"                                         Enter Account PIN : ";
  	            cin>>staff_pin_no_1;
  	            cout<<"                                         Enter The Amount WithDraw : ";
  	            cin>>staff_amount_to_wdraw_1;
  	            cout<<" "<<endl;
  	            cout<<"                                                   Status ""BEFORE"" WITHDRAW Amount from ACCOUNT"<<endl;
  	            cout<<" "<<endl;
    			print_data(root,staff_acc_no_1);
    			cout<<" "<<endl;
    			cout<<" "<<endl;
    			result_staff_3 = with_draw(root,staff_acc_no_1,staff_pin_no_1,staff_amount_to_wdraw_1);
    			if(result_staff_3 == 1){
    		    		cout<<"                                                   Status ""AFTER"" WITHDRAW Amount from ACCOUNT"<<endl;
  	            		cout<<" "<<endl;
    					print_data(root,staff_acc_no_1);
    					cout<<" "<<endl;
    					cout<<" "<<endl;
    				time_t now = time(0);
                	char* dt = ctime(&now);
                	ostringstream str1;
                	str1 << staff_amount_to_dep;
                        string add2 = "Amount " + str1.str();
                        string add3 = add2 + " has been Withdrawn  at " + dt;
						cout<<"                                         Amount "<<staff_amount_to_wdraw_1<<" has been Withdraw in Account Number  "<<staff_acc_no_1<<endl;insert_log(staff_acc_no_1,add3);}
    			else if(result_staff_3 == 0){cout<<"                                                     Account not Found....Amount is not With Drawn from User Account...!"<<endl;}
				else if(result_staff_3 == -1){cout<<"                                                     Account Balance is Insufficient "<<endl;}
				else if(result_staff_3 == -2){cout<<"                                                     PIN is InCorrect..!! "<<endl;}
    			cout<<" "<<endl;
    			cout<<" "<<endl;
			lol_staff_6:
				cout<<"                                         Press 3 to With Draw from another account : 5 to return to STAFF PANEL...!!! ";
                cin>>staff_return;
                if(staff_return==3){goto lol_staff_5;}
                else if(staff_return==5){goto jump3;}
                else{cout<<"                                         Invalid Output !!"<<endl;goto lol_staff_6;}}
  else if(c == 4){
            lol_staff_7:
  				system("cls");
  	            cout<<"                                         Enter Account Number: ";
  	            cin>>account_logs_cin;
                result_staff_4 = display1(account_logs_cin);
                print_data(root,account_logs_cin);
                if(result_staff_4 == 1){
                	cout<<""<<endl;
                	cout<<""<<endl;
                	display(account_logs_cin);
				    }
                else{cout<<"                                         Logs Not Found....!!!"<<endl;}
			lol_staff_8:
				cout<<"                                         Press 4 to Check Logs of  another account : 5 to return to STAFF PANEL...!!! ";
                cin>>staff_return;
                if(staff_return==4){goto lol_staff_7;}
                else if(staff_return==5){goto jump3;}
                else{cout<<"                                         Invalid Output !!"<<endl;goto lol_staff_8;}
			}
  else if(c == 5){
      system("cls");main();}
  else{goto jump3;}
}

int atm_panel()
{
  // declare variable
  int d;
  int atm_acc_no_1;
  int atm_pin_no_1;
  int atm_amount_to_wdraw_1;
  int result_atm_3;
  int atm_return;
  //End Variable Declaration

  ////////////JUMP_4
  jump4:
  system("Color B");
  system("cls");
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"                                                       ***************************************"<<endl;
  cout<<"                                                       *******************ATM*****************"<<endl;
  cout<<"                                                       ***************************************"<<endl;
  cout<<"                                                       *  Press 1 To Deposit Cash            *"<<endl;
  cout<<"                                                       *  Press 2 To Go Back to Main Menu    *"<<endl;
  cout<<"                                                       ***************************************"<<endl;
  cout<<"                                                       Enter an Option : ";
  cin>>d;
  if(d == 1){
  			lol_atm_1:
  				system("cls");
  	            cout<<"                                         Enter Account Number : ";
  	            cin>>atm_acc_no_1;
  	            cout<<"                                         Enter Account PIN : ";
  	            cin>>atm_pin_no_1;
  	            cout<<"                                         Enter The Amount WithDraw : ";
  	            cin>>atm_amount_to_wdraw_1;
  	            cout<<" "<<endl;
  	            cout<<"                                                   Status ""BEFORE"" WITHDRAW Amount from ACCOUNT"<<endl;
  	            cout<<" "<<endl;
    			print_data(root,atm_acc_no_1);
    			cout<<" "<<endl;
    			cout<<" "<<endl;
    			result_atm_3 = with_draw(root,atm_acc_no_1,atm_pin_no_1,atm_amount_to_wdraw_1);
    			if(result_atm_3 == 1){
    		    		cout<<"                                                   Status ""AFTER"" WITHDRAW Amount from ACCOUNT"<<endl;
  	            		cout<<" "<<endl;
    					print_data(root,atm_acc_no_1);
    					cout<<" "<<endl;
    					cout<<" "<<endl;
    				time_t now = time(0);
                	char* dt = ctime(&now);
                	ostringstream str1;
                	str1 << atm_amount_to_wdraw_1;
                        string add2 = "Amount " + str1.str();
                        string add3 = add2 + " has been Withdrawn  at " + dt;
						cout<<"                                         Amount "<<atm_amount_to_wdraw_1<<" has been Withdraw in Account Number  "<<atm_acc_no_1<<endl;insert_log(atm_acc_no_1,add3);}
    			else if(result_atm_3 == 0){cout<<"                                                     Account not Found....Amount is not With Drawn from User Account...!"<<endl;}
				else if(result_atm_3 == -1){cout<<"                                                     Account Balance is Insufficient "<<endl;}
				else if(result_atm_3 == -2){cout<<"                                                     PIN is InCorrect..!! "<<endl;}
    			cout<<" "<<endl;
    			cout<<" "<<endl;
			lol_staff_6:
				cout<<"                                         Press 3 to With Draw from another account : 5 to return to ATM PANEL...!!! ";
                cin>> atm_return;
                if(atm_return==3){goto lol_atm_1;}
                else if(atm_return==5){goto jump4;}
                else{cout<<"                                         Invalid Output !!"<<endl;goto lol_atm_1;}}

  else if(d == 2){
      system("cls");main();}
  else{goto jump4;}
}


int main()
{
    root = insertion(root,"G.P.Adhithya","12345-6789101-1",'M',"C",32001,1234,500000);
    insertion_for_log(32001);
    root = insertion(root,"M.Shreenithi","12345-6789101-2",'F',"C",32002,1122,90000);
    insertion_for_log(32002);
    root = insertion(root,"B.M.Vinush","12345-6789101-3",'M',"S",32003,4567,10000);
    insertion_for_log(32003);


  int a;
  int b;
  system("MODE 150, 40");
  //End Variable Declaration
  /////////////JUMP_1
  jump1:
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";


  system("Color B");
  system("cls");
  cout<<"\n";
  cout<<"                                                                BANKING SYSTEM          "<<endl;
  cout<<"\n"<<endl;
  cout<<"                                                       ********************************"<<endl;
  cout<<"                                                       **********LOGIN||PANEL**********"<<endl;
  cout<<"                                                       ********************************"<<endl;
  cout<<"                                                       *  Press 1 For ADMIN Login     *"<<endl;
  cout<<"                                                       *  Press 2 For STAFF Login     *"<<endl;
  cout<<"                                                       *  Press 3 For ATM Service     *"<<endl;
  cout<<"                                                       *  Press 4 To  Exit            *"<<endl;
  cout<<"                                                       ********************************"<<endl;
  cout<<"                                                       ********************************"<<endl;
  cout<<"\n"<<endl;
  cout<<"                                                       Enter Your Choice : ";
  cin>>a;
  if(a == 1){
        jump2:
        system("Color B");
        system("cls");
        cout<<"\n";
        cout<<"\n";
        cout<<"\n";
        cout<<"\n";
        cout<<"                                                       Enter Pin : ";
        cin >>b;
        if(b == admin_pswd){admin_panel();}
        else{goto jump2;}}
  else if(a == 2){
        jump3:
        system("Color B");
        system("cls");
        cout<<"\n";
        cout<<"\n";
        cout<<"\n";
        cout<<"\n";
        cout<<"                                                       Enter Pin : ";
        cin >>b;
        if(b == staff_pswd){staff_panel();}
        else{goto jump3;}}
  else if(a == 3){atm_panel();}
  else if(a == 4){exit(0);}
  else {goto jump1;}


}
                                                  //-------------------xxxxxxxxxxxxxxxxx---------------------------\\
