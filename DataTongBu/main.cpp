#include <iostream>
#include <opencv2\opencv.hpp>
#include <fstream>

using namespace std;
using namespace cv;

vector<string> split(const string &s, const string &seperator){
	vector<string> result;
	typedef string::size_type string_size;
	string_size i = 0;

	while (i != s.size()){
		//�ҵ��ַ������׸������ڷָ�������ĸ��
		int flag = 0;
		while (i != s.size() && flag == 0){
			flag = 1;
			for (string_size x = 0; x < seperator.size(); ++x)
			if (s[i] == seperator[x]){
				++i;
				flag = 0;
				break;
			}
		}

		//�ҵ���һ���ָ������������ָ���֮����ַ���ȡ����
		flag = 0;
		string_size j = i;
		while (j != s.size() && flag == 0){
			for (string_size x = 0; x < seperator.size(); ++x)
			if (s[j] == seperator[x]){
				flag = 1;
				break;
			}
			if (flag == 0)
				++j;
		}
		if (i != j){
			result.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return result;
}

int main(){
	ifstream fin("I:\\output.txt");

	string line;
	vector<string> lineData;

	while (getline(fin, line)){
		lineData.push_back(line);
	}

	char fileName[100];


	vector<string> lineSplit;
	for (int i = 1; i <= 558; i++){
		sprintf(fileName, "I:\\pan2\\ͬ������\\%d.txt", i);
		ofstream fout(fileName);

		for (int j = 0; j < lineData.size(); j++){
			lineSplit = split(lineData[j]," ");
			if (stoi(lineSplit[0])==i)
			{
				fout << lineSplit[1] << " " << lineSplit[2] << " " << lineSplit[3] << " " << lineSplit[4] << " " << lineSplit[5] << " " << lineSplit[6] << endl;
			}
			if (stoi(lineSplit[0]) > i)
			{
				break;
			}
		}

		fout.close();
	}
}