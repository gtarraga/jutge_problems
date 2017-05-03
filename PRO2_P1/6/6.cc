 #include<list>
 #include<iostream>
 using namespace std;
 
 void seleccio(const list<double>& l, list<double>& sel){
		list<double>::const_iterator itL = l.begin();
		double sum = *itL, n = 1;
		sel.insert(sel.end(), sum);
		++itL;
		double val;
		while(itL != l.end()){
			val = *itL;
			if(sum/n <= val) sel.insert(sel.end(), val);
			sum+=val;
			++n;
			++itL;
		}
}



