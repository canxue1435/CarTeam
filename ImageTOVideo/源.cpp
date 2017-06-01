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
		//找到字符串中首个不等于分隔符的字母；
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

		//找到又一个分隔符，将两个分隔符之间的字符串取出；
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

int main()
{
	//ifstream fin("D:\\faster_rcnn-master\\urban1821-原版-2.txt");
	//char imageName[200];
	//VideoWriter video("urban1821-SSD-third.avi", CV_FOURCC('M', 'J', 'P', 'G'), 20, Size(640, 480), 1);
	//int i = 1;
	//String lineData;
	//vector<string> line;
	//String putTextCon;
	//Mat src;
	//

	//while (getline(fin, lineData)){
	//	line = split(lineData, " ");

	//	const char *k = line[0].c_str();
	//	sprintf(imageName, "D:\\faster_rcnn-master\\urban1821\\%s.jpg", k);
	//	src = imread(imageName);

	//	for (int i = 1; i < line.size()-1; i += 6){
	//		if (line[i] == "car" || line[i] == "bus" || line[i] == "bicycle" || line[i] == "motorbike" || line[i] == "person" ){
	//			rectangle(src, Point(stod(line[i + 1]), stod(line[i + 2])), Point(stod(line[i + 3]), stod(line[i + 4])), Scalar(0, 0, 255), 2);
	//			putTextCon = line[i] + " "+line[i + 5];

	//			putText(src, putTextCon, Point(stod(line[i + 1]), stod(line[i + 2])), CV_FONT_HERSHEY_COMPLEX, 0.5, Scalar(0, 0, 255), 1);
	//		}
	//		
	//	}

	//		
	//	video.write(src);
	//	//imshow("a", src);
	//	//waitKey(10);
	//	cout << line[0] << endl;
	//}
	//video.release();

	//cout << "finish";

	char imageName[200];

	VideoWriter video("urban1821-SSD-third.avi", CV_FOURCC('M', 'J', 'P', 'G'), 20, Size(640, 480), 1);

	for (int i = 1; i < 1822; i++){
		sprintf(imageName, "L:\\ssd-temp第一次试验结果-视频\\第三个模型\\05-31-01-40\\%06d.jpg", i);

		Mat src = imread(imageName);

		video.write(src);
	}

	video.release();
}

