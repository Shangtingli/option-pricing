#include "options.h"
#include <time.h>
#include <fstream>
#include <algorithm>
#include <cmath>

void Initialize(double & RFI, double & V, double & M, double & StockP, double & StrikeP, char & S, char & T, double & q, int & TS )
{
    cout << "Please enter the following information: " << endl;
    cout << endl;
    cout << "Please enter Risk Free Interest of the Stock :"<< endl;
    cin >> RFI;
    while (RFI <= 0 || RFI >=1 )
    {
       cout << "RFI is invalid; Please enter Risk Free Interest of the Stock : " << endl;
       cin >> RFI;
    }

    cout << "Please enter Volitality(sigma) of the Stock :"<< endl;
    cin >> V;
    while (V < 0)
    {
       cout << "Volitality is invalid; Please enter Volitality(sigma) of the Stock : " << endl;
    cin >>V;
    }

    cout << "Please enter Maturity (in years) of the Stock :"<< endl;
    cin >> M;
    while (M <= 0)
    {
       cout << "Years of Maturity is invalid; Please enter Maturity (in years) of the Stock : " << endl;
    cin >>M;
    }

    cout << "Please enter Stock Price of the Stock :"<< endl;
    cin >> StockP;
    while (StockP <= 0)
    {
       cout << "Stock Price is invalid; Please enter Stock Price of the Stock : " << endl;
    cin >>StockP;
    }

    cout << "Please enter Strike Price of the Stock :"<< endl;
    cin >> StrikeP;
    while (StrikeP <= 0)
    {
       cout << "Strike Price is invalid; Please enter Strike Price of the Stock : " << endl;
    cin >>StrikeP;
    }

    cout << "Please enter Style(American->A,European->E) of the Stock :"<< endl;
    cin >> S;
    while (S != 'E' && S != 'A')
    {
       cout << "Style is invalid; Please enter Style(American->A,European->E) of the Stock : " << endl;
    cin >>S;
    }

    cout << "Please enter Type(Call->C,Put->P) of the Stock :"<< endl;
    cin >> T;
    while (T != 'C' && T!= 'P')
    {
       cout << "Type is invalid; Please enter Type(Call->C,Put->P) of the Stock : " << endl;
    cin >>T;
    }

    cout << "Please enter Divident Yield of the Stock :"<< endl;
    cin >> q;
    while (q < 0 || q > 1)
    {
       cout << "Divident Yield is invalid; Please enter Dividend Yield of the Stock : " << endl;
    cin >>q;
    }

    cout << "Please enter Time Steps of the Stock :"<< endl;
    cin >> TS;
    while (TS <= 0)
    {
       cout << "Time Steps is invalid; Please enter Time Steps of the Stock : " << endl;
       cin >>TS;
    }
}

