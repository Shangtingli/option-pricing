#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class Option
{
	private:
		char Type; /*Call or put */
		char Style; /*American or European */
		double StrikePrice;
		double StockPrice;
		double Maturity;
		double Volitality;
		double r; /*Risk Free Interest */
		double q; /*dividend yield*/
		double N;/*No. of time steps*/
		double OptionPrice;
		double u;
		double d;
	public:
		double getRFI() {return r;}
		double getVolitality() {return Volitality;}
		double getMaturity() {return Maturity;}
		double getStockPrice() {return StockPrice;}
		double getStrikePrice() {return StrikePrice;}
		char getStyle() {return Style;}
		char getType() {return Type;}
		double getDY(){return q;}
		double getN() {return N;}
		double getU();
		double getD();
		double getEuroOptionP();
		double getAmerOptionP();
		double getGeneralOptionP();
		/*GETTERS*/
		void setRFI(double RFI_input) {r = RFI_input;}
		void setVolitality(double V) {Volitality = V;}
		void setMaturity(double M) {Maturity = M;}
		void setStockPrice(double StockP) {StockPrice = StockP;}
		void setStrikePrice(double StrikeP) {StrikePrice = StrikeP;}
		void setStyle(char S) {Style = S;}
		void setType(char T) {Type = T;}
		void setDY(double DY) {q = DY;}
		void setN(double TS) {N = TS;}
		void setUD(bool choice);
		/*SETTERS*/
		Option();
		Option(double RFI,double V, double M, double StockP, double StrikeP, char S, char T, double q, double TS);
		/*CONSTRUCTORS*/
		double getOneValue(double P);
		double getProb();
		vector<double> getAllStockP(double TS,double u, double d); /*Temporarily public*/
		queue<double> getAllOptionV(double TS);
		/*Temporarily public*/
		/*FUNCTIONS*/



};
