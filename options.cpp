#include "options.h"

using namespace std;

Option::Option()
{}

Option::Option(double RFI, double V, double M, double StockP,double StrikeP, char S, char T, double q, double TS)
{
	setRFI(RFI);
	setVolitality(V);
	setMaturity(M);
	setStockPrice(StockP);
	setStrikePrice(StrikeP);
	setStyle(S);
	setType(T);
	setDY(q);
	setN(TS);
	setUD(false);
}

double Option::getOneValue(double P)
{
	//cout << "Strike price is : " << getStrikePrice() << endl;
	//cout << "P input is : " << P << endl;
	if (Type == 'C')
	{
		if (P-getStrikePrice() > 0)
			return P-getStrikePrice();
	}
	if (Type == 'P')
	{
		if (P-getStrikePrice() < 0)
			{
				//cout << "Price " << getStrikePrice()-P << endl;
				return getStrikePrice()-P;
			}
	}
	return 0;
}

double Option::getU()
{return exp(Volitality*sqrt((double)(Maturity/N)));}

double Option::getD()
{return exp(-Volitality*sqrt((double)(Maturity/N)));}

void Option::setUD(bool choice)
{
	if (choice)
	{
		double up = 0;
		double down = 0;
		cout << "Please enter the upper prob" << endl;
		cin >> up;
		cout << "Please enter the down prob" << endl;
		cin >> down;
		u = up;
		d = down;
		Volitality = -1;
	}
	else
	{
		u = getU();
		d = getD();
	}
}
double Option::getProb()
{
		//double u = getU();
		//double d = getD();
		double a = ((double)(r)-(double)(q))*(double)(Maturity)/(double)(N);
		//cout << "Risk Neutral Prob is : " << (exp(a)-d)/(u-d) << endl;
		return (exp(a)-d)/(u-d);
}

vector<double> Option::getAllStockP(double TS,double u, double d)
{
	vector<double> output;
	if (TS == 0)
	{
		output.push_back(StockPrice);
		return output;
	}
	double level = TS+1;
	//cout << "All stock Price : " << endl;
	for (int i = 0;i<(int)level;i++)
	{
		output.push_back(StockPrice*pow(u,level-1-i)*pow(d,i));
		//cout << StockPrice*pow(u,level-i-1)*pow(d,i)<< endl;
	}
	return output;
}

queue<double> Option::getAllOptionV(double TS) /*num is the number of nodes in the final level */
{
	/*num = N+1*/
	//cout << "TS is : " << TS << endl;
	queue<double> output;
	vector<double> Prices = getAllStockP(TS,u,d);
	for (auto it = Prices.begin();it != Prices.end();it++)
	{
		//cout << (*it) << " " << endl;
		output.push(getOneValue(*it));
		//cout << getOneValue(*it) << " "<< endl;
	}
	return output;
}

double Option::getEuroOptionP()
{
	queue<double> values = getAllOptionV(N);/*Size = N+1*/
	double ticks = N; /*ticks is the number of times of level, not the number of nodes in the final level*/
	double p = getProb();
	double ex = exp(-r*(Maturity/N));
	while(ticks>0)
	{
		for (int i=0;i<(int)ticks;i++)
		{
			double up = values.front();
			values.pop();
			double down = values.front();
			double value = ex*(p*up+(1-p)*down);
			values.push(value);
		}
		ticks--;
		values.pop();
	}
	OptionPrice = values.front();
	return values.front();
}


double Option::getAmerOptionP()
{
	queue<double> values = getAllOptionV(N);
	double ticks = N;
	double p = getProb();
	double ex = exp(-r*(Maturity/N));
	while(ticks>0)
	{
		queue<double> comp = getAllOptionV(ticks-1);
		for (int i=0;i<(int)ticks;i++)
		{
			double up = values.front();
			values.pop();
			double down = values.front();
			double value = ex*(p*up+(1-p)*down);
			if (value>=comp.front())
			{
				values.push(value);
			}
			else
			{
				values.push(comp.front());
			}
			comp.pop();
		}
		ticks--;
		values.pop();
	}
	OptionPrice = values.front();
	return values.front();
}

double Option::getGeneralOptionP()
{
	if (Style == 'A')
		return getAmerOptionP();
	if (Style == 'E')
		return getEuroOptionP();
	return 0;
}
