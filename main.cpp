#include <iostream>
#include <fstream>
#include <string>
using namespace std;
using std::fstream;

struct FileMatch 
{
private:
	string firstpath;
	string secondpath;
	fstream firstfile, secondfile;
	std::ios_base::openmode open_mode;
public:

	//setters
	void setFirPath(string firstpath) { this->firstpath = firstpath; }
	void setSecPath(string secondpath) { this->secondpath = secondpath; }
	void setOpenMode(ios_base::open_mode open_mode) { this->open_mode = open_mode; }

	//geters
	ios_base::open_mode getOpenMode() { return open_mode; }
	string getFirPath() { return firstpath; }
	string getSecPath() { return secondpath; }



	//constructors
	FileMatch()
	{
		setFirPath("text.txt");
		setSecPath("text.txt");
		setOpenMode(ios::in);
	}
	FileMatch(string firstpath, string secondpath) :FileMatch()
	{
		setFirPath(firstpath);
		setSecPath(secondpath);
	}
	FileMatch(string firstpath, string secondpath, ios_base::open_mode open_mode) :FileMatch(firstpath, secondpath)
	{
		setOpenMode(open_mode);
	}



	//destructors
	~FileMatch() {
		firstpath.clear();
		secondpath.clear();
		open_mode = 0;
		firstfile.close();
		secondfile.close();
	}


};

int main() {
	string firstpath = "C:\\Users\\Dines\\source\\repos\\cpp_app_27\\one.txt";
	string secondpath = "C:\\Users\\Dines\\source\\repos\\cpp_app_27\\two.txt";
	string firline, secline;
	char* firline2;
	int len = 2, row = 0, vow = 0, cons = 0, num = 0;
	fstream firstfile, secondfile;
	std::ios_base::openmode open_mode = ios::in;
	firstfile.open(firstpath, ios::in);
	secondfile.open(secondpath, ios::out);
	FileMatch** match = new FileMatch * [3] 
	{
		new FileMatch(),
			new FileMatch(firstpath, secondpath),
			new FileMatch(firstpath, secondpath, open_mode),
	};
	if (firstfile.is_open() && secondfile.is_open())
	{
		int i = 0;
		string firline;
		while (getline(firstfile, firline)) {
			row += 1;
			for (char litera : firline) {
				len++;
				if (litera == 'a' || litera == 'e' || litera == 'i' || litera == 'o' || litera == 'u' ||
					litera == 'A' || litera == 'E' || litera == 'I' || litera == 'O' || litera == 'U')
				{
					vow++;
				}
				else if ((litera >= 'a' && litera <= 'z') || (litera >= 'A' && litera <= 'Z')) 
				{
					cons++;
				}
				else if (litera >= '0' && litera <= '9') 
				{
					num++;
				}
			}
		}

		firstfile.close();
		secondfile << "num of characters - " << len << endl;
		secondfile << "num of rows - " << row << endl;
		secondfile << "num of vowels - " << vow << endl;
		secondfile << "num of consonants - " << cons << endl;
		secondfile << "num of numbers - " << num << endl;
		secondfile.close();
	}
	else
	{
		cout << "file not open" << endl;
	}

	return 0;
};