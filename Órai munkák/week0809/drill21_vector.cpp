#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <numeric>
#include <algorithm>

template<typename C>
void print(const C& c, char sep = '\n'){
	std::cout << "Container elements:\n";

	for(const auto elem : c){
		std::cout << elem << sep;
	}

	std::cout << std::endl;
}
int main(){
	try {
		
		const std::string iname {"input_float.txt"};
		std::ifstream ifs {iname};
		if(!ifs) throw std::runtime_error("Could not read file:" + iname);

		std::vector <double> vd;
		for(double d; ifs >> d;){
			vd.push_back(d);
		}

		print(vd);

		std::vector<int> vi(vd.size()); //vd méretével azonos helyet foglalunk le
		/*for(auto& d : vd){
			vi.push_back(d);
		}*/
		std::copy(vd.begin(), vd.end(), vi.begin());
		print(vi);

		for(int i = 0; i < vd.size(); i++){
			std::cout << vd[i] << '\t' << vi[i] << std::endl;
		}

		double vd_sum = 0;
		int vi_sum = 0;

		for(int i = 0; i < vd.size(); i++){ //vd összege
			vd_sum+=vd[i];
		}
		std::cout << "vd összege: " << vd_sum << std::endl;

		for(int i = 0; i < vi.size(); i++){ //vi összege
			vi_sum+=vi[i];
		}
		std::cout << "vi összege: " << vi_sum << std::endl;

		std::cout << "vd és vi különbsége: " << vd_sum - vi_sum << std::endl; //a két vektor különbsége

		std::reverse(vd.begin(), vd.end());
		print(vd);

		double vd_mean = vd_sum / vd.size(); //átlag
		std::cout << "Mean value of vd: " << vd_mean << std::endl;

		std::vector<double> vd2;

		for(int i = 0; i < vd.size(); i++){ //9. feladat
			if (vd[i] < vd_mean){
				vd2.push_back(vd[i]);
			}
		}
		print(vd2);

		std::sort(vd.begin(), vd.end());
		print(vd);
		
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
		return 1;
	} catch (...) {
		std::cerr <<"Unknown exception\n";
		return 2;

	}
}