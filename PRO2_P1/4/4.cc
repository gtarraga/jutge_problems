 #include<iostream>
 #include<vector>
 
 using namespace std;
 
 int comptatge_frontisses(const vector<int> &v){
	int left = 0, right = 0, cont = 0;
	int tam = v.size();
	for(int i = 0; i<tam; ++i){
		right+=v[i];
	}
	
	for(int i = 0; i<tam; ++i){
		right -= v[i];
		if(right - left == v[i]) ++cont;
		left += v[i];
	}
	return cont;
	
}