int main()
{
    cout << endl;
    cout << "Welcome to the usage of Option determining tool!" << endl;
    cout << "Developer : Shangting Li" << endl;
    cout << endl;
    cout << "What do you want to do ? Please enter exact number of the tasks in the instruction sheet: " << endl;
    cout << endl;
    cout << "FYI, -1 is for test user defined upper and lower leverages, 0 is a default case" << endl;
    cout << "ALSO , Case 5 are only for preliminary results. Question 2 and Question 3: " << endl;
    int choice;
    cin >> choice;
    switch(choice)
   {
    case -1:
        {
            cout << "This is used for test user defined upper and lower leverages" << endl;
            double StrikeP = 100;
            double StockP = 100;
            double V= 10;
            double RFI = 0;
            double q = 0;
            char T = 'C';
            char S = 'E';
            double M = 1;
            double TS = 1000000;
            Option option(RFI,V,M,StockP,StrikeP,S,T,q,TS);
            option.setUD(true);
            clock_t t;
            t = clock();
            double Price = option.getGeneralOptionP();
            cout << "Price is :" << Price << endl;
            cout << "Task -1 completion time :" << (float)(1000*t/CLOCKS_PER_SEC) << " milliseconds" << endl;
            return 0;
        }
    case 0:
        {
            double TS = 100000;
            cout << "Please specify time Steps of the program, Time step has to be at least 1000: "<< endl;
            cin >> TS;
            double StrikeP = 100;
            double StockP = 100;
            double V= 10;
            double RFI = 0.05;
            double q = 0;
            char T = 'C';
            char S = 'E';
            double M = 1;
            clock_t t;
            t = clock();
            Option option(RFI,V,M,StockP,StrikeP,S,T,q,TS);
            double price = option.getGeneralOptionP();
            cout << "IntrinsicValue : " << (StrikeP)-StockP << endl;
            cout << "RFI,V,M,StockP,StrikeP,S,T,q,TS" << endl;
            cout << RFI << " " << V << " "<< M << " "<<StockP<<" "<<StrikeP<<" "<<S << " " <<T << " "<<q << " "<<TS << endl;
            cout << "Price of the option : " << price << endl;
            t = clock() - t;
            cout << "Time of the operation : " << (float)(1000*t/CLOCKS_PER_SEC) << " milliseconds" << endl;
  
            return 0;
        }
    case 1:
        {
            double RFI = 0;
            double V = 0;
            double M = 0;
            double StockP = 0;
            double StrikeP = 0;
            char S ;
            char T ;
            double q = 0;
            int TS=0;
            Initialize(RFI,V,M,StockP,StrikeP,S,T,q,TS);
            clock_t t;
            t = clock();
            Option option(RFI,V,M,StockP,StrikeP,S,T,q,TS);
            double price = option.getGeneralOptionP();
            cout << "RFI,V,M,StockP,StrikeP,S,T,q,TS" << endl;
            cout << RFI << " " << V << " "<< M << " "<<StockP<<" "<<StrikeP<<" "<<S << " " <<T << " "<<q << " "<<TS << endl;
            cout << "Price of the option : " << price << endl;
            t = clock() -t;
            cout << "Time of the operation : " << (float)(1000*t/CLOCKS_PER_SEC) << " milliseconds" << endl;
            return 0;
        }

    case 2:
        {
            ofstream out("outCase2.txt");
            double RFI = .05;
            double V = 0.2;
            double M = 1;
            double StockP = 100;
            double StrikeP = 100;
            char S = 'E' ;
            char T = 'C' ;
            double q = 0.04;
            float Prices[200];
            int TS = 100;
            clock_t t;
            t = clock();
            for (int i=0;i<200;i++)
	       {
		       Option option(RFI,V,M,StockP,StrikeP,S,T,q,TS*(i+1));
    	       double price = option.getGeneralOptionP();
		       Prices[i] = price;
	       }
            out << endl;
	        out << "TimeSteps, Price" << endl;
            for (int j=0;j<200;j++)
	       {
		       out << TS*(j+1) << ", ";
		       out<< Prices[j] << endl;
	       }
            out << endl;
            t = clock() -t;
            cout << "Time of the operation : " << (float)(t/CLOCKS_PER_SEC) << " seconds" << endl;
            return 0;
        } 
    case 3:
        {
            //Task 1: Question: What is the Stock Price?? (Assumption: 100)
            cout << endl;
            cout << "TASK 1: Caclulate the time steps neede to reach 0.001 accuracy" << endl;
            cout << endl;
            //ofstream out("outCase3Task1.txt");
            double StrikeP = 100;
            //double StockP = 150;
            double V= 0.2;
            double RFI = 0.05;
            double q = 0;
            char T = 'P';
            char S = 'A';
            double M = 1;
            double TS = 2000;
            //out<<"Months, Timesteps" << endl;
            clock_t t;
            t = clock();
            cout << "TS IS :" << TS << endl;
            //return 0;
            //out.close();
            t = clock() -t;
            cout << "Task 1 Time of the operation : " << (float)(1000*t/CLOCKS_PER_SEC) << " milliseconds" << endl;
            //Task 2: Question: What is the time steps. (Assumption :2)
            t = clock();
            cout << endl;
            cout << "TASK 2: Plot the price of 12-month put as a function of S0" << endl;
            cout << endl;
            double stockPrice = 49;
            ofstream out2("outCase3Task2.txt");
            out2 << "Time Steps used : " << TS << endl;
            out2 << endl;
            out2 << "StockPrice , OptionPrice, IntrinsicValue" << endl;
            for (int k=0;k<101;k++)
            {
                stockPrice = stockPrice+1;
                Option option3(RFI,V,M,stockPrice,StrikeP,S,T,q,TS);
                double price = option3.getGeneralOptionP();
                double IntrinsicValue = (StrikeP-stockPrice>0)?(StrikeP-stockPrice):(0);
                out2 << stockPrice << " , " << price <<" , " << IntrinsicValue<< endl;
            }
            out2.close();
            t = clock() -t;
            cout << "Task 2 Time of the operation : " << (float)(1000*t/CLOCKS_PER_SEC) << " milliseconds" << endl;
            //Task 3: 
            //Question: What is the time steps ?? (Assumption :2)
            cout << endl;
            cout << "Task 3: Find the critical stock price for each maturity month"<<endl;
            cout << endl;
            t = clock();
            ofstream out3("outCase3Task3.txt");
            out3 << "Maturity(Months) (Without) , Critical Stock Price(Without)" << endl;
            for (int l=0;l<12;l++)
            {
                double stockPriceUP = 150;
                double stockPriceDOWN = 50;
                double stockPriceMID = (stockPriceUP+stockPriceDOWN)/2;
                M = (double)(l+1)/(double)12;
                Option compOptionMID(RFI,V,M,stockPriceMID,StrikeP,S,T,q,TS);
                double compOptionPriceMID =  compOptionMID.getGeneralOptionP();
                double IntrinsicValueMID = (StrikeP-stockPriceMID>0)?(StrikeP-stockPriceMID):(0);
                while(abs(stockPriceUP-stockPriceDOWN) > 0.005)
                {
                    if (abs(IntrinsicValueMID - compOptionPriceMID)<0.005)
                    {
                        stockPriceDOWN = stockPriceMID;
                        stockPriceMID = (stockPriceUP+stockPriceDOWN)/2;
                    }
                    else if (IntrinsicValueMID != compOptionPriceMID)
                    {
                        stockPriceUP = stockPriceMID;
                        stockPriceMID= (stockPriceUP+stockPriceDOWN)/2;
                    }
                    Option compOptionMID(RFI,V,M,stockPriceMID,StrikeP,S,T,q,TS);
                    compOptionPriceMID =  compOptionMID.getGeneralOptionP();
                    IntrinsicValueMID = (StrikeP-stockPriceMID>0)?(StrikeP-stockPriceMID):(0);
                }
                stockPriceMID = (stockPriceUP+stockPriceDOWN)/2;
                out3 << M*12 << " , " << stockPriceMID << endl;
            }
            t = clock() -t;
            cout << "Task 3 Time of the operation : " << (float)(1000*t/CLOCKS_PER_SEC) << " milliseconds" << endl;
            cout << endl;
            //Task 4:
            cout << "Task 4: Find the critical Stock price when the yield changes"<<endl;
           	cout << endl;
            t = clock();
            ofstream out4("outCase3Task4.txt");
            out4 << "Maturity(Months) (With) , Critical Stock Price(With)" << endl;
            for (int l=0;l<12;l++)
            {
                double stockPriceUP = 150;
                double stockPriceDOWN = 50;
                double stockPriceMID = (stockPriceUP+stockPriceDOWN)/2;
                M = (double)(l+1)/(double)12;
                Option compOptionMID(RFI,V,M,stockPriceMID,StrikeP,S,T,q,TS);
                double compOptionPriceMID =  compOptionMID.getGeneralOptionP();
                double IntrinsicValueMID = (StrikeP-stockPriceMID>0)?(StrikeP-stockPriceMID):(0);
                q = 0.04;
                while(abs(stockPriceUP-stockPriceDOWN) > 0.005)
                {
                    if (abs(IntrinsicValueMID - compOptionPriceMID)<0.005)
                    {
                        stockPriceDOWN = stockPriceMID;
                        stockPriceMID = (stockPriceUP+stockPriceDOWN)/2;
                    }
                    else if (IntrinsicValueMID != compOptionPriceMID)
                    {
                        stockPriceUP = stockPriceMID;
                        stockPriceMID= (stockPriceUP+stockPriceDOWN)/2;
                    }
                    Option compOptionMID(RFI,V,M,stockPriceMID,StrikeP,S,T,q,TS);
                    compOptionPriceMID =  compOptionMID.getGeneralOptionP();
                    IntrinsicValueMID = (StrikeP-stockPriceMID>0)?(StrikeP-stockPriceMID):(0);
                }
                stockPriceMID = (stockPriceUP+stockPriceDOWN)/2;
                out4 << M*12 << " , " << stockPriceMID << endl;
            }
            t = clock() -t;
            cout << "Task 4 Time of the operation : " << (float)(1000*t/CLOCKS_PER_SEC) << " milliseconds" << endl;
            return 0;
            
        }
    case 4:
        {
           //Task 1: Question: What is the Stock Price?? (Assumption: 100)
            cout << endl;
            cout << "TASK 1: Caclulate the time steps neede to reach 0.001 accuracy" << endl;
            cout << endl;
            //ofstream out("outCase3Task1.txt");
            double StrikeP = 100;
            //double StockP = 140;
            double V= 0.2;
            double RFI = 0.05;
            double q = 0.04;
            char T = 'C';
            char S = 'A';
            double M = 1;
            double TS = 2000;
            //out<<"Months, Timesteps" << endl;
            clock_t t;
            t = clock();
            /*for (int j = 1;j<1000;j++)
            {
                Option option1(RFI,V,M,StockP,StrikeP,S,T,q,j);
                Option option2(RFI,V,M,StockP,StrikeP,S,T,q,j+1);
                double price1 = option1.getGeneralOptionP();
                double price2 = option2.getGeneralOptionP();
                    //cout << price1 << " " << price2 << endl;
                if (abs(price1-price2) < .01 && abs(price1-price2) >0)
                {
                    TS = j;
                    break;
                }
            }*/
            //out.close();
            t = clock() -t;
            cout << "Task 1 Time of the operation : " << (float)(1000*t/CLOCKS_PER_SEC) << " milliseconds" << endl;
            //Task 2: Question: What is the time steps. (Assumption :2)
            t = clock();
            cout << endl;
            cout << "TASK 2: Plot the price of 12-month put as a function of S0" << endl;
            cout << endl;
            double stockPrice = 29;
            ofstream out2("outCase4Task2.txt");
            out2 << "Time Steps used : " << TS << endl;
            out2 << endl;
            out2 << "StockPrice , OptionPrice, IntrinsicValue" << endl;
            for (int k=0;k<141;k++)
            {
                stockPrice = stockPrice+1;
                Option option3(RFI,V,M,stockPrice,StrikeP,S,T,q,TS);
                double price = option3.getGeneralOptionP();
                double IntrinsicValue = (stockPrice-StrikeP>0)?(stockPrice-StrikeP):(0);
                out2 << stockPrice << " , " << price << " , " << IntrinsicValue<< endl;
            }
            out2.close();
            t = clock() -t;
            cout << "Task 2 Time of the operation : " << (float)(1000*t/CLOCKS_PER_SEC) << " milliseconds" << endl;
            //Task 3: 
            //Question: What is the time steps ?? (Assumption :2)
            cout << endl;
            cout << "Task 3: Find the critical stock price for each maturity month"<< endl;
            cout << endl;
            t = clock();
            ofstream out3("outCase4Task3.txt");
            out3 << "Maturity(Months) (Without) , Critical Stock Price(Without)" << endl;
            for (int l=0;l<12;l++)
            {
                double stockPriceUP = 170;
                double stockPriceDOWN = 30;
                double stockPriceMID = (stockPriceUP+stockPriceDOWN)/2;
                M = (double)(l+1)/(double)12;
                Option compOptionMID(RFI,V,M,stockPriceMID,StrikeP,S,T,q,TS);
                double compOptionPriceMID =  compOptionMID.getGeneralOptionP();
                double IntrinsicValueMID = (stockPriceMID-StrikeP>0)?(stockPriceMID-StrikeP):(0);
                while(abs(stockPriceUP-stockPriceDOWN) > 0.005)
                {
                    if (abs(IntrinsicValueMID - compOptionPriceMID)<0.005)
                    {
                        //cout << stockPriceMID << " , and " << IntrinsicValueMID << " equal" << endl;
                        stockPriceUP = stockPriceMID;
                        stockPriceMID = (stockPriceUP+stockPriceDOWN)/2;
                    }
                    else
                    {
                        //cout << stockPriceMID << " , and " << IntrinsicValueMID << " not equal" << endl;
                        stockPriceDOWN = stockPriceMID;
                        stockPriceMID= (stockPriceUP+stockPriceDOWN)/2;
                    }
                    Option compOptionMID(RFI,V,M,stockPriceMID,StrikeP,S,T,q,TS);
                    compOptionPriceMID =  compOptionMID.getGeneralOptionP();
                    IntrinsicValueMID = (stockPriceMID-StrikeP>0)?(stockPriceMID-StrikeP):(0);
                }
                stockPriceMID = (stockPriceUP+stockPriceDOWN)/2;
                out3 << M*12 << " , " << stockPriceMID << endl;
                t = clock() -t;
            	
            }
            cout << "Task 3 Time of the operation : " << (float)(1000*t/CLOCKS_PER_SEC) << " milliseconds" << endl;
            //Task 4:
            cout << endl;
            cout << "Task 4: Find the critical Stock price when the yield changes"<<endl;
           	cout << endl;
            t = clock();
            ofstream out4("outCase4Task4.txt");
            out4 << "Maturity(Months) (With) , Critical Stock Price(With)" << endl;
            for (int l=0;l<12;l++)
            {
                double stockPriceUP = 170;
                double stockPriceDOWN = 30;
                double stockPriceMID = (stockPriceUP+stockPriceDOWN)/2;
                M = (double)(l+1)/(double)12;
                Option compOptionMID(RFI,V,M,stockPriceMID,StrikeP,S,T,q,TS);
                double compOptionPriceMID =  compOptionMID.getGeneralOptionP();
                double IntrinsicValueMID = (stockPriceMID-StrikeP>0)?(stockPriceMID-StrikeP):(0);
                q = 0.08;
                while(abs(stockPriceUP-stockPriceDOWN) > 0.005)
                {
                    if (abs(IntrinsicValueMID - compOptionPriceMID)<0.005)
                    {
                        stockPriceUP = stockPriceMID;
                        stockPriceMID = (stockPriceUP+stockPriceDOWN)/2;
                    }
                    else
                    {
                        stockPriceDOWN = stockPriceMID;
                        stockPriceMID= (stockPriceUP+stockPriceDOWN)/2;
                    }
                    Option compOptionMID(RFI,V,M,stockPriceMID,StrikeP,S,T,q,TS);
                    compOptionPriceMID =  compOptionMID.getGeneralOptionP();
                    IntrinsicValueMID = (stockPriceMID-StrikeP>0)?(stockPriceMID-StrikeP):(0);
                }
                stockPriceMID = (stockPriceUP+stockPriceDOWN)/2;
                out4 << M*12 << " , " << stockPriceMID << endl;
            }
            t = clock() -t;
            cout << "Task 4 Time of the operation : " << (float)(1000*t/CLOCKS_PER_SEC) << " milliseconds" << endl;
            return 0;
        }
    case 5:
    {
        cout << "Case 5 for preliminary  Results. Second problem for P, Third problem for C" << endl; 
        double M = 0.5;
        char T = 'P';
        cout << "Call Or Put (C OR P) " << endl;
        cin >> T;
        double TS = 0.0;
        cout << "Please specify time Steps of the program, Time step has to be at least 1000: "<< endl;
        cin >> TS;
        cout << "Time Step Used : " << TS << endl;
        if (T != 'C' && T != 'P')
        {
            cout << "Please do not play with this serious program ." << endl;
            return 0;
        }
        double StrikeP = 100;
            //double StockP = 150;
        double V= 0.2;
        double RFI = 0.05;
        double q = 0.04;
        char S = 'A';
        double stockPriceUP = 150;
        double stockPriceDOWN = 50;
        double stockPriceMID = (stockPriceUP+stockPriceDOWN)/2;
        Option compOptionMID(RFI,V,M,stockPriceMID,StrikeP,S,T,q,TS);
        double compOptionPriceMID =  compOptionMID.getGeneralOptionP();

        double IntrinsicValueMID = 0.0;
        if (T == 'C')
            {IntrinsicValueMID = (stockPriceMID-StrikeP>0)?(stockPriceMID-StrikeP):(0);}
        if (T == 'P')
            {IntrinsicValueMID =(StrikeP-stockPriceMID>0)?(StrikeP-stockPriceMID):(0);}

        //cout << "IntrinsicValue : " << IntrinsicValueMID << endl;
        //cout << "PRICE : " << compOptionPriceMID << endl;
        cout << "StockPriceMID : " << stockPriceMID << endl;
        while(abs(stockPriceUP-stockPriceDOWN) > 0.005)
        {
            if (abs(IntrinsicValueMID - compOptionPriceMID)<0.005)
            {
                 
                if (T == 'C')
                {
                    stockPriceUP = stockPriceMID;
                    stockPriceMID = (stockPriceUP+stockPriceDOWN)/2;
                }
                if (T == 'P')
                {
                    stockPriceDOWN = stockPriceMID;
                    stockPriceMID = (stockPriceUP+stockPriceDOWN)/2;
                }
            }
            else if (IntrinsicValueMID != compOptionPriceMID)
            {
                if (T == 'C')
                {
                    stockPriceDOWN = stockPriceMID;
                    stockPriceMID= (stockPriceUP+stockPriceDOWN)/2;
                }
                if (T == 'P')
                {
                    stockPriceUP = stockPriceMID;
                    stockPriceMID= (stockPriceUP+stockPriceDOWN)/2;
                }
            }
            Option compOptionMID(RFI,V,M,stockPriceMID,StrikeP,S,T,q,TS);
            compOptionPriceMID =  compOptionMID.getGeneralOptionP();
            if (T == 'C')
                {IntrinsicValueMID =(stockPriceMID-StrikeP>0)?(stockPriceMID-StrikeP):(0);}
            if (T == 'P')
                {IntrinsicValueMID = (StrikeP-stockPriceMID>0)?(StrikeP-stockPriceMID):(0);}

            //cout << "IntrinsicValue : " << IntrinsicValueMID << endl;
            //cout << "PRICE : " << compOptionPriceMID << endl;
            cout << "StockPriceMID : " << stockPriceMID << endl;
        }
        stockPriceMID = (stockPriceUP+stockPriceDOWN)/2;
        cout << "Critical Stock Price : " << stockPriceMID << endl;

    }
    default:
        return 0;
   }
}
