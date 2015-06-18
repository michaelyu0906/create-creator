#include<fstream>
#include<string>
#include<map>
using namespace std;
ofstream fout("homework.xml");
class homework
{
private:
	map <string, int> subjectNo;
	int subjectNum = 0;
public:
	class subject
	{
	public:
		string subjectName;
		int chapterNum;
		class chapter
		{
		private:
			int queNum;
			class ques
			{
			private:
				int queNo;
				int difficulty;
			public:
				void print(int chapterNo)
				{
					fout << "\t\t\t<ques>\n";
					fout << "\t\t\t\t<quesNo>" << chapterNo << "." << queNo << "</quesNo>\n";
					fout << "\t\t\t\t<difficulty>" << difficulty << "</difficulty>\n";
				}
			};
			ques __ques[2];
		public:
			int chapterNo;
			void print()
			{
				fout << "\t\t<chapter No=\"" << chapterNo << "\">\n";
				for (int i = 0; i < queNum; i++)
					__ques[i].print(chapterNo);
				fout << "\t\t</chapter>\n";
			}
		};
		chapter* chapterHead[100];
	public:
		void chapterAppend(int chapter_Num)
		{
			chapterNum = chapter_Num;
			for (int i = 0; i < chapterNum; i++)
				chapterHead[i] = new chapter[1];
		}
		void print() //print a subject
		{
			fout << "\t<subject name=\"" << subjectName << "\">";
			for (int i = 0; i < chapterNum; i++)
				chapterHead[i]->print();
			fout << "\t</subject>\n";
		}
	};
	void print()  //print homework
	{
		fout << "<homework>\n";
		for (int i = 0; i < subjectNum; i++)
			subjectHead[i]->print();
		fout << "</homework>\n";
	}
	void subjectAppend(string subject_Name, int chapter_Num)  //apply ram for a subject
	{
		subjectHead[subjectNum++] = new subject[1];
		subjectHead[subjectNum - 1]->subjectName = subject_Name;
		subjectHead[subjectNum - 1]->chapterAppend(chapter_Num);
	}

private:
	subject* subjectHead[100];//point the head to subject
};

int main()
{
	homework homework1;
	homework1.print();
	return 0;
}